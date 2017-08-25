// look into suffix arrays
// this had tough edge cases

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	int ncases, i, beadslen, length, maxlen, j, k;
	char c, maxchar;
	scanf("%d", &ncases);
	string beads, temp;
	while(ncases--){
		map<string,int> array;
		cin>>beads;
		beadslen = beads.length();
		bool overflowflag = false;
		i = 0; c = '{'; // '{' > 'z', hence
		length = 0; maxlen = 10001; maxchar = '{';
		while(true){
			if(beads[i] < c){
				c = beads[i]; length = 1;
			}
			else if(beads[i] == c){
				if(length != 0)
					length++;
				else{
					length = 1;
				}
			}
			else{
				if(c<=maxchar){
					if(c==maxchar){
						if(length>maxlen){
							maxchar = c;
							maxlen = length;
							length = 0;
						}
					}
					else{
						maxchar = c;
						maxlen = length;
						length = 0;
					}
				}
				length = 0;
				if(overflowflag)
					break;
			}
			if(i+1 == beadslen){
				if(overflowflag){
					maxchar = c;
					maxlen = beadslen;
					break;
				}
				else
					overflowflag = true;
			}
			i = (i+1)%beadslen;
		}
		// cout<<maxchar<<" "<<maxlen<<endl;
		for(i=0;i<beadslen;i++){
			int m = i;
			if(beads[i]==maxchar){
				j = 0; temp = ""; int index = i;
				while(beads[i]==maxchar and j!=maxlen){
					temp += beads[i];
					i=(i+1)%beadslen; j++;
				}
				if(j==maxlen){
					k = i; int up = (beadslen-j);
					while(up--){
						temp += beads[k];
						k=(k+1)%beadslen;
					}
					array.insert(pair<string,int>(temp,index));
				}
			}
			i = m;
		}
		// for(auto it = array.begin();it!=array.end();it++){
		// 	cout<<it->first<<" "<<it->second<<endl;
		// }
		cout<<array.begin()->second+1<<endl;
		// cout<<endl;
	}
	return 0;
}