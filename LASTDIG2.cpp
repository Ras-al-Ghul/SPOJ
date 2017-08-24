// read problem statement carefully
// here 'a' wouldn't fit into long long, it was a 1000 digit number, but we needed only last digit

#include <iostream>
#include <string>
#include <cstdlib>
#define ull unsigned long long
using namespace std;
ull mulmod(ull a, ull b, ull c=10){ull x = 0,y=a%c;while(b > 0){if(b%2 == 1)x = (x+y)%c;y = (y*2)%c;b /= 2;}return x%c;}
main(){
	ull n,a,b,i;string t,t1;scanf("%llu",&n);getline(cin,t);
	while(n--){
		t1="";bool z = 0;getline(cin, t);
		for(i=0;i<t.length();i++)
			if(t[i]==' '){a = (ull)(t[i-1]-'0');if(!(i-1))z = 1;break;}
		for(i=i+1;i<t.length();i++)
			t1 += t[i];
		b = stoull(t1);
		if(a==0 and b==0){
			if(z)cout<<0<<endl;
			else cout<<1<<endl;
			continue;
		}
		ull x=1, y=a;
		while(b>0){
			if(b%2 == 1)x=mulmod(x,y);
			y=mulmod(y,y);
			b/=2;
		}
		cout<<x%10<<endl;
	}
}