FLAGS = -pedantic-errors -std=c++11

game: main.o room.o tony.o
	g++ $(FLAGS) $^ -o $@

room.o: room.cpp room.h
	g++ $(FLAGS) -c $<

tony.o: tony.cpp tony.h
	g++ $(FLAGS) -c $<

main.o: main.cpp
	g++ $(FLAGS) -c $<

clean:
	rm -f game main.o room.o tony.o 

.PHONY: clean
