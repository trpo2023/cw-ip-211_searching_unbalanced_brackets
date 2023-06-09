all: main

main: main.o console.o search.o writting.o
	g++ -o app main.o console.o search.o writting.o

main.o: main.cpp
	g++ -Wall -Wextra -c main.cpp -MMD
		
console.o: console.cpp
	g++ -Wall -Wextra -c console.cpp -MMD
	
search.o: search.cpp
	g++ -Wall -Wextra -c search.cpp -MMD
	
writting.o: writting.cpp
	g++ -Wall -Wextra -c writting.cpp -MMD
clean:
	rm app *.o *.d
	

