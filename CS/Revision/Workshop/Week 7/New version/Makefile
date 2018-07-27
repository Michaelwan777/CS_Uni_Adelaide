# C++ 11 - just in case
CXXFLAGS=--std=c++11

# must specify make target
all: X XT XS XST

clean:
	rm -f X XT XS XST *.o
 
# use precompiled asmxml, asmcode
X:	libcx.a asmtokens.o asmsymbols.o main.o
	g++ ${CXXFLAGS} -o X main.o asmtokens.o asmsymbols.o libcx.a
# use precompiled asmxml, asmcode, asmtokeniser
XT:	libtcx.a asmsymbols.o main.o
	g++ ${CXXFLAGS} -o XT main.o asmsymbols.o libtcx.a
# use precompiled asmxml, asmcode, asmsymbols
XS:	libscx.a asmtokens.o main.o
	g++ ${CXXFLAGS} -o XS main.o asmtokens.o libscx.a
# use precompiled asmxml, asmcode, asmtokeniser, asmsymbols
XST:	libstcx.a main.o
	g++ ${CXXFLAGS} -o XST main.o libstcx.a
