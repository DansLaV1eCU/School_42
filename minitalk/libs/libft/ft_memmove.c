/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:52:10 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:52:11 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	char str1[50] = "Hello, this is a memmove test!";
// 	char str2[50] = "Hello, this is a memmove test!";

// 	ft_memmove(str1 + 20, str1 + 7, 14);
// 	printf("(non-overlapping) str1: %s\n", str1);
// 	memmove(str2 + 20, str2 + 7, 14);
// 	printf("(non-overlapping) str2 (standard memmove): %s\n", str2);

// 	strcpy(str1, "1234567890");
// 	strcpy(str2, "1234567890");

// 	ft_memmove(str1 + 4, str1, 6);
// 	printf("(overlapping) str1: %s\n", str1);
// 	memmove(str2 + 4, str2, 6);
// 	printf("(overlapping) str2 (standard memmove): %s\n", str2);

// 	return (0);
// }