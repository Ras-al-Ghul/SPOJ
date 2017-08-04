// maybe the first time I handled all special cases correctly in the first go!

#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	bool isJ, isC, firstlastchar;
	while(getline(cin, line)){
		isJ = false;
		isC = false;

		firstlastchar = false;
		if((line[0] >= 97 and line[0] <= 122) and ((line[line.length() - 1] >= 97 and line[line.length() - 1] <= 122) or (line[line.length() - 1] >= 65 and line[line.length() - 1] <= 90)))
			firstlastchar = true;

		char prevchar = '_';
		for(int i=0; i<line.length(); i++){
			if(line[i] == '_'){
				if(prevchar == '_')
					firstlastchar = false;
				isC = true;
			}
			if(line[i] - 'A' >= 0 && line[i] - 'A' <= 25){
				isJ = true;
			}
			prevchar = line[i];
		}
		string opstring = "";
		if(isC and !isJ and firstlastchar){
			for(int i=0; i<line.length(); i++){
				if(line[i] == '_'){
					opstring += (char)((int)(line[i+1]) - 32);
					i++;
					continue;
				}
				else{
					opstring += line[i];
				}
			}
			cout<<opstring<<endl;
			continue;
		}
		else if(isJ and !isC and firstlastchar){
			for(int i=0; i<line.length(); i++){
				if(line[i] - 'A' >= 0 and line[i] - 'A' <= 25){
					opstring += '_';
					opstring += (char)((int)(line[i]) + 32);
				}
				else
					opstring += line[i];
			}
			cout<<opstring<<endl;
			continue;
		}
		else if((isC and isJ) or !firstlastchar){
			cout<<"Error!"<<endl;
			continue;
		}
		else
			cout<<line<<endl;
	}
	return 0;
}