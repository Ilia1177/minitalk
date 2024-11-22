/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:57:34 by npolack           #+#    #+#             */
/*   Updated: 2024/10/23 10:57:37 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_intlen(long long n, int baselen)
{
	long long	num;
	int			len;

	len = 1;
	num = n;
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= baselen)
	{
		len++;
		num = num / baselen;
	}
	return (len);
}
