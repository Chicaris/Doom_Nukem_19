# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbruno <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:23:57 by cbruno            #+#    #+#              #
#    Updated: 2019/11/18 15:48:32 by cbruno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = duked

UNAME_S := $(shell uname -s)
OS = MAC
ifeq ($(UNAME_S), Linux)
	OS = LINUX
endif
$(info OS is $(OS))

CFLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = -I ../includes/libft
LFLAGS = ../includes/libft/libft.a -lpthread -lSDL2_mixer -lSDL2_ttf

ifeq ($(OS), MAC)
	LFLAGS += `~/.brew/bin/sdl2-config --cflags --libs`
	LFLAGS += -framework CoreAudio -framework AudioToolbox -framework CoreFoundation
	CFLAGS += -DAUDIO
	INCLUDES += `~/.brew/bin/sdl2-config --cflags`
	BREW = ~/.brew
endif
ifeq ($(OS), LINUX)
	LFLAGS += `/home/linuxbrew/.linuxbrew/bin/sdl2-config --cflags --libs`
	LFLAGS += -lm
	INCLUDES += `/home/linuxbrew/.linuxbrew/bin/sdl2-config --cflags`
	BREW = /home/linuxbrew/.linuxbrew
endif

LIBFT_PATH = ../includes/libft

SRC = src/main.c src/Controller/key.c src/View/graphic.c src/View/sdl.c
SRC += src/View/grid.c src/Model/move.c
SRC += src/Model/select.c src/Model/player.c
SRC += src/View/font.c src/View/menu_wall.c src/View/menu_sector.c
SRC += src/View/menu_player.c src/View/menu_monster.c src/Model/flag.c
SRC += src/Controller/mouse00.c src/Controller/mouse01.c
SRC += src/View/draw00.c src/View/draw01.c src/View/draw02.c src/View/draw03.c
SRC += src/View/print00.c src/View/print01.c src/View/print02.c src/View/print03.c
SRC += src/Model/monster00.c src/Model/monster01.c
SRC += src/Model/read00.c src/Model/read01.c
SRC += src/Model/sector00.c src/Model/sector01.c src/Model/sector02.c
SRC += src/Model/texture00.c src/Model/texture01.c
SRC += src/Model/wall00.c src/Model/wall01.c src/Model/wall02.c
SRC += src/Model/write00.c src/Model/write01.c src/Model/write02.c
SRC += src/Model/Utils/math00.c src/Model/Utils/math01.c src/Model/Utils/math02.c src/Model/Utils/math03.c
SRC += src/View/menu_objet.c src/Model/pickup.c
SRC += src/Model/audio.c src/Model/free.c src/Controller/key1.c src/Model/free1.c
SRC += src/Controller/mouse03.c src/Model/pickup01.c src/View/menu_objet01.c
SRC += src/Model/write03.c src/View/menu_wall01.c src/View/menu_sector01.c

BREW_SDL = $(BREW)/Cellar/sdl2
BREW_MIX = $(BREW)/Cellar/sdl2_mixer

OBJ = $(addprefix bin/, $(patsubst %.c, %.o, $(SRC)))

all: $(BREW) $(BREW_SDL) $(BREW_MIX) $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	gcc -o $@ $(OBJ) $(LFLAGS)

$(BREW):
	$(shell /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)")
	$(BREW)/bin/brew upgrade
	$(BREW)/bin/brew -v install pkg-config

$(BREW_SDL):
	$(BREW)/bin/brew -v install sdl2

$(BREW_MIX):
	$(BREW)/bin/brew -v install sdl2_mixer

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

norminette:
	norminette src/
	norminette include/

SDL:
	make -C ../ SDL

SDL_clean:
	make -C ../ SDL_clean

bin/%.o : %.c
	@mkdir -p bin
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: all doomED re fclean clean SDL SDL_clean
