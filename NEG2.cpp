// in these kind of problems, look for patterns in numbers
// because of - and +, instead of dealing in twos, we dealt in fours
// edge cases like in line 57-58, line 91-94

#include <iostream>
#include <cstdlib>
#include <cmath>

#define ll long long

using namespace std;

int main(){
	ll num;
	scanf("%lld", &num);
	ll toggle, twopow, maxsum;
	if(num>=0){
		twopow = 1;
		maxsum = 1;
		toggle = 1;
		while(maxsum < num){
			twopow = twopow * 4 * toggle;
			maxsum += twopow;
		}
	}
	else{
		maxsum = -2;
		twopow = -2;
		toggle = 1;
		while(maxsum > num){
			twopow = twopow * 4 * toggle;
			maxsum += twopow;
		}
	}
	if(num == 0){
		cout<<0<<endl;
		return 0;
	}
	ll fir, sec, thi, fou;
	if(num > 0){
		cout<<1;
		ll diff = maxsum - twopow;
		ll tempnum = num - diff;
		fir = twopow/4; sec = twopow/2; thi = fir*3; fou = twopow;
		while(fir != sec){
			if(tempnum<=fir)
				cout<<"10";
			else if(tempnum>fir and tempnum<=sec)
				cout<<"11";
			else if(tempnum>sec and tempnum<=thi)
				cout<<"00";
			else
				cout<<"01";
			twopow /= 4;
			fir = twopow/4; sec = twopow/2; thi = fir*3; fou = twopow;
			tempnum %= twopow;
			if(tempnum == 0)
				tempnum = twopow;
		}
		cout<<endl;
		return 0;
	}

	ll forhalf = twopow/2;

	ll diff = abs(maxsum - twopow);
	ll tempnum = num + diff;

	fir = forhalf/4; sec = forhalf/2; thi = fir*3; fou = forhalf;
	if(tempnum>=forhalf){
		cout<<11;
	}
	else{
		cout<<10;
		fir += forhalf; sec += forhalf; thi += forhalf; fou += forhalf;
	}
	while(fir != sec){
		if(tempnum>=fir)
			cout<<"01";
		else if(tempnum<fir and tempnum>=sec)
			cout<<"00";
		else if(tempnum<sec and tempnum>=thi)
			cout<<"11";
		else
			cout<<"10";
		forhalf /= 4;
		fir = forhalf/4; sec = forhalf/2; thi = fir*3; fou = forhalf;
		if(tempnum<forhalf){
			fir += forhalf; sec += forhalf; thi += forhalf; fou += forhalf;		
		}
		if(tempnum<forhalf)
			tempnum = (tempnum%forhalf) + forhalf;
		else
			tempnum %= forhalf;
	}

	cout<<endl;
	return 0;
}