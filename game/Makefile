OBJS=game.o
CXXFLAGS=-I../common -std=c++11 -g
OUTPUT=game

all:$(OBJS)
	g++ -o $(OUTPUT) $(OBJS)

modules:
	cd ../server; make
	cd ../client; make

%o:%cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OUTPUT)
