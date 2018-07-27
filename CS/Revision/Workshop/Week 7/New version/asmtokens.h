#ifndef ASMTOKENS_H
#define ASMTOKENS_H
#include <string>

// the asmtokens class reads Hack assembly language tokens from cin
class asmtokens
{
public:
        static asmtokens *newtokeniser() ;	// create a new tokeniser to read from cin
        virtual std::string next_token() =0;	// read the next token from the input and return its kind
        virtual std::string token_value() =0;	// return the current token as a string
};
#endif //ASMTOKENS_H

