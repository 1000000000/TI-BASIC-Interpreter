objects = main.o TiBasic.o
CXXFLAGS = -Wall

clangdbg : CXXFLAGS = -O0 -g -Wall

clang : CXX = clang++

debug : CXXFLAGS = -O0 -g -Wall

tirun : $(objects)
	$(CXX) $(CXXFLAGS) -o tirun $(objects)

main.o : main.cpp  TiBasic.h TiBasic.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp

TiBasic.o : TiBasic.h TiBasic.cpp
	$(CXX) -c $(CXXFLAGS) TiBasic.cpp

clean :
	rm -f tirun $(objects)

all: tirun

debug: tirun

clang : tirun

clangdbg : tirun
