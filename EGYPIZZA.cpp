#include <iostream>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a, b;
	int q = 0, h = 0, tq = 0;
	while(n--){
		scanf("%d/%d", &a, &b);
		if(a==1)
			if(b==4)
				q++;
			else
				h++;
		else
			tq++;
	}
	int count = 0;
	int j = tq;
	while(tq--){
		if(q){
			q--;
		}
		else{
			break;
		}
	}
	count += (h/2);
	h%=2;
	int i = h;
	if(h){
		if(q){
			if(q>=2)
				q-=2;
			else
				q-=1;
		}
	}
	if(q%4)
		j+=1;
	count+=i+j+(q/4)+1;
	cout<<count<<endl;
	return 0;
}