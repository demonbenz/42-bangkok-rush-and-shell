/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:25:32 by tanukool          #+#    #+#             */
/*   Updated: 2022/05/08 17:10:41 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**copy_board(int **board, int size);
void	print_board(int **board, int size, int **views);
void	free_board(int **board, int size);
int		h_unique(int **board, int size);
int		v_unique(int **board, int size);

void	next_row_col(int row, int col, int *next_row, int *next_col)
{
	*next_col = (col + 1) % 4;
	if (col == 3)
		*next_row = row + 1;
	else
		*next_row = row;
}

int	count(int nums[], int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[j] != 0)
				nums[j] = nums[j] * (nums[i] < nums[j]);
			j++;
		}
		i++;
	}
	i = 0;
	count = 0;
	while (i < size)
	{
		if (nums[i++] != 0)
			count++;
	}
	return (count);
}

int	count_view(int	**board, int row, int col, int direction)
{
	int	i;
	int	nums[4];
	int	start;
	int	size;

	i = 0;
	size = 4;
	if (direction < 0)
		start = size;
	else
		start = -1;
	while (i < size)
	{
		start += direction;
		if (row > -1)
			nums[i++] = board[row][start];
		else
			nums[i++] = board[start][col];
	}
	return (count(nums, size));
}

int	is_valid_board(int **board, int size, int **view)
{
	int	i;
	int	is_unique;

	i = 0;
	is_unique = (h_unique(board, size) && v_unique(board, size));
	while (i < size)
	{
		if (!(count_view(board, i, -1, 1) == view[2][i] && \
				count_view(board, i, -1, -1) == view[3][i] && \
				count_view(board, -1, i, 1) == view[0][i] && \
				count_view(board, -1, i, -1) == view[1][i] \
				) || !is_unique)
			return (0);
		i++;
	}
	return (1);
}

void	fill_square(int **board, int row, int col, int **views)
{
	int	next_row;
	int	next_col;
	int	**next_board;
	int	value;

	value = 1;
	if (row == 4 && col == 0)
	{
		if (is_valid_board(board, 4, views))
		{
			print_board(board, 4, views);
		}
	}
	else
	{
		next_row_col(row, col, &next_row, &next_col);
		while (value <= 4)
		{
			next_board = copy_board(board, 4);
			next_board[row][col] = value++;
			if (h_unique(next_board, 4) && v_unique(next_board, 4))
				(fill_square(next_board, next_row, next_col, views));
			free_board(next_board, 4);
		}
	}
}
/*
int	main(void)
{
	int	a[][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 2, 2, 3}	
	};

	int	b[][4] = {
		{1, 2, 3, 4},
		{2, 4, 1, 3},
		{4, 3, 2, 1},
		{3, 1, 4, 2}
	};


	int	empty[][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	int	v[][4] = {
		{4, 3, 2, 1},
		{1, 2, 2, 2},
		{4, 3, 2, 1},
		{1, 2, 2, 2}
	};
	int	v1[][4] = {
		{3, 2, 2, 1},
		{2, 3, 1, 3},
		{4, 2, 1, 2},
		{1, 2, 4, 2}
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
			in[i][j] = empty[i][j];
			views[i][j] = v1[i][j];
			j++;
		}
		i++;
	}
	fill_square(in, 0, 0, views);
	free_board(in, 4);
	free_board(views, 4);
}
*/
