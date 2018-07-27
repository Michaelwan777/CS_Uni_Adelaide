#ifndef ASM_SYMBOLS_H
#define ASM_SYMBOLS_H

#include <string>

class symbols_int        // string to int symbol table
{
public:
        static symbols_int *newtable() ;			// create a new empty symbol table
        virtual bool insert(std::string symbol,int value) =0;	// returns false for duplicate symbol
        virtual int lookup(std::string symbol) =0;		// returns -1 for undefined symbol
	virtual void display() =0;				// display contents in an arbitrary order
	virtual void deleteme() =0;				// deletes the symbol table
} ;

class symbols_string     // string to string symbol table
{
public:
        static symbols_string *newtable() ;				// create a new empty symbol table
        virtual bool insert(std::string symbol,std::string value) =0;	// returns false for duplicate symbol
        virtual std::string lookup(std::string symbol) =0;		// returns "" for undefined symbol
	virtual void display() =0;					// display contents in an arbitrary order
	virtual void deleteme() =0;					// deletes the symbol table
} ;

#endif //ASM_SYMBOLS_H
