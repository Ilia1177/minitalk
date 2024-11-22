/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:59:54 by npolack           #+#    #+#             */
/*   Updated: 2024/10/18 10:22:29 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_hex(unsigned int n, int maj)
{
	int	len;

	len = get_intlen(n, 16);
	if (maj)
		ft_putnb_base(n, "0123456789ABCDEF");
	else
		ft_putnb_base(n, "0123456789abcdef");
	return (len);
}