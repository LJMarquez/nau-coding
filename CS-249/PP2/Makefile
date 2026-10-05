# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = puzzle

# Define the object files
OBJ = puzzle_lib.o puzzle_main.o

# Define the test executable
TEST_TARGET = puzzle_tests

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Explicit rule to create object files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creates a cleanup routine to remove object and target files
clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET)

# Creates a run routine to run your program
run: $(TARGET)
	./$(TARGET)

# Build and run unit tests (requires GoogleTest)
# Note: GoogleTest 1.14+ requires C++14
test: puzzle_unit_test.cpp puzzle_lib.cpp puzzle_lib.h
	$(CXX) -Wall -std=c++14 puzzle_unit_test.cpp puzzle_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
