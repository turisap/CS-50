#include <cs50.h>
#include <stdio.h>

void print_row(int);

int main(void)
{
    int height;

    do {
        height = get_int("I need heights of the pyramid \n");
    } while(height > 8 || height < 1);

    for(int i = 1; i <= height; i++) {
        for(int j = height * 2 + 2; j > 0; j--) {
            printf(" ");
        }
        printf("\n");
    }

}
