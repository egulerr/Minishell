/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:26:44 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/07 12:52:39 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(void)
{
	int	count;

	if (g_mini->command[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit (g_mini->dolar_number % 256);
	}
	count = 0;
	while (g_mini->command[count])
		count++;
	if (count > 2)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_mini->dolar_number = 1;
	}
	else if (ft_is_digit(g_mini->command[1]))
	{
		ft_putstr_fd("exit\n", 2);
		exit (ft_atoi(g_mini->command[1]) % 256);
	}
	else
		ft_if_not_numeric();
}

void	ft_if_not_numeric(void)
{
	ft_putstr_fd("exit\nminishell: exit: ", 2);
	ft_putstr_fd(g_mini->command[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
}

int	ft_is_digit(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] > '9' || command[i] < '0')
			return (0);
		i++;
	}
	return (1);
}
