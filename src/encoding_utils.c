/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:39:06 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/02 14:23:53 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

int	*key_build(char *key)
{
	int	*k;
	int	len_key;
	int	i;

	i = -1;
	len_key = ft_strlen(key);
	k = malloc(sizeof(int) * len_key);
	if (k == NULL)
		return (NULL);
	while (key[++i] != 0 && i < len_key)
		k[i] = key[i] - 'a';
	return (k);
}
