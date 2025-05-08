/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:41:11 by alucar            #+#    #+#             */
/*   Updated: 2023/10/11 11:41:13 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(t_struct *lc)
{
	int	i;

	i = 0;
	while (i < lc->column)
	{
		if (lc->map2d[0][i] != '1' || lc->map2d[lc->row - 1][i] != '1')
			error_message("Wall error");
		i++;
	}
	i = 0;
	while (i < lc->row)
	{
		if (lc->map2d[i][0] != '1' || lc->map2d[i][lc->column - 1] != '1')
			error_message("Wall error");
		i++;
	}
}

void	is_space(t_struct *lc)
{
	int	i;

	i = 0;
	while (lc->map[i])
	{
		if (lc->map[i] == '\n')
		{
			if (i != 0 && (lc->map[i - 1] != '1' || lc->map[i + 1] != '1'))
				error_message("There is a space on the map");
		}
		i++;
	}
}

void	is_missing(t_struct *lc)
{
	int	i;
	int	a;

	i = 0;
	while (lc->map2d[i])
	{
		a = 0;
		while (lc->map2d[i][a])
			a++;
		if (a != lc->column)
			error_message("There is a problem with the map");
		i++;
	}
}
