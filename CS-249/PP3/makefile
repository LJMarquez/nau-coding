# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = untzler

# Define the object files
OBJ = untzler_lib.o untzler_main.o

# Define the test executable
TEST_TARGET = untzler_tests

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
test: untzler_unit_test.cpp untzler_lib.cpp untzler_lib.h
	$(CXX) -Wall -std=c++14 untzler_unit_test.cpp untzler_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
