.PHONY: all

OBJ_DIR = obj

all: main testing

main: $(OBJ_DIR)/main.o $(OBJ_DIR)/libmain.a
	g++ -o src/appp $(OBJ_DIR)/main.o $(OBJ_DIR)/libmain.a

$(OBJ_DIR)/libmain.a: $(OBJ_DIR)/console.o $(OBJ_DIR)/search.o $(OBJ_DIR)/writting.o
	mkdir -p $(OBJ_DIR)
	ar rcs $(OBJ_DIR)/libmain.a $(OBJ_DIR)/console.o $(OBJ_DIR)/search.o $(OBJ_DIR)/writting.o

$(OBJ_DIR)/main.o: src/app/main.cpp
	mkdir -p $(OBJ_DIR)
	g++ -c -Wall -Wextra -o $(OBJ_DIR)/main.o  src/app/main.cpp -MMD -w -I src
	
$(OBJ_DIR)/console.o: src/app/console.cpp
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra  -o $(OBJ_DIR)/console.o -c src/app/console.cpp -MMD -w -I src

$(OBJ_DIR)/search.o: src/app/search.cpp
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra  -o $(OBJ_DIR)/search.o -c src/app/search.cpp -MMD -w -I src

$(OBJ_DIR)/writting.o: src/app/writting.cpp
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra  -o $(OBJ_DIR)/writting.o -c src/app/writting.cpp -MMD -w -I src
	
testing: $(OBJ_DIR)/main1.o $(OBJ_DIR)/test.o $(OBJ_DIR)/libmain.a
	g++ -o tests/testing $(OBJ_DIR)/main1.o $(OBJ_DIR)/test.o $(OBJ_DIR)/libmain.a

$(OBJ_DIR)/main1.o: tests/main.cpp
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra -o $(OBJ_DIR)/main1.o -c tests/main.cpp -MMD -w -I src
	
$(OBJ_DIR)/test.o: tests/test.cpp
	mkdir -p $(OBJ_DIR)
	g++ -Wall -Wextra -o $(OBJ_DIR)/test.o -c tests/test.cpp -MMD -w -I src
	
clean:
	rm src/appp $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(OBJ_DIR)/*.a -f
	rm tests/appp $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d tests/testing -f

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


