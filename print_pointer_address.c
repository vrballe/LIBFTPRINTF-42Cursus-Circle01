/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:36:34 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 15:29:29 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	getlen_ptr(unsigned long int ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

void	convert_ptr(unsigned long int ptr)
{
	if (ptr >= 16)
	{
		convert_ptr(ptr / 16);
		convert_ptr(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			print_character(ptr - 10 + 'a');
		else
			print_character(ptr + '0');
	}
}

int	print_pointer_address(unsigned long int ptr)
{
	int		len;

	len = 0;
	if (!ptr)
	{
		print_string("(nil)");
		return (5);
	}
	else
	{
		print_string("0x");
		convert_ptr(ptr);
	}
	return (getlen_ptr(ptr) + 2);
}
