/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:10:03 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 20:26:03 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_redir_start(void)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = 1;
	flag = 0;
	ft_operator_initialize();
	while (g_mini->operator[++i])
	{
		if (ft_strcmp2(g_mini->operator[i], ">") == 0)
			flag = ft_redir_bigger(j++, i);
		if (ft_strcmp2(g_mini->operator[i], ">>") == 0)
			flag = ft_redir_bigger_2(j++, i);
		if (ft_strcmp2(g_mini->operator[i], "<") == 0)
			flag = ft_redir_little(j++, i);
		if (ft_strcmp2(g_mini->operator[i], "<<") == 0)
			flag = ft_redir_little_2(j++, i);
		if (flag == 1)
			break ;
	}
	if (flag == 0)
		ft_redir_run();
}

void	ft_redir_cont(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_redir_trim();
	while (g_mini->op_command[i])
	{
		if (ft_redir_op(g_mini->op_command[i]))
			j++;
		i++;
	}
	g_mini->operator = ft_calloc(sizeof(char *), j + 1);
	i = 0;
	j = 0;
	while (g_mini->op_command[i])
	{
		if (ft_redir_op(g_mini->op_command[i]))
			g_mini->operator[j++] = ft_strdup(g_mini->op_command[i]);
		i++;
	}
	g_mini->operator[j] = NULL;
	ft_redir_com(i, j);
}

void	ft_redir_com(int i, int j)
{
	char	*str;
	int		x;

	str = ft_calloc(sizeof(char), (i - j + 1));
	x = 0;
	while (g_mini->op_command[x])
	{
		if (!ft_redir_op(g_mini->op_command[x]))
		{
			str = ft_strjoin(str, g_mini->op_command[x]);
			str = ft_strjoin(str, " ");
		}
		x++;
	}
	ft_double_free(g_mini->op_command);
	g_mini->op_command = ft_split_quote(str, ' ');
	free(str);
}

int	ft_redir_op(char *str)
{
	if (str != NULL)
	{
		if (ft_strcmp2(str, ">") == 0)
			return (1);
		if (ft_strcmp2(str, ">>") == 0)
			return (1);
		if (ft_strcmp2(str, "<") == 0)
			return (1);
		if (ft_strcmp2(str, "<<") == 0)
			return (1);
	}
	return (0);
}

void	ft_redir_trim(void)
{
	int	i;

	i = -1;
	while (g_mini->op_command[++i])
		g_mini->op_command[i] = ft_strtrim(g_mini->op_command[i], " ");
}
