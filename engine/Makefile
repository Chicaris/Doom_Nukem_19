# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-moff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 18:53:21 by hde-moff          #+#    #+#              #
#    Updated: 2019/11/20 10:42:28 by cbruno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

UNAME_S := $(shell uname -s)
OS = MAC
ifeq ($(UNAME_S), Linux)
    OS = LINUX
endif
$(info OS is $(OS))

CFLAGS = -Wall -Wextra -Werror -O3
INCLUDES = -I ../includes/libft
LFLAGS = ../includes/libft/libft.a -lpthread -lSDL2_ttf -lSDL2_mixer

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

SRC = src/main.c src/View/sdl_init.c src/View/graphic.c src/Controller/key.c src/Controller/key1.c
SRC += src/Model/print.c src/View/paint.c src/Model/world.c src/Model/camera.c src/Model/Utils/matrix.c
SRC += src/Model/Utils/rotate_camera.c src/Model/line.c src/Model/projection.c
SRC += src/Model/Utils/clip.c src/Controller/mouse.c src/Controller/mouse1.c src/Model/walls.c src/Model/walls2.c
SRC += src/Model/textures.c src/Model/Utils/math00.c
SRC += src/Model/Utils/math01.c src/View/fdf.c src/Model/Utils/floor_casting.c
SRC += src/Model/Utils/collision.c src/Model/monster.c src/Model/monster2.c src/Model/fire.c
SRC += src/Model/Utils/ray_monster.c src/Model/flag.c
SRC += src/Model/player.c src/Model/player2.c src/Model/player3.c src/View/hudd.c src/View/hud2.c src/View/hud3.c src/View/hud4.c src/View/font.c src/Model/pickup.c src/Model/pickup2.c
SRC += src/Model/free.c src/Model/free1.c src/Model/sound.c
SRC += src/Model/Utils/raycasting.c src/Model/Utils/raycasting1.c src/Model/Utils/raycasting2.c src/Model/Utils/raycasting3.c src/Model/Utils/raycasting4.c
SRC += src/Model/Utils/get_sector.c src/Model/Utils/get_sector1.c
SRC += src/Model/Utils/ray_pickup.c src/Model/Utils/ray_pickup1.c
SRC += src/Model/Utils/move.c src/Model/Utils/move1.c src/Model/Utils/move2.c
SRC += src/Model/parser.c src/Model/parser1.c src/Model/parser2.c src/Model/parser3.c

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

$(BREW_FT) :
			brew -v install freetype
$(BREW_TTF) :
			brew -v install sdl2_ttf
$(BREW_IMG) :
			brew -v install sdl2_image


clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

norminette:
	norminette src
	norminette include

bin/%.o:%.c
	@mkdir -p bin
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

.PHONY: all doom-nukem re fclean clean SDL SDL_clean
