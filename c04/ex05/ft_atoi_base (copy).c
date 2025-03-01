/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base (copy).c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:44:03 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/27 18:29:09 by zzerg            ###   ########.fr       */
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

char    *ft_putnbr_base(int nbr, char *base)
{
        long    nb;
	char	*strin;
	static int i;

        nb = (long) nbr;
        if (nb < ft_whatbase(base) && nb >= 0)
        {

		if (nb > 9)
		{
			strin[i] = (nb / 10 + '0');
			i++;
			strin[i] = (nb % 10 + '0');
			i++;
		}
		else
                	strin[i] = (nb);
			i++;
        }
        else
        {
                if (nb >= ft_whatbase(base))
                {
                        ft_putnbr_base(nb / ft_whatbase(base), base);
                        ft_putnbr_base(nb % ft_whatbase(base), base);
                }
                else
                {
                        strin[i] = ('-');
			i++;
                        ft_putnbr_base(-nb, base);
                }
        }
	return (strin);
}


int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	va;

	str = ft_putnbr_base(str, base);
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

	return (ft_atoi_base(ft_putnbr_base(va, base), base));
}

int	main(void)
{
	printf("%d", ft_atoi_base("----7456ssc", "poneyvif"));
	return(0);
}
