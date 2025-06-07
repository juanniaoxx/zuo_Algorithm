# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# Source files
SRCS := main.cpp print.cpp selection_sort.cpp bubble_sort.cpp insertion_sort.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := program

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful! Executable: $(TARGET)"
	@$(MAKE) clean_objs

# Compile each .cpp file into .o
%.o: %.cpp function.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up .o files (but keep executable)
clean_objs:
	@rm -f *.o
	@echo "Cleaned up object files."

# Full clean (executable + .o)
clean:
	@rm -f $(TARGET) *.o
	@echo "Cleaned up everything."