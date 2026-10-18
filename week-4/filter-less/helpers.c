#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels in the image
    // start with the first row
    for (int i = 0; i < height; i++)
    {
        // then columnar
        for (int j = 0; j < width; j++)
        {
            // extract each RGB val
            int bVal = image[i][j].rgbtBlue;
            int gVal = image[i][j].rgbtGreen;
            int rVal = image[i][j].rgbtRed;

            // get the average to determine the grey hue
            int greyish = round((bVal + gVal + rVal) / 3.0);

            // reassign the grey hue
            image[i][j].rgbtBlue = greyish;
            image[i][j].rgbtGreen = greyish;
            image[i][j].rgbtRed = greyish;
        }
    }

    return;
}

// sepia helper

int cap_hue(int sepVal)
{
    if (sepVal > 255)
    {
        return 255;
    }
    else
    {
        return sepVal;
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels in the image
    // start with the first row
    for (int i = 0; i < height; i++)
    {
        // then columnar
        for (int j = 0; j < width; j++)
        {
            // extract each RGB val
            int bVal = image[i][j].rgbtBlue;
            int gVal = image[i][j].rgbtGreen;
            int rVal = image[i][j].rgbtRed;

            // gets sepia

            int sepRed = round(.393 * rVal + .769 * gVal + .189 * bVal);
            int sepGreen = round(.349 * rVal + .686 * gVal + .168 * bVal);
            int sepBlue = round(.272 * rVal + .534 * gVal + .131 * bVal);

            // reassign the sepia val using helper
            image[i][j].rgbtBlue = cap_hue(sepBlue);
            image[i][j].rgbtGreen = cap_hue(sepGreen);
            image[i][j].rgbtRed = cap_hue(sepRed);
        }
    }
    return;
}

// Reflect image horizontall
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // loop over column
        // set j < width / 2 so it stops at the midpoint
        // middle doesn't need swapping
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            // width-1-j because 0-start indexing
            RGBTRIPLE og_pixel = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = og_pixel;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_totes = 0;
            int blue_totes = 0;
            int green_totes = 0;
            int adjacent = 0;
            for (int r = i - 1; r <= i + 1; r++)
            {
                for (int s = j - 1; s <= j + 1; s++)
                {
                    if (r >= 0 && r < height && s >= 0 && s < width)
                    {
                        red_totes += copy[r][s].rgbtRed;
                        blue_totes += copy[r][s].rgbtBlue;
                        green_totes += copy[r][s].rgbtGreen;

                        adjacent++;
                    }
                }
            }

            // get blurred bytes

            int blurRed = round(red_totes / (float)adjacent);
            int blurGreen = round(green_totes / (float)adjacent);
            int blurBlue = round(blue_totes / (float)adjacent);

            image[i][j].rgbtRed = cap_hue(blurRed);
            image[i][j].rgbtGreen = cap_hue(blurGreen);
            image[i][j].rgbtBlue = cap_hue(blurBlue);
        }
    }
}
