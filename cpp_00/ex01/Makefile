NAME = megaphone
CC = g++
FLAGS = -std=c++98 -Wall -Wextra -Werror # test시에는 c++14같은거로 해야할듯?
SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@	

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : clean fclean all re