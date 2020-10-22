#include <iostream>
#include <fstream>
#include "xmlConverter.h"

// Comment this line below to get xml file from objects,
// it will output objects with their path by default
#define outputObjects

using namespace std;

int main() {

    // Rename filename in corpus directory
    ifstream file ("corpus/Another_transactions.xml");

    string lines;
    if (file.is_open()) {
        string line;
        int start = 0;
        while (getline(file, line)) {
            bool flag = false, lock = true;

            ++start;

            if (start == 1) {
                for (int i = 0; i < line.size(); ++i) {
                    if (line[i] == '?') {
                        lock = false;
                        while (line[i] != '?' && line[i + 1] != '>') {
                            cout << line[i];
                        }
                        break;
                    }
                }
            }

            for (int i = 0; i < line.size(); ++i) {
                if (line[i] != ' ') {
                    flag = true;
                }

                if (flag && lock) {
                    lines += line[i];
                }
            }
        }
    } else {
        cout << "File was not opened.\n Nothing to convert!";
    }

//    cout << lines;
    XElement* root = xmlConverter::convert(lines);
#ifdef outputObjects
    xmlConverter::outputXml(root, "", 0);
#else
    xmlConverter::reverseConverter(root, 0);
#endif
    return 0;
}
