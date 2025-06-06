/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:53:13 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:53:14 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// #include <string.h>
// #include <stdio.h>
// int main() {
// 	char src[] = "Hello, world!";
// 	char dest[6];
// 	size_t result = strlcpy(dest, src, 6);
// 	printf("Destination buffer after strlcpy: '%s'\n", dest);
// 	printf("Length of src string: %zu\n", result);

// 	char my_src[] = "Hello, world!";
// 	char my_dest[6];
// 	size_t my_result = ft_strlcpy(my_dest, my_src, 6);
// 	printf("Destination buffer after strlcpy: '%s'\n", my_dest);
// 	printf("Length of src string: %zu\n", my_result);
// }