#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<math.h>

int get_multiplied(long sub) ;  //function to get numbers that would be multiplied by 2
int get_not_multiplied(long sub) ; //function to get numbers that wont be multiplied
bool status(int a, int b) ;
//function to add both multiplied and not multiplied numbers and compairs if their sum is a multiple of 10
string card_value(bool status_of_card, long no_on_card); //assigns value to the card number be it VISA, AMEX, or MASTERCARD



int main(void)
{
    //get input from user
    long card_no = get_long("Number: "); //gets card number
    long subs = card_no;
    int multiplied;
    int not_multiplied;
    bool card_status;
    string card_type;

    multiplied = get_multiplied(subs);
    not_multiplied = get_not_multiplied(subs);
    card_status = status(multiplied, not_multiplied);
    card_type = card_value(card_status, subs);

    printf(" %s\n", card_type); //prints out card type

}


int get_multiplied(long sub) //function to get numbers that would be multiplied by 2

{
    int multiplied = 0;
    int number;


    while (sub > 0)
    {
        for (int y = 0; y < 16; y++)
        {
            number = ((sub / 10) % 10) * 2 ;

            if (number > 9)
            {
                number -= 9;

            }

            multiplied += number;

            sub /= 100;

        }

    }
    return multiplied;
}


int get_not_multiplied(long sub) //function to get numbers that wont be multiplied
{

    int not_multiplied = 0;
    int number;
    int count = 1 ; // assigned a counter variable to increment at every loop


    while (sub > 0)
    {
        for (int y = 0; y < 16; y++)
        {

            if (count % 2 == 1) //makes sure number is increasing only if the count variable is even
            {
                number = (sub % 10) ;

                not_multiplied += number ;
                count ++ ;
                sub /= 10 ;
            }

            count ++ ;
            sub /= 10 ;

        }

    }
    return not_multiplied;
}



bool status(int a, int b) //function to add both multiplied and not multiplied numbers and compairs if their sum is a multiple of 10
{
    if ((a + b) % 10 == 0)
    {
        return true ;
    }


    else
    {
        return false ;
    }
}

string card_value(bool status_of_card, long no_on_card) //assigns value to the card number be it VISA, AMEX, or MASTERCARD
{
    string card_type;
    if (status_of_card == true)
    {
        //AMEX CARD
        if (((no_on_card >= (34 * pow(10, 13))) && (no_on_card <= (35 * pow(10, 13)))) || ((no_on_card >= (37 * pow(10, 13)))
                && (no_on_card <= (38 * pow(10, 13))))) //checks to see if card is AMEX
        {
            card_type = "AMEX" ;
        }
        //MASTERCARD
        else if ((no_on_card >= (51 * pow(10, 14))) && (no_on_card <= (56 * pow(10, 14)))) //checks to see if card is MASTERCARD
        {
            card_type = "MASTERCARD" ;
        }
        //VISA
        else if (((no_on_card > (40 * pow(10, 11))) && (no_on_card < (43 * pow(10, 11)))) || ((no_on_card > (40 * pow(10, 14)))
                 && (no_on_card < (43 * pow(10, 14))))) //checks to see if card is VISA
        {
            card_type = "VISA";
        }

        else //catches card numbers that its sum of multiplied and not multiplied numbers is a multiple of 10 but not a valid card type
        {
            card_type = "INVALID";
        }

    }

    if (status_of_card == false) //returns INVALID if sum is not a multiple of 10
    {
        card_type = "INVALID" ;
    }

    return card_type ;


}




