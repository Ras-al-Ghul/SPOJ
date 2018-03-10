// Tim Roughgarden reconstruction of solution idea
// backtrack here
// naive backtrack is slow, how to make it fast is not intuitive
// have to see what backtrack is repeating
// turns out it processes same string at same index many times

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define MAX 82

using namespace std;

int arr[MAX][MAX][2];
set <string> anss;
string a,b;
int lena,lenb,len;

void backtrack(int fir, int sec, set<string> processed[MAX][MAX], string an = ""){
	// if you've processed the same end part of string 'at this index'
	// don't process it again
	// this literally saves ass
	// very non obvious to spot why the backtracking was taking so much time
	// this is the reason --> processes same string at same index multiple times
	if(processed[fir][sec].find(an) != processed[fir][sec].end())
		return;
	if(arr[fir][sec][1] == 0){
		anss.insert(an);
	}
	else if(arr[fir][sec][1] == 1){
		an = a[sec-1] + an;
		backtrack(fir-1,sec-1,processed,an);
	}
	else if(arr[fir][sec][1] == 2){
		backtrack(fir-1,sec,processed,an);
	}
	else if(arr[fir][sec][1] == 3){
		backtrack(fir,sec-1,processed,an);
	}
	else{
		backtrack(fir-1,sec,processed,an);
		backtrack(fir,sec-1,processed,an);
	}
	processed[fir][sec].insert(an);
}

int main(){
	int n; scanf("%d", &n);
	while(n--){
		anss.clear();
		set<string> processed[MAX][MAX];
		cin>>a>>b;
		lena = a.length(), lenb = b.length();
		// one extra index for base cases
		// in the [2], [0] holds values, [1] holds directions
		// [1] --> 0:base case 1:diag 2:top 3:left 4:top/left
		
		for(int i=0; i<=lena; ++i)
			arr[0][i][0] = 0, arr[0][i][1] = 0;
		for(int i=0; i<=lenb; ++i)
			arr[i][0][0] = 0, arr[i][0][1] = 0;
		// a is horizontal b is vertical
		// hence b uses rows, a uses cols
		for(int i=1; i<=lenb; ++i){
			for(int j=1; j<=lena; ++j){
				// string index starts from 0
				if(b[i-1] == a[j-1]){
					arr[i][j][0] = arr[i-1][j-1][0] + 1;
					arr[i][j][1] = 1;
				}
				else{
					arr[i][j][0] = max(arr[i-1][j][0], arr[i][j-1][0]);
					if(arr[i-1][j][0] == arr[i][j-1][0])
						arr[i][j][1] = 4;
					else if(arr[i-1][j][0] == arr[i][j][0])
						arr[i][j][1] = 2;
					else
						arr[i][j][1] = 3;
				}
			}
		}
		// for(int i=0; i<lenb+1; ++i){
		// 	for(int j=0; j<lena+1; ++j){
		// 		cout<<arr[i][j][1]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// printf("%d\n", arr[lenb][lena][0]);
		len = arr[lenb][lena][0];

		// no need of this because of the 'processed[i][j]' thing
		// just doing it for backtrack(lenb, lena) is enough

		// holds all the indices from where to start backtracking
		// vector<pair<int, int> > vals;
		// for(int i=lenb; i>0; --i){
		// 	bool flag = true;
		// 	for(int j=lena; j>0; --j){
		// 		if(arr[i][j][0] == len)
		// 			vals.pb(mp(i,j));
		// 		else if(arr[i][j][0] < len){
		// 			break;
		// 			if(j==lena)
		// 				flag = false;
		// 		}
		// 	}
		// 	if(not flag)
		// 		break;
		// }
		// int fir, sec;
		// for(auto it = vals.begin(); it!=vals.end(); ++it){
		// 	fir = it->first, sec = it->second;
		// 	if(arr[fir][sec][1] == 1)
				// backtrack(fir,sec,processed);
		backtrack(lenb, lena, processed);
		// 	else
		// 		continue;
		// }
		if(anss.begin() != anss.end())
			for(auto it = anss.begin(); it!=anss.end(); ++it){
				cout<<(*it)<<endl;
			}
		else
			cout<<endl;
		if(n)
			cout<<endl;
	}
	return 0;
}