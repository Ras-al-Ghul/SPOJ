// sometimes initialization may need to be done in a custom fashion
// after base case is properly handled, everything will fall into place

#include <iostream>
#include <string>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		string sone, stwo;
		cin>>sone>>stwo;
		int s1 = sone.length(), s2 = stwo.length();
		int arr[s1+1][s2+1] = {};
	
		int repeat = 0;
		if(sone[0] == stwo[0]){
			arr[1][1] = 0;
			repeat = 1;
		}
		else{
			arr[1][1] = 1;
		}
		for(int j=2;j<=s2;++j){
			if(sone[0] == stwo[j-1])
				if(not repeat){
					arr[1][j] = arr[1][j-1]; repeat = 1;
				}
				else
					arr[1][j] = arr[1][j-1] + 1;
			else
				arr[1][j] = arr[1][j-1] + 1;
		}

		repeat = 0;
		if(sone[0] == stwo[0]){
			arr[1][1] = 0;
			repeat = 1;
		}
		else{
			arr[1][1] = 1;
		}
		for(int i=2;i<=s1;++i){
			if(sone[i-1] == stwo[0])
				if(not repeat){
					arr[i][1] = arr[i-1][1]; repeat = 1;
				}
				else
					arr[i][1] = arr[i-1][1] + 1;
			else
				arr[i][1] = arr[i-1][1] + 1;
		}

		for(int i=2;i<=s1;++i){
			for(int j=2;j<=s2;++j){
				if(sone[i-1] == stwo[j-1])
					arr[i][j] = arr[i-1][j-1];
				else{
					arr[i][j] = min(arr[i-1][j], arr[i][j-1]) + 1;
					arr[i][j] = min(arr[i][j], arr[i-1][j-1] + 1);
				}
			}
		}
		cout<<arr[s1][s2]<<endl;
	}
	return 0;
}