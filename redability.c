#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = 0;

    do
    {
        text = get_string("Give me some text: ");
    } while (!text);

    for (int i; len = strlen(text); i < len; i++)
    {
        printf("%c", text[i]);
    }
}