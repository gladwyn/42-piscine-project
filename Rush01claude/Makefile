# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 00:00:00 by student          #+#    #+#              #
#    Updated: 2024/08/27 00:00:00 by student         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = skyscraper

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Source files
SRCS = main.c \
       input_validation.c \
       io_utils.c \
       solver.c \
       validation_utils_1.c \
       validation_utils_2.c

# Object files
OBJS = $(SRCS:.c=.o)

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m # No Color

# Default target
all: $(NAME)

# Compile the program
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

# Compile object files
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@$(RM) $(OBJS)
	@echo "$(RED)✓ Object files cleaned!$(NC)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(RED)✓ $(NAME) cleaned!$(NC)"

# Rebuild everything
re: fclean all

# Test cases


# Debugging version
debug: CFLAGS += -DDEBUG
debug: re
	@echo "$(GREEN)Debug version compiled!$(NC)"

# Memory leak check (requires valgrind)
valgrind: $(NAME)
	@echo "$(CYAN)=============== MEMORY LEAK CHECK ===============$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "4 3 2 1 1 2 2 2" 2>&1 | grep -E "(ERROR SUMMARY|definitely lost|indirectly lost|possibly lost)"

# Help
help:
	@echo "$(CYAN)Available targets:$(NC)"
	@echo "  $(GREEN)all$(NC)           - Compile the program"
	@echo "  $(GREEN)clean$(NC)         - Remove object files"
	@echo "  $(GREEN)fclean$(NC)        - Remove object files and executable"
	@echo "  $(GREEN)re$(NC)            - Rebuild everything"
	@echo "  $(GREEN)test$(NC)          - Run comprehensive test suite (small grids)"
	@echo "  $(GREEN)test-big$(NC)      - Run big grid tests (5x5 to 9x9)"
	@echo "  $(GREEN)test-big-simple$(NC) - Run simpler big grid tests"
	@echo "  $(GREEN)test-quick$(NC)    - Run quick tests"
	@echo "  $(GREEN)debug$(NC)         - Compile debug version"
	@echo "  $(GREEN)valgrind$(NC)      - Check for memory leaks"
	@echo "  $(GREEN)help$(NC)          - Show this help message"

# Test individual cases
test-1x1: $(NAME)
	@echo "$(BLUE)Testing 1x1 grid:$(NC)"
	@./$(NAME) "1 1 1 1"

test-2x2: $(NAME)
	@echo "$(BLUE)Testing 2x2 grid:$(NC)"
	@./$(NAME) "2 1 1 2 2 1 1 2"

test-3x3: $(NAME)
	@echo "$(BLUE)Testing 3x3 grid:$(NC)"
	@./$(NAME) "2 2 1 1 2 3 2 2 1 1 2 3"

test-4x4: $(NAME)
	@echo "$(BLUE)Testing 4x4 grid:$(NC)"
	@./$(NAME) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

test-5x5: $(NAME)
	@echo "$(BLUE)Testing 5x5 grid (simple):$(NC)"
	 ./$(NAME) "2 4 1 4 3 3 1 3 2 3 2 1 3 3 2 2 2 1 2 3"

test-6x6: $(NAME)
	@echo "$(BLUE)Testing 6x6 grid (simple):$(NC)"
	@./$(NAME) "2 2 3 1 2 3 3 3 1 3 2 2 3 1 2 2 4 2 3 2 2 4 1 3"

#timeout 120
test-7x7: $(NAME)
	@echo "$(BLUE)Testing 7x7 grid:$(NC)"
	@time ./$(NAME) "1 2 2 5 3 4 4 3 2 3 1 3 3 2 1 2 3 2 3 2 2 6 4 3 1 2 5 2"

#timeout 180
test-8x8: $(NAME)
	@echo "$(BLUE)Testing 8x8 grid:$(NC)"
	@timeout 300 ./$(NAME) "2 3 2 3 1 4 5 4 2 1 3 2 3 3 2 2 4 1 3 4 5 6 5 2 2 3 3 2 3 1 2 3"

#timeout 300
test-9x9: $(NAME)
	@echo "$(BLUE)Testing 9x9 grid (maximum):$(NC)"
	@timeout 600 ./$(NAME) "2 4 3 3 2 3 1 4 2 3 1 2 3 4 2 3 2 3 4 1 3 4 4 2 3 2 2 2 5 3 1 3 4 2 4"

test-errors: $(NAME)
	@echo "$(BLUE)Testing error cases:$(NC)"
	@echo "No args:"
	@./$(NAME) || true
	@echo "Invalid input:"
	@./$(NAME) "invalid" || true
	@echo "Wrong count:"
	@./$(NAME) "1 2 3" || true

.PHONY: all clean fclean re debug valgrind help test-2x2 test-3x3 test-4x4 test-5x5 test-6x6 test-7x7 test-8x8 test-9x9 test-errors