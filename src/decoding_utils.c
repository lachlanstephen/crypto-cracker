/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoding_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:12:58 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/03 20:38:48 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

int	*coincidence_count(int len, char *str)
{
	int	*res;
	int	i;
	int	iter;
	int	total;

	iter = 0;
	res = malloc(sizeof(int) * len - 1);
	if (res == NULL)
		return (NULL);
	while (++iter < len)
	{
		total = 0;
		i = -1;
		while (str[++i] != 0 && i + iter < len)
		{
			if (str[i] == str[i + iter])
				total++;
		}
		res[iter - 1] = total;
	}
	return (res);
}

int	ft_getmax(int *coinc, int len)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (++i < len - 1)
	{
		if (coinc[i] > max)
			max = coinc[i];
	}
	return (max);
}

int	ft_getkeylen(int *coinc, int len, int max)
{
	int	key_len;
	int	i;
	int	iter;
	int	lim;
	int	step;

	i = -1;
	iter = 0;
	lim = 39;
	if (len / 8 > lim)
		lim = len / 8;
	step = -1;
	key_len = 0;
	while (++iter < len && step < 9 && key_len == 0)
	{
		i = 0;
		while ((++i * iter) < lim)
		{
			if (coinc[i * iter - 1] < max / 2 - 2)
				break ;
		}
		if (i * iter > lim && iter * 2 <= lim)
			key_len = iter;
	}
	return (key_len);
}
