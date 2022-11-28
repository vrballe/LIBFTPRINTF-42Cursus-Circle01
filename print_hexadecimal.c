/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:36:23 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 16:01:20 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	getlen_hex(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	convert_hex(unsigned int n, char format_specifier)
{
	if (n >= 16)
	{
		convert_hex(n / 16, format_specifier);
		convert_hex(n % 16, format_specifier);
	}
	else
	{
		if (n > 9)
		{
			if (format_specifier == 'X')
				print_character(n - 10 + 'A');
			else if (format_specifier == 'x')
				print_character(n - 10 + 'a');
		}
		else
			print_character(n + '0');
	}
}

int	print_hexadecimal(unsigned int n, char format_specifier)
{
	if (n == 0)
	{
		print_character('0');
		return (1);
	}
	convert_hex(n, format_specifier);
	return (getlen_hex(n));
}
