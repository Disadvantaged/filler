NAME = filler

FLAGS = -Wall -Werror -Wextra

FLAGS += -Ilibft/includes -Iincludes/

SRC = main.c \
	  read.c \
	  place.c \
	  algo.c \
	  smallMap.c \
	  bigMap.c

SRCS = $(addprefix src/, $(SRC))

LIBFT_PATH = libft/

OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

RM = rm -f

MKDIR = @mkdir -p $(@D)

all: $(NAME)

obj/%.o: src/%.c
	$(MKDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS)
	@ echo -n 'Compiling project ... '
	@ $(CC) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)
	@ echo '[done]'
clean:
	@ echo -n 'removing objects ... '
	@ $(RM) $(OBJS)
	@ $(RM) resources/filler.trace
	@ echo '[done]'
	make -C $(LIBFT_PATH) clean
fclean: clean
	@ echo -n 'removing binary ... '
	@ $(RM) $(NAME)
	@ echo '[done]'
	make -C $(LIBFT_PATH) fclean
re: fclean all

.PHONY: all clean fclean re
