/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:15:32 by mbaanni           #+#    #+#             */
/*   Updated: 2022/10/27 08:33:57 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int nb, int *count)
{
	char	c;

	c = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		*count = *count + 1;
		nb = nb * -1;
	}
	if (nb / 10)
		ft_putnbr(nb / 10, count);
	c = nb % 10 + 48;
	*count = *count + 1;
	write(1, &c, 1);
}
