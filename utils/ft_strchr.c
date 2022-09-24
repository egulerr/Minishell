/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:31:27 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/18 16:41:24 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != (char)c)
	{
		if (!s[count])
		{
			return (NULL);
		}
		count++;
	}
	return ((char *)&s[count]);
}
