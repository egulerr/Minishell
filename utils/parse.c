/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:23:07 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 16:00:46 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pathparse(char *path)
{
	int		i;
	char	**str;

	i = 0;
	if (path != NULL)
	{
		str = ft_split(path, ':');
		while (str[i])
			i++;
		g_mini->pathlst = ft_calloc(sizeof(char *), i + 1);
		ft_pathparse_2(str);
		ft_double_free(str);
		return (1);
	}
	return (0);
}

void	ft_pathparse_2(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = ft_strlen(str[i]);
		g_mini->pathlst[i] = ft_calloc(sizeof(char), j + 1);
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '\"')
				g_mini->pathlst[i][j] = str[i][j];
			j++;
		}
		g_mini->pathlst[i][j] = '\0';
		i++;
	}
	g_mini->pathlst[i] = NULL;
}

int	ft_joinpath(void)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (g_mini->env[i])
	{
		if (ft_strcmp(g_mini->env[i], "PATH="))
		{
			path = ft_strstr(g_mini->env[i], "PATH=");
			break ;
		}
		i++;
	}
	if (ft_pathparse(path))
		return (1);
	else
		return (0);
}

int	ft_dblen(char **a)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	len = 0;
	while (a[i])
	{
		y = 0;
		while (a[i][y++])
			len++;
		i++;
		len++;
	}
	return (len);
}

char	*ft_merge(char **command)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	arr = ft_calloc(sizeof(char), ft_dblen(command));
	while (command[i])
	{
		j = 0;
		while (command[i][j])
			arr[k++] = command[i][j++];
		if (command[i + 1])
			arr[k++] = ' ';
		i++;
	}
	arr[k] = '\0';
	return (arr);
}
