NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = ./
INCL_DIR = ./
SRCS = \
$(SRCS_DIR)/ft_atoi.c $(SRCS_DIR)/ft_bzero.c $(SRCS_DIR)/ft_calloc.c \
$(SRCS_DIR)/ft_isalnum.c $(SRCS_DIR)/ft_isalpha.c $(SRCS_DIR)/ft_isascii.c \
$(SRCS_DIR)/ft_isdigit.c $(SRCS_DIR)/ft_isprint.c $(SRCS_DIR)/ft_itoa.c \
$(SRCS_DIR)/ft_memchr.c $(SRCS_DIR)/ft_memcmp.c $(SRCS_DIR)/ft_memcpy.c\
$(SRCS_DIR)/ft_memmove.c $(SRCS_DIR)/ft_memset.c $(SRCS_DIR)/ft_putchar_fd.c\
$(SRCS_DIR)/ft_putendl_fd.c $(SRCS_DIR)/ft_putnbr_fd.c $(SRCS_DIR)/ft_putstr_fd.c\
$(SRCS_DIR)/ft_split.c $(SRCS_DIR)/ft_strchr.c $(SRCS_DIR)/ft_strdup.c \
$(SRCS_DIR)/ft_striteri.c $(SRCS_DIR)/ft_strjoin.c $(SRCS_DIR)/ft_strlcat.c\
$(SRCS_DIR)/ft_strlcpy.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strmapi.c\
$(SRCS_DIR)/ft_strncmp.c $(SRCS_DIR)/ft_strnstr.c $(SRCS_DIR)/ft_strrchr.c\
$(SRCS_DIR)/ft_strtrim.c $(SRCS_DIR)/ft_substr.c $(SRCS_DIR)/ft_tolower.c\
$(SRCS_DIR)/ft_toupper.c $(SRCS_DIR)/ft_putnbr_base.c $(SRCS_DIR)/ft_isspace.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(INCL_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
