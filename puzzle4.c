/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:51:21 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/03/09 20:20:19 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PZL_SZ 4

/* SET EASIER VALUES IN pzl_map */
// set highest values (PZL_SZ) in pzl_map (view = 1)
void	set_value_n(unsigned int input_grid[4][PZL_SZ], unsigned int pzl_map[PZL_SZ][PZL_SZ])
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	py;
	unsigned int	px;

	py = 0;
	px = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < PZL_SZ)
		{
			if (input_grid[y][x] == 1)
			{
				if (y == 0)
					pzl_map[0][x] = PZL_SZ;
				if (y == 1)
					pzl_map[PZL_SZ - 1][x] = PZL_SZ;
				if (y == 2)
					pzl_map[x][0] = PZL_SZ;
				if (y == 3)
					pzl_map[x][PZL_SZ - 1] = PZL_SZ;
			}
			x++;
		}
		y++;
	}
}

void	set_seq_val(unsigned int input_grid[4][PZL_SZ], unsigned int pzl_map[PZL_SZ][PZL_SZ])
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	px;
	unsigned int	py;
	unsigned int	val;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < PZL_SZ)
		{
			if(input_grid[y][x] == PZL_SZ)
			{
				val = 1;
				if (y == 0)
				{
					py = 0;
					px = x;
					while (py < PZL_SZ)
					{
						pzl_map[py][px] = val;
						py++;
						val++;
					}
				}
				val = 4;
				if (y == 1)
				{
					py = 0;
					px = x;
					while (py < PZL_SZ)
					{
						pzl_map[py][px] = val;
						py++;
						val--;
					}
				}
				val = 1;
				if (y == 2)
				{
					px = 0;
					py = x;
					while (px < PZL_SZ)
					{
						pzl_map[py][px] = val;
						px++;
						val++;
					}
				}
				val = 4;
				if (y == 3)
				{
					px = 0;
					py = x;
					while (px < PZL_SZ)
					{
						pzl_map[py][px] = val;
						px++;
						val--;
					}
				}
			}
			x++;
		}
		y++;
	}
}
