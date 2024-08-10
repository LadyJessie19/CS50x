#include <cs50.h>
#include <stdio.h>

long get_credit_card_number(void);
bool is_valid(long number);
void identify_card_brand(long number);

int main(void)
{
    // Solicitar o número do cartão de crédito
    long number = get_credit_card_number();

    // Verificar se o número do cartão é válido
    if (is_valid(number))
    {
        // Identificar a bandeira do cartão
        identify_card_brand(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Função para solicitar o número do cartão de crédito
long get_credit_card_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0); // Certifica-se de que o número seja positivo
    return number;
}

// Função para verificar a validade do cartão usando o algoritmo de Luhn
bool is_valid(long number)
{
    int sum = 0;
    int count = 0;

    while (number > 0)
    {
        int digit = number % 10;

        // Multiplica cada outro dígito por 2, começando pelo penúltimo
        if (count % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        // Soma os dígitos dos produtos e os outros dígitos não multiplicados
        sum += digit;
        number /= 10;
        count++;
    }

    // Verifica se o último dígito da soma é 0
    return (sum % 10 == 0);
}

// Função para identificar a bandeira do cartão
void identify_card_brand(long number)
{
    // Contagem do número de dígitos
    int count = 0;
    long digits = number;

    while (digits > 0)
    {
        digits /= 10;
        count++;
    }

    // Extrai os dois primeiros dígitos para determinar a bandeira
    long start_digits = number;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // Verifica a bandeira com base nos dígitos iniciais e quantidade total de dígitos
    if ((start_digits == 34 || start_digits == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if ((start_digits >= 51 && start_digits <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start_digits / 10 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
