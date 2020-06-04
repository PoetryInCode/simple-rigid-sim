CC = clang
LINK = -lstdc++ -lSDL2 -lm -ldl -lSDL_gfx
DBG = -Wall -g -gmodules -O0
CC += $(DBG)

all: build ;

goals = bin/main.o bin/Color.o bin/Quad.o bin/Vector.o bin/phys_obj.o bin/BoundingBox.o bin/Circle.o

define pro =
$(CC) -c $^ -o $@
endef

bin/main.o: src/main.cpp
	$(pro)
bin/BoundingBox.o: src/BoundingBox.cpp
	$(pro)
bin/Color.o: src/Color.cpp
	$(pro)
bin/Quad.o: src/Quad.cpp
	$(pro)
bin/Vector.o: src/Vector.cpp
	$(pro)
bin/phys_obj.o: src/phys_obj.cpp
	$(pro)
bin/Circle.o: src/Circle.cpp
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
