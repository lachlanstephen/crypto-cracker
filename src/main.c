/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:52:06 by darkwater         #+#    #+#             */
/*   Updated: 2024/06/05 21:27:29 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/crypto_cracker.h"

static void	prn_intro(void)
{
	system("clear");
	printf("\n\t - - - CRYPTO CRACKER v0.2.2 - - - \n\nWelcome to my \
first attempt at an encoding and decoding program, built in C. Currently \
the program can encrypt using Vigenere and Rot, and decrypt using Rot. \
It will be able to help you decrypt Vigenere, by providing summaries \
needed to work out the key. If you have the key, it can decrypt Vigenere. \
I am looking to expand that to other ciphers!\n\nPlease feel free to \
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

	/*input = "udot nyt kzlvpe zbv gsln waggnvs stx kww vifg kiuituxin \
lsy fvul lui qwnces lnye izk fzdf yuzs kugvizohx bmyn st vuhv \
ig yumt my";*/

	input = "uhgs rbg bzes mb xhf meiet tah bfznr tp unvk bm gle cbehs tbgxioz glesx qsrpmuc wfgg xo hxg lin tah sbp fyci wrpidbbys gkhmt itakioz svon mui bstaghfl glau lui gbmuirfw fsmf hs mt gbahioz vx jvlg ahbm fle xtaxee mb lemi byt ixe frftxjatm";
	//input="dazfi sfspa vqlsn pxysz wxalc dafgq uismt phzga mkttf tccfx kfcrg glpfe tzmmm zozde adwvz wmwkv gqsoh qsvhp wfkls lease pwhmj egkpu rvsxj xvbwv posde teqtx obzik wcxlw nuovj mjcll oeofa zenvm jilow zekaz ejaqd ilsww esgug ktzgq zvrmn wtqse otktk pbsta mqver mjegl jqrtl gfjyg sptzp gtacm oecbx sesci ygufp kvill twdks zodfw fweaa pqtfs tqirg mpmel ryelh qsvwb awmos delhm uzgpg yekzu kwtam zjmls evjqt glawv ovvxh kwqil ieuys zwxah huszo gmuzq cimvz uvwif jjhpw vxfse tzedf";

	//input = "The password is PleaseChangeMe";
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
