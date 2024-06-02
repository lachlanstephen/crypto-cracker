/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:15:52 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/02 14:15:59 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i] != 0)
		dst[i] = src[i];
	dst[i] = src[i];
	return (dst);
}

void	ft_prn_split(int *key_len, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		if (key_len[i] == 0)
			break ;
		else
			printf("\nKey Length: %d\n", key_len[i]);
		while (str[++j] != 0)
		{
			if (j % key_len[i] == 0)
				printf("\n");
			printf("%c", str[j]);
		}
		printf("\n");
	}
}
