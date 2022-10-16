#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Definição do alfabeto e da criptografia a ser usada, respectivamente
#define ALPH "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMB "0123456789"

#define AKHD "qweasdzxcrtyfghvbnuiojklmpQWEASDZXCRTYFGHVBNUIOJKLMP"
#define CNUM "1342589760"
//--------------------------------------------------------------------

//Função de processamento (descriptografia/criptografia) de texto que será usada durante o código
void textProcess(char text[], int N, int x, char resposta) {

    if (resposta == 'C' || resposta == 'c') {

        for (int i = 0; i < strlen(text); i++) {

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

    else if (resposta == 'D' || resposta == 'd') {

        for (int i = 0; i < strlen(text); i++) {

            if (isdigit(text[i])) {
                for (int j = 0; j < 10; j++) {
                    if (text[i] == NUMB[j]) {
                        while (j - x < 0) {
                            j += 10;
                        }
                        text[i] = CNUM[j-x];
                        break;
                    }
                }
            }

            else {

                for (int j = 0; j < 52; j++) {

                    if (text[i] == ALPH[j]) {

                        if (j - x > 25 && isupper(AKHD[j]) == 0) {
                            j -= 26;
                        }

                        else if (j - x > 51 && isupper(AKHD[j]) == 1) {
                            j -= 26;
                        }

                        else if (j - x < 0 && isupper(AKHD[j]) == 0) {
                            j += 26;
                        }

                        else if (j - x < 26 && isupper(AKHD[j]) == 1) {
                            j += 26;
                        }

                        text[i] = AKHD[j-x];
                        break;

                    }
                }
            }
        }
    }
}
//-------------------------------------------------------------------------------

//Função de processamento de arquivo de texto
void fileProcess (char resposta) {

    printf("O processo desejado eh de criptografia(C) ou descriptografia(D)? ");
    fflush(stdin);
    scanf("%c", &resposta);

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

        if (resposta == 'C' || resposta == 'c') {

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

                    for (int j = 0; j < 52; j++) {

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

        }

        else if (resposta == 'D' || resposta == 'd') {

                if (isdigit(ch)) {
                    for (int j = 0; j < 10; j++) {
                        if (ch == NUMB[j]) {
                            while (j - x < 0) {
                                j += 10;
                            }
                            ch = CNUM[j-x];
                            break;
                        }
                    }
                }

                else {

                    for (int j = 0; j < 52; j++) {

                        if (ch == ALPH[j]) {

                            if (j - x > 25 && isupper(AKHD[j]) == 0) {
                                j -= 26;
                            }

                            else if (j - x > 51 && isupper(AKHD[j]) == 1) {
                                j -= 26;
                            }

                            else if (j - x < 0 && isupper(AKHD[j]) == 0) {
                                j += 26;
                            }

                            else if (j - x < 26 && isupper(AKHD[j]) == 1) {
                                j += 26;
                            }

                            ch = AKHD[j-x];
                            break;

                        }
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

    Beep(349, 300);
    Beep(262, 300);
    Beep(165, 300);
    Beep(175, 300);

    Sleep(2800);
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

    Beep(175, 200);
    Beep(349, 300);

    Sleep(2500);
    system("cls");

	char resposta;

    //Apresentação do programa e questionamento sobre o que o usuário pretende fazer
    menu:
    system("mode con: cols=58 lines=40");
    printf("\t\t       ***MENU***");
	printf("\n\nOla! Seja bem vindo ao codificador/decodificador de CAPS!\n");
	printf("O que deseja fazer?\n\nCriptografar (C)\nDescriptografar (D)\nCriptografar/Descriptografar Arquivo de Texto (T)\nInformacoes (I)\nSair (S)\n");
	scanf("%s", &resposta);
    //------------------------------------------------------------------------------


    //O loop while checa se a resposta bate com as pré-definidas e, caso não, pede para o usuário escrever novamente a resposta
	while (resposta != 'S' && resposta != 's' && resposta != 'C' && resposta != 'c' && resposta != 'T' && resposta != 't' && resposta != 'I' && resposta != 'i' && resposta != 'D' && resposta != 'd') {

        printf("Resposta invalida, digite novamente a resposta!\n");
        scanf("%s", &resposta);

	}
    //-------------------------------------------------------------------------------------------------------------------------

	system("cls");

    //Loop que repete enquanto a resposta for diferente de S, ou seja, sair do aplicativo
	while (resposta != 'S' && resposta != 's') {
            system("mode con: cols=80 lines=40");
    //-----------------------------------------------------------------------------------

        //Esta condicional e suas subordinadas definem que função será chamada de acordo com a resposta do usuário
        //Neste primeiro caso (if), o programa executa a função de criptografia de texto digitado pelo usuário
        if (resposta == 'C' || resposta == 'c' || resposta == 'D' || resposta == 'd') {
            int N;

            printf("O texto a ser digitado tem, no minimo, quantos caracteres? \n");
            scanf("%d", &N);

            char text[N+1];

            printf("Otimo! Agora, digite o texto a ser %s:\n", resposta == 'C' || resposta == 'c' ? "criptografado" : "descriptografado");

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

            textProcess(text, N, x, resposta);

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

        //Já neste segundo caso, a função chamada é a de processamento de arquivos de texto
        else if (resposta == 'T' || resposta == 't') {
            fileProcess(resposta);

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

        //Nesta útlima extensão do if, o programa reconhecerá se o usuário quer informações sobre o software
        else if (resposta == 'I' || resposta == 'i') {
            system("mode con: cols=120 lines=72");
            puts("O menu apresenta 5 funcoes a serem usadas: \n"
                "(1) Criptografar (C)\n"
                "(2) Descriptografar (D)\n"
                "(3) Criptografar/Descriptografar Arquivo de Texto (T)\n"
                "(4) Informacoes (I)\n"
                "(5) Sair (S)\n"
                "\n"
                "Abaixo, segue a explicacao de como estas funcionam:\nNas explicacoes, um exemplo continuo sera utilizado\n"
                "-------------------------------------------------------------------\n"
                "\n"
                "Funcao de Criptografia(C) e Descriptografia(D) - Ambas funcoes sao similares, porem, possuem resultados diferentes, sendo que voce somente precisara inserir 3 inputs para faze-las funcionar:\n"
                "-Primeiro: Quantos caracteres o seu texto tem, no minimo. Pergunta utilizado para otimizar sua experiencia, espera que o usuario digite um numero que, em nosso exemplo,  sera '3'.\n"
                "-Segundo: Qual o texto a ser criptografado ou descriptografado. Somente necessita que voce digite qual o texto a ser processado, por exemplo, 'H2O', que possui 3 caracteres. Caso o numero informado na primeira pergunta for menor que o texto, o software tera problemas de execucao.\n"
                "-Terceiro: Qual sera a chave de criptografia. Esta tem como objetivo mudar a forma com que o texto sera embaralhado, podendo receber um numero digitado entre 0 e 26, sendo que cada numero utilizado dara um resultado diferente. Em nosso exemplo, utilizaremos o numero 5"
                "Ao inserir os 3 inputs utilizados no exemplo, levando em conta que a funcao escolhida foi a de criptografia(C), o resultado mostrado sera 'T8Z', que eh a formula H2O (3 letras) criptografada em CAPS com a chave 5.\n"
                "\n"
                "Funcao de Criptografia/Descriptografia de arquivos de texto (T) - Esta funcao, assim como a anterior, realizara o processamento de um texto. Porem, esta usara um arquivo de texto.\n"
                "Para que esta funcione de maneira correta, voce precisa garantir que o texto esteja localizado no arquivo 'texto.txt', na mesma pasta em que se encontra este software.\n"
                "-Primeiro: O software pedira que voce informe se o processamento necessario eh de criptografia, indicado digitando a letra 'C', ou descriptografia, indicado digitando a letra 'D'\n"
                "-Segundo: Da mesma forma que a funcao anterior, pede para que o usuario informe, por meio da digitacao de um numero entre 0 e 26, a chave que sera utilizada\n"
                "Caso o arquivo de texto esteja no local correto, junto ao executavel do software, este realizara o processamento de todo o texto contido no arquivo 'texto.txt', imprimindo na tela o resultado do processamento e criando ou editando, na mesma pasta, um arquivo chamado 'traduzido.txt', que contem o resultado deste processamento\n"
                "\n"
                "Funcao de Informacoes(I) - Esta funcao, assim como voce pode ver, exibe um 'help' do software, contendo informacoes de como usar e do que acontece em cada funcao\n"
                "\n"
                "Ao final das funcoes explicadas ate aqui, inclusive a que esta sendo executada agora, serao exibidos a voce 2 alternativas do que fazer a seguir: \n"
                "(S) Sair - Esta funcao fechara o programa. \n"
                "Ou\n"
                "(M) Voltar ao Menu Principal - Permitira que voce utilize outras funcionalidades, sem fechar o programa.\n"
                "\n"
                "Funcao Sair - Se desejar sair a qualquer momento, no fim dos procedimentos e no menu principal, sera exibida a opcao 'sair', executada ao digitar (S) ou (s). Esta encerrara o programa, acompanhada de uma mensagem de agradecimento por utilizar nossos servicos.\n\n"
                "Duvidas? Entre em contato com o nosso suporte.\n\nTelefone: 16 99357-2303\nE-Mail: siliciodehefesto@gmail.com\n        gotadavida@gmail.com");

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

        system("cls");

	}

	system("cls");

    //Ao finalizar o código, o programa se despede e, após 2500ms, fecha.
	printf("Obrigado por usar o tradutor de CAPS! Ate mais!\n");
	Sleep(2500);

	return 0;

}
