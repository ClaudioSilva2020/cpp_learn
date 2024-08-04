/**
 * @file AtributeParser.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __ATRIBUTE_PARSER_H__
#define __ATRIBUTE_PARSER_H__

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <algorithm>

class Tags
{
private:
    std::string findAtributeValue(const std::vector<std::string>& tags, const std::string &fullQuery);

public:
    std::string name;
    std::unordered_map<std::string, std::string> attributes;
    std::vector<std::unique_ptr<Tags>> children;
    Tags(const std::string &tag_name): name(tag_name) {};
    ~Tags();

    void addChildren(std::unique_ptr<Tags> child)
    {
        children.push_back(move(child));
    }

    std::string getAtributValue(const std::string &query);
    void parseHRMLLine(const std::string &line);

};


Tags::~Tags()
{
}

#endif