/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:56:29 by mbaanni           #+#    #+#             */
/*   Updated: 2022/11/10 15:16:12 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	if (str == 0)
		str = "(null)";
	write(1, str, ft_strlen(str));
	*counter = *counter + ft_strlen(str);
}
