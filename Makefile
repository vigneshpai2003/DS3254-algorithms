CXX = g++
CXXFLAGS = -Wall
SRC_DIR = src

# Ensure FILE is provided
ifndef FILE
$(error FILE is not set. Please specify it when running make, e.g., make FILE=sorting/main.cpp)
endif

# Extract the directory and filename without extension
DIR = $(dir $(FILE))
EXEC = $(basename $(FILE))

all:
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) $(FILE) -o $(EXEC).out

run:
	cd $(DIR) && ./$(notdir $(EXEC)).out

clean:
	rm -f $(EXEC)