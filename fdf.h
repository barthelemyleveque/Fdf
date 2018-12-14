/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:46:45 by bleveque          #+#    #+#             */
/*   Updated: 2018/12/12 17:58:19 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <fcntl.h>
#include "./libft/libft.h"

typedef	struct	s_adress
{
	void	*mlx;
	void	*win;
}				t_adress;

typedef struct	s_coords
{
	int		x;
	int		y;
	int		z;
}				t_coords;

#endif
