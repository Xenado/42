/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:01:40 by smortier          #+#    #+#             */
/*   Updated: 2017/11/24 15:47:13 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_readfile(char *av)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;
	char	*str;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		i += ret;
	}
	close(fd);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	fd = open(av, O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_strcat(str, buf);
	}
	return (str);
}
