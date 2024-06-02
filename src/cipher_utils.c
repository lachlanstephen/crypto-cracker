/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cipher_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:05:25 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/01 23:51:40 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

void	remove_spaces(char **str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while ((*str)[++i] != 0)
	{
		if ((*str)[i] != ' ')
			(*str)[++j] = (*str)[i];
	}
	(*str)[++j] = '\0';
}

int	frequency_analysis(char *str)
{
	int	vals[26];
	int	i;

	i = 0;
	while (i < 26)
		vals[i] = 0;
	i = -1;
	while (str[++i] != 0)
		vals[(str[i] - 'a')]++;
	return (1);
}
