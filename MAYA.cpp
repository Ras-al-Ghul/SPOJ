#include <iostream>
#include <string>
#define ull unsigned long long

using namespace std;

int main(){
	ull lines;
	string temp;
	string line;
	ull arr[7] = {1, 20, 360, 7200, 144000, 2880000, 57600000};
	ull dig, i, ans;
	while(1){
		getline(cin, temp);
		if(temp == "")
			continue;
		else
			lines = stoull(temp);
		if(lines==0)
			break;
		ans = 0;
		while(lines--){
			dig = 0;
			getline(cin, line);
			if(line=="S"){
				continue;
			}
			for(i=0; i<line.length(); i++){
				if(line[i]=='.')
					dig++;
				else if(line[i]=='-')
					dig+=5;
			}
			ans = ans + (dig*arr[lines]);
		}
		cout<<ans<<endl;
	}
	return 0;
}