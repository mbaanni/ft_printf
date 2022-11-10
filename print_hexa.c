/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:22:00 by mbaanni           #+#    #+#             */
/*   Updated: 2022/10/27 09:51:03 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(unsigned long int nb, char spec, int *count)
{
	char	*arrxx;
	char	*arrx;

	arrxx = "0123456789ABCDEF";
	arrx = "0123456789abcdef";
	if (nb / 16)
		print_hexa(nb / 16, spec, count);
	if (spec == 'X')
		ft_putchar(arrxx[nb % 16], count);
	else if (spec == 'x' || spec == 'p')
		ft_putchar(arrx[nb % 16], count);
}
