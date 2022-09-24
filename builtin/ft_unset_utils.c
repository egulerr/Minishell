/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:48:35 by eguler            #+#    #+#             */
/*   Updated: 2022/09/07 14:30:28 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_equal_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_mini->env[i])
	{
		if (ft_strcmp3(g_mini->env[i], str))
		{
			j = 0;
			while (str[j])
			{
				if (str[j] == '=')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_find_equal(char *str)
{
	int		i;
	char	*arr;

	i = 0;
	while (str[i] != '=' && str && str[i])
		i++;
	arr = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] != '=' && str && str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str && str[i])
		i++;
	return (i);
}

void	ft_delete_cpyenv(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*arr;

	temp = ft_find_equal(str);
	i = -1;
	while (g_mini->cpyenv && g_mini->cpyenv[++i])
	{
		arr = ft_calloc(sizeof(char), ft_len(g_mini->cpyenv[i]) + 1);
		j = 0;
		while (g_mini->cpyenv[i][j] && g_mini->cpyenv[i][j] != '=')
		{
			arr[j] = g_mini->cpyenv[i][j];
			j++;
		}
		arr[j] = '\0';
		if (ft_strcmp3(arr, temp))
		{
			ft_remove_found_line(g_mini->cpyenv, i, arr);
			break ;
		}
		free(arr);
	}
	free(temp);
}
