/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:51:04 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:51:05 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main() {
// 	printf("%d\n", isdigit('0'));
// 	printf("%d\n", isdigit('9'));
// 	printf("%d\n", isdigit('A'));
// 	printf("%d\n", isdigit('a'));

// 	printf("%d\n", ft_isdigit('0'));
// 	printf("%d\n", ft_isdigit('9'));
// 	printf("%d\n", ft_isdigit('A'));
// 	printf("%d\n", ft_isdigit('a'));
// }
