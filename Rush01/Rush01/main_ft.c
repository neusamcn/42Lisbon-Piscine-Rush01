/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:58:25 by mateferr          #+#    #+#             */
/*   Updated: 2025/03/09 21:35:02 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "begin.c"
#include "verifications.c"
#include "solve.c"
#include "puzzle4.c"
#include "validate_grid.c"

int     main(int argc, char *argv[])
{
        char            *views;
        unsigned int    matrix[4][4];
        unsigned int    pzlMap[4][4];

        if(error(argv[1]))
                return (0);


        views = ft_str(argv[1]);



        ft_rows_columns(matrix, views);

        create_matrix(pzlMap);

        set_seq_val(matrix, pzlMap);
        set_value_N(matrix, pzlMap);


        findAllSolutions(pzlMap, 0, 0, matrix);

}


