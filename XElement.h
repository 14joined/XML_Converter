//
// Created by Jimmy on 10/15/20 - Ubuntu 20.04
//

#ifndef XML_CONVERTER_XELEMENT_H
#define XML_CONVERTER_XELEMENT_H
#include <string>
#include <vector>
using namespace std;
class XElement {
public:
    string tag;
    string field;
    vector<XElement*> xElements;
    vector<XElement*> attributes;

    XElement(string xml);

};


#endif //XML_CONVERTER_XELEMENT_H
