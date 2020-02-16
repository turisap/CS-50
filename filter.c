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
// THIS IS A VERY SILLY IMPLEMENTAIONT DUE TO 4 NESTED FOR LOOPS :(
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int cell_count = 0;

            int row_range_start = i - 1 >= 0 ? i - 1 : 0;
            int row_range_end = i + 1 < height ? i + 1 : height - 1;

            int column_range_start = j - 1 >= 0 ? j - 1 : 0;
            int column_range_end = j + 1 < width ? j + 1 : width - 1;

            for (int el = column_range_start; el <= column_range_end; el++)
            {

                for (int sub_row = row_range_start; sub_row <= row_range_end; sub_row++)
                {

                    sum_red += image[sub_row][el].rgbtRed;
                    sum_green += image[sub_row][el].rgbtGreen;
                    sum_blue += image[sub_row][el].rgbtBlue;

                    cell_count++;
                }
            }

            int average_red = sum_red / cell_count;
            int average_green = sum_green / cell_count;
            int average_blue = sum_blue / cell_count;

            image[i][j].rgbtRed = average_red;
            image[i][j].rgbtGreen = average_green;
            image[i][j].rgbtBlue = average_blue;
        }
    }

    return;
}
