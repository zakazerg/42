/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:27:13 by zzerg             #+#    #+#             */
/*   Updated: 2025/03/03 04:57:13 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return(s1[i] - s2[i]);
}

void ft_sort_int_tab(char **tab, int size)
{
	int i;
	int n;
	char* tmp;
	int z;

	z = 1;
	while (z <= size)
	{
		i = 0;
		while (i <= size - 1)
		{
			n = i;
			while (ft_strcmp(tab[i], tab[n]) == 0 && n < size - 1)
			{
				n++;
			}
			if (ft_strcmp(tab[i], tab[n]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[n];
				tab[n] = tmp;
			}
			i++;
		}
		z++;
	}
}

int main(int argc, char *argv[])
{
	int i;

	argc = argc - 1;
	argv++;
	ft_sort_int_tab(argv, argc);
	i = 0;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}	
