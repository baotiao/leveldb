CXX = g++
CXXFLAGS = -Wall -W -DDEBUG -g -O0
OBJECT = t.o

LIB_PATH = -L../
LIBS = -lleveldb
INCLUDE_PATH = -I../include/

.PHONY: main clean

main: $(OBJECT)
	$(CXX) $(CXXFLAGS) $(OBJECT) $(INCLUDE_PATH) $(LIBS) $(LIB_PATH)
	rm $(OBJECT)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_PATH)
clean:
	rm ./a.out
