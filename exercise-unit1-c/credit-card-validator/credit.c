#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

long check_company_card(void);
int luhn_algorithm(void);

// Variáveis globais
string card_company_name;
char cc_to_ascii[30];
int card_numbers_lenght;

int main(void)
{
    long credit_card_numbers =
        check_company_card(); // Começa a verificação basica do cartão de crédito. Tamanho do numero do cartão e empresa do cartão.
    if (credit_card_numbers == -1)
    {
        return 0;
    }
    else
    {
        int luhn_validation = luhn_algorithm();
        if (luhn_validation == 1)
        {
            printf("%li\n%s\n", credit_card_numbers, card_company_name); // Se o cartão passar na validação de Luhn, imprime o número do cartão e o nome da empresa.
        }
        else
        {
            card_company_name = "INVALID";                               // Se o cartão não passar na validação de Luhn, define o nome da empresa como "INVALID".
            printf("%li\n%s\n", credit_card_numbers, card_company_name); // Imprime o número do cartão + "INVALID".
        }
    }
}

long check_company_card(void)
{
    string card_company[] = {"INVALID", "AMEX", "DISCOVER", "MASTERCARD", "VISA"};
    long credit_card_number; // Variável para armazenar o número do cartão de crédito.
    int company_id = 0;      // Variável para armazenar o ID da empresa do cartão de crédito.

    credit_card_number = get_long("Credit card number validator: "); // Pergunta para o usuário o número do cartão de crédito.
    sprintf(cc_to_ascii, "%li", credit_card_number);                 // Converte o número do cartão de crédito para ASCII.
    card_numbers_lenght = strlen(cc_to_ascii);                       // Conta o número de dígitos do cartão de crédito.

    if (card_numbers_lenght >= 13)
    {
        int check_two_digits = (cc_to_ascii[0] - '0') * 10 + (cc_to_ascii[1] - '0'); // Converte os dois primeiros dígitos do cartão de crédito para um número inteiro.
        if ((check_two_digits == 34 || check_two_digits == 37) && (card_numbers_lenght == 15))                                                                   // Amex
            company_id = 1;
        else if ((check_two_digits == 60 || check_two_digits == 64 || check_two_digits == 65) && (card_numbers_lenght >= 16 && card_numbers_lenght <= 19))       // Discover
            company_id = 2;
        else if ((check_two_digits >= 51 && check_two_digits <= 55) && (card_numbers_lenght == 16))                                                              // MasterCard
            company_id = 3;
        else if (((cc_to_ascii[0] - '0') == 4) && (card_numbers_lenght == 13 || card_numbers_lenght == 16 || card_numbers_lenght == 19))                         // Visa
            company_id = 4;
    }
    if (company_id == 0) // Se o cartão não for de nenhuma empresa válida, retorna -1 e uma mensagem.
    {
        printf("%li\n%s\n", credit_card_number, card_company[0]);
        return -1; // Retorna -1 se o cartão não for válido.
    }
    card_company_name =
        card_company[company_id]; // Armazena o nome da empresa do cartão de crédito.
    return credit_card_number;    // Retorna o número do cartão de crédito se for válido.
}

int luhn_algorithm(void)
{
    int checksum = 0;
    for (; card_numbers_lenght >= 0; card_numbers_lenght--)  // Repete a verificação do digitos ate chegar em zero;
    {
        int calc;
        calc = (cc_to_ascii[card_numbers_lenght - 1] - '0'); // Verifica o primeiro digito.

        if (card_numbers_lenght >= 1)                        // Verifica se esta no ultimo digito.
        {
            checksum += calc;                                // Soma o primeiro digito ao checksum.
        }

        card_numbers_lenght--;

        if (card_numbers_lenght >= 1)                                // Verifica se esta no ultimo digito.
        {
            calc = (cc_to_ascii[card_numbers_lenght - 1] - '0') * 2; // Verifica o segundo digito.
            if (calc > 9)                                            // Se o resultado for maior que 9, subtrai 10 e soma 1.
                calc = (calc - 10) + 1;

            checksum += calc;                                        // Soma o segundo digito ao checksum.
        }
    }
    printf("Checksum: %i\n", checksum); // Imprime o valor do checksum.
    if (checksum % 10 == 0)             // Verifica se o checksum é divisível por 10.
        return 1;                       // Retorna 1 se o cartão passar na validação de Luhn.
    else
        return 0;                       // Retorna 0 se o cartão não passar na validação de Luhn.
}
