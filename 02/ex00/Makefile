NAME = a.out

FILE = main.cpp Fixed.cpp
CC = c++ -Wall -Werror -Wextra -std=c++98

OBJ = ${FILE:.cpp=.o}

all: ${NAME}

%.o: %.cpp
	@${CC} -c $< -o $@

${NAME}:	${OBJ}
	@${CC} ${OBJ} -o ${NAME}

clean: 
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

re: fclean all