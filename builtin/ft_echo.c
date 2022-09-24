/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:37:47 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 12:25:25 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_quotes(char *s)
{
	int		j;
	int		x;
	char	*str;

	j = 0;
	if (s)
	{
		x = ft_quotes_size(s);
		str = ft_calloc(sizeof(char), x + 1);
		x = 0;
		while (s[j])
		{
			if (s[j] != '"' && s[j] != '\'')
			{
				str[x] = s[j];
				x++;
				j++;
			}
			else
				j++;
		}
		str[x] = '\0';
		printf("%s", str);
		free(str);
	}
}

int	ft_quotes_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
			j++;
		i++;
	}
	return (j);
}

void	ft_echo(void)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (g_mini->command[i])
	{
		if (!ft_strcmp2(g_mini->command[i], "-n"))
			flag = 1;
		else if (g_mini->command[i] != NULL && \
		ft_strcmp2(g_mini->command[i], "-n"))
		{
			ft_quotes(g_mini->command[i]);
		}
		if (g_mini->command[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (flag == 0)
		printf("\n");
}
