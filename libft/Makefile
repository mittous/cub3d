
NAME = libft.a
SRCS =				ft_atoi.c\
					ft_isalpha.c\
					ft_memmove.c\
					ft_putnbr_fd.c\
					ft_strdup.c\
					ft_strlcpy.c\
					ft_strnstr.c\
					ft_tolower.c\
					ft_bzero.c\
					ft_isascii.c\
					ft_memchr.c\
					ft_memset.c\
					ft_putstr_fd.c\
					ft_striteri.c\
					ft_strlen.c\
					ft_strrchr.c\
					ft_toupper.c\
					ft_calloc.c\
					ft_isdigit.c\
					ft_memcmp.c\
					ft_putchar_fd.c\
					ft_split.c\
					ft_strjoin.c\
					ft_strmapi.c\
					ft_strtrim.c\
					ft_isalnum.c\
					ft_isprint.c\
					ft_memcpy.c\
					ft_putendl_fd.c\
					ft_strchr.c\
					ft_strlcat.c\
					ft_strncmp.c\
					ft_substr.c\
					ft_itoa.c

					
BONUS_SRCS =	ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstnew.c
object = $(SRCS:.c=.o)
bonusobject = $(BONUS_SRCS:.c=.o)
CC				= gcc

RM				= @rm -f

CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(object)
	@ar -rc $(NAME) $(object)

bonus:	$(NAME) $(bonusobject)
	@ar -rc $(NAME) $(bonusobject)

clean:
	$(RM) $(object) $(bonusobject)

fclean: clean
	$(RM) $(NAME)

re: fclean all
