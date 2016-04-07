objects = main.o TiBasic.o Token.o
CXXFLAGS = -Wall

clangdbg : CXXFLAGS = -O0 -g -Wall

clang : CXX = clang++

debug : CXXFLAGS = -O0 -g -Wall

tirun : $(objects)
	$(CXX) $(CXXFLAGS) -o tirun $(objects)

main.o : main.cpp  TiBasic.h TiBasic.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp

TiBasic.o : TiBasic.h TiBasic.cpp  Token.h
	$(CXX) -c $(CXXFLAGS) TiBasic.cpp

Token.o : Token.h Token.cpp
	$(CXX) -c $(CXXFLAGS) Token.cpp

clean :
	rm -f tirun $(objects)

all: tirun

debug: tirun

clang : tirun

clangdbg : tirun
