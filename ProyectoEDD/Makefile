CXX = g++
CXXFLAGS = -std=c++11
SRCS = $(wildcard *.cpp *.cxx)
OBJS = $(SRCS:.cpp=.o)
TARGET = ejecutable

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

all: $(TARGET) run

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run all clean
