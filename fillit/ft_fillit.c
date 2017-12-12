/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:11:59 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/24 13:30:17 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_place_t(char **grid, int pos, int size, t_tetri *tetri)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = -1;
	x = pos / size;
	y = pos % size;
	while (++i < 4 && grid[x + i])
	{
		j = -1;
		while (++j < 4 && grid[x + i][y + j])
			if (ft_isalpha(tetri->tetri[i][j]))
				grid[x + i][y + j] = tetri->tetri[i][j];
	}
	tetri->placed = 1;
}

static void	ft_clear_grid(char **grid, int pos, int size, t_tetri *tetri)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = pos / size;
	y = pos % size;
	i = -1;
	while (tetri->prev && tetri->placed == 0)
		tetri = tetri->prev;
	if (tetri->placed == 1)
	{
		tetri->placed = 0;
		while (++i < 4 && grid[x + i])
		{
			j = -1;
			while (++j < 4 && grid[x + i][y + j])
				if (tetri->tetri[i][j] != '.')
					grid[x + i][y + j] = '.';
		}
	}
	tetri->placed = 0;
}

static int	ft_check_p(char **grid, int pos, int size, t_tetri *tetri)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		check;

	x = pos / size;
	y = pos % size;
	i = -1;
	check = 0;
	while (++i < 4 && grid[x + i])
	{
		j = -1;
		while (++j < 4 && grid[x + i][y + j])
			if (ft_isalpha(tetri->tetri[i][j]) && grid[x + i][y + j] == '.')
				check++;
	}
	if (check != 4)
		return (0);
	return (1);
}

static int	ft_check_g(t_tetri *tetri)
{
	t_tetri	*prev;

	prev = tetri;
	while (tetri->next)
		tetri = tetri->next;
	while (tetri)
	{
		if (tetri->placed == 0)
			return (0);
		tetri = tetri->prev;
	}
	tetri = prev;
	return (1);
}

int			ft_fillit(char **grid, int pos, int size, t_tetri *tetri)
{
	if (ft_check_g(tetri))
		return (1);
	if (pos > (size * size) - 4)
		return (0);
	if (ft_check_p(grid, pos, size, tetri))
	{
		ft_place_t(grid, pos, size, tetri);
		if (tetri->next)
			if (ft_fillit(grid, 0, size, tetri->next))
				return (1);
			else
				ft_clear_grid(grid, pos, size, tetri);
		else
			return (1);
	}
	return (ft_fillit(grid, pos + 1, size, tetri));
}
