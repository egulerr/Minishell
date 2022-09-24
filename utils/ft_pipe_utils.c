/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:30:03 by eguler            #+#    #+#             */
/*   Updated: 2022/09/09 12:50:28 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cont_quote(char *str)
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

void	ft_howmany_pipe(char **str, int flag, int i)
{
	int	j;

	j = 0;
	while (str[i][j])
	{
		if (flag == 0)
		{
			if (str[i][j] == '|')
			{
				g_mini->pipe_count++;
			}
		}
		j++;
	}
}
