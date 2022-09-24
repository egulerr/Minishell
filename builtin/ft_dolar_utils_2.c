/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolar_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:29:28 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 13:35:08 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_dolar_mark_utils(char *com)
{
	int		i;
	char	**comm;
	char	*com2;

	i = 0;
	comm = ft_split_quote(com, ' ');
	while (comm[i])
	{
		if (ft_is_dolar_question_mark(comm[i], "$?"))
		{
			free(comm[i]);
			if (g_mini->dolar_number != 130 && g_mini->dolar_number != 1 \
			&& g_mini->dolar_number != 2 && g_mini->dolar_number != 127)
				comm[i] = ft_itoa(g_mini->dolar_number / 256);
			else
				comm[i] = ft_itoa(g_mini->dolar_number);
		}
		i++;
	}
	com2 = ft_merge(comm);
	ft_double_free(comm);
	free(com);
	return (com2);
}

char	*ft_dolar_utils(char *com)
{
	int		i;
	char	**comm;
	char	*com2;

	i = 0;
	com2 = ft_calloc(sizeof(char), 1);
	comm = ft_split_quote(com, ' ');
	while (comm[i])
	{
		ft_delete_quotes_param(comm[i]);
		comm[i] = ft_dolar2(comm[i]);
		i++;
	}
	i = 0;
	while (comm[i])
	{
		com2 = ft_strjoin(com2, comm[i]);
		i++;
		com2 = ft_strjoin(com2, " ");
	}
	free(com);
	ft_double_free(comm);
	return (com2);
}

int	ft_dolar_and_equal_check(char *s)
{
	int	i;
	int	flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			flag++;
		if (s[i] == '=')
			flag2++;
		i++;
	}
	if (flag > 0 && flag2 > 0)
		return (1);
	return (0);
}
