/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:53:25 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:53:26 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// char example_function(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (c >= 'a' && c <= 'z') ? c - 32 : c;
// 	else
// 		return (c >= 'A' && c <= 'Z') ? c + 32 : c;
// }
// int main(void)
// {
// 	const char *str = "Hello, World!";
// 	char *result = ft_strmapi(str, example_function);
// 	printf("Original string: %s\n", str);
// 	printf("Modified string: %s\n", result);
// 	free(result);
// 	return 0;
// }