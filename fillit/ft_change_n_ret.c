/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_n_ret.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:58:05 by smortier          #+#    #+#             */
/*   Updated: 2017/11/23 19:12:35 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_size_tab(char *str)
{
	int		size_tab;

	size_tab = 0;
	while (*str)
	{
		while (ft_strncmp(str, "\n\n", 2) && *str)
			str++;
		size_tab += 1;
		str = (*str) ? str += 1 : str;
	}
	return (size_tab);
}

int				**ft_change_n_ret(char *str, int *size_grid)
{
	int		**tab;
	int		i;
	int		y;
	int		pos;

	i = 0;
	*size_grid = ft_size_tab(str);
	tab = (int **)ft_memalloc(sizeof(int *) * (*size_grid + 1));
	tab[*size_grid] = NULL;
	while (*str)
	{
		pos = 0;
		y = -1;
		tab[i] = (int *)ft_memalloc(sizeof(int) * 4);
		while (ft_strncmp(str, "\n\n", 2) && *str)
		{
			if (*str == '#')
				tab[i][++y] = pos;
			str++;
			pos++;
		}
		i++;
		str = (*str) ? str += 2 : str;
	}
	return (tab);
}
