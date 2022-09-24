NAME    = minishell
CC = gcc
INC = minishell.h
CFLAGS = -Wall -Wextra -Werror -I ./lib/readline/include -ggdb
LDFLAGS = -L ./lib/readline/lib -lreadline
LIB	= ./lib/.minishell
RM = rm -rf
SRCS    =	main.c								\
			setup.c								\
			command.c							\
			ft_exec.c							\
			ft_exec2.c							\
			ft_signal.c							\
			ft_pipe.c							\
			utils/utils.c						\
			utils/parse.c						\
			utils/ft_quotes_delete.c			\
			utils/ft_quotes_delete_2.c			\
			utils/ft_quotes_delete_2_utils.c	\
			utils/ft_parse_quotes.c				\
			utils/ft_free.c						\
			utils/control.c						\
			utils/ft_split.c					\
			utils/ft_strjoin.c					\
			utils/ft_strlen.c					\
			utils/ft_strdup.c					\
			utils/ft_strstr.c					\
			utils/ft_strcmp.c					\
			utils/ft_free_dup.c					\
			utils/ft_strncmp.c					\
			utils/ft_strrchr.c					\
			utils/ft_strtrim.c					\
			utils/ft_strchr.c					\
			utils/ft_calloc.c					\
			utils/ft_itoa.c						\
			utils/ft_atoi.c						\
			utils/ft_putstr_fd.c				\
			utils/ft_check_error.c				\
			utils/ft_pipe_utils.c				\
			builtin/ft_echo.c					\
			builtin/ft_env.c					\
			builtin/ft_exit.c					\
			builtin/ft_export.c					\
			builtin/ft_export_2.c				\
			builtin/ft_export_3.c				\
			builtin/ft_export_utils.c			\
			builtin/ft_export_utils_2.c			\
			builtin/ft_unset.c					\
			builtin/ft_unset_utils.c			\
			builtin/ft_pwd.c					\
			builtin/ft_cd.c						\
			builtin/ft_cd_utils.c				\
			builtin/ft_dolar.c					\
			builtin/ft_dolar_utils.c			\
			builtin/ft_dolar_utils_2.c			\
			operator/operator.c					\
			operator/operator2.c				\
			operator/operator_control.c			\
			operator/operator_control_2.c		\
			operator/operator_control_3.c		\
			operator/operator_control_4.c		\

OBJS = $(SRCS:.c=.o)
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	@$(CC) ${LDFLAGS} $(OBJS) -o $(NAME)
	@echo $(B)minishell is ready!

$(LIB):
	@make -C ./lib

%.o: %.c $(INC)
	@echo $(R)Complining [$<]
	@${CC} $(CFLAGS) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re