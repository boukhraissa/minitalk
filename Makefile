CLIENT             = client.c
SERVER             = server.c
CLIENT_PROC        = client
SERVER_PROC        = server
# FT_ATOI		       = ./bonus/ft_atoi_bonus.c
# CLIENT_BONUS       = ./bonus/client_bonus.c
# SERVER_BONUS       = ./bonus/server_bonus.c
# CLIENT_PROC_BONUS  = client_bonus
# SERVER_PROC_BONUS  = server_bonus
CC                 = cc
RM                 = rm -rf
CFLAGS             = -Wall -Wextra -Werror
DPRINTF            = ft_printf
PATH_PRINTF        = ./ft_printf/libftprintf.a
PATH_HEADER        = ./ft_printf/ft_printf.h


all: ${CLIENT_PROC} ${SERVER_PROC}

${CLIENT_PROC}: ${CLIENT} ${PATH_HEADER} minitalk.h 
	make -C ${DPRINTF}
	${CC} ${CFLAGS} ${PATH_PRINTF} ${CLIENT} -o ${CLIENT_PROC}

${SERVER_PROC}: ${SERVER} ${PATH_HEADER} minitalk.h 
	make -C ${DPRINTF}
	${CC} ${CFLAGS} ${PATH_PRINTF} ${SERVER} -o ${SERVER_PROC}


# bonus: ${CLIENT_PROC_BONUS} ${SERVER_PROC_BONUS}

# ${CLIENT_PROC_BONUS}: ${CLIENT_BONUS} ${PATH_HEADER} ./bonus/minitalk_bonus.h 
# 	make -C ${DPRINTF}
# 	${CC} ${CFLAGS} ${PATH_PRINTF} ${CLIENT_BONUS} ${FT_ATOI} -o ${CLIENT_PROC_BONUS}

# ${SERVER_PROC_BONUS}: ${SERVER_BONUS} ${PATH_HEADER} ./bonus/minitalk_bonus.h 
# 	make -C ${DPRINTF}
# 	${CC} ${CFLAGS} ${PATH_PRINTF} ${SERVER_BONUS} -o ${SERVER_PROC_BONUS}

clean:
	make clean -C ${DPRINTF}
	${RM} ${CLIENT_PROC}
	${RM} ${SERVER_PROC}
	${RM} ${CLIENT_PROC_BONUS}
	${RM} ${SERVER_PROC_BONUS}

fclean: clean
	make fclean -C ${DPRINTF}

re: fclean all

.PHONY: clean 
