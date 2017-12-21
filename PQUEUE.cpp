// notice how to add custom comparator
// two priority queue approach - have come across this somewhere
// or is it two stack approach?
// bracket matching?

#include <iostream>
#include <queue>

using namespace std;

typedef struct duo{
	int reindex, origindex;
}DUO;

class CompareClass{
	public:
		bool operator()(DUO a, DUO b){
			return a.reindex>b.reindex;
		}
};

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int n, m;
		scanf("%d %d", &n, &m);
		int priorities[n];
		DUO indices[n];
		for(int i=0; i<n; ++i){
			scanf("%d", &priorities[i]);
			indices[i].reindex = i, indices[i].origindex = i;
		}
		priority_queue<int, vector<int>, less<int> > priorityqueue(priorities, priorities+n);
		priority_queue<DUO, vector<DUO>, CompareClass> indexqueue(indices, indices+n);
		
		int cur = n; int time = 0;
		while(priorityqueue.size()){
			int curind = indexqueue.top().origindex;
			int curval = priorityqueue.top();
			if(priorities[curind] == curval){
				time+=1;
				if(curind == m)
					break;
				priorityqueue.pop();
				indexqueue.pop();
			}
			else{
				indexqueue.pop();
				DUO temp; temp.origindex = curind; temp.reindex = cur++;
				indexqueue.push(temp);
			}
		}
		printf("%d\n", time);
	}
	return 0;
}