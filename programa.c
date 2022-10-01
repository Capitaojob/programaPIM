#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Definição do alfabeto e da criptografia a ser usada, respectivamente
#define ALPH "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMB "0123456789"

#define AKHD "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"
#define CNUM "9876543210"
//--------------------------------------------------------------------

//Função de processamento de texto que será usada durante o código
void textProcess(char text[], int N, int x) {

	for (int i = 0; i < strlen(text); i++) {

        //!testar essa parte!//
	    /*if (text[i] == '\0' && text[i+1] == '\0' && text[i+2] == '\0') {

	    break;

        }*/

        if (isdigit(text[i])) {
            for (int j = 0; j < 10; j++) {
                if (text[i] == CNUM[j]) {
                    while (j + x > 9) {
                        j -= 10;
                    }
                    text[i] = NUMB[j+x];
                    break;
                }
            }
        }

        else {

            for (int j = 0; j < 52; j++) {

                if (text[i] == AKHD[j]) {

                    if (j + x > 25 && isupper(ALPH[j]) == 0) {
                        j -= 26;
                    }

                    else if (j + x > 51 && isupper(ALPH[j]) == 1) {
                        j -= 26;
                    }

                    else if (j + x < 0 && isupper(ALPH[j]) == 0) {
                        j += 26;
                    }

                    else if (j + x < 26 && isupper(ALPH[j]) == 1) {
                        j += 26;
                    }

                    text[i] = ALPH[j+x];
                    break;

                }
            }
        }
    }
}
//----------------------------------------------------------------

//Função de processamento de arquivo de texto
void fileProcess () {

    int x;
    printf("Qual eh a chave para encriptar?\nNote que a chave deve ser um inteiro entre 0 e 26: ");
    scanf("%d", &x);

    while (x > 26 || x < 0) {
        printf("\nErro: Numero digitado %s que %s\nDigite novamente a resposta: ", x < 1 ? "menor":"maior", x < 1 ? "0":"26");
        scanf("%d", &x);
    }

    FILE *fp = fopen("texto.txt", "r");
    FILE *fptr = fopen("traduzido.txt", "w");
    if (fp == NULL) {
        printf("Parece que o arquivo de texto nao foi encontrado\n");
        Sleep(500);
        exit(1);
    }
    else {
        printf("O texto do arquivo, pos traduzido, eh: \n");
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF) {

        if (isdigit(ch)) {
            for (int j = 0; j < 10; j++) {
                if (ch == CNUM[j]) {
                    while (j + x > 9) {
                        j -= 10;
                    }
                    ch = NUMB[j+x];
                    break;
                }
            }
        }

        else {

            for (int j = 0; j < 62; j++) {

                if (ch == AKHD[j]) {

                    if (j + x > 25 && isupper(ALPH[j]) == 0) {
                        j -= 26;
                    }

                    else if (j + x > 51 && isupper(ALPH[j]) == 1) {
                        j -= 26;
                    }

                    else if (j + x < 0 && isupper(ALPH[j]) == 0) {
                        j += 26;
                    }

                    else if (j + x < 26 && isupper(ALPH[j]) == 1) {
                        j += 26;
                    }

                    ch = ALPH[j+x];
                    break;

                }

            }
        }

        putchar(ch);
        fprintf(fptr, "%c", ch);

    }
    printf("\n");

    fclose(fptr);
    fclose(fp);

}
//-------------------------------------------

