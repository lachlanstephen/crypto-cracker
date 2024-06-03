/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vigenere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:16:57 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/03 21:49:26 by darkwater        ###   ########.fr       */
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
	key = "key";
	k = key_build(key);
	while (res[++i] != 0)
		res[i] = (res[i] - 'a' + k[(i % ft_strlen(key))]) % 26 + 'a';
	free(k);
	return (res);
}

int	calculate_key(int *letters, int count)
{
	int		i;
	float	max[2];
	float	total;
	int		shift;
	double	frequency[] = {0.0855169067319528, 0.0160479591682283, 0.031644353809001, 0.0387118373573742, 0.12096522475169, 0.0218151039691225, 0.0208633542509232, 0.0495570728057064, 0.0732511860723129, 0.00219778895610456, 0.00808697522714233, 0.0420646432930645, 0.0252632173601844, 0.0717218487628386, 0.0746726541081045, 0.0206616607889663, 0.00104024530143232, 0.0633271013284023, 0.0672820311749165, 0.0893812694965949, 0.0268158093623044, 0.0105934627466257, 0.0182536189504165, 0.00191350485941346, 0.0172136061524734, 0.00113756321470384};

	shift = -1;
	max[0] = 0;
	max[1] = 0;
	total = 0;
	while (++shift < 26)
	{
		i = -1;
		total = 0;
		while (++i < 26)
			total += frequency[i] * (letters[(i + shift) % 26] / (float)count);
		if (total > max[0])
		{
			max[0] = total;
			max[1] = shift;
		}
		//printf("Shift: %c, Total: %f\n", shift + 'a', total);
	}
	return (max[1]);
}

int	*key_generator(int key_len, char *str)
{
	int	i;
	int	j;
	int	letters[26];
	int	*key;
	int	count;

	i = -1;
	j = -1;
	key = malloc(sizeof(int) * key_len);
	if (key == NULL)
		return (NULL);
	while (++i < 26)
		letters[i] = 0;
	while (++j < key_len)
	{
		i = -1;
		count = 0;
		while (str[++i] != 0)
		{
			if (i % key_len == j)
			{
				letters[(str[i] - 'a')]++;
				count++;
			}
		}
		key[j] = calculate_key(letters, count);
	}
	return (key);
}

char	*solve_vigenere(int *key, int key_len, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i] != 0 && ++j >= 0)
	{
		if (str[i] != ' ')
			str[i] = ((str[i] - 'a' - key[j % key_len]) % 26 + 26) % 26 + 'a';
		else
			j--;
	}
	return (str);
}

char	*vigenere_cracker(char *cipher)
{
	char	*res;
	int		*coinc;
	int		len;
	int		key_len;
	int		*key;

	res = malloc(sizeof(char) * ft_strlen(cipher) + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, cipher);
	remove_spaces(&res);
	len = ft_strlen(res);
	coinc = coincidence_count(len, res);
	if (coinc == NULL)
		return (NULL);
	key_len = ft_getkeylen(coinc, len, ft_getmax(coinc, len));
	key = key_generator(key_len, res);
	printf("\nKey: ");
	for (int i = 0; i < key_len - 1; i++)
		printf("%c, ", key[i] + 'a');
	printf("%c\n", key[key_len - 1] + 'a');
	res = solve_vigenere(key, key_len, ft_strcpy(res, cipher));
	free(coinc);
	free(key);
	return (res);
}
