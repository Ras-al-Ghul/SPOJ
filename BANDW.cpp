#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char first[600], second[600];
	while(true){
		scanf("%s %s ", first, second);
		if(first[0]=='*')
			break;
		int count = 0, size = strlen(first);
		for(int i=0; i<size;){
			while(first[i]==second[i] and i<size)
				++i;
			if(first[i] != second[i] and i<size){
				while(first[i]!=second[i] and i<size)
					++i;
				++count;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}