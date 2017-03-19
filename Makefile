NAME = filler

FLAGS = -Wall -Werror -Wextra

FLAGS += -Ilibft/includes -Iincludes/

SRC = main.c

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
	@ echo '[done]'
	make -C $(LIBFT_PATH) clean
fight1:
	./resources/filler_vm -p1 ./filler -p2 resources/players/abanlin.filler -f resources/maps/map00
fight2:
	./resources/filler_vm -p1 ./filler -p2 resources/players/hcan.filler -f resources/maps/map01
fight3:
	./resources/filler_vm -p1 ./filler -p2 resources/players/carli.filler -f resources/maps/map02
fclean: clean
	@ echo -n 'removing binary ... '
	@ $(RM) $(NAME)
	@ echo '[done]'
	make -C $(LIBFT_PATH) fclean
re: fclean all
