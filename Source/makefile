CC := g++
CFLAGS := -c -Wall

OBJDIR := ../obj
DISTDIR := ../Distribution

APPLICATIONDIR := Application
UTILSDIR := Core/Utils

all: compileUtils compileApplication compileMain createExecutable

compileApplication: $(OBJDIR)/Application.o

compileUtils: $(OBJDIR)/Utils.o

compileMain: $(OBJDIR)/main.o
	
createExecutable:
	@mkdir -p $(DISTDIR)
	$(CC) $(OBJDIR)/*.o -o $(DISTDIR)/RiseOfViwx
	
$(OBJDIR)/main.o: main.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Application.o: $(APPLICATIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/Utils.o: $(UTILSDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(DISTDIR) *~ -rf
	rm $(OBJDIR) *~ -rf
