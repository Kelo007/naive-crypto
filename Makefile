CXX = g++
CXXFLAGS = -g -Wall -std=c++2a
BUILD_DIR = ./build

PROG = test
OBJ = test.o prime.o

all: $(PROG)

test: test.o prime.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): type.h prime.h

clean:
	-rm $(OBJ)
	-rm $(PROG)

.PHONY: all test