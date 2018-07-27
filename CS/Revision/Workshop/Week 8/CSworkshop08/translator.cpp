// convert Jack VM Code into XML
#include <iostream>
#include "vmxml.h"
#include "vmtokens.h"

// assume that standard input is the contents of a Hack assembly file
// read each token and output it in XML format
int main()
{
	// create a new XML output object
	vmxml *xml = new vmxml() ;

	// create a new assembler tokeniser then read the first token
	vmtokens *tokeniser = vmtokens::newtokeniser() ;
	std::string token = tokeniser->next_token() ;

	// a token counters
	int tokens = 0 ;

	// XML root node is tokens
	xml->open_node("tokens") ;
	while ( token != "?" )			// stop at EOF, "?" denotes EOF
	{
		// output next token as an XML node
		xml->open_node(token) ;
		xml->node_text(tokeniser->token_value()) ;
		xml->close_node(token) ;

		// increment token counter
		tokens++ ;

		// read the next token
		token = tokeniser->next_token() ;
	}
	// close the root node
	xml->close_node("tokens") ;

	std::cout << "Number of tokens read: " << tokens << std::endl ;

	return 0 ;
}
