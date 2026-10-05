# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = delivery

# Define the object files
OBJ = delivery_lib.o delivery_main.o

# Define the test executable
TEST_TARGET = delivery_tests

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Explicit rule to create object files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creates a cleanup routine to remove object and target files
clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET) $(MEMORY_TARGET)

# Creates a run routine to run your program
run: $(TARGET)
	./$(TARGET)

# Build and run memory test with valgrind
MEMORY_TARGET = delivery_memory_test

memtest: delivery_memory_test.cpp delivery_lib.cpp delivery_lib.h
	$(CXX) $(CXXFLAGS) -g -O0 delivery_memory_test.cpp delivery_lib.cpp -o $(MEMORY_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MEMORY_TARGET)

# Build and run unit tests (requires GoogleTest)
# Note: GoogleTest 1.14+ requires C++14
test: delivery_unit_test.cpp delivery_lib.cpp delivery_lib.h
	$(CXX) -Wall -std=c++14 delivery_unit_test.cpp delivery_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
