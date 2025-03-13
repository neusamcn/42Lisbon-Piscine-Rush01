#include <stdio.h>
#include "validate_grid.c"

#define PZL_SZ 4

int unique(unsigned int matrix[PZL_SZ][PZL_SZ], unsigned int row, unsigned int col, unsigned num) 
{
    unsigned int i;
    i = 0;

    while (i < PZL_SZ) 
    {
        if (matrix[row][i] == num)
            return (0);
        i++;
    }
    
    i = 0;
    while (i < PZL_SZ) 
    {
        if (matrix[i][col] == num)
            return (0);
        i++;
    }

    return (1); 
}

int solve(unsigned int matrix[PZL_SZ][PZL_SZ], unsigned int row, unsigned int col) 
{
    if (row == PZL_SZ) 
    {
        return (1);
    }

    if (col == PZL_SZ) 
    {
        return solve(matrix, row + 1, 0);
    }

    if (matrix[row][col] != 0) {
        return solve(matrix, row, col + 1);
    }

    unsigned num;
    num = 1;
    while (num <= PZL_SZ) {
        if (unique(matrix, row, col, num)) 
        {
            matrix[row][col] = num;  
            if (solve(matrix, row, col + 1)) 
            {
                return (1);
            }
            matrix[row][col] = 0;
        }
        num++;
    }

    return (0);
}

void printMatrix(unsigned int matrix[PZL_SZ][PZL_SZ]) 
{
    unsigned int i;
    unsigned int j;

    i = 0;
    while (i < PZL_SZ) 
    {
        j = 0;
        while (j < PZL_SZ) 
        {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}


void findAllSolutions(unsigned int matrix[PZL_SZ][PZL_SZ], unsigned int row, unsigned int col, unsigned int views[PZL_SZ][PZL_SZ]) 
{
    if (row == PZL_SZ) 
    {
	if (validate_grid(matrix, views))
        	printMatrix(matrix);
        printf("\n");
        return;
    }

    if (col == PZL_SZ) 
    {
        findAllSolutions(matrix, row + 1, 0, views);
        return;
    }

    if (matrix[row][col] != 0) 
    {
        findAllSolutions(matrix, row, col + 1, views);
        return;
    }


    unsigned num = 1;
    while (num <= PZL_SZ) 
    {
        if (unique(matrix, row, col, num)) 
        {
            matrix[row][col] = num; 
            findAllSolutions(matrix, row, col + 1, views);
            matrix[row][col] = 0;
        }
        num++;
    }
}

/*
int main() {
    unsigned int matrix[PZL_SZ][PZL_SZ] = {
        {0, 0, 0, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {4, 0, 0, 0}
    };

    printf("All plausible solutions:\n");
    findAllSolutions(matrix, 0, 0);

    return 0;
}
    */
