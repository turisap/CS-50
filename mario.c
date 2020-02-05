#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("I need heights of the pyramid \n");
    } while (height > 8 || height < 1);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height * 2 + 2; j++)
        {

            if (j <= height - i)
            {
                printf(" ");
            }

            if (j > height - i && j <= height)
            {
                printf("#");
            }

            if (j > height && j <= height + 2)
            {
                printf(" ");
            }

            if (j >= height + 2 && j < height + 2 + i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
