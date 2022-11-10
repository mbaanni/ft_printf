/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:20:24 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/10 15:44:33 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_tag(int *i, int *counter)
{
	write(1, "%", 1);
	*i = *i + 1;
	*counter = *counter + 1;
}

void	hexa_p(va_list lst, char *str, int *counter, int *i)
{
	write(1, "0x", 2);
	print_hexa(va_arg(lst, unsigned long int), str[*i + 1], counter);
	*counter = *counter + 2;
}

void	print_it(char *str, va_list lst, int *i, int *counter)
{
	if (str[*i + 1] == 'c' || str[*i + 1] == 's')
	{
		if (str[*i + 1] == 'c')
			ft_putchar(va_arg(lst, int), counter);
		else
			ft_putstr(va_arg(lst, char *), counter);
		*i = *i + 1;
	}
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i' || str[*i + 1] == 'u')
	{
		if (str[*i + 1] == 'u')
			ft_putnbr(va_arg(lst, unsigned int), counter);
		else
			ft_putnbr(va_arg(lst, int), counter);
		*i = *i + 1;
	}
	else if (str[*i + 1] == 'p' || str[*i + 1] == 'x' || str[*i + 1] == 'X')
	{
		if (str[*i + 1] == 'p')
			hexa_p(lst, str, counter, i);
		else
			print_hexa(va_arg(lst, unsigned int), str[*i + 1], counter);
		*i = *i + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		counter;

	counter = 0;
	va_start(lst, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				write_tag(&i, &counter);
			else
				print_it((char *)str, lst, &i, &counter);
		}
		else
		{
			write(1, str + i, 1);
			counter++;
		}
		i++;
	}
	va_end(lst);
	return (counter);
}
