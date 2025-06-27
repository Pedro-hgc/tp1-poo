##
# Flight Manangment System
#
# @file
# @version 0.1

#	Compiler Definitions
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude
TARGET := airline_system

#	Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

#	Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))
DEPS := $(wildcard $(INCLUDE_DIR)/*.hpp)

#	Default Target
all: $(BUILD_DIR) $(TARGET)

#	Create directory if doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run


# end
