
all: main testing

main: obj/project/main.o obj/project/libmain.a
	g++ -o src/appp obj/project/main.o obj/project/libmain.a

obj/project/libmain.a: obj/project/console.o obj/project/search.o obj/project/writting.o
	ar rcs obj/project/libmain.a obj/project/console.o obj/project/search.o obj/project/writting.o

obj/project/main.o: src/app/main.cpp
	g++ -Wall -Wextra -o obj/project/main.o -c src/app/main.cpp -MMD -w -I src
	
obj/project/console.o: src/app/console.cpp
	g++ -Wall -Wextra  -o obj/project/console.o -c src/app/console.cpp -MMD -w -I src

obj/project/search.o: src/app/search.cpp
	g++ -Wall -Wextra  -o obj/project/search.o -c src/app/search.cpp -MMD -w -I src

obj/project/writting.o: src/app/writting.cpp
	g++ -Wall -Wextra  -o obj/project/writting.o -c src/app/writting.cpp -MMD -w -I src
	
testing: obj/test/main.o obj/test/test.o obj/project/libmain.a
	g++ -o tests/testing obj/test/main.o obj/test/test.o obj/project/libmain.a

obj/test/main.o: tests/main.cpp
	g++ -Wall -Wextra  -o obj/test/main.o -c tests/main.cpp -MMD -w -I src
	
obj/test/test.o: tests/test.cpp
	g++ -Wall -Wextra  -o obj/test/test.o -c tests/test.cpp -MMD -w -I src
	
clean:
	rm src/appp obj/project/*.o obj/project/*.d obj/project/*.a -f
	rm tests/appp obj/test/*.o obj/test/*.d tests/testing -f
	
run: testing
	./tests/testing
	
runap: main
	./src/appp
	
start:
	make
	make run
	make runap
	
start1:
	make clean
	make
	make run
	make runap


