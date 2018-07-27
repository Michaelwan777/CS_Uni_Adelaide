#ifndef VMTOKENS_H
#define VMTOKENS_H
#include <string>

// the vmtokens class reads Jack VM Code tokens from cin
class vmtokens
{
public:
        static vmtokens *newtokeniser() ;	// create a new tokeniser to read from cin
        virtual std::string next_token() =0;	// read the next token from the input and return its kind
        virtual std::string token_value() =0;	// return the current token as a string
};
#endif //VMTOKENS_H

