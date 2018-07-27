#ifndef ASMCODE_H
#define ASMCODE_H

#include <string>
#include <bitset>

class asmcode
{
public:
	static void output_0s_and_1s(std::string) ;	// outputs string followed by endl
	static void output_16bits(int) ;		// outputs least significant 16bits as 0s and 1s followed by endl
};
#endif //ASMCODE_H
