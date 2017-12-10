// fairly simple once you realize that you have to do ops in O(n) time
// you will need two more arrays to make everything O(1)

#include <iostream>
#include <sstream>
#include <string>

#define nrows 1234
#define ncols 5678

using namespace std;

int main(){

	string s;
	int count = 0;
	
	int arr[nrows + 1];
	for(int i=1; i<=nrows; ++i)
		arr[i] = i;
	
	int arc[ncols + 1];
	for(int i=1; i<=ncols; ++i)
		arc[i] = i;

	while(getline(cin,s)){
		stringstream ss;
		ss<<s;
		char c;
		int a, b, temp;

		if(s[0] == 'R'){
			ss>>c>>a>>b;
			temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
		if(s[0] == 'C'){
			ss>>c>>a>>b;
			temp = arc[a];
			arc[a] = arc[b];
			arc[b] = temp;
		}
		if(s[0] == 'Q'){
			ss>>c>>a>>b;
			cout<<((arr[a]-1)*ncols) + arc[b]<<endl;
		}
		if(s[0] == 'W'){
			ss>>c>>temp;

			a = temp%ncols == 0? temp/ncols : (temp/ncols) + 1;
			b = temp - ((a-1)*ncols);
			
			for(int i=1;i<=nrows; ++i)
				if(arr[i] == a) cout<<i<<" ";
			for(int i=1;i<=ncols; ++i)
				if(arc[i] == b) cout<<i<<endl;
		}
	}

	return 0;
}