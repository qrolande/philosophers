/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:17:57 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/05 13:32:06 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	pre_parsing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
		{
			printf("Error: '%s' is invalid argument\n", str);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	ft_isdigit(int c)
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
	if (pre_parsing(str) == -1)
		return (-1);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i++] - '0';
	}
	if (num > MAX_INT)
	{
		printf("%s - is greater that MAX_INT.\n", str);
		return (-1);
	}
	return ((int)num);
}
