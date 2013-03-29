/* EECS 211 - PROGRAM 4: BASIC TOKEN PARSING

BY: VICTOR ABECASSIS
DATE: 2/15/2012

*/

#include "definitions.h" 
#include "system_utilities.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {

	char cline[MAX_CMD_LINE_LENGTH];
	char *tklist[MAX_TOKENS_ON_A_LINE];
	int tokCount;
	int num_cmd_lines = 6;

	ifstream infile;
	infile.open("p4input.txt", ios::in);

	if(!infile.is_open()) {
		cout<<"The File was not opened."<<endl;
		return 0;
	}

	for(int cur_line = 0; cur_line < num_cmd_lines; cur_line++) {
		memset(cline, 0 , MAX_CMD_LINE_LENGTH);
		infile.getline(cline, MAX_CMD_LINE_LENGTH);
		tokCount = parseCommandLine(cline,tklist);
		cout<<"There are "<<tokCount<<" tokens on the command line."<<endl;

		cout<<"\nBelow is a list of the tokens:\n"<<endl;
		for(int i=0; i<tokCount; i++) {
			char *str = tklist[i];
			cout<<"Token number "<<i+1<<" is: "<<str<<endl;
		}

		cout<<"\n============================";
		cout<<"\n============================\n"<<endl;
		for(int j=0; j<tokCount; j++) {
			free((void *)tklist[j]);
		}
	}

	infile.close();
	int close_program;
	cout<<"Enter 0 to exit the program"<<endl;
	cin>>close_program;
	return 0;
}