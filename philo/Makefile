#!-----------------------------------------------------------------------------#
#!                                 GENERICS                                    #
#!-----------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	FALSE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

#!-----------------------------------------------------------------------------#
#!                                TARGETS                                      #
#!-----------------------------------------------------------------------------#

# Dir and file names
NAME	=	philo
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	src/data.c		src/eat.c		src/error.c			src/forks.c	\
			src/ft_atoi.c	src/ft_calloc.c	src/init_philos.c	src/philo.c \
			src/sleep.c		src/think.c		src/time.c			src/print_action.c \
			src/monitor.c
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(HIDE)$(RM) test_philo*

# Removes objects and executables and remakes
re: fclean all

#!-----------------------------------------------------------------------------#
#!                                 TESTS                                       #
#!-----------------------------------------------------------------------------#
# 	n_philos  t_die  t_eat  t_sleep  [n_eats]
T_ARGS	= 10 400 200 100

test: all
	$(HIDE)clear
	$(HIDE)./$(NAME) $(T_ARGS)