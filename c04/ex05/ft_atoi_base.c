/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:44:03 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/27 17:04:57 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int ft_convert(int nb, char *base)
{
	static int	v;
	int	nbr;

	nbr = nb;
	if (nb < 0)
		nbr = nb * (-1);
	if (nbr < ft_whatbase(base) && nbr >= 0)
	{
                        v = v * 10 + nbr;
	}
	else
	{
		if (nbr >= ft_whatbase(base))
		{
			ft_convert(nbr / ft_whatbase(base), base);
			ft_convert(nbr % ft_whatbase(base), base);
		}
	}
	if (nb < 0)
		v = v * (-1);
	return (v);

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
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				n++;
				i++;
		}
		va = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			va = va * 10 + (str[i] - '0');
			i++;
		}
		if (n % 2 == 1)
			va = va * (-1);
	}	

	return (ft_convert(va, base));
}

int	main(void)
{
	printf("%i", ft_atoi_base("----7456ssc", "poneyvif"));
	return(0);
}
