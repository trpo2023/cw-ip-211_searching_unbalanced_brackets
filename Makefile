CC=g++
CFLAGS=-c -Wall
LDFLAGS=functions.h
SOURCES=main.cpp search.cpp writting.cpp console.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=win

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
  $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
  $(CC) $(CFLAGS) $< -o $@
