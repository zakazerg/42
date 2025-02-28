/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:41:54 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/22 19:29:23 by zzerg            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rush(int x, int y)
{
	int colonnes;
	int lignes;

	if (x == 0 || y == 0)
	{
		return;
	}
	lignes= 1;
	while (lignes<= y)
	{
		colonnes= 1;
		while (colonnes<= x)
		{
			if ((colonnes>1 && colonnes<x)&&(lignes==1 || lignes==y))
			{
				ft_putchar('-');
			}
			else if ((colonnes>1 && colonnes<x)&&(lignes>1 && lignes<y))
			{
				ft_putchar(' ');
			}
			else if ((colonnes==1 || colonnes==x)&&(lignes>1 && lignes<y))
			{
				ft_putchar('|');
			}
			else
			{
				ft_putchar('o');
			}colonnes++;
		}lignes++;
		ft_putchar('\n');
	}
}

int main(void)
{
	rush(4, 5);
	return (0);
}
