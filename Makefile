CXX = g++
CXXFLAGS = -std=c++2a -Wall -g

# Find all source files in the current directory
SOURCES = $(wildcard *.cc) $(wildcard *.cpp)

# Generate corresponding object file names
OBJECTS = $(SOURCES:.cc=.o) $(SOURCES:.cpp=.o)

# Default target is to build the executable
all: truthtable

# Rule to build the executable
truthtable: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o truthtable

# Rule to build object files from source files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJECTS) truthtable

.PHONY: all clean
