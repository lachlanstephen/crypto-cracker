/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:38:41 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/05 21:07:15 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

char	*rot_encrypt(char *plain)
{
	char	*res;
	int		i;
	int		rot;

	i = -1;
	res = malloc(sizeof(char) * ft_strlen(plain) + 1);
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, plain);
	while (true)
	{
		printf("How many rotations to apply? ");
		rot = 23 + '0';
//		rot = getchar();
//		if (rot < '0' || rot > '9')
//			continue;
		break ;
	}
	while (res[++i] != 0)
	{
		if (res[i] != ' ')
		{
			if (res[i] >= 'A' && res[i] <= 'Z')
				res[i] = (res[i] - 'A' + (rot - '0')) % 26 + 'A';
			else if (res[i] >= 'a' && res[i] <= 'z')
				res[i] = (res[i] - 'a' + (rot - '0')) % 26 + 'a';
		}
	}
	return (res);
}

char	*rot_cracker(char *cipher)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	res = malloc(sizeof(char) * ft_strlen(cipher) + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, cipher);
	while (++i < 25)
	{
		j = -1;
		while (res[++j] != 0)
		{
			if (res[j] != ' ')
			{
				if (res[j] >= 'A' && res[j] <= 'Z')
					res[j] = (res[j] - 'A' + 1) % 26 + 'A';
				else if (res[j] >= 'a' && res[j] <= 'z')
					res[j] = (res[j] - 'a' + 1) % 26 + 'a';
			}
		}
		printf("\nRotate: %d, String: %s\n", i + 1, res);
	}
	free(res);
	return (NULL);
}
