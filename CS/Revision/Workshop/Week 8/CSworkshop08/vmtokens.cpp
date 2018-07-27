// a skeleton of the vmtokens class implementation

#include <iostream>
#include <ctype.h>
#include "vmsymbols.h"
#include "vmtokens.h"

using namespace std ;

// define your own class to implement vmtokens
class vmtokens_x : public vmtokens
{
public:
	vmtokens_x() ;			// create a new tokeniser
        string next_token() ; 		// read the next token from the input and return its kind
        string token_value() ;		// return the current token as a string
private:
        symbols_string *symbols ;	// internal symbol table - maps token values to token class
} ;

// return a pointer to a new tokeniser
vmtokens *vmtokens::newtokeniser()
{
	return new vmtokens_x() ;
}

// create a new tokeniser
vmtokens_x::vmtokens_x()
{
	// create a new symbol table for string to string
	symbols = symbols_string::newtable() ;

	// stack
	symbols->insert("push","stack") ;
	symbols->insert("pop","stack") ;

	// segment
	symbols->insert("argument","segment") ;
	symbols->insert("constant","segment") ;
	symbols->insert("local","segment") ;
	symbols->insert("pointer","segment") ;
	symbols->insert("static","segment") ;
	symbols->insert("temp","segment") ;
	symbols->insert("that","segment") ;
	symbols->insert("this","segment") ;

	// func
	symbols->insert("call","func") ;
	symbols->insert("function","func") ;

	// ops
	symbols->insert("return","op") ;
	symbols->insert("add","op") ;
	symbols->insert("and","op") ;
	symbols->insert("eq","op") ;
	symbols->insert("gt","op") ;
	symbols->insert("lt","op") ;
	symbols->insert("neg","op") ;
	symbols->insert("not","op") ;
	symbols->insert("or","op") ;
	symbols->insert("sub","op") ;

	// jump
	symbols->insert("goto","jump") ;
	symbols->insert("if-goto","jump") ;
	symbols->insert("label","jump") ;
}

// read the next token from the input and return its kind
string vmtokens_x::next_token()
{
	return "?" ;
}

// return the current token as a string
string vmtokens_x::token_value()
{
	return "?" ;
}
