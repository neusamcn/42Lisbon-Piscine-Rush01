/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:09:51 by mateferr          #+#    #+#             */
/*   Updated: 2025/03/09 21:14:01 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	validate_grid(unsigned int matrix[4][4], unsigned int views[4][4])
{
	int	c;
	int	l;
	int	count;
	
	c = 0;
	l = 0;
	count = 1;
	while (c <= 3)
	{
		while (l <= 2 && matrix[l][c] != 4)
		{
			if (matrix[l][c] < matrix[l + 1][c])
				count++;
			l++;
		}
		if (count != views[0][c])
		{
			printf("1. %d, %d, %d\n", count, l ,c);
			return (0);
		}
		l = 0;
		count = 1;
		c++;
	}
	
	l = 0;
	c = 0;
	while (l <= 3)
	{
		while (c <= 2 && matrix[l][c] != 4)
		{
			if (matrix[l][c] < matrix[l][c + 1])
				count++;
			c++;
		}
		if (count != views[2][l])
		{
			printf("2. %d, %d, %d\n", count, l ,c);
			return (0);
		}
		count = 1;
		l++;
		c = 0;
	}
	return (1);
}
