#include <iostream>
#include <map>
#include <string>

#define mp make_pair

using namespace std;

int main(){
	string a, b;
	map<char,int> m;
	m.insert(mp('0',0));m.insert(mp('1',1));m.insert(mp('2',2));
	m.insert(mp('3',3));m.insert(mp('4',4));m.insert(mp('5',5));
	m.insert(mp('6',6));m.insert(mp('7',7));m.insert(mp('8',8));
	m.insert(mp('9',9));m.insert(mp('A',10));m.insert(mp('B',11));
	m.insert(mp('C',12));m.insert(mp('D',13));m.insert(mp('E',14));
	m.insert(mp('F',15));m.insert(mp('G',16));
	while(true){
		cin>>a>>b;
		if(a[0]=='*')
			break;
		int l = max(a.length(), b.length());
		int arr1[l] = {}, arr2[l] = {};
		int c = l-1;
		for(int i=a.length()-1; i>=0; --i){
			arr1[c--] = m[a[i]];
		}
		c = l-1;
		for(int i=b.length()-1; i>=0; --i){
			arr2[c--] = m[b[i]];
		}
		bool flag = true;
		for(int i=0; i<l; ++i){
			if(arr1[i] < arr2[i]){
				printf("<\n"); flag = false; break;
			}
			else if(arr2[i] < arr1[i]){
				printf(">\n"); flag = false; break;
			}
		}
		if(flag)
			printf("=\n");
	}
	return 0;
}