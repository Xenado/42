/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:30:07 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/23 12:45:32 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_fill_grid(int size)
{
	char	**grid;
	int		i;
	int		i2;

	if (!(grid = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		if (!(grid[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
	grid[i] = NULL;
	i = -1;
	while (++i < size)
	{
		i2 = -1;
		while (++i2 < size)
			grid[i][i2] = '.';
		grid[i][i2] = '\0';
	}
	return (grid);
}
