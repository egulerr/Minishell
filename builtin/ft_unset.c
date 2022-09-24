/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:44:29 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/07 14:32:51 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(void)
{
	int	comcount;

	comcount = 0;
	while (g_mini->command[comcount + 1])
		comcount++;
	if (comcount == 1)
	{
		if (ft_equal_check(g_mini->command[1]) || !ft_numeric_cont(1))
			ft_check_error(4, 1);
		else
		{
			ft_delete_env(g_mini->command[1]);
			ft_delete_cpyenv(g_mini->command[1]);
			ft_delete_export(g_mini->command[1]);
		}
	}
	else if (comcount > 1)
		ft_more_argument();
}

void	ft_more_argument(void)
{
	int	i;

	i = 1;
	while (g_mini->command[i])
	{
		if (ft_equal_check(g_mini->command[i]) || !ft_numeric_cont(i))
			ft_check_error(4, i);
		else
		{
			ft_delete_env(g_mini->command[i]);
			ft_delete_export(g_mini->command[i]);
			ft_delete_cpyenv(g_mini->command[i]);
		}
		i++;
	}
}

void	ft_delete_export(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*arr;

	temp = ft_find_equal(str);
	i = -1;
	while (g_mini->export && g_mini->export[++i])
	{
		arr = ft_calloc(sizeof(char), ft_len(g_mini->export[i]) + 1);
		j = 0;
		while (g_mini->export[i][j] && g_mini->export[i][j] != '=')
		{
			arr[j] = g_mini->export[i][j];
			j++;
		}
		arr[j] = '\0';
		if (ft_strcmp3(arr, temp))
		{
			ft_remove_found_line(g_mini->export, i, arr);
			break ;
		}
		free(arr);
	}
	free(temp);
}

void	ft_delete_env(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*arr;

	temp = ft_find_equal(str);
	i = -1;
	while (g_mini->env && g_mini->env[++i])
	{
		arr = ft_calloc(sizeof(char), ft_len(g_mini->env[i]) + 1);
		j = 0;
		while (g_mini->env[i][j] && g_mini->env[i][j] != '=')
		{
			arr[j] = g_mini->env[i][j];
			j++;
		}
		arr[j] = '\0';
		if (ft_strcmp3(arr, temp))
		{
			ft_remove_found_line(g_mini->env, i, arr);
			break ;
		}
		free(arr);
	}
	free(temp);
}

void	ft_remove_found_line(char **found_line, int i, char *arr)
{
	free(found_line[i]);
	while (found_line[i])
	{
		found_line[i] = found_line[i + 1];
		i++;
	}
	free(arr);
}
