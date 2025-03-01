/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:29:45 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/27 18:15:00 by zzerg            ###   ########.fr       */
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

char	ft_count_pos(int nb)
{
	if (nb > 9)
		return ('A' + nb - 10);
	else
		return (nb + '0');
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = (long) nbr;
	if (nb < ft_whatbase(base) && nb >= 0)
	{
		ft_putchar(base[nb]);
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
			ft_putchar('-');
			ft_putnbr_base(-nb, base);
		}
	}
}

int	main(void)
{
	ft_putnbr_base(73775, "{}");
	return (0);
}
