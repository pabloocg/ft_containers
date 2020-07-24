#--------------------Files-----------------------------#

SRCS =	main.cpp

NAME = ft_containers

#--------------------Comands---------------------------#

GCC = clang++

FLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.cpp=.o}

RM = rm -f

#---------------------Orders---------------------------#

.cpp.o:
			${GCC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			${GCC} ${FLAGS} ${OBJS} -o ${NAME}

test all:	$(NAME)
			list stack queue vector map

list:		$(NAME)
			./${NAME} list_test > FT_LIST.TXT
			./${NAME} list_sys > STD_LIST.TXT

stack:		$(NAME)
			./${NAME} stack_test > FT_STACK.TXT
			./${NAME} stack_sys > STD_STACK.TXT

queue:		$(NAME)
			./${NAME} queue_test > FT_QUEUE.TXT
			./${NAME} queue_sys > STD_QUEUE.TXT

vector:		$(NAME)
			./${NAME} vector_test > FT_VECTOR.TXT
			./${NAME} vector_sys > STD_VECTOR.TXT

map:		$(NAME)
			./${NAME} map_test > FT_MAP.TXT
			./${NAME} map_sys > STD_MAP.TXT

txt:
			rm *.TXT

all:		$(NAME)

re:			fclean all


clean:
			${RM} ${OBJS}

fclean:
			${RM} ${NAME}