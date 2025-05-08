/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:56:07 by alucar            #+#    #+#             */
/*   Updated: 2023/10/11 11:56:10 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(long n, int len, char *base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= len)
	{
		i += print_base(n / len, len, base);
		i += print_base(n % len, len, base);
	}
	else
		i += write(1, &base[n], 1);
	return (i);
}

int	print_chr(int n)
{
	write(1, &n, 1);
	return (1);
}

int	print_str(char *n)
{
	int	i;

	if (!n)
		return (print_str("(null)"));
	i = 0;
	while (n[i])
	{
		i += write(1, &n[i], 1);
	}
	return (i);
}

int	p_flag(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += p_flag(n / 16);
	if ((n % 16) < 10)
		i += print_chr((n % 16) + '0');
	else
		i += print_chr((n % 16) + 87);
	return (i);
}
