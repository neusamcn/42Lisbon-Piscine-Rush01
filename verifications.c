/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:26:20 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/03/09 20:25:02 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(char *input_string)
{
	unsigned int	i;

	i = 0;
	while (input_string[i] != '\0')
		i++;
	if (i != 31)
		return (1);
	i = 0;
	while (input_string[i] != '\0' && i <= 30)
	{
		if (input_string[i] < '1' || input_string[i] > '4')
			return (1);
		i += 2;
	}
	i = 0;
	while (i < 15)
	{
		if (input_string[i] != input_string[i + 16])
			return (1);
		i += 2;
	}
	return (0);
}
