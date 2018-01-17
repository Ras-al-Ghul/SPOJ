// awesome question
// <https://www.quora.com/How-can-the-problem-Ones-and-zeros-on-SPOJ-be-solved-using-BFS>
// <https://stackoverflow.com/questions/16945626/spoj-370-ones-and-zeros-onezero>
// <http://hmrockstar.blogspot.in/2016/11/onezero-ones-and-zeros-solution.html>

#include <iostream>
#include <string>
#include <queue>

#define psi pair<string, int>
#define mp make_pair

using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		psi start = mp("1",1);
		
		queue<psi> bfs; bfs.push(start);
		bool visited[n] = {};
		psi temp;
		while(true){
			temp = bfs.front(); bfs.pop();
			int mod = temp.second % n;
			if(mod == 0)
				break;
			if(visited[mod])
				continue;
			visited[mod] = true;
			bfs.push(mp(temp.first+"0", ((temp.second%n)*10)+0));
			bfs.push(mp(temp.first+"1", ((temp.second%n)*10)+1));
		}
		cout<<temp.first<<endl;
	}
	return 0;
}