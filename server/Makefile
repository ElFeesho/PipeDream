OBJS=server.o
CXXFLAGS=-I../common -std=c++11
OUTPUT=server.lib

all:$(OBJS)
	g++ -o $(OUTPUT) -dynamiclib -undefined suppress -flat_namespace $(OBJS)

%o:%cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OUTPUT)
