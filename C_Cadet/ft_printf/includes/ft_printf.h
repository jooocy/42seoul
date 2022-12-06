/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:47:16 by jjin              #+#    #+#             */
/*   Updated: 2022/06/29 21:30:22 by jjin             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int ft_print_char(char c);
int ft_print_dec(int d);
int ft_hex_len(uintptr_t n);
void ft_put_hex(const char f, uintptr_t n);
int ft_print_hex(const char f, unsigned int n);
int ft_print_ptr(uintptr_t n);
int ft_print_str(char *str);
int ft_dec_len(unsigned int n);
void ft_put_dec(unsigned int n);
int ft_print_unsigned(unsigned int n);
int ft_printformat(const char f, va_list vl);
int ft_printf(const char *str, ...);

#endif