/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:21:47 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 23:36:00 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_mini = ft_calloc(sizeof(t_mini), 1);
	ft_cpyenv(env);
	ft_cpyexport(env);
	ft_sort_export();
	ft_minisetup(env);
}
