// convert Hack assembly into XML
#include "asmxml.h"
#include "asmcode.h"
#include "asmtokens.h"

// assume that standard input is the contents of a Hack assembly file
// read each token and output it in XML format
int main()
{
	// create a new XML output object
	asmxml *xml = new asmxml() ;

	// create a new assembler tokeniser then read the first token
	asmtokens *tokeniser = asmtokens::newtokeniser() ;
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

	// output token counter as binary
	asmcode::output_0s_and_1s("Number of tokens read:") ;
	asmcode::output_16bits(tokens++) ;

	return 0 ;
}
