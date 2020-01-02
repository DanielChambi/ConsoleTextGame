PROG = textGame
CC = g++
OBJS =  modelXML.o controller.o view.o tinyxml2.o main.o
PATH = ./src/

$(PROG): $(OBJS)
	$(CC) -o $(PROG).out $(OBJS)
main.o:
	$(CC) -c $(PATH)main.cpp

modelXML.o : $(PATH)modelXML.h
	$(CC) -c $(PATH)modelXML.cpp

controller.o : $(PATH)controller.h
	$(CC) -c $(PATH)controller.cpp

view.o : $(PATH)view.h
	$(CC) -c $(PATH)view.cpp

tinyxml2.o: $(PATH)tinyxml2.h
	$(CC) -c $(PATH)tinyxml2.cpp

clean:
	rm -f core $(PROG).out $(OBJS)