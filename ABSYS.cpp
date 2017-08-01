// string s;

// bool has_only_digits = (s.find_first_not_of( "0123456789" ) == string::npos);

// these lines led to two SIGABRTs
// sometimes fancy things may not work

#include <iostream>
#include <string>

#define ll long long

using namespace std;

int main(){
	ll numoftestcases;
	scanf("%lld", &numoftestcases);

	ll x, y, ans;
	string line, xx, yy, ansans;
	getline(cin, line);
	while(numoftestcases--){
		getline(cin, line);
		while(line == ""){
			getline(cin, line);
		}

		ll i = 0;
		xx = "", yy = "", ansans = "";
		ll where = 2;
		while(i<line.length()){
			if(line[i] == '+' || line[i] == 'm'){
				if(line[i] == 'm'){
					where = 0;
					xx += line[i];
					i++;
					continue;
				}
				i+=2;
				break;
			}
			xx += line[i];
			i++;
		}
		while(i<line.length()){
			if(line[i] == '=' || line[i] == 'm'){
				if(line[i] == 'm'){
					where = 1;
					yy += line[i];
					i++;
					continue;
				}
				i+=2;
				break;
			}
			yy += line[i];
			i++;
		}
		while(i<line.length()){
			ansans += line[i];
			i++;
		}

		if(where!=2){
			ans = stoll(ansans);
			if(where!=0){
				x = stoll(xx);
				cout<<x<<" + "<<ans-x<<" = "<<ans<<endl;
			}
			else{
				y = stoll(yy);
				cout<<ans-y<<" + "<<y<<" = "<<ans<<endl;
			}
		}
		else{
			x = stoll(xx);
			y = stoll(yy);
			cout<<x<<" + "<<y<<" = "<<x+y<<endl;
		}
	}
	return 0;
}