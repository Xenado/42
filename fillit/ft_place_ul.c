/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_ul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:14:39 by smortier          #+#    #+#             */
/*   Updated: 2017/11/24 15:46:20 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_place_ul(int **tab)
{
	int		i;
	int		y;
	int		tmp;

	i = -1;
	tmp = 0;
	while (tab[++i])
	{
		y = -1;
		tmp = tab[i][0] % 5;
		while (++y < 4)
			tmp = ((tab[i][y] % 5) < tmp) ? tab[i][y] % 5 : tmp;
		y = -1;
		while (++y < 4)
			tab[i][y] -= tmp;
		while (tab[i][0] > 4)
		{
			y = -1;
			while (++y < 4)
				tab[i][y] -= 5;
		}
	}
	return (tab);
}
