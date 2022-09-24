/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:22:52 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 11:52:01 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_dolar3(char *s, int j)
{
	int		i;
	int		flag;
	char	*comm;
	char	**com;

	flag = 0;
	i = -1;
	comm = ft_calloc(1, sizeof(char));
	com = ft_split_quote(s, '$');
	while (com[++i])
	{
		j = 0;
		while (g_mini->env[j])
		{
			if (ft_strcmp(g_mini->env[j], com[i]))
			{
				flag = 1;
				free(com[i]);
				com[i] = ft_strdup(ft_strstr2(g_mini->env[j], com[i]));
				break ;
			}
			j++;
		}
	}
	return (ft_dolar3_utils(com, flag, comm, s));
}

char	*ft_dolar2(char *s)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] == '$')
		{
			f = ft_dolar_cont_2(&s[i]);
			break ;
		}
		i++;
	}
	return (ft_dolar2_utils(f, s));
}

char	*ft_dolar(char *com)
{
	if (ft_dolar_cont(com) && (ft_dolar_quotes(ft_split_quote(com, ' ')) \
		&& (!ft_is_dolar_question_mark(com, "$?"))))
		return (ft_dolar_utils(com));
	else if (ft_is_dolar_question_mark(com, "$?"))
		return (ft_dolar_mark_utils(com));
	else
		return (com);
}
