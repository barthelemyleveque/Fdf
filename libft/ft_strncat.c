/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:26:21 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/11 16:02:33 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s1[i])
		i++;
	while (s2[c] && c < n)
	{
		if (&s1[i] == &s2[i])
			return ((void*)0);
		s1[i] = s2[c];
		i++;
		c++;
	}
	s1[i] = '\0';
	return (s1);
}
