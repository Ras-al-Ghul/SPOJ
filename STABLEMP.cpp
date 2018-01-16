// <https://www.youtube.com/watch?v=GsBf3fJFpSw>
// <https://en.wikipedia.org/wiki/Stable_marriage_problem>

// men keep proposing to women until they're accepted and no man is left
// women keep accepting as long as they get better match

// the proposers get best match possible, acceptors get worst match possible
// because proposers have entire set to choose from, acceptors have only limited choice

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int women[n+1][n+1];

		int index, temp;
		for(int i=1; i<=n; ++i){
			scanf("%d", &index);
			for(int j=1; j<=n; ++j){
				scanf("%d", &temp);
				women[index][temp] = j;
			}
		}

		queue<int> men[n+1];
		for(int i=1; i<=n; ++i){
			scanf("%d", &index);
			for(int j=1; j<=n; ++j){
				scanf("%d", &temp); men[index].push(temp);
			}
		}

		int women_engaged[n+1] = {};
		set<int> men_notengaged;
		for(int i=1; i<=n; ++i)
			men_notengaged.insert(i);

		while(not men_notengaged.empty()){
			int cur_man = *(men_notengaged.begin());
			int cur_woman = men[cur_man].front(); men[cur_man].pop();
			if(women_engaged[cur_woman] == 0){
				men_notengaged.erase(cur_man);
				women_engaged[cur_woman] = cur_man;
			}
			else{
				int other_man = women_engaged[cur_woman];
				if(women[cur_woman][cur_man] < women[cur_woman][other_man]){
					men_notengaged.insert(other_man);
					men_notengaged.erase(cur_man);
					women_engaged[cur_woman] = cur_man;		
				}
			}
		}
		int men_final[n+1];
		for(int i=1; i<=n; ++i)
			men_final[women_engaged[i]] = i;

		for(int i=1; i<=n; ++i)
			printf("%d %d\n", i, men_final[i]);
	}
	return 0;
}