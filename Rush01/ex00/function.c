/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:28:15 by tanukool          #+#    #+#             */
/*   Updated: 2022/05/08 17:35:42 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nbr);

void	input_array(char **argv, int **rolcol, int **table, int i)
{
	int	j;
	int	k;
	int	n;

	j = -1;
	k = 0;
	while (++j < i / 4)
	{
		n = 0;
		while (n < (i / 4))
		{
			rolcol[j][n] = (int)(argv[1][k] - '0');
			table[j][n] = 0;
			k += 2;
			n++;
		}
	}
}

void	set_zero(int **zero, int i)
{
	int	j;
	int	n;

	j = -1;
	while (++j < i / 4)
	{
		n = 0;
		while (n < (i / 4))
		{
			zero[j][n] = 0;
			n++;
		}
	}
}

void	show_table(int **table, int i)
{
	int	j;
	int	k;

	j = -1;
	while (++j < (i / 4))
	{
		k = 0;
		while (k < (i / 4))
		{
			ft_putnbr(table[j][k]);
			write(1, " ", 1);
			k++;
		}
		write(1, "\n", 1);
	}
}

void	ft_free(int **rolcol, int **table)
{
	int	j;

	j = -1;
	while (++j)
	{
		free(rolcol[j]);
		free(table[j]);
	}
	free(rolcol);
	free(table);
}
