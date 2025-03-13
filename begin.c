/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:30:26 by mateferr          #+#    #+#             */
/*   Updated: 2025/03/09 16:43:16 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str(char *str)
{
	int		i;
	int		j;
	char	*str2;

	str2 = malloc(16);
	i = 0;
	j = 0;
	while (j < 16)
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

void	ft_rows_columns(unsigned int rc[4][4], char *str)
{
	int	i;
	int	j;
	int	k;
	
	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			rc[i][j] = str[k] - '0';
		
			j++;
			k++;	
		}
		
		i++;
	}
	free(str);
}

void	create_matrix(unsigned int rc[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			rc[i][j] = 0;
			j++;
		}
		i++;
	}
}

