/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:37:41 by smortier          #+#    #+#             */
/*   Updated: 2017/11/24 13:49:22 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		usage(void)
{
	ft_putstr("usage: fillit file\n");
}

static int		ft_sqrt_fillit(int val)
{
	int		i;

	i = 1;
	while (i * i < val)
		i++;
	return (i);
}

static void		ft_show_grid(char **grid, int size, t_tetri *tetri)
{
	int		i;

	while (!ft_fillit(grid, 0, size, tetri))
	{
		size++;
		free(grid);
		grid = ft_fill_grid(size);
	}
	i = -1;
	while (++i < size)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
	}
	free(grid);
}

int				main(int ac, char **av)
{
	char		*str;
	int			**tab;
	t_tetri		*tetriminos;
	int			size;
	char		**grid;

	if (ac != 2)
	{
		usage();
		return (0);
	}
	str = ft_readfile(av[1]);
	if (!(ft_checker(str)) || !str)
	{
		ft_putstr("error\n");
		return (0);
	}
	tab = ft_place_ul(ft_change_n_ret(str, &size));
	free(str);
	tetriminos = ft_fill_list(tab, size);
	size = ft_sqrt_fillit(size * 4);
	grid = ft_fill_grid(size);
	ft_show_grid(grid, size, tetriminos);
	return (0);
}
