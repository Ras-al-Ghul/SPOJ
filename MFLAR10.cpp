// edge case and string handling

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string temp,line;

	while(true){
		
		getline(cin, line);
		if(line == "*")
			break;

		bool flag = false;
		int current = 0;
		
		stringstream ss(line);
		while(ss>>temp){
			if((int(temp[0]) + 32) == current or (int(temp[0]) - 32) == current or (int(temp[0])) == current)
				continue;
			else{
				if(current == 0){
					current = int(temp[0]);
				}
				else{
					flag = true;
					break;
				}
			}
		}
		if(flag or line[0] == ' ')
			cout<<"N"<<endl;
		else
			cout<<"Y"<<endl;
	}
	return 0;
}