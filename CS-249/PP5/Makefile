# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = music_player

# Define the object files
OBJ = music_lib.o music_main.o

# Define the test executable
TEST_TARGET = music_tests

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
MEMORY_TARGET = music_memory_test

memtest: music_memory_test.cpp music_lib.cpp music_lib.h
	$(CXX) $(CXXFLAGS) -g -O0 music_memory_test.cpp music_lib.cpp -o $(MEMORY_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MEMORY_TARGET)

# Build and run unit tests (requires GoogleTest)
# Note: GoogleTest 1.14+ requires C++14
test: music_unit_test.cpp music_lib.cpp music_lib.h
	$(CXX) -Wall -std=c++14 music_unit_test.cpp music_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
