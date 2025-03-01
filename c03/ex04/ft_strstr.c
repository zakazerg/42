/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzerg <zzerg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:31:41 by zzerg             #+#    #+#             */
/*   Updated: 2025/02/25 23:00:17 by zzerg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	
	i = 0;
	if (!to_find[0])
		return str;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
			j++;
		if (!to_find[j])
			return (str + i);
		i++;
	}
	return ((void *)0);
}

int	main()
{
	char	test[] = "je suis mohamedgdsfgdfhfgjdghdjgh";
	char	find[] = "suis";
	printf("%s", ft_strstr(test, find));

}
