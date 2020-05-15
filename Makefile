CC = clang
LINK = -lstdc++ -lSDL2 -lOpenGL -lGLEW -lGLU
DBG = -Wall
CC += $(DBG)

all: build ;

goals = bin/main.o bin/Cube.o bin/Color.o bin/Quad.o bin/Vertex.o

define pro =
$(CC) -c $^ -o $@
endef

bin/main.o: src/main.cpp
	$(pro)
bin/Cube.o: src/Cube.cpp
	$(pro)
bin/Color.o: src/Color.cpp
	$(pro)
bin/Quad.o: src/Quad.cpp
	$(pro)
bin/Vertex.o: src/Vertex.cpp
	$(pro)
#targets = $(patsubst bin/%.o,src/%.cpp,$(goals))
#$(goals): $(targets) ;
#	$(foreach goal,$(goals),$( \
#		$(CC) $(patsubst bin/%.o, src/%.cpp, $(goal)) \
#		echo $(goal) \
#	))

build: $(goals) ;
	$(CC) $(goals) -o ./bin/simulator $(LINK)

#bin/%.o : src/%.cpp ;
	

.PHONY: clean
clean:
	rm -rf ./bin/*

.PHONY: run
run: build ;
	./bin/simulator