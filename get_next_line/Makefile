# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:11:21 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/05/30 19:38:19 by ncruz-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

OBJS = get_next_line.o get_next_line_utils.o

OBJS_BONUS = get_next_line_bonus.o get_next_line_utils_bonus.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

MAIN_OBJS = TESTS/main.o

EXEC = TESTS/main

$(EXEC): $(MAIN_OBJS) $(NAME)
	$(CC) $(CFLAGS) -g -Wno-format -Wno-format-overflow $(MAIN_OBJS) $(NAME) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	-rm -f $(OBJS) $(MAIN_OBJS)

fclean: clean
	-rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re run