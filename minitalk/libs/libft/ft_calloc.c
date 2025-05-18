/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:50:08 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:50:10 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	if (num != 0 && (num * size) / num != size)
		return (NULL);
	result = malloc(num * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, num * size);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
// 	int n = 5;
// 	int *arr = (int *)calloc(n, sizeof(int));
// 	for (int i = 0; i < n; i++) {
// 			printf("arr[%d] = %d\n", i, arr[i]);
// 	}
// 	free(arr);
// 	int *my_arr = (int *)ft_calloc(n, sizeof(int));
// 	for (int b = 0; b < n; b++) {
// 			printf("arr[%d] = %d\n", b, my_arr[b]);
// 	}
// 	free(my_arr);
// 	return (0);
// }
