/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:18:42 by tanukool          #+#    #+#             */
/*   Updated: 2022/05/08 17:14:34 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

int	**copy_board(int **board, int size)
{
	int	i;
	int	j;
	int	**new_board;

	i = 0;
	new_board = malloc(size * sizeof(int *));
	while (i < size)
	{
		j = 0;
		new_board[i] = malloc(size * sizeof(int));
		while (j < size)
		{
			new_board[i][j] = board[i][j];
			j++;
		}
		i++;
	}
	return (new_board);
}

void	print_board(int **board, int size, int **views)
{
	int	i;
	int	j;

	i = 0;
	views[0][0] = -1;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(board[i][j] + '0');
			if (j != size - 1)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}

void	free_board(int **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(board[i++]);
	free(board);
}

int	h_unique(int **board, int size)
{
	int	a[4];
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 4)
			a[j] = 0;
		j = -1;
		while (++j < size)
		{
			if (board[i][j] != 0)
			{
				a[board[i][j] - 1]++;
				if (a[board[i][j] - 1] > 1)
					return (0);
			}
		}	
	}
	return (1);
}

int	v_unique(int **board, int size)
{
	int	a[4];
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 4)
			a[j] = 0;
		j = -1;
		while (++j < size)
		{
			if (board[j][i] != 0)
			{
				a[board[j][i] - 1]++;
				if (a[board[j][i] - 1] > 1)
					return (0);
			}
		}	
	}
	return (1);
}
/*
int	main(void)
{
	int	a[][4] = {
		{1, 2, 3, 4},
		{2, 4, 1, 3},
		{4, 3, 2, 1},
		{3, 1, 4, 2}
	};
	int	v[][4] = {
		{4, 3, 2, 1},
		{1, 2, 2, 2},
		{4, 3, 2, 1},
		{1, 2, 2, 2}
	};

	int	**in = malloc(4 * sizeof(int *));
	int	**views = malloc(4 * sizeof(int *));
	int	i = 0;
	int	j = 0;
	while (i < 4)
	{
		in[i] = malloc(4 * sizeof(int));
		views[i] = malloc(4 * sizeof(int));
		j = 0;
		while (j < 4)
		{
			in[i][j] = a[i][j];
			views[i][j] = v[i][j];
			j++;
		}
		i++;
	}

	printf("%d\n", h_unique(in, 4) && v_unique(in, 4));
	free_board(in, 4);
	free_board(views, 4);
}
*/
