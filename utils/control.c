/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:13:52 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 14:02:40 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_space_cont(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (s != NULL)
	{
		while (s[i] && s[i] != '\0')
		{
			if (s[i] != ' ' && s[i] != '\t')
				flag = 1;
			i++;
		}
		if (flag == 1)
			return (0);
		else
			return (1);
	}
	return (0);
}
