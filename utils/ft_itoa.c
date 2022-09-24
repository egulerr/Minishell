/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:46:04 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/30 13:56:08 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	nbrlen(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = (long)nbr * -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int	ft_div(int len)
{
	int	count;

	count = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		count *= 10;
		len--;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			count;
	int			len;
	int			len2;
	long int	new_n;

	count = 0;
	new_n = n;
	len = nbrlen(new_n);
	len2 = nbrlen(new_n);
	arr = ft_calloc(sizeof(char), (len + 1));
	if (!arr)
		return (0);
	if (new_n < 0)
	{
		new_n *= -1;
		arr[0] = '-';
		count++;
		len--;
	}
	while (count < len2)
		arr[count++] = (((new_n / (ft_div(len--)) % 10) + 48));
	arr[count] = '\0';
	return (arr);
}
