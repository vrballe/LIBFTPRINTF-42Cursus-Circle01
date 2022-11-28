/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:36:43 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 15:51:09 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	getlen_uns(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*convert_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	long int		num;

	len = getlen_uns(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	num = n;
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	print_unsigned_integer(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = convert_utoa(n);
	len = print_string(num);
	free(num);
	return (len);
}
