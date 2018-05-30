#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 13:28:25 by azaporoz          #+#    #+#              #
#    Updated: 2018/05/23 12:06:26 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

all:
	cc -I /Users/azaporoz/fdf/minilibx/ main.c reader.c drawer.c clean_img.c ../libft/libft.a -L /Users/azaporoz/fdf/minilibx/ -lmlx -framework OpenGL -framework AppKit -o fdf
	@echo "\033[36m-----> (¬_¬) (ಠ_ಠ) <-----"

#	@echo "\[033[36m\]-----> (¬_¬) (ಠ_ಠ) <-----"
#	Black="\[\033[0;30m\]"
clean:
	rm -rf *~
	