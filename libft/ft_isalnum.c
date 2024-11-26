/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:06:09 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 19:39:26 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int str)
{
	return ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')
		|| (str >= '0' && str <= '9'));
}

// int	main(void)
// {
// 	char	c;

// 	c = '5';
// 	printf("%d", ft_isalnum((int)c));
// }