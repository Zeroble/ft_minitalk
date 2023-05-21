SERVER_OBJ =	server.o

CLIENT_OBJ =	client.o \
				atoi.o

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIENT_NAME = client
SERVER_NAME = server

all : ${SERVER_NAME} ${CLIENT_NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

# %.o : %.c
# 	${CC} -c $? -o $@

$(CLIENT_NAME) : ${CLIENT_OBJ}
	${CC} $? -o ${CLIENT_NAME}

$(SERVER_NAME) : ${SERVER_OBJ}
	${CC} $? -o ${SERVER_NAME}

clean :
	rm -f ${SERVER_OBJ}
	rm -f ${CLIENT_OBJ}

fclean : clean
	rm -f ${SERVER_NAME}
	rm -f ${CLIENT_NAME}

re : fclean all
