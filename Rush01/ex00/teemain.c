/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:42:41 by tanukool          #+#    #+#             */
/*   Updated: 2022/05/08 17:39:45 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_free(int **rolcol, int **table);
int		check_error(int argc, char **argv, int i);
int		fill_square(int **board, int row, int col, int **views);
void	ft_putnbr(int nb);
//void	put_min_to_max(int **table, int max, int **rolcol);
void	ft_case(int **table, int max, int **rolcol);
void	put_min(int **table, int max, int **rolcol);
void	input_array(char **argv, int **rolcol, int **table, int i);
void	set_zero(int **zero, int i);
//void	show_table(int **table, int i);

int	array(char **argv)
{
	int		i;

	i = 0;
	if (argv[1][0] >= '0' && argv[1][0] <= '9')
	{
		i++;
	}
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == ' ' && argv[1][i + 1] >= '0' \
				&& argv[1][i + 1] <= '9')
			i += 2;
		else
		{
			return (-1);
		}
	}
	i = (i / 2) + 1;
	return (i);
}

void	is_table(int i, int j, int max, int **table)
{
	int	c;
	int	k;

	k = 0;
	c = 1;
	if (i == 0)
		while (k < max / 4)
			table[k++][j] = c++;
	if (i == 1)
		while (k < max / 4)
			table[(max / 4) - 1 - k++][j] = c++;
	if (i == 2)
		while (k < max / 4)
			table[j][k++] = c++;
	if (i == 3)
		while (k < max / 4)
			table[j][max / 4 - 1 - k++] = c++;
}

void	put_min_to_max(int **table, int max, int **rolcol)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (max / 4))
	{
		j = -1;
		while (++j < (max / 4))
		{
			is_table(i, j, max, table);
			if (rolcol[i][j] == (max / 4))
			{
				is_table(i, j, max, table);
			}
		}
	}
}

int	ft_run(int **rolcol, int **table, char **argv, int i)
{
	int	**zero;
	int	j;

	j = -1;
	zero = malloc((i / 4) * sizeof(int *));
	while (++j < (i / 4))
	{
		zero[j] = malloc((i / 4) * sizeof(int));
	}
	set_zero(zero, i);
	input_array(argv, rolcol, table, i);
	put_min_to_max(table, i, rolcol);
	put_min(table, i, rolcol);
	fill_square(zero, 0, 0, rolcol);
	if (rolcol[0][0] != -1)
	{
		write(1, "No solution.", 12);
		return (-1);
	}
	ft_free(rolcol, table);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	**rolcol;
	int	**table;

	if (argc != 2)
	{
		write(1, "Input error!", 12);
		return (0);
	}
	i = array(argv);
	if (check_error(argc, argv, i) == -1)
		return (0);
	j = -1;
	rolcol = malloc((i / 4) * sizeof(int *));
	table = malloc((i / 4) * sizeof(int *));
	while (++j < (i / 4))
	{
		rolcol[j] = malloc((i / 4) * sizeof(int));
		table[j] = malloc((i / 4) * sizeof(int));
	}
	ft_run(rolcol, table, argv, i);
	return (0);
}
