/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:32:27 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/26 15:55:44 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	v;

	i = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				n++;
				i++;
		}
		v = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			v = v * 10 + (str[i] - '0');
			i++;
		}
		if (n % 2 == 1)
			v = v * (-1);
		return (v);
	}	
}

/*int	main(void)
{
	printf("%i", ft_atoi("---75123dfss"));
	return (0);
}*/
