
all: main testing

main: src/app/main.o src/app/console.o src/app/search.o src/app/writting.o
	g++ -o src/appp src/app/main.o src/app/console.o src/app/search.o src/app/writting.o

main.o: src/app/main.cpp
	g++ -Wall -Wextra -c src/app/main.cpp -MMD
	
console.o: src/app/console.cpp
	g++ -Wall -Wextra -c src/app/console.cpp -MMD

search.o: src/app/search.cpp
	g++ -Wall -Wextra -c src/app/search.cpp -MMD

writting.o: src/app/writting.cpp
	g++ -Wall -Wextra -c src/app/writting.cpp -MMD
	
testing: tests/main1.o tests/test.o src/app/main.o src/app/console.o src/app/search.o src/app/writting.o
	g++ -o tests/testing tests/main1.o tests/test.o src/app/console.o src/app/search.o src/app/writting.o
	
main1.o: tests/main1.cpp
	g++ -Wall -Wextra -c test/main1.cpp -MMD
	
test.o: tests/test.cpp
	g++ -Wall -Wextra -c tests/test.cpp -MMD
	
clean:
	rm src/appp src/app/*.o src/app/*.d -f
	rm tests/appp tests/*.o tests/*.d tests/testing -f
	
run: testing
	./tests/testing
	
runap: appp
	./src/app
	
start:
	make
	make run
	make runap
	
start1:
	make clean
	make
	make run
	make runap
	

