/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:15:40 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 20:34:39 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_redir_stabilizer(void)
{
	char	*c;
	char	**str;

	str = ft_split_quote(g_mini->redir_command, '<');
	c = ft_merge(str);
	ft_double_free(str);
	str = ft_split_quote(c, '>');
	free(c);
	c = ft_merge(str);
	ft_double_free(str);
	str = ft_split_quote(c, ' ');
	free(c);
	return (str);
}

int	ft_redir_bigger(int x, int a)
{
	char	**str;
	int		i;

	i = -1;
	if (g_mini->l_flag == 1 || g_mini->ll_flag == 1)
		str = ft_redir_stabilizer();
	else
		str = ft_split_quote(g_mini->redir_command, '>');
	while (str[++i])
		str[i] = ft_strtrim(str[i], " ");
	if (str[x] != NULL && ft_check_red(str[x]))
	{
		ft_delete_quotes_param(str[x]);
		g_mini->r_lastfd = open(str[x], \
		O_CREAT | O_RDONLY | O_WRONLY, 0644);
		if (g_mini->r_flag == 0)
			g_mini->r_flag = 1;
		ft_double_free(str);
		return (0);
	}
	else
		return (ft_operator_error(str, a));
}

int	ft_redir_bigger_2(int x, int a)
{
	char	**str;
	int		i;

	i = -1;
	if (g_mini->l_flag == 1 || g_mini->ll_flag == 1)
		str = ft_redir_stabilizer();
	else
		str = ft_split_quote(g_mini->redir_command, '>');
	while (str[++i])
		str[i] = ft_strtrim(str[i], " ");
	if (str[x] != NULL && ft_check_red(str[x]))
	{
		ft_delete_quotes_param(str[x]);
		g_mini->r_lastfd = open(str[x], \
		O_CREAT | O_RDWR | O_APPEND, 0644);
		if (g_mini->r_flag == 0)
			g_mini->r_flag = 1;
		ft_double_free(str);
		return (0);
	}
	else
		return (ft_operator_error(str, a));
}

int	ft_redir_little(int x, int a)
{
	char	**str;
	int		i;

	i = -1;
	str = ft_redir_stabilizer();
	while (str[++i])
		str[i] = ft_strtrim(str[i], " ");
	if (str[x] != NULL && ft_check_red(str[x]))
	{
		ft_delete_quotes_param(str[x]);
		g_mini->l_lastfd = open(str[x], O_RDONLY);
		if (g_mini->l_flag == 0)
			g_mini->l_flag = 1;
		ft_double_free(str);
		return (0);
	}
	else
	{
		ft_check_error_2(1, a);
		ft_double_free(str);
		return (1);
	}
}

int	ft_redir_little_2(int x, int a)
{
	char	**str;
	int		pid;
	int		i;

	pipe(g_mini->ll_pipe);
	i = -1;
	if (g_mini->ll_flag == 0)
		g_mini->ll_flag = 1;
	str = ft_redir_stabilizer();
	while (str[++i])
		str[i] = ft_strtrim(str[i], " ");
	if (str[x] != NULL && ft_check_red(str[x]))
	{
		pid = fork();
		if (pid == 0)
		{		
			ft_redir_double_run(str[x]);
			exit(0);
		}
		ft_double_free(str);
		wait(NULL);
		return (0);
	}
	else
		return (ft_operator_error(str, a));
}
