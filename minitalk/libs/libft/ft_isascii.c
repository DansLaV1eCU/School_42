/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:50:56 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:50:57 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
	{
		return (1);
	}
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main() {
// 	printf("%d\n", isascii('0'));
// 	printf("%d\n", isascii(-1));
// 	printf("%d\n", isascii(0177));
// 	printf("%d\n", isascii(190));

// 	printf("%d\n", ft_isascii('0'));
// 	printf("%d\n", ft_isascii(-1));
// 	printf("%d\n", ft_isascii(0177));
// 	printf("%d\n", ft_isascii(190));
// }
