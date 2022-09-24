/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:18:28 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/07 12:54:04 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_export_add_3(char *buff, char *command)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	c = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(buff) + ft_strlen(command)) + 3);
	while (buff[i])
		str[c++] = buff[i++];
	i = 0;
	while (command[i] && command[i] != '=')
		str[c++] = command[i++];
	str[c++] = '=';
	if (g_mini->quotes_flag == 0)
		str[c++] = '"';
	i++;
	while (command[i])
		str[c++] = command[i++];
	if (g_mini->quotes_flag == 0)
		str[c++] = '"';
	str[c] = '\0';
	free(buff);
	return (str);
}

char	*ft_export_add_4(char *buff, char *command)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	c = 0;
	str = ft_calloc(sizeof(char), (ft_strlen(buff) + ft_strlen(command)) + 3);
	while (buff && buff[i])
		str[c++] = buff[i++];
	i = 0;
	while (command && command[i])
		str[c++] = command[i++];
	str[c] = '\0';
	free(buff);
	return (str);
}
