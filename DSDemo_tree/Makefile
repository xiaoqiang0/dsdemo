CC=g++
CFLAGS+=-g
CPPFLAGS+=-g
files=BiTree.cpp BSTree.cpp test_BiTree.cpp
obj=$(patsubst %.c,%.o,$(files))
Target=test_BiTree
all: $(Target)

test_BiTree:$(files)
	$(CC) -lm $(CFLAGFS) -g -o $@ $^  -lm
clean:
	rm -f $(obj) $(Target) *.o
