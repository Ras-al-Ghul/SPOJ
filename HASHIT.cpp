// straightforward hashing

#include <iostream>
#include <string>

using namespace std;

int Hash(string key){
	int sum = 0;
	for(int i=0; i<key.length(); ++i){
		sum = sum + ((int(key[i])*(i+1))%101);
		sum = sum % 101;
	}
	sum = (19*sum)%101;
	return sum;
}

int collision(int hash, int num){
	return ((hash + (num*num) + (23*num)) % 101);
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int numcases;
		scanf("%d", &numcases);
		string arr[101] = {};
		int numofkeys = 0;

		while(numcases--){
			string input;
			cin>>input;

			// 0 for ADD, 1 for DEL
			int op = 0;
			if(input[0] == 'D')
				op = 1;

			string key = "";
			int i = 0;
			while(input[i] != ':')
				++i;
			key = input.string::substr(i+1, input.length());
			
			int hkey = Hash(key);

			if(not op){
				// ADD
				bool flag = false;
				// check if key exists
				for(int i=0; i<=19; ++i){
					int position = collision(hkey, i);
					if(arr[position] == key){
						flag = true;
						break;
					}
				}

				if(flag)
					continue;

				if(arr[hkey] == ""){
					arr[hkey] = key;
					++numofkeys;
				}
				else{
					for(int i=1; i<=19; ++i){
						int position = collision(hkey, i);
						if(arr[position] == ""){
							arr[position] = key;
							++numofkeys;
							break;
						}
					}
				}
			}
			else{
				// DEL
				if(arr[hkey] == key){
					arr[hkey] = "";
					--numofkeys;
				}
				else{
					for(int i=1; i<=19; ++i){
						int position = collision(hkey, i);
						if(arr[position] == key){
							arr[position] = "";
							--numofkeys;
							break;
						}
					}
				}
			}
		}
		printf("%d\n", numofkeys);
		for(int i=0; i<101; ++i)
			if(arr[i] != "")
				cout<<i<<":"<<arr[i]<<endl;
	}
	return 0;
}