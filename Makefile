
all : main testing

              main : src
                     / main.o src
                     / console.o src
                     / search.o src
                     / writting.o g++
        - o app src / main.o src / console.o src / search.o src
                / writting.o

                          main.o
    : src / main.cpp g++
        - Wall - Wextra - c src / main.cpp
        - MMD

                        console.o
    : src / console.cpp g++
        - Wall - Wextra - c src / console.cpp
        - MMD

                        search.o
    : src / search.cpp g++
        - Wall - Wextra - c src / search.cpp
        - MMD

                        writting.o
    : src / writting.cpp g++
        - Wall - Wextra - c src / writting.cpp
        - MMD

                        testing : tests
                                  / main1.o tests
                                  / test.o src
                                  / main.o src
                                  / console.o src
                                  / search.o src
                                  / writting.o g++
        - o tests / testing tests / main1.o tests / test.o src / console.o src
                / search.o src
                / writting.o

                          main1.o
    : tests / main1.cpp g++
        - Wall - Wextra - c test / main1.cpp
        - MMD

                        test.o
    : tests / test.cpp g++
        - Wall - Wextra - c tests / test.cpp
        - MMD

                clean : rm app src/*.o src/*.d -f
	rm tests/app tests/*.o tests/*.d tests/testing -f
	
run: testing
	./tests/testing
	
runap: app
	./app
	
start:
	make
	make run
	make runap
	
start1:
	make clean
	make
	make run
	make runap
	

