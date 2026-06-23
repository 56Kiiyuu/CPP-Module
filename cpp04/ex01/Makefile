NAME = animal
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CPP = c++
SRCS = Animal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
