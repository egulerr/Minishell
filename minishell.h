/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:50:28 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 16:59:26 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <fcntl.h>

typedef struct s_mini
{
	int		pipe_count;
	char	*command3;
	char	*command2;
	char	**pipe_command;
	char	**command;
	char	**pathlst;
	char	**env;
	char	**cpyenv;
	char	**export;
	char	*old_pwd;
	char	*new_pwd;
	char	*cmd;
	int		env_flag;
	int		export_flag;
	char	*last_command;

	int		quotes_flag;
	int		quotes_flag_env;

	char	*redir_command;
	char	**op_command;
	char	**operator;
	int		r_lastfd;
	int		r_flag;
	int		l_lastfd;
	int		l_flag;
	int		ll_flag;
	int		ll_pipe[2];

	int		**fd;
	int		*pid_list;

	int		dolar_number;
	int		e_flag;
}				t_mini;

t_mini	*g_mini;

//Main Functions

int		main(int ac, char **av, char **env);

//Setup Functions

void	ft_minisetup(char **env);
void	ft_pipe_start(char *command);
void	ft_lastcomm(char *s);
void	start(char *command);
void	ft_norm_start(char *command);

//Parse Functions

int		ft_pathparse(char	*path);
int		ft_joinpath(void);
int		ft_dblen(char **a);
char	*ft_merge(char **command);
void	ft_quotes(char *s);
int		ft_quotes_size(char *str);
void	ft_pathparse_2(char **str);

//Signal Functions

void	ft_signal(int sig);
void	ft_signal_cat(int sig);

//Control Functions

int		ft_space_cont(char *s);

//Pipe Functions

int		ft_pipe_control(char *command);
void	ft_pipe(void);
void	ft_fork(int i);
void	ft_close(int i);
int		ft_cont_quote(char *str);
int		ft_pipe_cont(void);

//Free Functions

void	ft_free(void);
void	ft_freepath(void);
void	ft_double_free(char **s);
void	ft_pwd_free(void);
void	ft_double_free_int(int **s);

//Exec Functions

void	ft_exec(void);
void	ft_exec_run(char *s);
void	ft_exec_run_2(char *s);
int		ft_exec_dot(void);
void	ft_dot_exec(void);
void	ft_dot_exec2(char *com, char **com2);
void	ft_dot_run(char *command, char *com);

//Command Functions

int		ft_command(void);
int		ft_command2(void);

//Utils Functions

void	ft_cpyenv(char **env);
void	ft_cpyexport(char **env);
void	ft_free_cpyenv(char	**env);
char	**ft_env_cpy(char **env);

//Quotes Delete Functions

void	ft_delete_quotes(void);
void	ft_delete_quotes_param(char *str);
int		ft_dolar_quotes(char **str);
char	*ft_delete_quotes_ey(char *command);
char	*ft_return_string(char *command);
char	*ft_return_equal(char *command);
char	*ft_return_equal_2(char *str, char *command);
int		ft_len_for_malloc(char *str, int flag);
int		ft_quotes_malloc_flag2(char *str);
int		ft_quotes_malloc_flag3(char *str);
char	*ft_return_equal_com(char *com);

//Quotes Parse Functions

char	**ft_split_quote(char const *s, char c);
size_t	w_l(char const *s, char c);
size_t	w_c(char const *s, char c);
int		in_single_quotes(const char *s, int i);
int		in_quotes(const char *s, int i);
int		in_char(const char *str, int index, char c);

//Builtin Functions

//#CD
void	ft_cd(void);
void	ft_updatexport(void);
void	ft_updatenv(void);
void	ft_dash(void);
void	ft_dot_or_twodots(void);
void	ft_updates(void);

