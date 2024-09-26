/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:45:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/02/08 17:13:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	size_t	digit_count;
	char	*num;

	digit_count = ft_count_digits(n);
	num = (char *)malloc(sizeof(char) * (digit_count + 1));
	if (!num)
		return (NULL);
	num[digit_count] = '\0';
	if (n == 0)
		num[0] = '0';
	else if (n < 0)
		num[0] = '-';
	while (n != 0)
	{
		digit_count--;
		num[digit_count] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (num);
}
