/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:10:56 by smortier          #+#    #+#             */
/*   Updated: 2017/11/23 19:35:13 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_newtetri(t_tetri *tetri)
{
	t_tetri		*newtetri;
	int			i;

	i = -1;
	if (!(newtetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	newtetri->next = NULL;
	newtetri->prev = tetri;
	if (!(newtetri->tetri = malloc(sizeof(char *) * 5)))
		return (NULL);
	while (++i < 4)
	{
		if (!(newtetri->tetri[i] = malloc(sizeof(char) * 5)))
			return (NULL);
	}
	return (newtetri);
}

static int		ft_check_t(int **tab, int i, int i1, int i2)
{
	int		x;

	x = -1;
	while (++x < 4)
	{
		if (tab[i][x] / 5 == i1 && tab[i][x] % 5 == i2)
			return (1);
	}
	return (0);
}

static t_tetri	*ft_fill_r(char ***str, int size_tab)
{
	t_tetri		*tetriminos;
	t_tetri		*start;
	int			i;

	i = -1;
	tetriminos = ft_newtetri(NULL);
	start = tetriminos;
	while (++i < size_tab)
	{
		tetriminos->tetri = str[i];
		tetriminos->placed = 0;
		if (i != size_tab - 1)
		{
			tetriminos->next = ft_newtetri(tetriminos);
			tetriminos = tetriminos->next;
		}
	}
	return (start);
}

t_tetri			*ft_fill_list(int **tab, int size)
{
	char	***str;
	int		i;
	int		i1;
	int		i2;

	i = -1;
	str = ft_memalloc(sizeof(char **) * size);
	while (++i < size && str)
	{
		i1 = -1;
		str[i] = ft_memalloc(sizeof(char *) * 5);
		while (++i1 < 4 && str[i])
		{
			i2 = -1;
			str[i][i1] = ft_memalloc(sizeof(char) * 5);
			while (++i2 < 4 && str[i][i1])
				str[i][i1][i2] = (ft_check_t(tab, i, i1, i2)) ? 'A' + i : '.';
			str[i][i1] ? str[i][i1][i2] = '\0' : 0;
		}
		str[i][i1] = NULL;
	}
	return (ft_fill_r(str, size));
}
