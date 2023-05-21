#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//get users key and plain text
//encrypt
//display

int main(int argc, string argv[])
{
    //validation : if user tries to impute non int values or multiple arguements
    if ( argc != 2 || atoi(argv[1]) <0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //looping
    int key = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    char cypher_text[strlen(plain_text)];
    char que ;
    for (int i = 0; i < strlen(plain_text); i++)
    {
        que = plain_text[i];
        if (que >= 'a' && que <= 'z')
        {
            que = que + key;

            if (que > 'z')
            {
                que = que - 'z' ;

            }


        }
        else if(que >= 'A' && que <= 'Z')
        {
            que = que + key;

            if (que > 'Z')
            {
                que = que - 'z' + 'a' - 1;

            }
        }

        cypher_text[i]= que;
    }
    printf("Ciphertext: %s\n",cypher_text);

}