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
MIXEREXCEPTIONDIR := $(SRCCOREDIR)/Exception/MixerException
EVENTLISTENERDIR := $(SRCCOREDIR)/EventListener
RESOURCESMANAGERDIR := $(SRCCOREDIR)/ResourcesManager
FONTMANAGERDIR := $(RESOURCESMANAGERDIR)/Managers/FontManager
IMAGEMANAGERDIR := $(RESOURCESMANAGERDIR)/Managers/ImageManager
SOUNDMANAGERDIR := $(RESOURCESMANAGERDIR)/Managers/SoundManager
MUSICMANAGERDIR := $(RESOURCESMANAGERDIR)/Managers/MusicManager
FONTDIR := $(RESOURCESMANAGERDIR)/Resources/Font
IMAGEDIR := $(RESOURCESMANAGERDIR)/Resources/Image
SOUNDDIR := $(RESOURCESMANAGERDIR)/Resources/Sound
MUSICDIR := $(RESOURCESMANAGERDIR)/Resources/Music

.PHONY: all
all: core application main createExecutable

application: $(OBJDIR)/Application.o

core: utils logger exceptions settings eventlistener resourcesmanager

exceptions: genericexception sdlexception ttfexception mixerexception

utils: $(OBJDIR)/Utils.o

logger: $(OBJDIR)/Logger.o

settings: $(OBJDIR)/SettingsCreator.o

resourcesmanager: font image sound music $(OBJDIR)/ResourcesManager.o fontmanager imagemanager soundmanager musicmanager

font: $(OBJDIR)/Font.o

image: $(OBJDIR)/Image.o

sound: $(OBJDIR)/Sound.o

music: $(OBJDIR)/Music.o

fontmanager: $(OBJDIR)/FontManager.o

imagemanager: $(OBJDIR)/ImageManager.o

soundmanager: $(OBJDIR)/SoundManager.o

musicmanager: $(OBJDIR)/MusicManager.o

eventlistener: $(OBJDIR)/EventListener.o

genericexception: $(OBJDIR)/GenericException.o

sdlexception: $(OBJDIR)/SDLException.o

ttfexception: $(OBJDIR)/TTFException.o

mixerexception: $(OBJDIR)/MixerException.o

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

$(OBJDIR)/MixerException.o: $(MIXEREXCEPTIONDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/EventListener.o: $(EVENTLISTENERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/ResourcesManager.o: $(RESOURCESMANAGERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Font.o: $(FONTDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/Image.o: $(IMAGEDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Sound.o: $(SOUNDDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Music.o: $(MUSICDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/FontManager.o: $(FONTMANAGERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(OBJDIR)/ImageManager.o: $(IMAGEMANAGERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/SoundManager.o: $(SOUNDMANAGERDIR)/*.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/MusicManager.o: $(MUSICMANAGERDIR)/*.cpp
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
