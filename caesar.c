#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
void encrypt(int rotKey, string toEncrypt);
 
int main(int argc, string argv[])
{
    string input;
    if (argc == 2 && atoi(argv[1]) != 0)
    {   
        int key = atoi(argv[1]) % 26;
        // printf("Please enter the text you'd like encoded at ROT%d.\n", key);
        input = GetString();    // The above comment is purely aesthetic.
        encrypt(key, input);    // I like it, but it's unnecessary.
        return 0;
    }
    else
    {    
        printf("Please try again with a single positive integer.\n");
        return 1;
    }
}
 
void encrypt(int rotKey, string toEncrypt)  // separated to allow for cleaner
{                                           // main function
    int encrypted;
    for (int x = 0; x < strlen(toEncrypt); x++)
    {
        if ('a' <= (char)toEncrypt[x] && 'z' >= (char)toEncrypt[x])
        {
            encrypted = toEncrypt[x] + rotKey;
            if (encrypted > 'z')
                encrypted = ('a' - 1) + encrypted - 'z';  // establish base,
            printf("%c", encrypted);                      // determine overflow
        }
        else if ('A' <= (char)toEncrypt[x] && 'Z' >= (char)toEncrypt[x])
        {
            encrypted = toEncrypt[x] + rotKey;
            if (encrypted > 'Z')
                encrypted = ('A' - 1) + encrypted - 'Z';
            printf("%c", encrypted);
        }
        else
            printf("%c", toEncrypt[x]);
    }
    printf("\n");
    return;
}
