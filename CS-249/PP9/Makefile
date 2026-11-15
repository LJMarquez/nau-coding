# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = stock_market

# Define the object files
OBJ = stock_market_lib.o stock_market_main.o

# Define test executables
TEST_TARGET = stock_market_tests
MEMORY_TARGET = stock_market_memory_test

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
memtest: stock_market_memory_test.cpp stock_market_lib.cpp stock_market_lib.h
	$(CXX) $(CXXFLAGS) -g -O0 stock_market_memory_test.cpp stock_market_lib.cpp -o $(MEMORY_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MEMORY_TARGET)

# Build and run unit tests (requires GoogleTest)
test: stock_market_unit_test.cpp stock_market_lib.cpp stock_market_lib.h
	$(CXX) -Wall -std=c++14 stock_market_unit_test.cpp stock_market_lib.cpp -lgtest -lgtest_main -pthread -o $(TEST_TARGET)
	./$(TEST_TARGET)
