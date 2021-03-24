#--------------------Files-----------------------------#

SRCS =	main.cpp

NAME = ft_containers

#--------------------Comands---------------------------#

GCC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = ${SRCS:.cpp=.o}

RM = rm -f

#---------------------Orders---------------------------#

.cpp.o:
			${GCC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			${GCC} ${FLAGS} ${OBJS} -o ${NAME}

testall:	list stack queue vector map multimap set multiset

list:		$(NAME)
			./${NAME} list_test > FT_LIST.TXT
			./${NAME} list_sys > STD_LIST.TXT
			diff FT_LIST.TXT STD_LIST.TXT

stack:		$(NAME)
			./${NAME} stack_test > FT_STACK.TXT
			./${NAME} stack_sys > STD_STACK.TXT
			diff FT_STACK.TXT STD_STACK.TXT

queue:		$(NAME)
			./${NAME} queue_test > FT_QUEUE.TXT
			./${NAME} queue_sys > STD_QUEUE.TXT
			diff FT_QUEUE.TXT STD_QUEUE.TXT

vector:		$(NAME)
			./${NAME} vector_test > FT_VECTOR.TXT
			./${NAME} vector_sys > STD_VECTOR.TXT
			diff FT_VECTOR.TXT STD_VECTOR.TXT

map:		$(NAME)
			./${NAME} map_test > FT_MAP.TXT
			./${NAME} map_sys > STD_MAP.TXT
			diff FT_MAP.TXT STD_MAP.TXT

multimap:	$(NAME)
			./${NAME} multimap_test > FT_MULTIMAP.TXT
			./${NAME} multimap_sys > STD_MULTIMAP.TXT
			diff FT_MULTIMAP.TXT STD_MULTIMAP.TXT

set:		$(NAME)
			./${NAME} set_test > FT_SET.TXT
			./${NAME} set_sys > STD_SET.TXT
			diff FT_SET.TXT STD_SET.TXT

multiset:	$(NAME)
			./${NAME} multiset_test > FT_MULTISET.TXT
			./${NAME} multiset_sys > STD_MULTISET.TXT
			diff FT_MULTISET.TXT STD_MULTISET.TXT


all:		$(NAME)

re:			fclean all


clean:
			${RM} ${OBJS} *.TXT

fclean:
			${RM} ${NAME}