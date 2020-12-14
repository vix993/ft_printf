# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnascime <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 18:49:41 by vnascime          #+#    #+#              #
#    Updated: 2020/02/09 16:11:01 by vnascime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
	 ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memmove.c ft_memset.c ft_putnbrmax_fd.c ft_strchr.c ft_strdup.c ft_strndup.c ft_strlcat.c \
	 ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	 ft_tolower.c ft_toupper.c ft_isalpha.c ft_substr.c ft_strjoin.c \
	 ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_base.c ft_putchar_fd.c ft_putnbr_fd.c \
	 ft_putnbrumax_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c

OBJECTS=ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isascii.o \
		ft_isdigit.o ft_isprint.o ft_putnbrmax_fd.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		ft_memcpy.o ft_memmove.o ft_memset.o ft_strchr.o ft_strdup.o ft_strndup.o \
		ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strcmp.o ft_strncmp.o ft_strnew.o ft_strnstr.o \
		ft_strrchr.o ft_tolower.o ft_toupper.o ft_isalpha.o ft_substr.o \
		ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_itoa_base.o ft_putchar_fd.o \
		ft_putnbrumax_fd.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_putendl_fd.o ft_strmapi.o

BONUS_SRCS=ft_lstadd_back.c ft_lstnew.c ft_lstadd_front.c ft_lstdelone.c \
		   ft_lstclear.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c

BONUS_OBJECTS=ft_lstadd_back.o ft_lstnew.o ft_lstadd_front.o ft_lstdelone.o \
			  ft_lstclear.o ft_lstsize.o ft_lstlast.o ft_lstiter.o ft_lstmap.o

INCLUDES=includes/libft.h

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Werror -Wextra -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: $(BONUS_SRCS)
	@gcc -Wall -Werror -Wextra -I$(INCLUDES) -c $(BONUS_SRCS)
	@ar rc $(NAME) $(BONUS_OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
