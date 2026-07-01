# Executable name
NAME = push_swap
CHECKER_NAME = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./include/libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
SRC_CHECKER_DIR = ./src_checker
OBJ_CHECKER_DIR = ./obj_checker

# Source files for push_swap
SRCS = main.c \
		swap.c \
		push.c \
		rotate.c \
		rotate_reverse.c \
		utils.c \
		find_cible.c \
		calcul_cost.c \
		move_2_stacks.c \
		push_element.c \
		sort.c \
		print_error.c \
		validation_args.c \
		stacks.c \
		chunk_move_stacks.c \
		chunk_a_to_b.c \
		chunk_b_to_a.c \
		parsing.c \
		clear.c \

# Source files for checker
CHECKER_SRCS = main.c \
				swap.c \
				push.c \
				rotate.c \
				rotate_reverse.c \
				utils.c \
				print_error.c \
				validation_stacks.c \
				validation_args.c \
				parsing.c \
				instruction.c \
				clear.c \


# Object files with path prefix
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CHECKER_OBJS = $(addprefix $(OBJ_CHECKER_DIR)/, $(CHECKER_SRCS:.c=.o))

# Include directories
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

# Default rule
all: $(NAME)

# Rule for checker (bonus)
bonus: re $(NAME) $(CHECKER_NAME)

# Create the push_swap program
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Create the checker program
$(CHECKER_NAME): $(CHECKER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER_NAME)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile source files into object files for checker
$(OBJ_CHECKER_DIR)/%.o: $(SRC_CHECKER_DIR)/%.c | $(OBJ_CHECKER_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ensure the object directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_CHECKER_DIR):
	@mkdir -p $(OBJ_CHECKER_DIR)

# Build the library (libft)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR) $(OBJ_CHECKER_DIR)

# Clean object files and executable
fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the library and the main program
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
