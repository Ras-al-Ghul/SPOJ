// don't rely on segfaults for out of bounds
// in case of char strings accessing out of bounds index didn't give segfault
// had to manually ensure that index is not out of bounds

#include <iostream>
#include <cstring>

#define MAXSIZE 251

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
				closingbracecount = openingbracecount;
				openingbracecount++;
			}
			else if(expr[i]==')'){
				listofbraces[closingbracecount][1] = i;
				closingbracecount--;
			}
		}
		// for(int i=0; i<openingbracecount; i++)
		// 	cout<<listofbraces[i][0]<<" "<<listofbraces[i][1]<<endl;
		// break;
		for(int i=openingbracecount-1; i>=0; i--){
			char curoperator = ' ';
			if(expr[listofbraces[i][0]+1] == '('){
				// printf("YO\n");
				for(int j=listofbraces[i+1][1]+1; j<listofbraces[i][1]-1; j++){
					if(expr[j]=='+' || expr[j]=='-' || expr[j]=='*' || expr[j]=='/'){
						curoperator = expr[j];
						break;
					}
				}
			}
			else{
				for(int j=listofbraces[i][0]+1; j<listofbraces[i][1]-1; j++){
					if(expr[j]=='+' || expr[j]=='-' || expr[j]=='*' || expr[j]=='/'){
						curoperator = expr[j];
						break;
					}
				}
			}
			if(curoperator != ' '){
				// printf("%c\n", curoperator);
				if(!(listofbraces[i][0] == 0 and (listofbraces[i][1] == strlen(expr) - 1))){
					char previousoperator = ' ', nextoperator = ' ';
					if((listofbraces[i][0]-1 >=0) and (expr[listofbraces[i][0]-1] != '(')){
						previousoperator = expr[listofbraces[i][0] - 1];
					}
					if((listofbraces[i][1]+1 <strlen(expr)) and (expr[listofbraces[i][1]+1] != ')')){
						nextoperator = expr[listofbraces[i][1] + 1];
					}
					// printf("prev %c next %c\n", previousoperator, nextoperator);
					bool flag = false;
					if(previousoperator == ' ' and nextoperator != ' '){
						switch(curoperator){
							case '+':
								if(nextoperator == '+' or nextoperator == '-')
									flag = true;
								break;
							case '-':
								if(nextoperator == '-' or nextoperator == '+')
									flag = true;
								break;
							case '*':
								flag = true;
								break;
							case '/':
								flag = true;
								break;
						}
					}
					else if(previousoperator != ' ' and nextoperator == ' '){
						switch(curoperator){
							case '+':
								if(previousoperator == '+')
									flag = true;
								break;
							case '-':
								if(previousoperator == '+')
									flag = true;
								break;
							case '*':
								if(previousoperator != '/')
									flag = true;
								break;
							case '/':
								if(previousoperator != '/')
									flag = true;
								break;
						}	
					}
					else if(previousoperator != ' ' and nextoperator != ' '){
						switch(curoperator){
							case '+':
								if(nextoperator == '+' or nextoperator == '-')
									if(previousoperator == '+')
										flag = true;
								break;
							case '-':
								if(nextoperator == '-' or nextoperator == '+')
									if(previousoperator == '+'){
										flag = true;
									}
								break;
							case '*':
								if(previousoperator != '/')
									flag = true;
								break;
							case '/':
								if(previousoperator != '/')
									flag = true;
								break;
						}
					}
					else{
						flag = true;
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

			// for(int i=0; i<strlen(expr); i++){
			// 	printf("%c", expr[i]);
			// }
			// printf("\n");
		}
		// break;
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