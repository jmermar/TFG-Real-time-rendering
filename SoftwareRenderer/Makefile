LINK := -lmingw32 -lSDL2main -lSDL2 -fopenmp
ARGS := -std=c++11 -fopenmp -pthread -O2
INCLUDE := -I ../include -I include
BIN=../rasterizer.exe

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

$(BIN): $(OBJ)
	g++ $(OBJ) $(ARGS) $(LINK)  -o $@ 

src/%.o: src/%.cpp
	g++ -c $< $(INCLUDE) $(ARGS) -o $@

clean:
	rm src/*.o $(BIN)