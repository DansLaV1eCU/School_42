/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:53:19 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:53:20 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	const char *str1 = "Hello, World!";
// 	const char *str2 = "";
// 	const char *str3 = "42 Network";

// 	printf("Length of '%s' is: %zu\n", str1, ft_strlen(str1));
// 	printf("Length of an empty string is: %zu\n", ft_strlen(str2));
// 	printf("Length of '%s' is: %zu\n", str3, ft_strlen(str3));

// 	return 0;
// }