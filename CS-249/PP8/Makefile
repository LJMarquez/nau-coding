# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = leaderboard

# Define the object files
OBJ = leaderboard_lib.o leaderboard_main.o

# Define the test executable
TEST_TARGET = leaderboard_tests

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
MEMORY_TARGET = leaderboard_memory_test

memtest: leaderboard_memory_test.cpp leaderboard_lib.cpp leaderboard_lib.h
	$(CXX) $(CXXFLAGS) -g -O0 leaderboard_memory_test.cpp leaderboard_lib.cpp -o $(MEMORY_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MEMORY_TARGET)

# Build and run unit tests (requires GoogleTest)
test: leaderboard_unit_test.cpp leaderboard_lib.cpp leaderboard_lib.h
	$(CXX) -Wall -std=c++14 leaderboard_unit_test.cpp leaderboard_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
