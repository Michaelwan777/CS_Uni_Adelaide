#ifndef ASMXML_H
#define ASMXML_H

#include <string>

// the asmxl class writes XML nodes and data to cout
// in element names must only include, letters, digits, '-' '_' and '.'
// it will translate <,>,&,'," to HTML entities
class asmxml
{
public:
	static void open_node(std::string element) ;	// outputs <elementname>
	static void node_text(std::string content) ;	// outputs the content but translates &,<,>,',"
	static void close_node(std::string element) ;	// outputs </elementname>
};
#endif //ASMXML_H
