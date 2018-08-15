
NAME = libftprintf.a

SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
	libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_strcat.c \
	libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strncat.c \
	libft/ft_strncpy.c libft/ft_strrchr.c libft/ft_strstr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_strnstr.c libft/ft_strncmp.c \
	libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c libft/ft_putchar.c libft/ft_strpull_ptr.c \
	libft/ft_strpull_idx.c libft/ft_putstr.c libft/ft_putchar_fd.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c  \
	libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_strsplit.c libft/ft_lstdel.c libft/ft_strchr_idx.c\
	libft/ft_itoa.c libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strcount.c libft/ft_lstdelone.c \
	libft/ft_putnbr_fd.c libft/ft_strrev.c libft/ft_wordlen.c libft/ft_intlen.c libft/ft_lstadd.c libft/ft_lstnew.c libft/ft_lstiter.c libft/ft_lstmap.c \
	libft/get_next_line.c libft/ft_isspace.c  libft/ft_split.c libft/ft_intcpy.c libft/ft_atol.c libft/ft_deldouble.c libft/ft_doublesize.c \
	libft/ft_printchardouble.c libft/ft_printintarray.c libft/ft_strmerge.c \
	src/basicchecker.c src/createpadding.c src/createstruc.c src/destroy.c src/dynamicstring.c src/findhex.c src/findoct.c src/findops.c src/findunsdigit.c \
	src/ft_itoa_base.c src/ft_printf.c  src/ft_uitoa.c src/handlenonvalid.c src/lengthmod.c src/precision.c src/strprocessing.c src/ft_lltoa.c src/wildcard.c \
	src/findwchar.c src/findwstr.c src/wcharsupport.c src/finddigit.c src/findpointer.c src/paddingsupportfunc.c\
	

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I.libft/ -I.src/ -c
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all