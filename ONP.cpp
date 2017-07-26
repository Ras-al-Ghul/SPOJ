// whenever you're using rule based algorithms, always look at complete input file
// don't assume things
// here I was removing one operand as soon as I saw an operator, but that was the wrong thing to do
// see line 45 for details

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	char input[400];
	char output[400];
	int num;
	char cur;
	char pops;
	scanf("%d", &num);
	stack<char> chars;

	while(num--){
		scanf("%s", input);
		int len = strlen(input);
		int opcounter = 0;
		for(int i=0; i<len; i++){
			cur = input[i];
			switch(cur){
				case '(':
					chars.push(cur);
					break;
				case ')':
					while(true){
						output[opcounter++] = chars.top();
						chars.pop();
						if(chars.top() == '(')
							break;
					}
					chars.pop();
					break;
				case '*':
				case '+':
				case '-':
				case '/':
				case '^':
					if(chars.top() != '('){
						output[opcounter++] = chars.top();
						chars.pop();
						chars.push(cur);
					}
					else
						chars.push(cur);
					break;
				default:
					chars.push(cur);
			}
		}
		output[opcounter] = '\0';
		printf("%s\n", output);
	}

	return 0;
}