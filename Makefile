FILES = $(wildcard src/*.cpp src/*/*.cpp)

all: build

force:

$(FILES): force
	mkdir -p obj
	g++ -c -g -o obj/$(subst /,_,$(subst .cpp,.o,$@)) $@

debug: $(FILES)
	g++ obj/*.o -o Punch -lsfml-graphics -lsfml-window -lsfml-system

release: $(FILES)
	g++ obj/*.o -Ofast -s -o Punch -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf obj
	rm -f */*.o
