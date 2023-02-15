/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imittous <imittous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:43:22 by imittous          #+#    #+#             */
/*   Updated: 2023/02/14 06:43:27 by imittous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ns1;
	const unsigned char	*ns2;
	int					i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	ns1 = (const unsigned char *)s1;
	ns2 = (const unsigned char *)s2;
	while (ns1[i] && ns2[i] && ns1[i] == ns2[i])
		i++;
	return (ns1[i] - ns2[i]);
}
