/*
	1000monkeys.c : a thousand monkeys typing
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of Au, the Alice in Userland project.
	Released under the MIT License.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <helpers.h>

char **words = NULL;
unsigned long int numwords = 0;
FILE *dict;

void setentry( unsigned long int idx, const char *word )
{
	if ( idx >= numwords )
		return;
	if ( word == NULL )
		return;
	if ( words[idx] != NULL )
		free(words[idx]);
	words[idx] = malloc(strlen(word)+1);
	strcpy(words[idx],word);
}

void increasedict( void )
{
	if ( words == NULL )
	{
		words = malloc(sizeof(char*));
		words[0] = NULL;
	}
	else
	{
		words = realloc(words,sizeof(char*)*(numwords+1));
		words[numwords] = NULL;
	}
}

char* readline( void )
{
	unsigned long int i = 0;
	int ch = 0;
	char *line = NULL;
	line = malloc(2);
	while ( !feof(dict) )
	{
		ch = fgetc(dict);
		if ( ch == '\n' )
		{
			line = realloc(line,i+2);
			line[++i] = '\0';
			break;
		}
		if ( feof(dict) )
			break;
		line = realloc(line,i+2);
		line[i] = ch;
		line[++i] = '\0';
	}
	return line;
}

int fillwords( void )
{
	unsigned long int i = 0;
	char *gotword = NULL;
	dict = fopen("/usr/share/dict/words","r");
	if ( dict == NULL )
		return bail("Error: Could not find /usr/share/dict/words\n");
	while ( !feof(dict) )
	{
		increasedict();
		gotword = readline();
		if ( gotword == NULL )
			break;
		if ( strlen(gotword) <= 0 )
			break;
		numwords++;
		setentry(i++,gotword);
		free(gotword);
		gotword = NULL;
	}
	fclose(dict);
	return 0;
}

int main( void )
{
	srand(time(NULL));
	if ( fillwords() )
		return 1;
	while ( printf("%s ",words[rand()%numwords]) > 0 );
	return 0;
}

