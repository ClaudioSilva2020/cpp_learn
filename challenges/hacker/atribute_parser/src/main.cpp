#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include "../include/AtributeParser.h"
using namespace std;



int main() {
       
    int n, q;
    cin >> n >> q;
    cin.ignore(); // Consume newline after n q


    vector<string> hrmlLines;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        hrmlLines.push_back(line);
    }
    

    vector<string> queries;
    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);
        queries.push_back(query);
    }

    unique_ptr<Tags> root = nullptr;
    Tags* currentTag = nullptr;

    for (const string& line : hrmlLines) {
        stringstream ss(line);
        string token;
        ss >> token;

        if (token == "</") {
            // Closing tag
            if (!currentTag->children.empty()) {
                currentTag = currentTag->children.back().get();
            }
        } else if (token == "<") {
            // Opening tag
            string tagName;
            ss >> tagName;

            auto newTag = make_unique<Tags>(tagName);
            newTag->parseHRMLLine(line);

            if (!root) {
                root = move(newTag);
                currentTag = root.get();
            } else {
                currentTag->addChildren(move(newTag));
                currentTag = currentTag->children.back().get();
            }
        }
    }

    for (const string& query : queries) {
        if (root) {
            auto result = root->getAtributValue(query);
            if (result.has_value()) {
                cout << result.value() << endl;
            } else {
                cout << "Not Found!" << endl;
            }
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
