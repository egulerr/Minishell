/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 11:39:13 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 12:30:17 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export(void)
{
	int		i;

	i = 0;
	while (g_mini->command[++i] != NULL)
	{
		if (ft_numeric_cont(i))
			ft_allchecks_add_or_update(i);
		else
			ft_check_error(3, i);
	}
	if (g_mini->command[1] == NULL)
	{
		while (g_mini->export[i] && !g_mini->e_flag)
			printf("declare -x %s\n", g_mini->export[i++]);
	}
	g_mini->e_flag = 0;
}

void	ft_allchecks_add_or_update(int i)
{
	if (ft_control(i))
	{
		if (ft_quotes_check(i))
		{
			g_mini->command[i] = ft_delete_quotes_ey(g_mini->command[i]);
			g_mini->quotes_flag = 1;
		}
		if (ft_export_check(i))
			ft_export_add(i);
		else
			ft_export_update(i);
		if (ft_env_check(i))
			ft_env_add(i);
		else
			ft_env_update(i);
	}
	else
	{
		if (ft_export_check(i))
			ft_export_add_2(i);
	}
}
