/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:01:55 by npolack           #+#    #+#             */
/*   Updated: 2024/10/17 11:44:48 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;

	s_len = ft_strlen(s);
	dest = 0;
	dest = (char *)ft_calloc(s_len + 1, sizeof (char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s, s_len + 1);
	return (dest);
}