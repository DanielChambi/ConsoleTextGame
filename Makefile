PROG = textGame
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++0x
OBJS =  modelXML.o XMLParser.o controller.o view.o tinyxml2.o main.o
PATH = ./src/

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG).out $(OBJS)
main.o:
	$(CXX) $(CXXFLAGS) -c $(PATH)main.cpp

modelXML.o : $(PATH)modelXML.h
	$(CXX) $(CXXFLAGS) -c $(PATH)modelXML.cpp

XMLParser.o : $(PATH)XMLParser.h
	$(CXX) $(CXXFLAGS) -c $(PATH)XMLParser.cpp

controller.o : $(PATH)controller.h
	$(CXX) $(CXXFLAGS) -c $(PATH)controller.cpp

view.o : $(PATH)view.h
	$(CXX) $(CXXFLAGS) -c $(PATH)view.cpp

tinyxml2.o: $(PATH)tinyxml2.h
	$(CXX) $(CXXFLAGS) -c $(PATH)tinyxml2.cpp

clean:
	rm -f core $(PROG).out $(OBJS)