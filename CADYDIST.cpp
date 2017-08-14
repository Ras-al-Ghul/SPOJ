// still using google for stdlib structures
// should avoid that

#include <iostream>
#include <queue>

using namespace std;

int main(){
	long long n, i, temp, ans;
	while(true){
		scanf("%lld", &n);
		if(n==0)
			break;
		priority_queue<long long> students;
		priority_queue<long long, vector<long long>, greater<long long> > prices;

		for(i=0;i<n;i++){
			scanf("%lld", &temp);
			students.push(temp);
		}
		for(i=0;i<n;i++){
			scanf("%lld", &temp);
			prices.push(temp);
		}
		ans = 0;
		for(i=0;i<n;i++){
			ans = ans + (students.top()*prices.top());
			students.pop();
			prices.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
