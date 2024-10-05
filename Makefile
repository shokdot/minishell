NAME = minishell

SRC_DIR = srcs
OBJ_DIR = build
SUBDIRS = builtin signal

LIBFT = ./libft

INCLUDES = -I includes
HEADER = $(wildcard includes/*.c)

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

LIBFLAGS = -L /opt/homebrew/Cellar/readline/8.2.13/lib/ -lreadline -L $(LIBFT) -lft
CFLAGS = -g3 # -Wall -Wextra -Werror -g3

GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

all: $(NAME)

bonus: $(NAME)

$(OBJ_DIR): libs
	@mkdir -p $(OBJ_DIR)

libs:
	@make -C $(LIBFT)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Minishell isn't for you!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED) Deleting minishell!$(RESET)"

re: fclean all

.PHONY: all clean re fclean libs
