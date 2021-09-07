#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double red,blue,green;
    int avg;
    int h = height;
    int w = width;
    for(int i = 0 ; i < h; i++ )
        {
            for(int j = 0 ; j < w ; j++ )
            {
                // takes the values
                red = image[i][j].rgbtRed;
                blue = image[i][j].rgbtBlue;
                green = image[i][j].rgbtGreen;
                // this avegarges the double values then type cast them to int and save to avg
                avg = (int)round((red+blue+green)/3);
                // these codes below assign the avg value so the equivalent greyscale may made
                image[i][j].rgbtRed = avg;
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;

            }

        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int h = height;
    int w = width;
    int k,j;
    RGBTRIPLE INVERSE[h][w]; // this is he array to INVERSE the values
    for(int i = 0 ; i < h; i++ )
        {
            for( j = 0,(k = w-1) ; j < w ; j++ , k-- ) // k is assigned the last columns value and j is the first and subsequently k decreses and j increases
            {

                INVERSE[i][j].rgbtRed = image[i][k].rgbtRed; // here the last value is assigned to the first value in the begiig of the loop and then j increases and k decreases and thus replica is saved in INVERSE
                INVERSE[i][j].rgbtBlue = image[i][k].rgbtBlue;
                INVERSE[i][j].rgbtGreen = image[i][k].rgbtGreen;
            }

        }

        for(int i = 0 ; i < h; i++ )
        {
            for(j = 0, (k = w-1) ; j < w ; j++ , k-- )
            {
                image[i][j].rgbtRed = INVERSE[i][j].rgbtRed; // from here the original images array is aasigned the inverse arrays values
                image[i][j].rgbtBlue = INVERSE[i][j].rgbtBlue;
                image[i][j].rgbtGreen = INVERSE[i][j].rgbtGreen;
            }

        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    RGBTRIPLE blur[height][width];

    for(int i = 0 ; i < height ; i++ )
        {
            for(int j = 0 ; j < width ; j++)
            {
                double counter = 0;
                double sumgrn = 0;
                double sumred = 0;
                double sumblue = 0;
                for(int k = -1; k< 2; k++ ) // k and l are loops used for storing the 3* 3 upper and lower values in blur[3][3]
                {

                    for(int h = -1 ; h < 2 ; h++ ) // z and x are the final limits till when the lopps should work as we haven't set k+3 and l+3 cause the values of k will change in every iteration which will result in infinite loop condition.
                    {

                        if( i + k < 0 || i+ k > height -1 || j + h < 0  || j + h > width -1 )
                        {

                            continue;
                        }

			        sumgrn += image[k+i][h+j].rgbtGreen;// to sum up the values
	             	sumred += image[k+i][h+j].rgbtRed;
		     	    sumblue += image[k+i][h+j].rgbtBlue;
                    counter++;

               	     }
	            }

			        // to store the avg blured value in an another blur array because we cannot chage any value of the existing image array until last operation is done.
		            blur[i][j].rgbtRed = (int)round((sumred/counter));
		            blur[i][j].rgbtBlue = (int)round((sumblue/counter));
		            blur[i][j].rgbtGreen = (int)round((sumgrn/counter));
                    counter = 0;
            }
        }
		// this is the loop to finally copy the blur values from the blur array to the original image array
		for(int i = 0 ; i < height; i++ )
        		{
            		for(int j = 0 ; j < width ; j++)
           			 {
                	    image[i][j].rgbtRed = blur[i][j].rgbtRed;
			            image[i][j].rgbtBlue = blur[i][j].rgbtBlue;
			            image[i][j].rgbtGreen = blur[i][j].rgbtGreen;
            		 }
        		}

    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
     int gx[3][3] = { {-1 , 0 , 1} , {-2 , 0 , 2} , {-1 , 0 , 1} };
     int gy[3][3] = { {-1 , -2 , -1} , {0 , 0 , 0} , {1 , 2 , 1} };
     RGBTRIPLE temp[height][width];

    for(int i = 0 ; i < height ; i++ )
        {
            for(int j = 0 ; j < width ; j++)
            {

                double sumgrngy = 0;
                double sumredgy = 0;
                double sumbluegy = 0;
                double sumgrngx = 0;
                double sumredgx = 0;
                double sumbluegx = 0;


                for(int k = -1; k< 2; k++ ) // k and l are loops used for storing the 3* 3 upper and lower values in blur[3][3]
                {

                    for(int h = -1 ; h < 2 ; h++ ) // z and x are the final limits till when the lopps should work as we haven't set k+3 and l+3 cause the values of k will change in every iteration which will result in infinite loop condition.
                    {

                        if( i + k < 0 || i+ k > height -1 || j + h < 0  || j + h > width -1 )
                        {

                            continue;
                        }

			        sumgrngy += (image[k+i][h+j].rgbtGreen * gy[k+1][h+1]);// to sum up the gy matrix into correspond 3*3 colour value
	             	sumredgy += (image[k+i][h+j].rgbtRed * gy[k+1][h+1]);
		     	    sumbluegy += (image[k+i][h+j].rgbtBlue * gy[k+1][h+1]);

                    sumgrngx += (image[k+i][h+j].rgbtGreen * gx[k+1][h+1]);// to sum up the gx matrix into correspond 3*3 colour value
	             	sumredgx += (image[k+i][h+j].rgbtRed * gx[k+1][h+1]);
		     	    sumbluegx += (image[k+i][h+j].rgbtBlue * gx[k+1][h+1]);



               	     }
	            }// to store the sqrt of sum og  gx^2 and gy^2 sum value in an another temp array because we cannot chage any value of the existing image array until last operation is done.
                    if (sqrt(sumredgx*sumredgx + sumredgy*sumredgy) <= 255)
			        {
		            temp[i][j].rgbtRed = (int)round((sqrt(sumredgx*sumredgx + sumredgy*sumredgy)));
			        }
			        else
			        {
			            temp[i][j].rgbtRed = 255;
			        }

			         if (sqrt(sumbluegx*sumbluegx + sumbluegy*sumbluegy) <= 255)
			        {
		             temp[i][j].rgbtBlue = (int)round((sqrt(sumbluegx*sumbluegx + sumbluegy*sumbluegy)));
			        }
			        else
			        {
			            temp[i][j].rgbtBlue = 255;
			        }

			         if (sqrt(sumgrngx*sumgrngx + sumgrngy*sumgrngy) <= 255)
			        {
		             temp[i][j].rgbtGreen = (int)round((sqrt(sumgrngx*sumgrngx + sumgrngy*sumgrngy)));
			        }
			        else
			        {
			            temp[i][j].rgbtGreen = 255;
			        }




            }
        }
        	// this is the loop to finally copy the edge values from the temp array to the original image array
		for(int i = 0 ; i < height; i++ )
        		{
            		for(int j = 0 ; j < width ; j++)
           			 {
             image[i][j].rgbtRed = temp[i][j].rgbtRed;
			 image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
			 image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            	}
        }
    return;
}
