NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HDDIRS = lemin.h

SRC = main.c read_from_stdin.c grab_number_of_ants.c add_room.c add_room2.c add_link.c set_distance_from_start.c set_distance_from_end.c solve.c sort_end_links.c check_room_formatting.c check_path_exists.c set_new_distance.c push_all_remaining.c blocker_cascade_check.c blocker_cascade_check2.c blocker_cascade_check3.c blocker_cascade_check4.c check_room_formatting2.c push_all_remaining2.c read_from_stdin2.c set_new_distance2.c solve2.c solve3.c

LIB = Libft_Final/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C Libft_Final/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
