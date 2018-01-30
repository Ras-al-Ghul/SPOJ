#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	while(getline(cin,input)){
		if(input.length() == 0){
			printf("\n");
			continue;
		}
		bool flag = false;
		int count = 0; char c = input[0];
		for(int i=0; i<input.length();){
			if(count == 0)
				c = input[i];
			while(input[i++] == c and count < 9){
				++count;
			}
			i--;
			if(count == 1){
				if(flag == false){
					if(c != '1')
						printf("1%c", c);
					else
						printf("111");
					flag = true;
				}
				else{
					if(c != '1')
						printf("%c", c);
					else
						printf("11");
				}
			}
			else if(count <= 9){
				if(flag){
					printf("1");
					flag = false;
				}
				printf("%d%c", count, c);
			}
			count = 0;
		}
		if(flag)
			printf("1");
		printf("\n");
	}
	return 0;
}