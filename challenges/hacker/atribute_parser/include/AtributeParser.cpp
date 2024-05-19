

#include "AtributeParser.h"

std::string Tags::getAtributValue(const std::string &query)
{
    std::stringstream ss(query);
        std::string token;

        getline(ss, token, '~');

        std::vector<std::string> tags;
        std::string tagName;
        while (getline(ss, tagName, '.')) {
            tags.push_back(tagName);
        }

        return findAtributeValue(tags);
}

void Tags::parseHRMLLine(const std::string &line)
{
    std::stringstream ss(line);
    std::string token;

    ss >> token;
    if (token == "<")
    {
        std::string tagName;
        ss >> tagName;

        while (ss >> token && token != ">")
        {
            std::string attrName, equals, attrValue;
            ss >> attrName >> equals >> attrValue;
            attrValue.erase(remove(attrValue.begin(), attrValue.end(), '"'), attrValue.end());
            attributes[attrName] = attrValue;
        }   
    }
}

std::string Tags::findAtributeValue(const std::vector<std::string>& tags, const std::string &fullQuery)
{
    if (tags.empty() || tags[0] != name) {
            return "Not Found!";
        }

        if (tags.size() == 1) {
            // Reached the target tag, now get the attribute value
            std::stringstream ss;
            std::string attrName;
            getline(ss, attrName, '~'); // Get the attribute name after '~'

            auto it = attributes.find(attrName);
            if (it != attributes.end()) {
                return it->second; // Return attribute value if found
            } else {
                return "Not Found!";
            }
        }

        // Traverse to the next level of nested tags
        for (const Tags& child : children) {
            std::string childTag = tags[1]; // Next tag in the query
            if (child.name == childTag) {
                return child.findAtributeValue(std::vector<std::string>(tags.begin() + 1, tags.end()));
            }
        }

        return "Not Found!";
}
