/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:22:41 by smortier          #+#    #+#             */
/*   Updated: 2017/11/24 15:45:43 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_column(char *str)
{
	int		column;

	column = 0;
	while (*str)
	{
		while (*str != '\n' && *str)
		{
			column += 1;
			str++;
		}
		if (column == 0)
			column = 4;
		if (column != 4)
			return (0);
		column = 0;
		if (*str)
			str++;
	}
	return (1);
}

static int	check_line(char *str)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	while (*str)
	{
		while (ft_strncmp(str, "\n\n", 2) && *str)
		{
			str++;
			line += 1;
		}
		if (line != 19 && line != 20)
			return (0);
		line = -1;
		if (*str)
			str++;
	}
	return (1);
}

static int	check_char(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
	}
	return (1);
}

static int	check_tetri(char *str)
{
	int		nb_hash;
	int		link_hash;

	link_hash = 0;
	while (*str)
	{
		nb_hash = 0;
		while (ft_strncmp(str, "\n\n", 2) && *str)
		{
			if (*str == '#')
			{
				nb_hash++;
				link_hash = (*(str + 5) == *str) ? link_hash += 1 : link_hash;
				link_hash = (*(str + 1) == *str) ? link_hash += 1 : link_hash;
			}
			str++;
			if (link_hash < 3 && nb_hash > 3)
				return (0);
		}
		if (nb_hash != 4)
			return (0);
		link_hash = 0;
		str = (*str) ? str += 1 : str;
	}
	return (1);
}

int			ft_checker(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (0);
	if (!(check_column(str)))
		return (0);
	if (!(check_line(str)))
		return (0);
	if (!(check_char(str)))
		return (0);
	if (!(check_tetri(str)))
		return (0);
	return (1);
}
