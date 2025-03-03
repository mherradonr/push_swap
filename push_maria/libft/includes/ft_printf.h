/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:40:26 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/12 17:41:25 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"

// FUNCTIONS FT_PRINTF
int	select_type(va_list parameters, char complete_str);
int	ft_printf(char const *total_str, ...);

// UTILS FUNCTIONS FT_PRINTF
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putnbr_hexa(unsigned long nb, char *base);
int	ft_putptr(unsigned long nb);

#endif