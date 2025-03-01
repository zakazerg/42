/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:25:47 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/26 00:21:02 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	l = ft_strlen(src)
	if (size == 0)
		return (l)
	i = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[i] = '\0'
	return (l);
}

