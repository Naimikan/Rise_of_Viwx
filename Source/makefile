CC := g++
CFLAGS := -c -Wall

OBJDIR := ../obj
DISTDIR := ../Distribution

all: compileMain

compileMain: $(OBJDIR)/main.o
	@mkdir -p $(DISTDIR)
	$(CC) $(OBJDIR)/main.o -o $(DISTDIR)/RiseOfViwx
	
$(OBJDIR)/main.o: main.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(OBJDIR) *~ -rf
