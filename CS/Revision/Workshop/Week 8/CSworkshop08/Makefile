# C++ 11 just in case
CXXFLAGS=--std=c++11

# must specify make target
all: tokens parser translator

clean:
	rm -f tokens parser translator *.o

# use precompiled vmxml, vmtokeniser, vmsymbols
tokens:	libstcx.a tokens.o
	g++ ${CXXFLAGS} -o tokens tokens.o libstcx.a

parser:	libstcx.a parser.o
	g++ ${CXXFLAGS} -o parser parser.o libstcx.a

translator:	libstcx.a translator.o
	g++ ${CXXFLAGS} -o translator translator.o libstcx.a
