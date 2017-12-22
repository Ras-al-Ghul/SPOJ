#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int n, length, temp;
	string name;
	while(true){
		scanf("%d %d", &n, &length);
		if(n == 0)
			break;
		map<string, int> dic;
		int arr[n] = {};
		for(int i=0; i<n; ++i){
			cin>>name;
			auto it = dic.find(name);
			if(it != dic.end()){
				temp = it->second;
				if(arr[temp-1] != 0)
					arr[temp-1]--;
				arr[temp]++;
				(it->second)++;
			}
			else{
				dic[name] += 1;
				arr[0]++;
			}
		}
		for(int i=0; i<n; ++i){
			printf("%d\n", arr[i]);
		}
	}
	return 0;
}