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
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepia_red = floor(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepia_green = floor(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepia_blue = floor(0.272 * red + 0.534 * green + 0.131 * blue);

            sepia_red = sepia_red > 255 ? 255 : sepia_red;
            sepia_green = sepia_green > 255 ? 255 : sepia_green;
            sepia_blue = sepia_blue > 255 ? 255 : sepia_blue;

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE inverse_row[width];
        for (int j = 0; j < width; j++)
        {
            inverse_row[width - j - 1] = image[i][j];
        }
        for (int k = 0; k < width; k++)
        {
            image[i][k] = inverse_row[k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