int main (void) {

    //Cores que irão aparecer no DOS (o primeiro dígito é o background, enquanto o segundo é a letra)
    system("COLOR 0F");
    //-----------------------------------------------------------------------------------------------

    system("title CAPS Cryptographer");

    system("mode con: cols=81 lines=30");

    puts("                                        @@                                      \n"
         "                                     ,@@@@@@,                                   \n"
         "                                   @@@      @@@                                 \n"
         "                                 @@@          @@@                               \n"
         "                               @@@             %@@                              \n"
         "                             @@@                 @@@                            \n"
         "                            @@@                    @@                           \n"
         "                          ,@@                       @@@                         \n"
         "                         @@@                         @@@                        \n"
         "                        @@@                           @@@                       \n"
         "                       (@@                             @@)                      \n"
         "                       @@ @@@@@@@@@@@       @@@@@@@@@@@ @@                      \n"
         "                      @@@@@         @@@@ @@@@         @@@@@                     \n"
         "                      @@@              @@@              @@@                     \n"
         "                      @@@               @               @@@                     \n"
         "                      @@@                              @@@@                     \n"
         "                      @@@@@                           @@@@@                     \n"
         "                      @@@@@@@                       @@@ @@@                     \n"
         "                       @@@ (@@@                   @@@  @@@                      \n"
         "                        @@@   @@@@             @@@@   @@@                       \n"
         "                          @@@,   @@@        @@@@   ,@@@                         \n"
         "                             @@@@   @@@  @@@@   @@@@                            \n"
         "                      @@%        '@@@@@@@@@@@@@@@'      %@@                     \n"
         "         @@@         @@                @@                 @@         @@@        \n"
         "       @@@          @@@@                                 @@@@         @@@       \n"
         "         @@@            @@@@@@@@%               %@@@@@@@@            @@@        \n"
         "           @@@@                   @@@@@@@@@@@@@                   @@@@          \n"
         "               @@@@@@@                                     @@@@@@@              \n"
         "                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                     ");

    Sleep(4000);
    system("cls");

    system("mode con: cols=114 lines=12");

    puts("   ______     ___    _________     _        ______        _        ____   ____  _____  ______        _            \n"
         " .' ___  |  .'   `. |  _   _  |   / \\      |_   _ `.     / \\      |_  _| |_  _||_   _||_   _ `.     / \\        \n"
         "/ .'   \\_| /  .-.  \\|_/ | | \\_|  / _ \\       | | `. \\   / _ \\       \\ \\   / /    | |    | | `. \\   / _ \\\n"
         "| |   ____ | |   | |    | |     / ___ \\      | |  | |  / ___ \\       \\ \\ / /     | |    | |  | |  / ___ \\    \n"
         "\\ `.___]  |\\  `-'  /   _| |_  _/ /   \\ \\_   _| |_.' /_/ /   \\ \\_      \\ ' /     _| |_  _| |_.' /_/ /   \\ \\_\n"
         " `._____.'  `.___.'   |_____||____| |____| |______.'|____| |____|      \\_/     |_____||______.'|____| |____|     \n"
         "                                                                                                                  \n"
         "                                         Tradutor de Criptografia CAPS                                            \n"
         "                                                                                                                  \n"
         "                                       Um software por Silicio de Hefesto                                         \n");

    Sleep(3000);
    system("cls");

	char resposta;

	system("mode con: cols=58 lines=40");

    //Apresentação do programa e questionamento sobre o que o usuário pretende fazer
    menu:
    printf("\t\t       ***MENU***");
	printf("\n\nOla! Seja bem vindo ao codificador/decodificador de CAPS!\n");
	printf("O que deseja fazer?\n\nCriptografar/Descriptografar (C)\nCriptografar/Descriptografar Arquivo de Texto (T)\nInformacoes (I)\nSair (S)\n");
	scanf("%s", &resposta);
    //------------------------------------------------------------------------------


    //O loop while checa se a resposta bate com as pré-definidas e, caso não, pede para o usuário escrever novamente a resposta
	while (resposta != 'S' && resposta != 's' && resposta != 'C' && resposta != 'c' && resposta != 'T' && resposta != 't' && resposta != 'I' && resposta != 'i') {

        printf("Resposta invalida, digite novamente a resposta!\n");
        scanf("%s", &resposta);

	}
    //-------------------------------------------------------------------------------------------------------------------------

	system("cls");

    //Loop que repete enquanto a resposta for diferente de S, ou seja, sair do aplicativo
	while (resposta != 'S' && resposta != 's') {

        //Esta seção define algumas perguntas a serem feitas quando o usuário deseja de/criptografar um texto
        if (resposta == 'C' || resposta == 'c') {
            int N;

            printf("O texto a ser digitado tem quantos caracteres?\n");
            scanf("%d", &N);

            char text[N+1];

            printf("Otimo! Agora, digite o texto a ser criptografado/descriptografado:\n");

            fflush(stdin);
            fgets(text, N+1, stdin);

            //Inclusive, nesta parte da seção, define a chave de criptografia. Note que a mesma é simétrica, ou seja, é usada nas duas pontas (criptografar e descriptografar)
            printf("Para finalizar, qual eh a chave para encriptar?\nNote que a chave deve ser um inteiro entre 0 e 26: ");

            int x;
            scanf("%d", &x);

            while (x > 26 || x < 0) {
                printf("\nErro: Numero digitado %s que %s\nDigite novamente a resposta: ", x < 1 ? "menor":"maior", x < 1 ? "0":"26");
                scanf("%d", &x);
            }

            textProcess(text, N, x);

        	printf("O texto digitado traduzido para CAPS eh: \n");
        	puts(text);

        	printf("\nDeseja retornar ao menu (M) ou sair do programa (S)?\n");
        	scanf("%s", &resposta);

        	if (resposta == 'M' || resposta == 'm') {
                system("cls");
                goto menu;
        	}

        	else if (resposta == 'S' || resposta == 's') {
                break;
        	}

        }
        //---------------------------------------------------------------------------------------------------


        //O if / else if nesta seção reconhece se o usuário quer criptografar ou descriptografar um texto e,
        //de acordo com o que for certo, chama as funções e escreve o resultado na tela
        else if (resposta == 'T' || resposta == 't') {
            fileProcess();

            printf("\nDeseja retornar ao menu (M) ou sair do programa (S)?\n");
        	scanf("%s", &resposta);

        	if (resposta == 'M' || resposta == 'm') {
                system("cls");
                goto menu;
        	}

        	else if (resposta == 'S' || resposta == 's') {
                break;
        	}
        }
        //---------------------------------------------------------------------------------------------------

        //Nesta extensão do if, o programa reconhecerá se o usuário quer informações sobre o software
        else if (resposta == 'I' || resposta == 'i') {
            puts("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque a facilisis tortor. Aliquam eget neque non mi eleifend vestibulum. Mauris feugiat enim posuere nisl eleifend cursus. Vivamus facilisis, mi varius bibendum eleifend, metus lorem maximus eros, nec eleifend neque sem ac justo. Maecenas fermentum sodales nisl, vel posuere ligula ornare non. Donec eu blandit sem. Praesent dictum scelerisque accumsan. Ut vehicula mollis nisl, id mattis tortor mattis et.\n");

            printf("\nDeseja retornar ao menu (M) ou sair do programa (S)?\n");
        	scanf("%s", &resposta);

        	if (resposta == 'M' || resposta == 'm') {
                system("cls");
                goto menu;
        	}

        	else if (resposta == 'S' || resposta == 's') {
                break;
        	}
        }
        //-------------------------------------------------------------------------------------------


        //Finalmente, o código pergunta novamente ao usuário o que ele deseja fazer, retornando ao while definido
        //na linha 84 com o novo resultado para que possa ser novamente processado o requerimento.

        //!system("cls");

        /*printf("\nO que deseja fazer agora?\nEncode (E)\nDecode (D)\nEncode/Decode Text (T)\nInfo (I)\nSair (S)\n");
        fflush(stdin);
        scanf("%s", &resposta);
        //-------------------------------------------------------------------------------------------------------


        //Este while não deixa que a resposta seja inválida novamente
        while (resposta != 'S' && resposta != 'E' && resposta != 'D' && resposta != 's' && resposta != 'e' && resposta != 'd' && resposta != 'T' && resposta != 't' && resposta != 'I' && resposta != 'i') {

	        printf("Resposta invalida, digite novamente a resposta!\n");
	        scanf("%s", &resposta);

		}*/
        //--------------------------------------------------------------------------------------------

        system("cls");

	}

	system("cls");

    //Ao finalizar o código, o programa se despede e, após 2500ms, fecha.
	printf("Obrigado por usar o tradutor de CAPS! Ate mais!\n");
	Sleep(2500);

	return 0;

}
