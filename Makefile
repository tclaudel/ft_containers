NAME			= containers
HEADER			= Allocator/Allocator.hpp main.hpp
SRCS_PATH 		= ./
SRCS_NAME		= main.cpp
OBJ_PATH		= obj/
OBJ_NAME		= ${SRCS_NAME:.c=.o}
OBJ				= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
FLAGS			= -Wall -Werror -Wextra -g3 -O3 -fsanitize=address
RM				= rm -rf

all: $(NAME) $(HEADER)
	@:

$(NAME): Makefile main.cpp $(HEADER)
	@g++ $(FLAGS) main.cpp -o $(NAME)
	@printf "\033[2K\r$(DARK_BLUE)$(NAME) : $(LIGHT_GREEN)Updated\n\033[0m"

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

