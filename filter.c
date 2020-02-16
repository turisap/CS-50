#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;

            int average = floor((red + green + blue) / 3);

            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;

            printf("%i\n", image[i][j].rgbtGreen);
            printf("%i\n", image[i][j].rgbtBlue);
            printf("%i\n", image[i][j].rgbtRed);
            printf("===============");
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
