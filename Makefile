CXXFLAGS=-std=c++14 -Wall -Wextra -Werror -pedantic -g3
CXX=g++
SRC= main.cc tile.cc map.cc djikstra.cc 
VPATH=src
BIN=path_finding 

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@
clean: 
	@rm -rf $(BIN)
