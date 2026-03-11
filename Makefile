CXX = g++
CXXFLAGS = -pedantic-errors -std=c++11

TARGET = detective
OBJS = main.o game.o case.o notebook.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.cpp game.h case.h notebook.h
	$(CXX) $(CXXFLAGS) -c game.cpp

case.o: case.cpp case.h
	$(CXX) $(CXXFLAGS) -c case.cpp

notebook.o: notebook.cpp notebook.h case.h
	$(CXX) $(CXXFLAGS) -c notebook.cpp

clean:
	rm -f *.o $(TARGET)