#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string strcasestr(string haystack, char needle);

int main(int argc, string argv[])
{
    bool onlyAlpha = true;
    bool onlyUnique = true;

    if (argc == 1 || argc > 2)
    {
        printf("You must provide a single argument [key]\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("The encrypt key must be 26 chars long\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            onlyAlpha = false;
        }

        if (strcasestr(key, key[i]))
        {
            onlyUnique = false;
        }
    }

    if (!onlyAlpha)
    {
        printf("The key must contain only alphabetic characters\n");
        return 1;
    }

    if (!onlyUnique)
    {
        printf("The key must contain only unique characters");
    }
}