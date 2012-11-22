/*
	thousandmonkeys.c : a thousand monkeys typing
	(C)2012 Marisa Kirisame, UnSX Team.
	Part of Au, the Alice in Userland project.
	Released under the MIT License.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char **words = NULL;
unsigned int numwords = 0;

/*
   read dictionary and fill up the words array
*/
int fillwords()
{
	unsigned int i = 0, j = 0;
	int ch = 0;
	FILE *dict;
	dict = fopen("/usr/share/dict/words","r");
	if ( dict == NULL )
	{
		fprintf(stderr,"Error: Could not find /usr/share/dict/words\n");
		return 1;
	}
	words = malloc(sizeof(char*));
	while ( !feof(dict) )
	{
		numwords++;
		words = realloc(words,sizeof(char*) * numwords);
		words[i] = NULL;
		words[i] = malloc(2);
		j = 0;
		while ( !feof(dict) )
		{
			ch = fgetc(dict);
			if ( ch == '\n' )
			{
				words[i] = realloc(words[i],j+2);
				j++;
				words[i][j] = '\0';
				i++;
				break;
			}
			if ( feof(dict) )
				break;
			words[i][j] = ch;
			words[i] = realloc(words[i],j+2);
			j++;
			words[i][j] = '\0';
		}
	}
	fclose(dict);
	return 0;
}

int main ()
{
	srand(time(NULL));
	if ( fillwords() == 1 )
		return 1;
	while ( true )
		printf("%s ",words[rand()%numwords]);
	return 0;
}
