/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:40:22 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 12:01:02 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	if (nb == 1)
		return (1);
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (nb * ft_power(nb, power - 1));
}
