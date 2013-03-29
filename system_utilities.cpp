#include "system_utilities.h"
#include "definitions.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>

using namespace std;

int parseCommandLine(char cline[], char *tklist[]) {
	int string_length, token_length, i, j;
	int next_Token = 0;

	string_length = strlen(cline);
	i = 0;

	while(cline[i] !=0) {

		// Find the next Blank
		while(cline[i]==' ') i++;
		j=i+1; // Set j to the next character

		if(cline[i] !='"') {
			// Keep going through the characters while cline[j] isn't blank
			while(cline[j]!=' ' && cline[j] != 0) j++;
			token_length=j+1 - i;
		}

		else {
			i = i+1;
			j = i+1;
			while(cline[j] != '"') j++;
			token_length = j+1 - i;
			j=j+1;
		}

		tklist[next_Token] = (char* )malloc(token_length);
		memcpy(tklist[next_Token], cline+i, token_length-1);
		tklist[next_Token][token_length-1] = 0;
		next_Token++;
		i = j;
	}

	return next_Token;
}
	