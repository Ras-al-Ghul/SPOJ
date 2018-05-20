// given that it is greedy, then it becomes slightly easier to solve
// notice that it is costlier to keep earlier demands pending for
// longer time because the distance increases, hence earlier a demand
// occurs, earlier it has to be satisfied, something like fcfs
// which motivates something like a queue, but how about handling things
// to the right which we haven't seen yet, treat buys and sells similarly
// meaning buy = -sell like they can be treated homogeneously
// i.e. maintain two queues and use appropriate signs, then that problem
// gets solved, so in short, keep a buy queue, keep a sell queue, satisfy
// buys and sells as you traverse from left to right

#include <iostream>
#include <queue>

#define mp make_pair
#define ll long long

using namespace std;

int main(){
	ll n, i, ip, temp;
	while(scanf("%lld", &n)==1){
		if(n==0)
			break;
		queue<pair<ll,ll> > buy;
		queue<pair<ll,ll> > sell;
		ll ans = 0;
		for(i=0; i<n; ++i){
			scanf("%lld", &ip);
			if(ip>0){
				if(not sell.empty()){
					while((not sell.empty()) and ip>0){
						temp = min(ip, sell.front().first);
						ans += (temp*(i-sell.front().second));
						if(temp < ip or temp == sell.front().first)
							sell.pop();
						else
							sell.front().first -= temp;
						ip -= temp;
					}
					if(ip>0)
						buy.push(mp(ip,i));
				}
				else
					buy.push(mp(ip,i));
			}
			else if(ip<0){
				if(not buy.empty()){
					ip = (-ip);
					while((not buy.empty()) and ip>0){
						temp = min(ip, buy.front().first);
						ans += (temp*(i-buy.front().second));
						if(temp < ip or temp == buy.front().first)
							buy.pop();
						else
							buy.front().first -= temp;
						ip -= temp;
					}
					if(ip>0)
						sell.push(mp(ip,i));
				}
				else
					sell.push(mp(-ip,i));
			}
		}
		printf("%lld\n", ans);
	}
}