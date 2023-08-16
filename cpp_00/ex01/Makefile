# Makefile


NAME = phonebook


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I #-fsanitize=address

SRCS =  phonebook.cpp \
		main.cpp

OBJECT_FILES = $(SRCS:.cpp=.o)
HEADER = -I
all: $(NAME) 
.c.o:
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	@printf "$(YELLOW)Compiling $(NAME): << $< >>\033[K\r$(DEFAULT)"

$(NAME): $(OBJECT_FILES)
	@$(CC) $(CFLAGS) $(HEADER) -o $(NAME) $(SRCS) 

#------------------------------------------------------------------------------
clean: 
	@rm -rf $(OBJECT_FILES)
	@echo "$(GREEN)<<<<< clean from $(NAME) done ! >>>>>\n$(DEFAULT)"

#------------------------------------------------------------------------------
fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)<<<<< fclean done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------
re: fclean all
	@echo "$(GREEN)<<<<< $(NAME) make re done ! >>>>>\n$(DEFAULT)"
#------------------------------------------------------------------------------

#COLORS
RED = \033[3;31m
GREEN = \033[3;32m
YELLOW = \033[3;33m
DEFAULT = \033[0m
#------------------------------------------------------------------------------
#DEBUG
# -fsanitize=address
# valgrind --leak-check=full
# find . -type f -name "*.o" -delete