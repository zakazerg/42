/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:35:27 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/27 20:59:18 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_whatbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if (!(base[i] == '+' || base[i] == '-'))
		{
			while (base[j] != '\0')
			{
				if (base[j] == base[i] && !(i == j))
					return (0);
				j++;
			}
			i++;
		}
		else
			return (0);
	}
	return (i);
}

int	check_base(char *str, char *base, int i)
{
        int     n;

        while (str[i] != '\0')
        {
		n = 0;
		while (str[i] != base[n] && base[n] != '\0')
		{
			n++;
		}
		if (base[n] == '\0')
			return (i);
		else
			i++;
	}
	return (i);
}

int	ft_count_pos(char nb, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (nb == base[i])
			return (i);
		else
			i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	va;

	i = 0;
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i] != '\0')
		{
			if ((str[i] == '\n' || str[i] == '\r') || (str[i] == '\t' || str[i] == '\v'))
				i++;
			if (str[i] == ' ' || str[i] == '\f')
				i++;
		       	if (str[i] == '-' || str[i] == '+')
			{
				if (str[i] == '-')
				{
					n++;
					i++;
				}
				else
					i++;
			}
		}
		if (check_base(str, base, i) == i)
			return (0);
		va = 0;
		while (str[i] != str[check_base(str, base, i)])
		{
			va = va * ft_whatbase(base) + ft_count_pos(str[i] , base);
			i++;
		}
		if (n % 2 == 1)
			va = va * (-1);
	}	

	return (va);
}

int	main(void)
{
	printf("%i", ft_atoi_base("----npef15w", "poneyvif"));
	return(0);
}

