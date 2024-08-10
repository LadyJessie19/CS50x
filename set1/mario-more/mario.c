#include <cs50.h>
#include <stdio.h>

void createBricks(void);
int getSizeBetweenOneAndEight();

int main(void)
{
    createBricks();
}

int getSizeBetweenOneAndEight()
{
    int size;
    do
    {
        size = get_int("Choose a number between 1-8: ");
    }
    while (size < 1 || size > 8);

    return size;
}

void createBricks(void)
{
    int size = getSizeBetweenOneAndEight();

    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