//#DOLAR
char	*ft_dolar3(char *s, int j);
char	*ft_dolar2(char *s);
int		ft_dolar_cont_2(char *s);
int		ft_dolar_cont(char *s);
char	*ft_dolar(char *com);
char	*ft_is_return_before_dolar(char *s);
char	*ft_dolar2_utils(int f, char *s);
char	*ft_dolar3_utils(char **com, int flag, char *comm, char *s);
char	*ft_dolar_mark_utils(char *com);
char	*ft_dolar_utils(char *com);
int		ft_dolar_and_equal_check(char *s);

//#ECHO
void	ft_echo(void);

//#ENV
void	ft_env(void);

//#EXİT
void	ft_exit(void);
void	ft_if_not_numeric(void);

//#EXPORT
int		is_already_added(char *export);
int		ft_quotes_check(int index);
char	*ft_add_quotes(char *export);
void	ft_addquotes_showexport(void);
char	*ft_export_allocation(char *str);
void	ft_sort_export(void);
void	ft_addenv(void);
int		ft_control(int a);
int		ft_env_check(int a);
int		ft_export_check(int a);
int		ft_numeric_cont(int a);
void	ft_export(void);
void	ft_env_add(int a);
void	ft_env_update(int a);
void	ft_export_add(int a);
void	ft_export_add_2(int a);
void	ft_export_update(int a);
char	*ft_export_add_3(char *buff, char *command);
char	*ft_export_add_4(char *buff, char *command);
char	*ft_export_allocation(char *str);
void	ft_sortenv(void);
void	ft_allchecks_add_or_update(int i);
//#PWD
void	ft_pwd(void);

//#UNSET
void	ft_unset(void);
void	ft_delete_export(char *str);
void	ft_delete_env(char *str);
void	ft_delete_cpyenv(char *str);
int		ft_len(char *str);
char	*ft_find_equal(char *str);
int		ft_equal_check(char *str);
void	ft_more_argument(void);
void	ft_remove_found_line(char **found_line, int i, char *arr);

//Operator Functions

int		ft_op_control(char *command);
int		ft_string(char *command, int i, char **op_command);
int		ft_ope(char *command);
void	ft_op_parse(char *command);
void	ft_open_file(char **command, char **operator);
void	r_run_op(void);
void	l_run_op(void);
void	op_start(char *command);
void	ft_exec_op(void);
void	ft_exec_op_run(char *s);
int		ft_op_cont_quote(char *str);
int		ft_com_parse(char *com);
int		ft_red_cont(void);

void	ft_redir_cont(void);
void	ft_redir_trim(void);
int		ft_redir_op(char *str);
void	ft_redir_com(int i, int j);
void	ft_redir_start(void);
int		ft_redir_bigger(int x, int a);
int		ft_redir_bigger_2(int x, int a);
int		ft_redir_little(int x, int a);
int		ft_redir_little_2(int x, int a);
void	ft_redir_run(void);
char	**ft_redir_stabilizer(void);
void	ft_redir_bigger_start(void);
void	ft_redir_little_start(void);
void	ft_redir_double_penetration(void);
void	ft_redir_double_little(void);
void	ft_redir_double_run(char *str);
int		ft_check_red(char *s);
void	ft_operator_initialize(void);
int		ft_operator_error(char **str, int a);

//Libft Utils

char	*ft_free_dup(char *str);

//Split
int		s_cut(char const *s, char c);
char	*news_copy(char *newstr, const char *s, int index, int len);
void	*news_split(char **newstr, char const *s, char c, int count);
char	**ft_split(char const *s, char c);
//end
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp2(char *s1, char *s2);
int		ft_strcmp3(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int len);
char	*ft_strrchr(char *s, int c);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strstr2(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
void	*ft_memset(void *str, int a, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
void	ft_check_error(int flag, int index);
void	ft_check_error_2(int flag, int index);
int		ft_is_dolar_question_mark(char *s1, char *s2);
void	ft_howmany_pipe(char **str, int flag, int i);
int		ft_is_digit(char *command);
//itoa
int		nbrlen(long nbr);
int		ft_div(int len);
char	*ft_itoa(int n);

#endif