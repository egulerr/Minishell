/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:26:06 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/07 12:05:44 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_command(void)
{
	ft_delete_quotes();
	if (ft_strcmp3(g_mini->command[0], "echo"))
	{
		ft_echo();
		return (1);
	}
	if (ft_strcmp3(g_mini->command[0], "env"))
	{
		ft_env();
		return (1);
	}
	if (ft_strcmp3(g_mini->command[0], "exit"))
	{
		ft_exit();
		return (1);
	}
	else
		return (ft_command2());
	return (0);
}

int	ft_command2(void)
{
	if (ft_strcmp3(g_mini->command[0], "export"))
	{
		ft_export();
		return (1);
	}
	if (ft_strcmp3(g_mini->command[0], "unset"))
	{
		ft_unset();
		return (1);
	}
	if (ft_strcmp3(g_mini->command[0], "pwd"))
	{
		ft_pwd();
		return (1);
	}
	if (ft_strcmp3(g_mini->command[0], "cd"))
	{
		ft_cd();
		return (1);
	}
	return (0);
}
