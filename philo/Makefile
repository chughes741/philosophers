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
SRCS	=	src/data.c src/eat.c src/error.c src/ft_atoi.c src/ft_calloc.c\
			src/init_philos.c src/philo.c src/sleep.c src/think.c
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

# Removes objects and executables and remakes
re: fclean all

#!-----------------------------------------------------------------------------#
#!                                 TESTS                                       #
#!-----------------------------------------------------------------------------#

T_ARGS	= 1 1 1 1

test: $(NAME)
	$(HIDE)clear
	$(HIDE)./$^ $(T_ARGS)