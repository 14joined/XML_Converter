//
// Created by Jimmy on 10/15/20 - Ubuntu 20.04
//

#include <iostream>
#include "XElement.h"

XElement::XElement(string xml) {
    if (!xml.empty()) {
        int i = 1, j;
        while (xml[i] != '>' && xml[i] != '/' && xml[i] != ' ') {
            ++i;
        }
        tag = xml.substr(1, i - 1);
        field = "null";
        while (xml[i] == ' ') {
            while (xml[i] == ' ') ++i;
            if (xml[i] == '/' || xml[i] == '>') break;
            j = i + 1;
            while (xml[j] != '=') {
                ++j;
            }
            XElement *element = new XElement("");
            element->tag = xml.substr(i, j - i);
            while (xml[j] != '\"' && xml[j] != '\'') ++j;
            i = j + 1;
            while (xml[i] != '\"' && xml[i] != '\'') ++i;
            element->field = xml.substr(j, i + 1 - j);
            attributes.push_back(element);
            ++i;
        }
        if (xml[i] != '/') {
            j = ++i;
            while (xml[j] != '<') ++j;
            field = '\"' + (i < j ? xml.substr(i, j - i) : "") + '\"';
        }
    }
}
