/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:52:49 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:52:50 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *original = "Hello, 42!";
// 	char *duplicate;

// 	printf("Original string: %s\n", original);
// 	duplicate = ft_strdup(original);
// 	if (duplicate == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return 1;
// 	}

// 	printf("Duplicated string: %s\n", duplicate);

// 	free(duplicate);

// 	return 0;
// }