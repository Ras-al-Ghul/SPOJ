// probably one of the toughest to handle edge cases
// <https://apps.topcoder.com/forums//?module=Thread&threadID=567782&mc=30&view=threaded>
// very important
// 0. Count total digits, and count total digit modulo 3 --> remainder.
// 1. Choose last digit, if there are any 0, use it, if there are any 5, use it as last digit, otherwise it is impossible.
// 2. If remainder is 0, we're done, print all the digits from 9 to 0.
// 3. If remainder is 1, try to substract with proper number, I guess maybe this is where I missed something, I thought that you could ignore all 0,3,6,9 digits, because substracting them would not change anything.
// - I will consider first trying to substract just one digit, any f 1's,4's or 7's. If there are none of these then
// - I will consider trying to substract two digits, combination of 2,5,8. in this order (2,2), (5,2), (5,5), (8,2), (8,5) or (8,8).
// 4. If remainder is 2, do similar to step 3, with 1,4,7 replaced with 2,5,8.

// up to speed until - 'subtracting more than two digits is useless'
// that was the critical insight

// I consider removing numbers from either these two set of number (1,4,7) which are 1 in modulo 3 and (2,5,8) which are 2 in modulo 3. I guess you agree removing 0,3,6,9 will have no effects on remainder.
// Removing three numbers either a,b,c from the first or A,B,C from second set:
// if all 3 from the first set it will have no effect. if before removing you have X, after removing you have X-(a+b+c). Where (a+b+c)%3 == 0 since a%3, b%3, c%3 == 1. So (X-(a+b+c))%3 is still the same as X%3.
// Taking one from the first set and two from the second set will have the same effect as taking just one from the second set. X-(a+B+C) = X-(1+2+2)%3 = X-2;
// Taking two from the first set and one from the second set will have the same effect as just taking one from the first X-(a+b+C) = X-(1+1+2)%3 = X-1;
// Taking all from the second set will have no effect with similar explanation as taking all from the first. 

// I am too lazy to think further, but basically since we are working with modulo 3, removing any n numbers, will have only 3 kinds of effects, either the same as adding 0, 1, or 2.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline int count(string num){
	int sum = 0;
	for(int i=0; i<num.length(); ++i)
		sum += num[i];
	return sum;
}

inline string removeleadingzero(string num){
	int i = 0;
	while(num[i] == '0' and i<(num.length()-1)){
		num.erase(0,1);
	}
	return num;
}

int main(){
	int ncases;
	string input;
	size_t found;
	cin>>input;
	ncases = stoi(input);
	while(ncases--){
		cin>>input;
		sort(input.begin(), input.end(), greater<char>());

		int len = input.length();
		if(input[len-1] != '0'){
			found = input.find('5');
			if(found == string::npos){
				printf("impossible\n");
				continue;
			}
			else{
				input.erase(found, 1);
				input += "5";
			}
		}
		// check divisibility by 3
		int rem = count(input) % 3;
		if(rem == 0){
			input = removeleadingzero(input);
			cout<<input<<endl;
		}
		else if(rem == 1){
			if(input.find('1') != string::npos or input.find('4') != string::npos or input.find('7') != string::npos){
				if(input.find('1') != string::npos){
					found = input.find('1');input.erase(found, 1);
				}
				else if(input.find('4') != string::npos){
					found = input.find('4');input.erase(found, 1);
				}
				else{
					found = input.find('7');input.erase(found, 1);
				}
				input = removeleadingzero(input);
				cout<<input<<endl;
			}
			else{
				string five = "";
				if(input[input.length()-1] == '5'){
					five = "5";
					input.erase(input.length()-1,1);
				}
				bool flag = false;
				char arr[6][2] = {{'2','2'},{'5','2'},{'5','5'},{'8','2'},{'8','5'},{'8','8'}};
				for(int i=0;i<6;++i){
					if(input.find(arr[i][0]) != string::npos and input.find(arr[i][1],input.find(arr[i][0])+1) != string::npos){
						found = input.find(arr[i][0]);input.erase(found, 1);
						found = input.find(arr[i][1]);input.erase(found, 1);
						input = removeleadingzero(input);
						cout<<input+five<<endl;
						flag = true;
						break;
					}
				}
				if(not flag)
					printf("impossible\n");
			}
		}
		else{
			string five = "";
			if(input[input.length()-1] == '5'){
				five = "5";
				input.erase(input.length()-1,1);
			}
			if(input.find('2') != string::npos or input.find('5') != string::npos or input.find('8') != string::npos){
				if(input.find('2') != string::npos){
					found = input.find('2');input.erase(found, 1);
				}
				else if(input.find('5') != string::npos){
					found = input.find('5');input.erase(found, 1);
				}
				else{
					found = input.find('8');input.erase(found, 1);
				}
				input = removeleadingzero(input);
				cout<<input+five<<endl;
			}
			else{
				bool flag = false;
				char arr[6][2] = {{'1','1'},{'4','1'},{'4','4'},{'7','1'},{'7','4'},{'7','7'}};
				for(int i=0;i<6;++i){
					if(input.find(arr[i][0]) != string::npos and input.find(arr[i][1],input.find(arr[i][0])+1) != string::npos){
						found = input.find(arr[i][0]);input.erase(found, 1);
						found = input.find(arr[i][1]);input.erase(found, 1);
						input = removeleadingzero(input);
						cout<<input<<endl;
						flag = true;
						break;
					}
				}
				if(not flag)
					printf("impossible\n");
			}	
		}

	}
	return 0;
}