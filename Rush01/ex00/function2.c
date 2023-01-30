/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:30:11 by tanukool          #+#    #+#             */
/*   Updated: 2022/05/08 17:39:31 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		array(char **argv);
void	set_zero(int **zero, int i);

void	put_min(int **table, int max, int **rolcol)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (max / 4))
	{
		j = -1;
		while (++j < (max / 4))
		{
			if (rolcol[i][j] == 1)
			{
				if (i == 0)
					table[0][j] = (max / 4);
				if (i == 1)
					table[max / 4 - 1][j] = (max / 4);
				if (i == 2)
					table[j][0] = (max / 4);
				if (i == 3)
					table[j][max / 4 - 1] = (max / 4);
			}
		}
	}
}

int	check_error(int argc, char **argv, int i)
{
	if (argc != 2)
	{
		write(1, "input error!\n", 13);
		return (-1);
	}
	if (array(argv) == -1)
	{
		write(1, "input error!\n", 13);
		return (-1);
	}
	if (i % 4 != 0)
	{
		write(1, "input error!\n", 13);
		return (-1);
	}
	return (0);
}

void	ft_case(int **table, int max, int **rolcol)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < max / 4)
	{
		j = -1;
		while (++j < max / 4)
		{
			if (rolcol[0][j] == (max / 2) - 1 \
					&& rolcol[1][j] == (max / 2) + 1)
				table[max / 2 - 1][j] = max;
			if (rolcol[1][j] == (max / 2) + 1 \
					&& rolcol[0][j] == (max / 2) - 1)
				table[max / 2 + 1][j] = max;
			if (rolcol[2][j] == (max / 2) - 1 \
					&& rolcol[j][3] == (max / 2) + 1)
				table[max / 2 - 1][j] = max;
			if (rolcol[3][j] == (max / 2) + 1 \
					&& rolcol[2][j] == (max / 2) - 1)
				table[j][max / 2 + 1] = max;
		}
	}
}
