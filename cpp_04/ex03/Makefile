.DEFAULT_GOAL := all
CPP := c++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP # -fsanitize=address -g
NAME := a.out
SRCS := main.cpp	\
		AMateria.cpp	\
		Character.cpp	\
		Cure.cpp	\
		Ice.cpp		\
		MateriaSource.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(DEPS)

fclean :
	rm  -rf $(OBJS) $(DEPS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
