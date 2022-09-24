/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:46:53 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 23:37:55 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_op_cont_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	ft_op_control(char *command)
{
	int		i;
	int		j;
	int		flag;
	char	**str;

	i = 0;
	str = ft_split_quote(command, ' ');
	while (str[i])
	{
		j = 0;
		flag = ft_op_cont_quote(str[i]);
		while (str[i][j])
		{
			if ((str[i][j] == '<' && flag == 0) \
			|| (str[i][j] == '>' && flag == 0))
			{
				ft_double_free(str);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_double_free(str);
	return (0);
}

int	ft_string(char *command, int i, char **op_command)
{
	int		j;
	int		x;
	char	*str;

	x = i;
	j = 0;
	while (command[x] != '>' && command[x] != '<' && command[x])
	{
		j++;
		x++;
	}
	str = ft_calloc(sizeof(char), j + 1);
	x = 0;
	while (command[i] != '>' && command[i] != '<' && command[i])
		str[x++] = command[i++];
	*op_command = ft_strdup(str);
	return (i);
}

int	ft_ope(char *command)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (command[i])
	{
		if (command[i] == '\"')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (1);
	else
		return (0);
}

int	ft_check_red(char *s)
{
	if (s[0] <= 32)
		return (0);
	else
		return (1);
}
