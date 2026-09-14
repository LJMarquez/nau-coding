# Define the compiler and the flags constants
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = mosaic_restoration

# Define the object files
OBJ = mosaic_lib.o mosaic_main.o

# Define the output file
OUTPUT = output.txt

# Build the target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Explicit rule to create object files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creates a cleanup routine to remove object and target files
clean:
	rm -f $(OBJ) $(TARGET) $(OUTPUT)

# Creates a run routine to run your program
run: $(TARGET)
	.\$(TARGET) > $(OUTPUT)
