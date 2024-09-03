#include <stdio.h>
#include <string.h>
void caesar_cipher(char text[], int shift) 
{
    int i;
    char cipherText[strlen(text)];
    
    for (i = 0; i < strlen(text); i++)
	{
        if (text[i] >= 'A' && text[i] <= 'Z')
		{
            cipherText[i] = (text[i] - 'A' + shift) % 26 + 'A';
        } else 
		{
        	cipherText[i] = text[i];
        }
    }
    cipherText[i] = '\0';
    printf("your Cipher Text is: %s\n", cipherText);
}

int main() 
{
    char text[100];
    int shift;
    
    printf("Enter the text to be encrypted (uppercase letters): ");
    scanf("%s", text);
    
    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    
    caesar_cipher(text, shift);
    
    return 0;
}
