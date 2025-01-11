.DEFAULT_GOAL := all
CPP := c++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP
NAME := scavTrap
SRCS := main.cpp \
		ClapTrap.cpp	\
		ScavTrap.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

-include $(DEPS)

all :
	@make $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(DEPS)

fclean :
	rm -rf $(OBJS) $(DEPS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
