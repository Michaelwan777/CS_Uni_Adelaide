// a skeleton of the asmsymbols class file

#include "asmsymbols.h"
#include <iostream>

using namespace std ;

// define your own class to implement symbols_int
class symbols_int_x : public symbols_int
{
        bool insert(string symbol,int value)		// returns false for duplicate symbol
	{
		return false ;
	}
        int lookup(string symbol)			// returns -1 for undefined symbol
	{
		return -1 ;
	}
	void display()					// display contents in an arbitrary order
	{
	}
	void deleteme()					// deletes the symbol table
	{
	}
} ;

symbols_int *symbols_int::newtable()
{
	return new symbols_int_x() ;
}

// define your own class to implement symbols_string
class symbols_string_x : public symbols_string
{
	// remember to include definitions of all the inherited pure virtual functions
        bool insert(string symbol,string value)		// returns false for duplicate symbol
	{
		return false ;
	}
        string lookup(string symbol)			// returns "" for undefined symbol
	{
		return "" ;
	}
	void display()					// display contents in an arbitrary order
	{
	}
	void deleteme()					// deletes the symbol table
	{
	}
} ;

symbols_string *symbols_string::newtable()
{
	return new symbols_string_x() ;
}

