#include <iostream>
#include <queue>

#define ll long long
#define pq priority_queue

using namespace std;

int main(){
	ll testcases;
	scanf("%lld", &testcases);

	ll reqd, friends, temp, count = 0;
	bool flag;
	while(count < testcases){
		scanf("%lld %lld", &reqd, &friends);

		pq <ll> lists;
		while(friends--){
			scanf("%lld", &temp);
			lists.push(temp);
		}
		flag = false;
		friends++;
		while(!lists.empty()){
			reqd -= lists.top();
			lists.pop();
			friends++;
			if(reqd<=0){
				cout<<"Scenario #"<<count+1<<":"<<endl;
				cout<<friends<<endl<<endl;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<"Scenario #"<<count+1<<":"<<endl;
			cout<<"impossible"<<endl<<endl;
		}
		count++;
	}
	return 0;
}