#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize)
{
	char *t = (char *) malloc (sizeof(char) * sSize);
	if (t)
	{
		for (int i = 0; i < sSize-1; i++)
		{
			t[i] = s[sSize - 2 - i];
		}
		t[sSize - 1] = '\0';
		for (int i = 0; i < sSize; i++) // czy sa inne sposoby
		{
			s[i] = t[i];
		}
		free(t);
	}
}

char *reverseStr(char* s, int k) 
{
	char* t = malloc(sizeof(char) * (strlen(s) + 1));
	if (t)
	{
		for (int i = 0; i < strlen(s); i++)
		{
			if(i % (2 * k) < k)
			{
				if (i/k == strlen(s)/k)
				{
					t[k * (i / k) + i % k] = s[strlen(s) - 1 - i % k];
				}
				else
				{
					t[k * (i/k) + i%k] = s[k * (i/k + 1) - 1 - i % k];
				}
			}
			else
			{
				t[i] = s[i];
			}
		}
		t[strlen(s)] = '\0';
		return t;
		//free(t);
	}
	
}

int main()
{
	char s[] = "abcdefghij";
	char *wynik;
	int k = 4;
	wynik = reverseStr(s, k);
	printf("%s\n", wynik);
	free(wynik);

	
	/*
	reverseString(s, 10); //sprawdz czemu podajemy adres
	printf("%s\n", s);
	*/

	return 0;
}