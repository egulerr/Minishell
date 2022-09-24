/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:17:33 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 13:10:17 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_mini->dolar_number = 1;
	g_mini->pipe_count = 0;
}

void	ft_signal_cat(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(0);
	}
	g_mini->dolar_number = 1;
	g_mini->pipe_count = 0;
}
