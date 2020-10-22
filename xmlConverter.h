//
// Created by Jimmy on 10/15/20 - Ubuntu 20.04
//

#ifndef XML_CONVERTER_XMLCONVERTER_H
#define XML_CONVERTER_XMLCONVERTER_H


#include "XElement.h"
#include "string"

class xmlConverter {
public:
    static XElement* convert(string xml);
    static void outputXml(XElement *node, string path, int depth);
    static void reverseConverter(XElement *node, int depth);
};


#endif //XML_CONVERTER_XMLCONVERTER_H
