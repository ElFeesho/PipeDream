OBJS=game.o
CXXFLAGS=-I../common
OUTPUT=game

all:$(OBJS)
	g++ -o $(OUTPUT) $(OBJS)

%o:%cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OUTPUT)
