OBJS=game.o
CXXFLAGS=-I../common -std=c++11 -g
OUTPUT=game

all:$(OBJS)
	g++ -o $(OUTPUT) $(OBJS)

%o:%cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OUTPUT)
