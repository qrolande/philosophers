/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:17:57 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/23 20:50:23 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	modif_atoi(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		num = num * 10 + str[i++] - '0';
	if (num > MAX_INT)
	{
		printf("%s - is greater that MAX_INT.\n", str);
		return (-1);
	}
	else if (num <= 0)
	{
		printf("Error: invalid argument\n");
		return (-1);
	}
	return ((int)num);
}
