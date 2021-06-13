CXX = g++
CXXFLAGS = -g -Wall -std=c++2a
BUILD_DIR = ./build

PROG = test rsa
OBJ = type.o test.o prime.o rsa.o

all: $(PROG)

test: test.o type.o prime.o
	$(CXX) $(CXXFLAGS) -o $@ $^

rsa: rsa.o type.o prime.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): type.h prime.h

clean:
	-rm $(OBJ)
	-rm $(PROG)

.PHONY: all test