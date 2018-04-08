#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <iterator>

#define mp make_pair
#define pq priority_queue

using namespace std;

// trying to replicate processing things in order
// <http://discuss.spoj.com/t/picad-problem-58-wa/2595/5>
// 5 10 (observe)
// 4
// 1 8
// 5 8
// 7 10
// 8 9

// 1(1+): x
// 5(2+): x x
// 5(0+) : x x (start to update max and min), max = min =2.
// 7(3+) : x x X , max = min =3.
// 8(4+) : x x x x, max = min = 4
// 8(1-) : x x x, max=4, min =3
// 8(2-) : x x, max = 4, min = 2
// 9(3-) : x, max = 4, min = 1
// 10(0-) : x , break.
int main(){
	int c1, c2, N, a, b;
	while (scanf("%d %d %d", &c1, &c2, &N) == 3){
		pq<int, vector<pair<int,int> >, greater<pair<int,int> > > t;
		for(int i=0; i<N; ++i){
			scanf("%d %d", &a, &b);
			t.push(mp(a,1)); t.push(mp(b,4));
		}
		t.push(mp(c1,2)); t.push(mp(c2,3));

		// counting for min and max:
		// order:
		// add before
		// c1
		// count min, max
		// subtract if any

		// add
		// count min, max
		// subtract
		// count min, max

		// add
		// c2
		// count min, max
		// neglect
		int minc = INT_MAX, maxc = 0, c = 0;
		bool flag = false;
		for(int i=0; i<(N*2)+2; ++i){
			a = t.top().first; b = t.top().second;
			if(a >= c1 and a <= c2 and flag){
				minc = min(minc, c);
				maxc = max(maxc, c);
			}
			if(b == 1)
				++c;
			else if(b == 4)
				--c;
			else if(b == 3)
				break;
			else
				flag = true;
			t.pop();
		}

		printf("%d %d\n", minc, maxc);
	}
}
// this code is still fine, but the flow might not be right
// what to do and how to process events
// but the idea of pq and event processing one at a time (both enter and leave together) is correct
// instead of mixing two approaches - one for max and one for min,
// a cohesive approach is better
// int main(){
// 	int c1, c2, N;
// 	while (scanf("%d %d %d", &c1, &c2, &N) == 3){
// 		vector<pair<int,int> > times(N);
// 		for(int i=0; i<N; ++i)
// 			scanf("%d %d", &times[i].first, &times[i].second);
		
// 		sort(times.begin(), times.end());
		
// 		auto it = times.begin();
// 		while(it->first < c1 and it->second < c1 and it != times.end())
// 			++it;
		
// 		pq<int, vector<pair<int,int> >, greater<pair<int,int> > > t;

// 		int maxc = 0;
// 		int minc = 0;
// 		if(it != times.end() and it->first <= c2){
// 			minc = N;
// 			while(it != times.end() and it->first <= c2){
// 				if((not t.empty()) and (it->first>t.top().first)){
// 					while((not t.empty()) and it->first>t.top().first)
// 						t.pop();
// 					if(t.empty())
// 						minc = min(minc,int(t.size()));
// 					else if(it->first > t.top().second and it->first > c1)
// 						minc = min(minc,int(t.size()));
// 					else if(it->first == t.top().first and t.top().first < c2){
// 						int tt = it->first;
// 						while(it != times.end() and it->first == tt)
// 							t.push(mp(it->second,it->first));
// 						maxc = max(maxc, int(t.size()));
// 						while((not t.empty()) and t.top().first == tt)
// 							t.pop();
// 						minc = min(minc,int(t.size()));
// 						++it; continue;
// 					}
// 					t.push(mp(it->second,it->first));
// 				}
// 				else{
// 					t.push(mp(it->second,it->first));
// 					maxc = max(maxc, int(t.size()));
// 				}
// 				++it;
// 			}
// 			if(not t.empty()){
// 				pq<int, vector<pair<int,int> >, greater<pair<int,int> > > tim;
// 				while(not t.empty()){
// 					tim.push(mp(t.top().first,2));//end times
// 					tim.push(mp(t.top().second,1));//start times
// 					t.pop();
// 				}
// 				tim.push(mp(c1,0)); tim.push(mp(c2,0));
// 				int c = 0;
// 				while(not tim.empty()){
// 					if(tim.top().second == 0){
// 						int tt = tim.top().first; tim.pop();
// 						if((not tim.empty()) and tim.top().first == tt)
// 							continue;
// 						else
// 							minc = min(minc, c);
// 						continue;
// 					}
// 					int tem = tim.top().first;
// 					if(tim.top().second == 1){
// 						if(tem > c1)
// 							minc = min(minc,c);
// 						while((not tim.empty()) and tim.top().first == tem and tim.top().second == 1){
// 							tim.pop(); ++c;
// 						}
// 						if(tem >= c1)
// 							minc = min(minc,c);
// 						if((not tim.empty()) and tim.top().second == 2 and tim.top().first == tem){
// 							while((not tim.empty()) and tim.top().first == tem and tim.top().second == 2){
// 								tim.pop(); --c;
// 							}
// 							if(tem < c2)
// 								minc = min(minc,c);
// 						}
// 					}
// 					else{
// 						if(tem <= c2)
// 							minc = min(minc,c);
// 						while((not tim.empty()) and tim.top().first == tem and tim.top().second == 2){
// 							tim.pop(); --c;
// 						}
// 						if(tem < c2)
// 							minc = min(minc,c);
// 					}
// 				}
// 			}
// 		}
// 		printf("%d %d\n", minc, maxc);
// 	}
// 	return 0;
// }