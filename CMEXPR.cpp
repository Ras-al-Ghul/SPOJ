// feel proud after doing this

// don't rely on segfaults for out of bounds
// in case of char strings accessing out of bounds index didn't give segfault
// had to manually ensure that index is not out of bounds

// use stacks for detecting opening and closing of braces, other methods are inefficient - refer openingbracecount, closingbracecount below

// edge cases are really tricky
// sometimes test cases may not cover everything
// time complexity of this algo seems good

// the approach was to consider each brace pair at a time
// for each brace pair, consider a list of curoperators (bear in mind that there can be more than one)
// for each brace pair, find the prevoperator and nextoperator if it exists
// check if the conditions are satisfied for each element in the list of curoperators
// only then remove the braces

// manage memory

#include <iostream>
#include <cstring>
#include <stack>

#define MAXSIZE 500

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);

	char expr[MAXSIZE];

	int *listofbraces[int(MAXSIZE/2)];
	int openingbracecount, closingbracecount;	
	while(numoftestcases--){
		scanf("%s", expr);

		openingbracecount = 0;
		for(int i=0; i<strlen(expr); i++){
			if(expr[i]=='('){
				listofbraces[openingbracecount] = new int[2];
				listofbraces[openingbracecount][0] = i;
				listofbraces[openingbracecount][1] = -1;
				closingbracecount = openingbracecount;
				openingbracecount++;
			}
			else if(expr[i]==')'){
				while(true){
					if(listofbraces[closingbracecount][1] == -1){
						listofbraces[closingbracecount][1] = i;
						closingbracecount--;		
						break;
					}
					closingbracecount--;
				}
			}
		}

		for(int i=openingbracecount-1; i>=0; i--){
			
			char *curoperatorlist[int(MAXSIZE/2)];
			int curoperatorlistcount = 0;

			stack<char> bracesstack; 
			for(int j=listofbraces[i][0]+1; j<listofbraces[i][1]-1; j++){
				if(expr[j]=='('){
					bracesstack.push(expr[j]);
				}
				else if(expr[j]==')'){
					bracesstack.pop();
				}
				else if(expr[j]=='+' or expr[j]=='-' or expr[j]=='*' or expr[j]=='/'){
					if(bracesstack.empty()){
						curoperatorlist[curoperatorlistcount] = new char[2];
						curoperatorlist[curoperatorlistcount][0] = expr[j];
						curoperatorlist[curoperatorlistcount][1] = '0';
						curoperatorlistcount++;
					}
				}
			}

			if(curoperatorlistcount != 0){
				// printf("%c\n", curoperator);
				if(!(listofbraces[i][0] == 0 and (listofbraces[i][1] == strlen(expr) - 1))){

					for(int j=0; j<curoperatorlistcount; j++){
						char curoperator = curoperatorlist[j][0];
						char previousoperator = ' ', nextoperator = ' ';
						if((listofbraces[i][0]-1) >= 0){
							if(expr[listofbraces[i][0]-1] != '(')
								previousoperator = expr[listofbraces[i][0] - 1];	
						}
						if((listofbraces[i][1]+1) < strlen(expr)){
							if(expr[listofbraces[i][1]+1] != ')')
								nextoperator = expr[listofbraces[i][1] + 1];
						}
						
						if(previousoperator == ' ' and nextoperator != ' '){
							switch(curoperator){
								case '+':
									if(nextoperator == '+' or nextoperator == '-')
										curoperatorlist[j][1] = '1';
									break;
								case '-':
									if(nextoperator == '-' or nextoperator == '+')
										curoperatorlist[j][1] = '1';
									break;
								case '*':
									curoperatorlist[j][1] = '1';
									break;
								case '/':
									curoperatorlist[j][1] = '1';
									break;
							}
						}
						else if(previousoperator != ' ' and nextoperator == ' '){
							switch(curoperator){
								case '+':
									if(previousoperator == '+')
										curoperatorlist[j][1] = '1';
									break;
								case '-':
									if(previousoperator == '+')
										curoperatorlist[j][1] = '1';
									break;
								case '*':
									if(previousoperator != '/')
										curoperatorlist[j][1] = '1';
									break;
								case '/':
									if(previousoperator != '/')
										curoperatorlist[j][1] = '1';
									break;
							}	
						}
						else if(previousoperator != ' ' and nextoperator != ' '){
							switch(curoperator){
								case '+':
									if(nextoperator == '+' or nextoperator == '-')
										if(previousoperator == '+')
											curoperatorlist[j][1] = '1';
									break;
								case '-':
									if(nextoperator == '-' or nextoperator == '+')
										if(previousoperator == '+'){
											curoperatorlist[j][1] = '1';
										}
									break;
								case '*':
									if(previousoperator != '/')
										curoperatorlist[j][1] = '1';
									break;
								case '/':
									if(previousoperator != '/')
										curoperatorlist[j][1] = '1';
									break;
							}
						}
						else{
							curoperatorlist[j][1] = '1';
						}

					}

					bool flag = true;
					for(int j=0; j<curoperatorlistcount; j++){
						if(curoperatorlist[j][1] == '0'){
							flag = false;
							break;
						}
					}
					if(flag == true){
						expr[listofbraces[i][0]] = '0';
						expr[listofbraces[i][1]] = '0';
					}
				}
				else{
					expr[listofbraces[i][0]] = '0';
					expr[listofbraces[i][1]] = '0';
				}
			}
			else{
				expr[listofbraces[i][0]] = '0';
				expr[listofbraces[i][1]] = '0';
			}

			for(int j=0; j<curoperatorlistcount; j++){
				delete[] curoperatorlist[j];
			}
		}
		for(int i=0; i<strlen(expr); i++){
			if(expr[i] != '0')
				printf("%c", expr[i]);
		}
		printf("\n");
		for(int i=0; i<openingbracecount; i++)
			delete[] listofbraces[i];
	}

	return 0;
}