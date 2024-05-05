NAME = fractol
CC = cc
CFLAGS = -Wextra -Wall -Werror
MLX = -lmlx -lXext -lX11 -O3
RM = rm -f
SRC = color_inp.c event_hooks.c fractol_utils.c fractol.c \

OSRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
		$(CC) $(CFLAGS) $(OSRC) $(MLX) -o $@

clean:
	$(RM) $(OSRC)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
