//
// Created by Jimmy on 10/15/20 - Ubuntu 20.04
//

#include <iostream>
#include <deque>
#include "xmlConverter.h"
using namespace std;

XElement* xmlConverter::convert(string xml) {
    int i = 0, j;

    XElement* root = new XElement("");
    deque<XElement*> queue;
    queue.push_back(root);

    while (i < xml.size()) {
        j = i + 1;
        if (xml[j] == '/') {
            queue.pop_back();
            while (xml[j] != '>') ++j;
            i = j + 1;
            continue;
        }

        while (xml[j] != '/' && xml[j] != '>') ++j;
        XElement* pElement = queue.back();
        XElement* element;

        if (xml[j] == '/') {
            element = new XElement(xml.substr(i, j + 2 - i));
            i = j + 2;
        } else {
            ++j;
            if (xml[j] != '<' || (xml[j] != '<' && xml[j + 1] != '/')) {
                while (xml[j] != '>') ++j;
                element = new XElement(xml.substr(i, j + 1 - i));
                i = j + 1;
            } else {
                element = new XElement(xml.substr(i, j - 1 - i) + "/>");
                queue.push_back(element);
                element->field = "";
                i = j;
            }
        }

        if (pElement != nullptr) pElement->xElements.push_back(element);
    }

    return root;
}

void xmlConverter::outputXml(XElement *node, string path, int depth) {
    if (depth > 0) {
        cout << "\nPath: " << path << '/' << node->tag;
        cout << "\n     Field: " << (node->field.empty() ? "" : "\n") << "       " << node->field << '\n';
        bool b = true;
        for (XElement *e : node->attributes) {
            if (b) cout << "    Attribute(s):";
            cout << e->tag << ':' << e->field;
            b = false;
        }
    }
    for (XElement* e : node->xElements) {
        outputXml(e, path + (depth > 0 ? "/" + node->tag : ""), depth + 1);
    }
}

void xmlConverter::reverseConverter(XElement *node, int depth) {

    if (depth > 0) {
        for (int tab = 0; tab < depth; ++tab) {
            cout << '\t';
        }
        cout << '<' << node->tag;
        for (XElement *e : node->attributes) {
            int length = e->tag.length();
            cout << ' ' << e->tag.substr(0, length - 1) << "=" << e->field;
        }
        cout << ">";
        if (node->field.empty()) cout << '\n';
        int length = node->field.length();
        if (length > 0) {
            cout << node->field.substr(1, length - 2);
        }
    }
    for (XElement* e : node->xElements) {
        reverseConverter(e, depth + 1);
    }
    if (node->field.empty()) {
        for (int tab = 0; tab < depth; ++tab) {
            cout << '\t';
        }
    }
    if (depth > 0) {
        cout << "</" << node->tag << ">\n";
    }
}


