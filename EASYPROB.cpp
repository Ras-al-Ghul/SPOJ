// thought source code had limit of 500B, but had to submit text file
// not clear problem description

#include<iostream>
#include<string>
#include<cmath>
#define e <<endl
#define z return
using namespace std;
string r(int n){
	int i=0;
	while(pow(2, i)<=n)
		i++;
	i--;
	if(n==0)
		z "";
	if(i==0 and n==pow(2,i))
		z "2(0)";
	if(i==1 and n==pow(2,i))
		z "2";
	n-=pow(2,i);
	if(r(i)!="2(0)")
		if(r(n)!="")
			z"2("+r(i)+")+"+r(n);
		else 
			z"2("+r(i)+")";
	else 
		z"2+"+r(n);
}
int main(){
	cout<<"137="<<r(137)e<<"1315="<<r(1315)e<<"73="<<r(73)e<<"136="<<r(136)e<<"255="<<r(255)e<<"1384="<<r(1384)e<<"16385="<<r(16385)<<endl;
}