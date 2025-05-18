/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:53:42 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:53:43 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*last;
	unsigned char	uc;

	if (!s)
		return (NULL);
	last = NULL;
	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == (char)uc)
			last = (char *)&s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (last);
}

// #include <string.h>
// #include <stdio.h>
// int main() {
// 	const char *str = "Hello, world!";
// 	char ch = 'o';

// 	char *result = strrchr(str, 'o');
// 	char *my_result = ft_strrchr(str, 'o');

// 	printf("Character '%c' position: %ld\n", ch, result - str);
// 	printf("Character '%c' position: %ld\n", ch, my_result - str);

// 	return (0);
// }