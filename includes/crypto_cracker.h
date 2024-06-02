/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypto_cracker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:56:12 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/02 18:42:25 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRYPTO_CRACKER_H
# define CRYPTO_CRACKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

char		*ft_strcpy(char *dst, const char *src);
char		*rot_cracker(char *cipher);
char		*rot_encrypt(char *plain);
char		*vigenere_cracker(char *cipher);
char		*vigenere_encrypt(char *plain);

int			ft_getmax(int *coinc, int len);
int			ft_strlen(char *str);

int			*coincidence_count(int len, char *str);
int			*ft_getkeylen(int *coinc, int len, int max);
int			*key_build(char *key);

void		ft_prn_split(int *key_len, char *str);
void		remove_spaces(char **str);

#endif
