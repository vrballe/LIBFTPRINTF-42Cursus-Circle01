/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:35:58 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 14:53:42 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_format(va_list varg, char format_specifier)
{
	int	len;

	len = 0;
	if (format_specifier == 'c')
		len = len + print_character(va_arg(varg, int));
	else if (format_specifier == '%')
		len = len + print_character('%');
	else if (format_specifier == 's')
		len = len + print_string(va_arg(varg, char *));
	else if (format_specifier == 'd' || format_specifier == 'i')
		len = len + print_number(va_arg(varg, int));
	else if (format_specifier == 'u')
		len = len + print_unsigned_integer(va_arg(varg, unsigned int));
	else if (format_specifier == 'x' || format_specifier == 'X')
		len = len + print_hexadecimal(va_arg(varg, long int), format_specifier);
	else if (format_specifier == 'p')
		len = len + print_pointer_address(va_arg(varg, long int));
	return (len);
}

int	ft_printf(const char *print, ...)
{
	va_list	varg;
	int		i;
	int		len;

	va_start(varg, print);
	i = 0;
	len = 0;
	while (print[i])
	{
		if (print[i] == '%')
		{
			len = len + set_format(varg, print[i + 1]);
			i++;
		}
		else
			len = len + print_character(print[i]);
		i++;
	}
	va_end(varg);
	return (len);
}
