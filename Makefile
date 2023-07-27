SERVER_OBJ =	server.o

CLIENT_OBJ =	client.o \
				atoi.o

BONUS_SERVER_OBJ =	server_bonus.o

BONUS_CLIENT_OBJ =	client_bonus.o \
					atoi.o

CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIENT_NAME = client
SERVER_NAME = server
BONUS_CLIENT_NAME = client_
BONUS_SERVER_NAME = server_

all : ${SERVER_NAME} ${CLIENT_NAME}

bonus : ${BONUS_CLIENT_NAME} ${BONUS_SERVER_NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

$(CLIENT_NAME) : ${CLIENT_OBJ}
	${CC} $^ -o ${CLIENT_NAME}

$(SERVER_NAME) : ${SERVER_OBJ}
	${CC} $^ -o ${SERVER_NAME}

$(BONUS_CLIENT_NAME) : ${BONUS_CLIENT_OBJ}
	${CC} $^ -o ${CLIENT_NAME}

$(BONUS_SERVER_NAME) : ${BONUS_SERVER_OBJ}
	${CC} $^ -o ${SERVER_NAME}

clean :
	rm -f ${SERVER_OBJ}
	rm -f ${CLIENT_OBJ}
	rm -f ${BONUS_SERVER_OBJ}
	rm -f ${BONUS_CLIENT_OBJ}

fclean : clean
	rm -f ${SERVER_NAME}
	rm -f ${CLIENT_NAME}

re :
	make fclean
	make all
