CC=g++

SRC=src
INCLUDE=include
LIBSDL=SDL-1.2.15
SDL_CONFIG=$(LIBSDL)/build/include
SDL_INCLUDE=$(LIBSDL)/include
SDL_GFX=SDL_gfx-2.0.25
TINY_INCLUDE=tinyxml2
OBJ=obj
BIN=bin

WARNINGS=-Wall -Wextra -pedantic
CPP_VERSION=-std=c++11
LINKED_LIBS= -lm\
             -Iinclude/ \
             -I$(SDL_INCLUDE)/ -L$(SDL_INCLUDE)/\
             -I$(SDL_GFX) -L$(SDL_GFX)/build -lSDL_gfx \
             -I$(TINY_INCLUDE)/ -L$(TINY_INCLUDE)/\
             -lSDL -I$(SDL_CONFIG) -L$(SDL_CONFIG) -ISDL_image-1.2.12/ -LSDL_image-1.2.12/build -lSDL_image -lSDLmain
OPTIMIZATIONS=-g

OUT_NAME=AIS_ILF7.out

OBJECTS_ROOT=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(wildcard $(SRC)/*.cpp)) $(TINY_INCLUDE)/tinyxml2.o
OBJECTS_ENGINE=

all: $(OUT_NAME)

$(OUT_NAME) : $(OBJECTS_ROOT)
	$(CC) -o $@ $^ $(LINKED_LIBS) $(CPP_VERSION) $(WARNINGS) $(OPTIMIZATIONS)

$(OBJ)/GameInitializer.o : $(INCLUDE)/GameInitializer.hpp
$(OBJ)/XmlLoader.o : $(INCLUDE)/XmlLoader.hpp
$(OBJ)/Arguments.o : $(INCLUDE)/Arguments.hpp
$(OBJ)/SDLLoader.o : $(INCLUDE)/SDLLoader.hpp
$(OBJ)/Backgrounds.o : $(INCLUDE)/Backgrounds.hpp
$(OBJ)/Sounds.o : $(INCLUDE)/Sounds.hpp
$(OBJ)/Sprites.o : $(INCLUDE)/Sprites.hpp
$(OBJ)/Objects.o : $(INCLUDE)/Objects.hpp
$(OBJ)/Object.o : $(INCLUDE)/Object.hpp
$(OBJ)/ImageLoader.o : $(INCLUDE)/ImageLoader.hpp
$(OBJ)/NameResolver.o : $(INCLUDE)/NameResolver.hpp
$(OBJ)/GameEngine.o : $(INCLUDE)/GameEngine.hpp
$(OBJ)/StateStack.o : $(INCLUDE)/StateStack.hpp
$(OBJ)/Rooms.o : $(INCLUDE)/Rooms.hpp
$(OBJ)/Player.o : $(INCLUDE)/Player.hpp
$(OBJ)/Options.o : $(INCLUDE)/Options.hpp
$(OBJ)/BasicCannon.o : $(INCLUDE)/BasicCannon.hpp
$(OBJ)/Cannons.o : $(INCLUDE)/Cannons.hpp
$(OBJ)/Drawer.o : $(INCLUDE)/Drawer.hpp
$(OBJ)/BulletContainer.o : $(INCLUDE)/BulletContainer.hpp
$(OBJ)/InputEventManager.o : $(INCLUDE)/InputEventManager.hpp
$(OBJ)/Room.o : $(INCLUDE)/Room.hpp
$(OBJ)/BattleRoom.o : $(INCLUDE)/BattleRoom.hpp

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $(CPP_VERSION) -o $@ -c $< $(WARNINGS) $(LINKED_LIBS) $(OPTIMIZATIONS)

clean:
	rm -f $(OBJ)/*.o $(OUT_NAME)

install:
	cd SDL-1.2.15 && mkdir build && cd build && ../configure && make
	cd SDL_image-1.2.12 && mkdir build && cd build && ../configure && make
	cd SDL_gfx-2.0.25 && mkdir build && cd build && ../configure && make
