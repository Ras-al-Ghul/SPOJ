#include <iostream>
#include <string>
#include <map>

#define psul pair<string, unsigned long long>
#define pcs pair<char, string>
#define ull unsigned long long

using namespace std;

int main(){
	string ip, temp, tempans;
	
	map<string, unsigned long long> stoimap;
	stoimap.insert(psul("063",0));stoimap.insert(psul("010",1));
	stoimap.insert(psul("093",2));stoimap.insert(psul("079",3));
	stoimap.insert(psul("106",4));stoimap.insert(psul("103",5));
	stoimap.insert(psul("119",6));stoimap.insert(psul("011",7));
	stoimap.insert(psul("127",8));stoimap.insert(psul("107",9));

	map<char, string> itosmap;
	itosmap.insert(pcs('0',"063"));itosmap.insert(pcs('1',"010"));
	itosmap.insert(pcs('2',"093"));itosmap.insert(pcs('3',"079"));
	itosmap.insert(pcs('4',"106"));itosmap.insert(pcs('5',"103"));
	itosmap.insert(pcs('6',"119"));itosmap.insert(pcs('7',"011"));
	itosmap.insert(pcs('8',"127"));itosmap.insert(pcs('9',"107"));

	while(true){
		cin>>ip;
		if(ip == "BYE")
			break;
		ull ans = 0, a = 0, b = 0;
		ull i = 0,j = 0;
		temp = "";
		while(ip[i] != '+'){
			temp += ip[i++];
			if(i%3 == 0){
				a = (a*10) + (stoimap.find(temp))->second;
				temp = "";
			}
		}
		i++;
		temp = "";
		while(ip[i+j] != '='){
			temp += ip[i+(j++)];
			if(j%3 == 0){
				b = (b*10) + (stoimap.find(temp))->second;
				temp = "";
			}
		}
		ans = a+b;
		temp = to_string(ans);
		tempans = "";
		i = 0;
		while(i<temp.length()){
			tempans += itosmap.find(temp[i++])->second;
		}
		cout<<ip<<tempans<<endl;
	}
	return 0;
}