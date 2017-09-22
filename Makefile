OBJECTS = src/main.o src/vec2.o src/vec3.o

EXEC = bin/waglm.exe

CXXFLAGS = -Wall -std=c++11

CXX = g++

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)