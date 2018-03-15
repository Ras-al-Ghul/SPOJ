// textbook Djikstra

#include <iostream>
#include <cstdio>
#include <queue>

#define pq priority_queue
#define pp pair<long, pair<int, int> >
#define mp make_pair

using namespace std;

int main(){
	int t, i, j; scanf("%d", &t);
	while(t--){
		int m, n; scanf("%d %d", &m, &n);
		int arr[m][n];
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j)
				scanf("%d", &arr[i][j]);
		int destr, destc, maxt; scanf("%d %d %d", &destr, &destc, &maxt);
		--destr, --destc;

		int visited[m][n] = {};
		visited[0][0] = 1;
		int distarr[m][n] = {};
		distarr[0][0] = arr[0][0];
		pq<pp, vector<pp >, greater<pp > > heap;
		if(n>1)
			heap.push(pp(distarr[0][0]+arr[0][1], mp(0,1)));
		if(m>1)
			heap.push(pp(distarr[0][0]+arr[1][0], mp(1,0)));
		
		bool flag = true;
		if(destr == 0 and destc == 0)
			if(distarr[0][0] > maxt)
				flag = false;
		while(not visited[destr][destc]){
			int xcor = heap.top().second.first;
			int ycor = heap.top().second.second;
			int cost = heap.top().first;

			heap.pop();
			if(not visited[xcor][ycor]){
				visited[xcor][ycor] = 1;
				distarr[xcor][ycor] = cost;

				if(cost > maxt){
					flag = false; break;
				}

				if(destr == xcor and destc == ycor)
					break;

				if(ycor + 1 < n and (not visited[xcor][ycor+1]))
					heap.push(pp(cost+arr[xcor][ycor+1],mp(xcor,ycor+1)));
				if(ycor - 1 >= 0 and (not visited[xcor][ycor-1]))
					heap.push(pp(cost+arr[xcor][ycor-1],mp(xcor,ycor-1)));
				if(xcor + 1 < m and (not visited[xcor+1][ycor]))
					heap.push(pp(cost+arr[xcor+1][ycor],mp(xcor+1,ycor)));
				if(xcor - 1 >= 0 and (not visited[xcor-1][ycor]))
					heap.push(pp(cost+arr[xcor-1][ycor],mp(xcor-1,ycor)));
			}
		}
		if(flag)
			printf("YES\n%d\n", maxt - distarr[destr][destc]);
		else
			printf("NO\n");
	}
	return 0;
}