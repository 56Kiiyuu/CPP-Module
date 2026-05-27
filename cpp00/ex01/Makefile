NAME = phonebook
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CPP = c++
SRCS = *.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
