# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++11 -Wall

# Define the source files
SRCS = main.cpp FileManager.cpp RandomPassGen.cpp User.cpp Cipher.cpp HashTable.cpp LinkedList.cpp Decipher.cpp

# Define the header files
HEADERS = FileManager.hpp RandomPassGen.hpp User.hpp Cipher.hpp HashTable.hpp LinkedList.hpp Decipher.hpp
# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the executable name
TARGET = cop4534-project-1

# The default target, which will be executed when you run `make`
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)

# Rule to build, run the program, and then clean up
run: $(TARGET)
	./$(TARGET)
	$(MAKE) clean

.PHONY: all clean run
