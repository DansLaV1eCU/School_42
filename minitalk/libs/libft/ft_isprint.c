/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:51:08 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:51:09 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
	{
		return (1);
	}
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main() {
// 	printf("%d\n", isprint(31));
// 	printf("%d\n", isprint(126));
// 	printf("%d\n", isprint('A'));
// 	printf("%d\n", isprint('~'));

// 	printf("%d\n", ft_isprint(31));
// 	printf("%d\n", ft_isprint(126));
// 	printf("%d\n", ft_isprint('A'));
// 	printf("%d\n", ft_isprint('~'));
// }
