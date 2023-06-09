
all: main testing

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
	
testing: main1.o test.o main.o console.o search.o writting.o
	g++ -o testing main1.o test.o console.o search.o writting.o
	
main1.o: main1.cpp
	g++ -Wall -Wextra -c main1.cpp -MMD
	
test.o: test.cpp
	g++ -Wall -Wextra -c test.cpp -MMD
clean:
	rm app *.o *.d
run: testing
	./testing
runapp: app
	./app
start:
	make clean
	make
	make run
	make runapp
	

