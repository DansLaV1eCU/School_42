/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:51:24 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:51:26 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;

	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	char buffer1[] = { 'a', 'b', 'c', 'd', 'c' };
// 	char buffer2[] = { 'a', 'b', 'c', 'd', 'e' };
// 	int result = memcmp(buffer1, buffer2, 5);
// 	int my_result = ft_memcmp(buffer1, buffer2, 5);
// 	if (result < 0) {
// 		printf("buffer1 is less than buffer2\n");
// 	} else if (result > 0) {
// 		printf("buffer1 is greater than buffer2\n");
// 	} else {
// 		printf("buffer1 is equal to buffer2\n");
// 	}
// 	if (my_result < 0) {
// 		printf("buffer1 is less than buffer2\n");
// 	} else if (my_result > 0) {
// 		printf("buffer1 is greater than buffer2\n");
// 	} else {
// 		printf("buffer1 is equal to buffer2\n");
// 	}
// 	return (0);
// }