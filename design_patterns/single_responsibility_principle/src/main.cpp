#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

struct Journal
{
    string title;
    vector<string> entires;
    Journal(const string &title) : title(title) {}

    void add_entry(const string& entry)
    {
        static int count = 1;
        entires.push_back(to_string(count++) + ": " + entry);
    }

    void remove_entry(const int index)
    {
        entires.erase(entires.begin() + (index));
    }

};

struct PersistenceManager
{
    static void save(const Journal& j ,const string& filename)
    {
        ofstream ofs(filename);
        ofs << j.title << endl;
        for (auto& e : j.entires)
        {
            ofs << e << endl;
        }
    }
};

int main(int, char**){
    Journal  journal{"Dear Diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");
    journal.add_entry("I ate a pizza");
    journal.add_entry("I cried sunday");

    // journal.remove_entry(0);

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
}
