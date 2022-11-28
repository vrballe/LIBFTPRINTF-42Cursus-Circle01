/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:36:47 by vballe            #+#    #+#             */
/*   Updated: 2022/11/28 16:01:30 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/

int	ft_printf(const char *print, ...);
int	print_character(int c);
int	print_hexadecimal(unsigned int n, char format_specifier);
int	print_number(int n);
int	print_pointer_address(unsigned long int ptr);
int	print_string(char *s);
int	print_unsigned_integer(unsigned int n);

#endif