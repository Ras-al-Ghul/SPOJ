#include <iostream>
#include <string>

using namespace std;

int main(){
	char first[] = {'a','e','i','o','u'};
	char second[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
	int map[] = {0,0,1,2,1,3,4,5,2,6,7,8,9,10,3,11,12,13,14,15,4,16,17,18,19,20};
	int n, ind, cur; scanf("%d", &n);
	while(n--){
		string input; cin>>input;
		string output = "";
		int occur[26] = {};
		for(int i=0; i<input.length(); ++i){
			ind = input[i] - 97;
			if(input[i] == 'a' or input[i] == 'e' or input[i] == 'i' or input[i] == 'o' or input[i] == 'u'){
				cur = occur[ind];
				cur = (cur * 5); cur+=map[ind];
				cur = cur%21; output += second[cur];
				occur[ind]++;
			}
			else{
				cur = occur[ind];
				cur = (cur * 21); cur+=map[ind];
				cur = cur%5; output += first[cur];
				occur[ind]++;
			}
		}
		cout<<output<<endl;
	}
	return 0;
}