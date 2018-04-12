/* A basic program to encypher text according to a single keyword
entered in the command line.  */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
void encrypt(string k, string toEncrypt);
 
int main(int argc, string argv[])
{
    string input;
    if (argc == 2)  // Non-letter & lack of argv[1] detection
        for (int x = 0; x < strlen(argv[1]); x++)
                if (!isalpha(argv[1][x]))
                    argc = 1;
                     
    if (argc == 2)
    {    
        printf("Please enter the text you would like encoded.\n");
        input = GetString();
        encrypt(argv[1], input);
        return 0;
    }
    else
    {    
        printf("Please try again with a single letter-only word.\n");
        return 1;
    }
}
 
void encrypt(string k, string toEncrypt)  
{                                       
    int encrypted;
    int kCount = 0;
    for (int x = 0; x < strlen(toEncrypt); x++)
    {
        kCount = kCount % strlen(k);
        if ('a' <= (char)toEncrypt[x] && 'z' >= (char)toEncrypt[x])
        {
            encrypted = toEncrypt[x] + tolower(k[kCount]) - 'a';
            if (encrypted > 'z')
                encrypted = ('a' - 1) + encrypted - 'z';  
            printf("%c", encrypted);
            kCount++;                     
        }
        else if ('A' <= (char)toEncrypt[x] && 'Z' >= (char)toEncrypt[x])
        {
            encrypted = toEncrypt[x] + toupper(k[kCount]) - 'A';
            if (encrypted > 'Z')
                encrypted = ('A' - 1) + encrypted - 'Z';
            printf("%c", encrypted);
            kCount++;
        }
        else
            printf("%c", toEncrypt[x]);
    }
    printf("\n");
    return;
}
