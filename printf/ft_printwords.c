/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:31:41 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/11 12:21:30 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
// int	main()
// {
// 	char	c;
// 	char	*s;
// 	int	i;
// 	int	j;
// 	c = '%';
// 	s = "hello";
// 	i = ft_putchar(c);
// 	j = ft_putstr(s);
// 	printf("\n%d %d", i, j);
// 	return (0);
// }