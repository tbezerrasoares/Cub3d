/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2023/08/06 16:33:59 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbuild(char *s1, const char *s2)
{
	char	*joined;
	size_t	l;
	size_t	l1;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	l1 = ft_strlen(s1);
	l = l1 + ft_strlen(s2) + 1;
	joined = malloc(l * sizeof(char));
	if (!joined)
		return (s1);
	joined[0] = '\0';
	ft_strlcat(joined, s1, l);
	ft_strlcat(joined, s2, l);
	free(s1);
	return (joined);
}
