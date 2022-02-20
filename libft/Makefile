FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -f

OBJS 		=	${SRCS:.c=.o}

OBJB		=	${BONUS:.c=.o}

HEAD		=	includes

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putnbr_fd.c \
ft_substr.c ft_split.c ft_strtrim.c ft_strcpy.c ft_putendl_fd.c \
ft_strequ.c ft_get_char_by_index.c ft_strndup.c

BONUS		=	ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME		=	libft.a

.c.o:	
		${CC} ${FLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

bonus :		${OBJS} ${OBJB}
			ar -rcs ${NAME} ${OBJS} ${OBJB}

clean:
			${RM} ${OBJS} ${OBJB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

