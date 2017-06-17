NAME = ft_retro

SRC = Boss.cpp EnemyB.cpp EnemyC.cpp Missile.cpp Enemy.cpp Entity.cpp Player.cpp main.cpp Window.cpp Wave.cpp

SRCO = $(SRC:.cpp=.o)

CC = c++ -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC) game.hpp
	@echo "Compiling $(NAME)."
	@$(CC) -c $(SRC)
	@$(CC) -lncurses $(SRCO) -o $(NAME)
	@/bin/rm -rf obj/
	@mkdir obj/
	@mv $(SRCO) obj/

clean:
	@echo "Deleting $(NAME) sources."
	@/bin/rm -rf obj/

fclean: clean
	@echo "Deleting $(NAME)."
	@/bin/rm -f $(NAME)

re: clean fclean all
