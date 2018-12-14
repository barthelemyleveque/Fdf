/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:35:20 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 15:04:05 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_check(const char *base)
{
	int	i;
	int j;

	i = 1;
	if (!base)
		return (0);
	if (ft_strlen(base) < 2)
	{
		ft_putstr("Fail : Your base must have at least 2 char\n");
		return (0);
	}
	while (base[i] != '\0')
	{
		j = -1 + i;
		while (base[++i])
		{
			if (base[i] == base[j])
			{
				ft_putstr("Fail : Your base must have different chars\n");
				return (0);
			}
		}
		i = ++j + 1;
	}
	return (1);
}

static int	ft_maxpow(int nb, int baselen)
{
	int i;

	i = 0;
	nb = (nb < 0) ? nb : -nb;
	while (nb < -baselen)
	{
		nb = nb / baselen;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int nb, const char *base)
{
	size_t	base_len;
	char	*str;
	int		i;
	int		c;
	int		sign;

	if (!(ft_base_check(base)))
		return (NULL);
	base_len = ft_strlen(base);
	i = ft_maxpow(nb, base_len);
	sign = (nb < 0) ? 3 : 2;
	if (!(str = (char*)ft_memalloc(sizeof(char) * i + sign)))
		return (NULL);
	str[0] = '-';
	c = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? nb : -nb;
	while (i >= 0)
	{
		str[c] = base[(nb / -ft_power(base_len, i))];
		nb = nb % ft_power(base_len, i--);
		c++;
	}
	return (str);
}
