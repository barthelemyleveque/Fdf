/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:06:52 by bleveque          #+#    #+#             */
/*   Updated: 2018/12/12 20:10:41 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		deal_key(int key, void *ptr)
{
	int 	x;
	int 	y;
	char	*str;
	t_adress	*matrix;

	matrix = ptr;
	str = "Ah c'est marrant";
	x = 10;
	y = 10;
	mlx_string_put(matrix->mlx, matrix->win, 250, 250, 0250000000, str);
	while (y <= 100)
	{
		x = 10;
		while (x <= 100)
		{
			mlx_pixel_put(matrix->mlx, matrix->win, x, y, 0000250000);
			x++;
		}
		y++;
	}
	ft_putnbr(key);
	return (0);
}

t_coords	*get_line_coords(t_coords **allcoords, char *line, int nb)
{
	int i;




t_coords	**get_all_coords(int fd)
{
	char 		*line;
	//int			ret;
	t_coords	**all_coords;
	int			i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(allcoords = (t_coords**)malloc(sizeof(t_coords*) * i + 1)))
			return (NULL);
		if (!(allcoords[i] = (t_coords*)malloc(sizeof(t_coords))))
			return (NULL);
		all_coords[i] = get_line_coord(allcoords, line, i);
		free(line);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_adress	*matrix;
	t_coords	**coords;
	int			fd;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx Barth");
	if (!(matrix = (t_adress*)malloc(sizeof(t_adress))))
		return (0);
	matrix->mlx = mlx_ptr;
	matrix->win = win_ptr;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		coords = get_all_coords(fd);
	}
	mlx_key_hook(win_ptr, deal_key, (void*)matrix);
	mlx_loop(mlx_ptr);
	return (0);
}
