/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:11:55 by smortier          #+#    #+#             */
/*   Updated: 2017/11/24 15:46:43 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 5

typedef struct		s_tetri
{
	int				placed;
	char			**tetri;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

char				**ft_fill_grid(int size);

int					ft_fillit(char **grid, int pos, int size, t_tetri *tetri);

char				*ft_readfile(char *av);

int					ft_checker(char *str);

int					**ft_change_n_ret(char *str, int *size_grid);

int					**ft_place_ul(int **tab);

t_tetri				*ft_fill_list(int **tab, int size);

#endif
