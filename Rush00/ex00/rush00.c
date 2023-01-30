/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:15:51 by otangkab          #+#    #+#             */
/*   Updated: 2022/05/01 15:53:00 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char a);

int	ft_line(int yy, int xx, int x, int y)
{
	if (xx == 0 || xx == x -1 || yy == 0 || yy == y - 1)
	{
		if ((xx == 0 && yy == 0) || (xx == x - 1 && yy == y -1))
		{
			ft_putchar('o');
		}
		else if ((xx == 0 && yy == y - 1) || (xx == x - 1 && yy == 0))
		{
			ft_putchar('o');
		}
		else if ((yy == 0 && yy == y - 1) || (xx >= 1 && xx < x - 1))
		{
			ft_putchar('-');
		}
		else
		{
			ft_putchar('|');
		}
	}
	else
	{
		ft_putchar(' ');
	}
	return (0);
}

void	rush(int x, int y)
{
	int	x_col;
	int	y_row;

	y_row = 0;
	while (y_row < y)
	{
		x_col = 0;
		while (x_col < x)
		{
			ft_line(y_row, x_col, x, y);
			x_col++;
		}
		ft_putchar('\n');
		y_row++;
	}
}
