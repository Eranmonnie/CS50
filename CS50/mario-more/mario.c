#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;

    do
    {
        //loop to check if its less than one or greater than eight.
        number = get_int("Height : ");
    }

    while (number < 1 || number > 8);


    for (int i = 1; i <= number; i++) //allows us to loop to the desired height.
    {

        for (int e = number - i; e >= 1; e--) //makes spaces that allows first pyramid  be right angled.
        {

            printf(" ");
        }

        for (int j = 0; j < i; j++) //adds the hashes to make the first pyramid
        {

            printf("#");
        }

        for (int k = 0; k < 2; k++) //makes space for second pyramid
        {

            printf(" ");

        }

        for (int e = 0; e < i; e++) //adds hashes tomake second pyramid
        {

            printf("#");

        }

        printf("\n");

    }

}