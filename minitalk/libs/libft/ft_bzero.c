/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:50:01 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:50:03 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <strings.h>
// #include <stdio.h>
// int main() {
// 	char buffer[10];
// 	char my_buffer[10];
// 	bzero(buffer, sizeof(buffer));
// 	for (int i = 0; i < 10; i++) {
// 			printf("%d ", buffer[i]);
// 	}
// 	printf("\n");
// 	ft_bzero(my_buffer, sizeof(my_buffer));
// 	for (int i = 0; i < 10; i++) {
// 			printf("%d ", my_buffer[i]);
// 	}
// }
