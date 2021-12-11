/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:51:31 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/07 19:53:43 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/bonus_philo.h"

void	print_error(int flag)
{
	if (flag == 1)
		printf("5 or 6 arguments needed\n");
	else if (flag == 2)
		printf("Feed the philosophers at least once\n");
	else if (flag == 3)
		printf("There should be from 1 to 200\n");
	else if (flag == 4)
		printf("Oops, can't allocate memory\n");
	exit (-1);
}
