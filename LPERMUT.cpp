#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

int main(){
	int n; scanf("%d", &n);
	int arr[MAX][2] = {};
	queue<int> sofar;
	int maxlen = 0, ip, index = 0, lastind, firstind, t;
	int spacearr[MAX][2] = {};
	for(int i=1; i<=n; ++i){
		scanf("%d", &ip);
		if(arr[ip][0]){
			if(arr[1][0] == 1){
				int newspacearr[100001] = {};
				int temp = arr[1][1];
				while(spacearr[temp][0] == 1 and temp < MAX){
					newspacearr[spacearr[temp][1]] = 1;
					++temp;
				}
				temp = arr[1][1];
				while(spacearr[temp][0] == 1 and temp > 0){
					newspacearr[spacearr[temp][1]] = 1;
					--temp;
				}
				temp = 1;
				while(newspacearr[temp] == 1 and temp < MAX)
					++temp;
				maxlen = max(maxlen, temp-1);
			}

			// take care of index
			
			while(sofar.front() != ip){
				t = sofar.front();
				spacearr[arr[t][1]][0] = 0; spacearr[arr[t][1]][1] = 0;
				arr[t][0] = 0; arr[t][1] = 0;
				sofar.pop();
			}
			// don't reset arr for ip, because it is already set
			sofar.pop(); // pop ip --> previous position
			sofar.push(ip); // push ip --> now it is in its correct new position
			arr[ip][1] = i; // setting new position of ip
		}
		else{
			sofar.push(ip);
			arr[ip][0] = 1; arr[ip][1] = i;
			if(index == i-1){
				while(arr[index+1][0] == 1 and index+1<MAX){
					++index;
					spacearr[arr[index][1]][0] = 1; spacearr[arr[index][1]][1] = index;
				}
			}
		}
	}

	index = 1; //int spacearr[MAX][2] = {};
	while(arr[index][0] == 1 and index < MAX){
		spacearr[arr[index][1]][0] = 1;
		spacearr[arr[index][1]][1] = index;
		++index;
	}
	if(arr[1][0] == 1){
		int newspacearr[100001] = {};
		int temp = arr[1][1];
		while(spacearr[temp][0] == 1 and temp < MAX){
			newspacearr[spacearr[temp][1]] = 1;
			++temp;
		}
		temp = arr[1][1];
		while(spacearr[temp][0] == 1 and temp > 0){
			newspacearr[spacearr[temp][1]] = 1;
			--temp;
		}
		temp = 1;
		while(newspacearr[temp] == 1 and temp < MAX)
			++temp;
		maxlen = max(maxlen, temp-1);
	}


	printf("%d\n", maxlen);
	return 0;
}