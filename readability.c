#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int isascii(char c);

int main(void)
{
    string text = 0;
    int letters = 0;
    int words = 0;
    int sentences = 0;

    do
    {
        text = get_string("Give me some text: ");
    } while (!text);

    int len = strlen(text);

    for (int i = 0; i <= len; i++)
    {
        bool isASCI = isascii(text[i]);
        bool isAChar = isalpha(text[i]);
        bool isSpace = isblank(text[i]);
        bool isTerminatingString = text[i] == '\0';

        if (isASCI && isAChar)
        {
            letters++;
        }

        if (isSpace || isTerminatingString)
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float K = 100 / (double)words;
    float L = (double)letters * K;
    float S = (double)sentences * K;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = (int)round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    if (grade > 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}
