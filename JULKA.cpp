// don't mess up where variables are reused
// in this case 'carry' was reused but it was not being reset correctly every time
// plus take care of edge cases >=, > while subtracting numbers

#include <iostream>
#include <string>

#define MAXSIZE 105

using namespace std;

int main(){
	int sum[MAXSIZE], morethan[MAXSIZE];
	int sumleft, morethanleft;

	int diff[MAXSIZE];
	int diffleft;

	int quo[MAXSIZE];
	int quoright;

	int klaudia[MAXSIZE];
	int klaudialeft;

	string input;

	int testcases = 10;
	while(testcases--){
		cin>>input;
		sumleft = MAXSIZE-1;
		for(int i=input.length()-1; i>=0; i--){
			sum[sumleft--] = input[i] - '0';
		}
		sumleft++;

		cin>>input;
		morethanleft = MAXSIZE-1;
		for(int i=input.length()-1; i>=0; i--){
			morethan[morethanleft--] = input[i] - '0';
		}
		morethanleft++;

		// do (sum - morethan)
		diffleft = MAXSIZE-1;
		for(int i=MAXSIZE-1; i>=sumleft; i--){
			int subtract;
			if(i<morethanleft)
				subtract = 0;
			else
				subtract = morethan[i];
			if(sum[i] >= subtract){
				diff[diffleft--] = sum[i] - subtract;
			}
			else{
				if((i-1)>=sumleft){
					sum[i-1] -= 1;
					diff[diffleft--] = sum[i] + 10 - subtract;
				}
			}
		}
		diffleft++;

		// divide by 2
		quoright = 0;
		for(int i=diffleft; i<MAXSIZE; i++){
			quo[quoright++] = diff[i]/2;
			if((i+1) < MAXSIZE)
				diff[i+1] += ((diff[i]%2) * 10);
		}
		quoright--;

		// shift to rightmost style
		for(int i=quoright; i>=0; i--){
			quo[MAXSIZE - 1 - quoright + i] = quo[i];
		}
		quoright = MAXSIZE - 1 - quoright;

		// make both lengths equal
		if(quoright>morethanleft){
			for(int i=morethanleft; i<quoright; i++)
				quo[i] = 0;
		}
		else if(morethanleft>quoright){
			for(int i=quoright; i<morethanleft; i++)
				morethan[i] = 0;
		}

		// add morethan to whatever the quotient is
		int carry = 0;
		int sums;
		klaudialeft = MAXSIZE-1;
		for(int i=MAXSIZE-1; i>= min(quoright, morethanleft); i--){
			sums = carry + quo[i] + morethan[i];
			if(sums > 9){
				klaudia[klaudialeft--] = sums%10;
				carry = sums/10;
			}
			else{
				klaudia[klaudialeft--] = sums;
				carry = 0;
			}
		}
		if(carry != 0)
			klaudia[klaudialeft--] = carry;
		klaudialeft++;

		// move to first non zero number
		for(int i=klaudialeft; i<MAXSIZE; i++){
			if(klaudia[i] != 0){
				klaudialeft = i;
				break;
			}
		}
		for(int i=klaudialeft; i<MAXSIZE; i++){
			printf("%d", klaudia[i]);
		}
		printf("\n");

		// move to first non zero number
		for(int i=quoright; i<MAXSIZE; i++){
			if(quo[i] != 0){
				quoright = i;
				break;
			}
		}
		for(int i=quoright; i<MAXSIZE; i++){
			printf("%d", quo[i]);
		}
		printf("\n");
	}

	return 0;
}