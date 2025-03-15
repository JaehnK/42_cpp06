C++ = c++
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS =	main.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
		Base.cpp \

HEADR =	A.hpp \
		B.hpp \
		C.hpp \
		Base.hpp \


OBJS = $(SRCS:.cpp=.o)

NAME = identify

all: $(NAME)

$(NAME):$(OBJS)
		$(C++) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
		$(C++) $(CPP_FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:
		make clean
		rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
 