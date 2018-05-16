// copied division by 7 from
// <https://github.com/velazqua/competitive-programming/blob/master/online-judges/SPOJ/PUCMM025/PUCMM025.cpp>
// <https://kartikkukreja.wordpress.com/2013/12/22/divisibility-rules/>

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string ip;
	while(cin>>ip){
		bool div[10] = {};
		int counts[10] = {};
		int sum = 0;
		int len = ip.length();
		for(int i=0; i<len; ++i){
			sum += (ip[i]-'0');
			counts[ip[i]-'0']++;
		}
		// 1
		div[1] = true;
		// 2
		if(((ip[len-1]-'0')&1) == 0)
			div[2] = true;
		// 3
		if(sum%3 == 0)
			div[3] = true;
		// 4
		int temp;
		if(len>1)
			temp = ((ip[len-2]-'0')*10) + (ip[len-1]-'0');
		else
			temp = ip[len-1]-'0';
		if(temp%4 == 0)
			div[4] = true;
		// 5
		if(ip[len-1]-'0' == 0 or ip[len-1]-'0' == 5)
			div[5] = true;
		// 6
		div[6] = (div[2]&div[3]);
		// 7
		int seq[6] = {1,3,2,6,4,5};
		string revnum = ip;
		reverse( revnum.begin(), revnum.end());
		int revsum = 0;
		for(int j=0; j<len; ++j)
			revsum += ((revnum[j]-'0')*seq[j%6]);
		if(revsum%7 == 0)
			div[7] = true;
		// 8
		if(len>2)
			temp = ((ip[len-3]-'0')*100) + ((ip[len-2]-'0')*10) + (ip[len-1]-'0');
		else if(len>1)
			temp = ((ip[len-2]-'0')*10) + (ip[len-1]-'0');
		else
			temp = ip[len-1]-'0';
		if(temp%8 == 0)
			div[8] = true;
		// 9
		if(sum%9 == 0)
			div[9] = true;

		int ans = 0;
		for(int i=1; i<=9; ++i)
			ans += (div[i]*counts[i]);
		printf("%d\n", ans);
	}
	return 0;
}