CC = em++
LINK = -s USE_SDL=2#-lstdc++ -lSDL2 -lm -ldl #-lSDL_gfx
DBG = -g -s LLD_REPORT_UNDEFINED#-Wall -g -gmodules -O0
CC += $(DBG)

all: build ;

#goals = bin/main.o bin/Color.o bin/Quad.o bin/Vector.o bin/phys_obj.o bin/BoundingBox.o bin/Circle.o

goals = bin/main.wasm bin/Color.wasm bin/Quad.wasm bin/Vector.wasm bin/phys_obj.wasm bin/BoundingBox.wasm bin/Circle.wasm

define pro =
$(CC) $^ -o $@
endef

bin/main.wasm: src/main.cpp
	$(pro)
bin/BoundingBox.wasm: src/BoundingBox.cpp
	$(pro)
bin/Color.wasm: src/Color.cpp
	$(pro)
bin/Quad.wasm: src/Quad.cpp
	$(pro)
bin/Vector.wasm: src/Vector.cpp
	$(pro)
bin/phys_obj.wasm: src/phys_obj.cpp
	$(pro)
bin/Circle.wasm: src/Circle.cpp
	$(pro)

#targets = $(patsubst bin/%.o,src/%.cpp,$(goals))
#$(goals): $(targets) ;
#	$(foreach goal,$(goals),$( \
#		$(CC) $(patsubst bin/%.o, src/%.cpp, $(goal)) \
#		echo $(goal) \
#	))

build: $(goals) ;
	$(CC) $(goals) -o ./bin/simulator.html $(LINK)

#bin/%.o : src/%.cpp ;


.PHONY: clean
clean:
	rm -rf ./bin/*

.PHONY: run
run: build ;
	./bin/simulator
