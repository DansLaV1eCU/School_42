/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:52:45 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:52:46 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

// #include <string.h>
// #include <stdio.h>
// int main() {
// 	const char *str = "Hello, world!";
// 	char ch = 'o';

// 	char *result = strchr(str, 'o');
// 	char *my_result = ft_strchr(str, 'o');

// 	printf("Character '%c' position: %ld\n", ch, result - str);
// 	printf("Character '%c' position: %ld\n", ch, my_result - str);

// 	return (0);
// }