.DEFAULT_GOAL := all
CPP := c++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror -MMD -MP
# CPPFLAGS := -std=c++14 -Wall -Wextra -Werror -MMD -MP
NAME := IdentifyType
SRCS :=	Base.cpp 	\
		A.cpp	\
		B.cpp	\
		C.cpp	\
		main.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(DEPS) $(OBJS)

fclean :
	rm -rf $(DEPS) $(OBJS) $(NAME)

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re
 