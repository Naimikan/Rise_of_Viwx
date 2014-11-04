CC := g++
CFLAGS := -c -Wall
LDFLAGS := -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image

OBJDIR := Obj
DISTDIR := Distribution
SRCDIR := Source
SRCCOREDIR := $(SRCDIR)/Core
LOGDIR := Logs
PROJECTNAME := RiseOfViwx

APPLICATIONDIR := $(SRCDIR)/Application
UTILSDIR := $(SRCCOREDIR)/Utils
LOGGERDIR := $(SRCCOREDIR)/Logger
SETTINGSCREATORDIR := $(SRCCOREDIR)/SettingsCreator
GENERICEXCEPTIONDIR := $(SRCCOREDIR)/Exception
SDLEXCEPTIONDIR := $(SRCCOREDIR)/Exception/SDLException
TTFEXCEPTIONDIR := $(SRCCOREDIR)/Exception/TTFException

.PHONY: all
all: core application main createExecutable

application: $(OBJDIR)/Application.o

core: utils logger exceptions settings

exceptions: genericexception sdlexception ttfexception

utils: $(OBJDIR)/Utils.o

logger: $(OBJDIR)/Logger.o

settings: $(OBJDIR)/SettingsCreator.o

genericexception: $(OBJDIR)/GenericException.o

sdlexception: $(OBJDIR)/SDLException.o

ttfexception: $(OBJDIR)/TTFException.o

main: $(OBJDIR)/main.o

createExecutable:
	@mkdir -p $(DISTDIR)
	$(CC) $(OBJDIR)/*.o -o $(DISTDIR)/$(PROJECTNAME) $(LDFLAGS)
	
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Application.o: $(APPLICATIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/Utils.o: $(UTILSDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/Logger.o: $(LOGGERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	@mkdir -p $(LOGDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/SettingsCreator.o: $(SETTINGSCREATORDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/GenericException.o: $(GENERICEXCEPTIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/SDLException.o: $(SDLEXCEPTIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/TTFException.o: $(TTFEXCEPTIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: install
install:
	@echo "install"

.PHONY: clean
clean:
	rm $(DISTDIR) *~ -rf
	rm $(OBJDIR) *~ -rf
	rm $(LOGDIR) *~ -rf
