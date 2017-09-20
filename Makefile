CXXFLAGS=-std=c++14 -Wall -Wextra -Werror -pedantic -g3
CXX=g++
SRC= main.cc case.cc map.cc 
VPATH=src
BIN=path_finding 

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@
clean: 
	@rm -rf $(BIN)
