// need not convert back and forth in some problems like these

#include <iostream>
#include <string>

using namespace std;

int main(){
	string temp;
	int ncases, i, carry;
	scanf("%d", &ncases);
	getline(cin, temp);
	while(ncases--){
		getline(cin, temp);
		int arr1[4] = {0};int arr2[4] = {0};int *cur;
		cur = arr1;
		i = 0;
		while(i<temp.length()){
			if(temp[i] == 'm'){
				if((i-1)!=-1 and temp[i-1]!=' ')
					cur[0]+=(temp[i-1] - '0');
				else
					cur[0] = 1;
			}
			else if(temp[i] == 'c'){
				if(isdigit(temp[i-1]))
					cur[1]+=(temp[i-1] - '0');
				else
					cur[1] = 1;
			}
			else if(temp[i] == 'x'){
				if(isdigit(temp[i-1]))
					cur[2]+=(temp[i-1] - '0');
				else
					cur[2] = 1;
			}
			else if(temp[i] == 'i'){
				if(isdigit(temp[i-1]))
					cur[3]+=(temp[i-1] - '0');
				else
					cur[3] = 1;
			}
			else if(temp[i] == ' '){
				cur = arr2;
			}
			i++;
		}
		carry = 0;
		for(i=3;i>=0;i--){
			carry = arr1[i]+arr2[i]+carry;
			arr1[i] = carry%10;
			carry/=10;
		}
		for(i=0;i<4;i++){
			if(arr1[i]){
				if(arr1[i]>1)
					cout<<arr1[i];
			}
			else
				continue;
			switch(i){
				case 0:
					cout<<'m';break;
				case 1:
					cout<<'c';break;
				case 2:
					cout<<'x';break;
				case 3:
					cout<<'i';break;
			}
		}
		cout<<endl;
	}
	return 0;
}