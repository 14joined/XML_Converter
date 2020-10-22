# XML_Converter
## Project 1. XML Converter

This is an assigment from Project 1, 20201, HUST

## Implementation

  1. Start in 'main.cpp', we read the file, convert the xml file to a string and discard the prologue if needed. If there is no available file, the program output 
  "File was not opened.\n Nothing to convert."

  2. Creat 'XElement' class contains 'tag' (string), 'field' (string), a vector (xElements) saving child element(s), another vector (attributes) for attributes.
  This class take a string in its constructor, extract its tag, field and push its attributes into a vector as we mentioned 'attributes'.
  
  3. Create 'xmlConverter' class, which will return the root pointer of the xml root element. We also have two functions, 'outputXml' and 'reverseConverter' in 
  this class, the first one handle the task output objects with its path, the latter output the origin xml file given the root pointer.
  
  4. To change between two task, comment line 7 '#define outputObjects;' in 'main.cpp'. Test files are in corpus, and switch between file by changing filename in 
  line 14 (main.cpp). 

## References

  Theory: XMl, JetBrains Academy.
  
## Contact

  1. Facebook: https://www.facebook.com/jimmity.raynor.5/
  
  2. Email: khang.vt183561@sis.hust.edu.vn
 
