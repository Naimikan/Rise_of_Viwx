CC := g++
CFLAGS := -c -Wall
LDFLAGS := -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image

OBJDIR := Obj
DISTDIR := Distribution
SRCDIR := Source
LOGDIR := Logs
PROJECTNAME := RiseOfViwx

APPLICATIONDIR := $(SRCDIR)/Application
UTILSDIR := $(SRCDIR)/Core/Utils
LOGGERDIR := $(SRCDIR)/Core/Logger
SETTINGSCREATORDIR := $(SRCDIR)/Core/SettingsCreator

.PHONY: all
all: core application main createExecutable

application: $(OBJDIR)/Application.o

core: utils logger settings

utils: $(OBJDIR)/Utils.o

logger: $(OBJDIR)/Logger.o

settings: $(OBJDIR)/SettingsCreator.o

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

.PHONY: install
install:
	@echo "install"

.PHONY: clean
clean:
	rm $(DISTDIR) *~ -rf
	rm $(OBJDIR) *~ -rf
	rm $(LOGDIR) *~ -rf
