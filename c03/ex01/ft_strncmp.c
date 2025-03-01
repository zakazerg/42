/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:32:28 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/25 21:35:09 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] < s2[i])
				return (-1);
			else if (s1[i] == s2[i])
				return (0);
			else
				return (1);
			i++;
		}
	}
}
