#ifndef VMXML_H
#define VMXML_H

#include <string>

// the vmxl class writes XML nodes and data to cout
// in element names must only include, letters, digits, '-' '_' and '.'
// it will translate <,>,&,'," to HTML entities
class vmxml
{
public:
	static void open_node(std::string element) ;	// outputs <elementname>
	static void node_text(std::string content) ;	// outputs the content but translates &,<,>,',"
	static void close_node(std::string element) ;	// outputs </elementname>
};
#endif //VMXML_H
