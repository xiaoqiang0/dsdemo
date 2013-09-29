CC=g++
CFLAGS+=-g
dirs := .
files := MGraph.cpp ALGraph.cpp graph.h test_MGraph.cpp test_ALGraph.cpp
obj=test_MGraph test_ALGraph
all: $(obj)

test_MGraph: test_MGraph.cpp MGraph.cpp ALGraph.cpp graph.h 
	$(CC) $(CFLAGS) -o $@ $^

test_ALGraph: test_ALGraph.cpp MGraph.cpp ALGraph.cpp graph.h 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(obj)
graph:graph.h
graph2:graph.h
