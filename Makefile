
all:
	gcc -Wall -Wextra -Werror -I /Users/azaporoz/fdf/minilibx/ main.c reader.c preparation.c error.c helper.c drawer.c action.c keys.c mouse.c matrix_caller.c ../../fdf/libft/libft.a -L /Users/azaporoz/fdf/minilibx/ -lmlx -framework OpenGL -framework AppKit -o fdf