CC=g++
CFLAGS+=-g
dirs := .
files := MGraph.cpp ALGraph.cpp graph.h
obj=test_MGraph test_ALGraph
all: $(obj)

test_MGraph: test_MGraph.cpp MGraph.cpp ALGraph.cpp graph.h 
	$(CC) $(CFLAGS) -o $@ $^

test_ALGraph: test_ALGraph.cpp MGraph.cpp ALGraph.cpp graph.h 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(obj) *.~bpr *.obj *.cbproj.local *.exe *.map *.res *.tds *.~bpr *Debug* *.obj *Debug_Build* *__history*
