/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:36:29 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 16:14:31 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	getlen_dec(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*convert_itoa(int n)
{
	char		*str;
	int			len;
	long int	num;

	len = getlen_dec(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	num = n;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	str[len--] = '\0';
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	print_number(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = convert_itoa(n);
	len = print_string(num);
	free(num);
	return (len);
}
