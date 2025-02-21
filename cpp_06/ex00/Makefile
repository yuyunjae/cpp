.DEFAULT_GOAL := all
CPP := c++
CPPFLAG := -std=c++98 -Wall -Wextra -Werror -MMD -MP
NAME := convert
SRCS := ScalarConverter.cpp 	\
		main.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAG) $(OBJS) -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAG) -c $< -o $@

clean :
	rm -rf $(OBJS) $(DEPS)

fclean :
	rm  -rf $(OBJS) $(DEPS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
