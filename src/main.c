/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:52:06 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/02 19:18:06 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

static void	prn_intro(void)
{
	system("clear");
	printf("\n\t - - - CRYPTO CRACKER v0.2 - - - \n\nWelcome to my \
first attempt at an encoding and decoding program, built in C. Presently \
I am only handling the information gathering side of the Vigenere Cipher, \
but am looking to expand that to other ciphers!\n\nPlease feel free to \
leave comments on how I can improve this :)\n");
	printf("\n\n\tPress enter to continue!\n\n> ");
}

static void	prn_options(int num)
{
	if (num == 1)
		printf("\nPlease select 'e' to encode, or 'd' to decode\n\n> ");
	else if (num == 2)
		printf("\nEncoding Options:\n\n\t1) Rot Cipher\n\n\t2) Vigenere Cipher\n\n> ");
	else if (num == 3)
		printf("\nDecoding Options:\n\n\t1) Rot Cipher\n\n\t2) Vigenere Cipher\n\n> ");
}

int	main(void)
{
	char	*input;
	char	*result;
	char	choice;

	input = "udot nyt kzlvpe zbv gsln waggnvs stx kww vifg kiuituxin \
lsy fvul lui qwnces lnye izk fzdf yuzs kugvizohx bmyn st vuhv \
ig yumt my";
	prn_intro();
	getchar();
	system("clear");
	while (true)
	{
		prn_options(1);
		choice = getchar();
		system("clear");
		if (choice == 'd')
		{
			while (true)
			{
				prn_options(3);
				choice = getchar();
				if (choice == '1')
					result = rot_cracker(input);
				else if (choice == '2')
					result = vigenere_cracker(input);
				if (choice == '1' || choice == '2')
					break ;
			}
		}
		else if (choice == 'e')
		{
			while (true)
			{
				prn_options(3);
				choice = getchar();
				if (choice == '1')
					result = rot_encrypt(input);
				else if (choice == '2')
					result = vigenere_encrypt(input);
				if (choice == '1' || choice == '2')
					break ;
			}
		}
		else
			continue ;
		break ;
	}
	printf("\nThe input string is: %s\n\nThe resulting string is: %s\n", input, result);
	//free(result);
	return (0);
}
