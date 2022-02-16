# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 18:32:46 by mjodge            #+#    #+#              #
#    Updated: 2022/02/02 18:12:10 by mjodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = check_input.c creat_threads.c get_time.c init.c life_cycle_philo.c main.c utils.c
SRC_BONUS = check_input_bonus.c get_time_bonus.c init_bonus.c life_cycle_philo_bonus.c main_bonus.c utils_bonus.c life_cycle_utils_bonus.c

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) philo.h
	$(CC) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) 
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all