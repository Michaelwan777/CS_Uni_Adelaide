// a skeleton of the vmtokens class implementation

#include <iostream>
#include <ctype.h>
#include "asmsymbols.h"
#include "asmtokens.h"

using namespace std ;

// define your own class to implement asmtokens
class asmtokens_x : public asmtokens
{
public:
	asmtokens_x() ;			// create a new tokeniser
        string next_token() ; 		// read the next token from the input and return its kind
        string token_value() ;		// return the current token as a string
private:
        symbols_string *symbols ;	// internal symbol table - maps token values to token class
	string tvalue ;			// the current token as a string
	int ch ;			// the next character in the input
	void nextch() ;			// a function to read the next character and update ch
} ;

// return a pointer to a new tokeniser
asmtokens *asmtokens::newtokeniser()
{
	return new asmtokens_x() ;
}

// read the next character if not at EOF and update the variable ch
void asmtokens_x::nextch()
{
	if ( ch != EOF ) ch = cin.get() ;
}

// create a new tokeniser
asmtokens_x::asmtokens_x()
{
	// read the first character in the input and initialise tvalue
	ch = cin.get() ;
	tvalue = ch == EOF ? "?" : "" ;

	// create a new symbol table for string to string
	symbols = symbols_string::newtable() ;

	//token class dest
	symbols->insert("MD","dest") ;
	symbols->insert("AM","dest") ;
	symbols->insert("AD","dest") ;
	symbols->insert("AMD","dest") ;

	//token class dest-comp?
	symbols->insert("A","dest-comp?") ;
	symbols->insert("M","dest-comp?") ;
	symbols->insert("D","dest-comp?") ;

	// comp
	symbols->insert("0","comp") ;
	symbols->insert("1","comp") ;
	symbols->insert("-1","comp") ;
	symbols->insert("!D","comp") ;
	symbols->insert("!A","comp") ;
	symbols->insert("-D","comp") ;
	symbols->insert("-A","comp") ;
	symbols->insert("D+1","comp") ;
	symbols->insert("A+1","comp") ;
	symbols->insert("D-1","comp") ;
	symbols->insert("A-1","comp") ;
	symbols->insert("D+A","comp") ;
	symbols->insert("D-A","comp") ;
	symbols->insert("A-D","comp") ;
	symbols->insert("D&A","comp") ;
	symbols->insert("D|A","comp") ;

	symbols->insert("!M","comp") ;
	symbols->insert("-M","comp") ;
	symbols->insert("M+1","comp") ;
	symbols->insert("M-1","comp") ;
	symbols->insert("D+M","comp") ;
	symbols->insert("D-M","comp") ;
	symbols->insert("M-D","comp") ;
	symbols->insert("D&M","comp") ;
	symbols->insert("D|M","comp") ;

	// jump
	symbols->insert("JMP","jump") ;
	symbols->insert("JLT","jump") ;
	symbols->insert("JLE","jump") ;
	symbols->insert("JGT","jump") ;
	symbols->insert("JGE","jump") ;
	symbols->insert("JEQ","jump") ;
	symbols->insert("JNE","jump") ;

	// null
	symbols->insert("NULL","null") ;
}

// return the current token as a string
string asmtokens_x::token_value()
{
	return tvalue ;
}

// read the next token from the input and return its kind
string asmtokens_x::next_token()
{
	// once we have returned "?" we always return "?"
	if ( tvalue == "?" ) return "?" ;

	// loop to read characters until a token is found or EOF is found
	while ( true )
	{
		if ( ch == EOF )
		{
			tvalue = "?" ;
			return "?" ;
		}
		nextch() ;
	}
}
