/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigenere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:16:57 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/02 14:28:39 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

char	*vigenere_encrypt(char *plain)
{
	char	*res;
	char	*key;
	int		*k;
	int		i;

	i = -1;
	res = malloc(sizeof(char) * ft_strlen(plain) + 1);
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, plain);
	remove_spaces(&res);
	key = "key";
	k = key_build(key);
	while (res[++i] != 0)
		res[i] = (res[i] - 'a' + k[(i % ft_strlen(key))]) % 26 + 'a';
	free(k);
	return (res);
}

char	*vigenere_cracker(char *cipher)
{
	char	*str;
	int		*coinc;
	int		len;
	int		*key_len;

	str = malloc(sizeof(char) * ft_strlen(cipher) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, cipher);
	remove_spaces(&str);
	len = ft_strlen(str);
	coinc = coincidence_count(len, str);
	if (coinc == NULL)
		return (NULL);
	key_len = ft_getkeylen(coinc, len, ft_getmax(coinc, len));
	ft_prn_split(key_len, str);
	free(coinc);
	free(str);
	return ("I have reached the end");
}
