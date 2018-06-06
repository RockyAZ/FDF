
all:
	cc -I /Users/azaporoz/fdf/minilibx/ main.c reader.c preparation.c error.c drawer.c action.c matrix.c keys.c mouse.c ../../fdf/libft/libft.a -L /Users/azaporoz/fdf/minilibx/ -lmlx -framework OpenGL -framework AppKit -o fdf