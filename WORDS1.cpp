// did not need union find - how to do union find in directed graph?
// did dfs instead - a different kind of dfs
// like once you visit a node, make all outgoing 0, instead of subtracting one by one
// and add that outgoing to the stack. we can make it 0 directly because we need not actually traverse
// we're actually doing some kind of union find - trying to find out all possible vertices reachable from start vertex
// so just adding to dfs stack after making all outgoing 0 is enough
// then check if anything is non zero - if that happens, it means, graph is not connected.

// <https://www.quora.com/How-do-I-solve-the-SPOJ-Play-on-Words-problem>

// the first thing to look at is what is edge and what is vertex, consider both cases and pick appropriately
// here, only after we decide edges connect starting and ending letter, are we able to see that it is Euler path problem
// see if you can use adjacency matrix if domain size is small

// in this case vertices are both end letters and edges connect starting and ending letters of word
// since we need to use all words, it means, find Euler path - path which uses all the edges

// store incoming and outgoing vertices too
// if all vertices have equal indegree and outdegree, then their overall degree (in degree + out degree for each vertex) is even
// if exactly two vertices have outdegree - indegree = 1 and indegree - outdegree = 1, then one is start and the other is end

// if not above two cases, then not possible to find Euler path
// and for above two cases, check for connected graph using earlier mentioned dfs
// and choose start vertex properly - in case of all even degrees, choose anyone with outdegree > 0
// in case of at most two odd degree, choose one with outdegree - indegree = 1

#include <iostream>
#include <string>
#include <stack>

#define ll long long

using namespace std;

int main(){
	ll ncases, numwords, i, j, edgecount;
	string word;
	scanf("%lld", &ncases);
	while(ncases--){
		ll arr[26][28] = {};
		// 26 is outdegree
		// 27 is indegree
		scanf("%lld", &numwords);
		edgecount = numwords;
		while(numwords--){
			cin>>word;
			arr[word[0]-'a'][word[word.length()-1]-'a'] += 1;
			arr[word[0]-'a'][26] += 1;
			arr[word[word.length()-1]-'a'][27] += 1;
		}
		
		ll oddcount = 0;
		ll oddindexfirst = -1, oddindexlast = -1;
		for(i=0;i<26;i++){
			if(arr[i][26] == arr[i][27]){
				continue;
			}
			else{
				oddcount += 1;
				if(oddcount == 1 or oddcount == 2){
					if(arr[i][26] - arr[i][27] == 1)
						oddindexfirst = i;
					if(arr[i][27] - arr[i][26] == 1)
						oddindexlast = i;
				}
			}
		}

		// for(i=0;i<26;++i){
		// 	for(j=0;j<28;++j)
		// 		cout<<arr[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<oddcount<<" "<<oddindexfirst<<" "<<oddindexlast<<endl;

		if(oddcount == 1 or oddcount > 2){
			cout<<"The door cannot be opened."<<endl;
			continue;
		}
		if(oddcount == 2){
			if(oddindexfirst == -1 or oddindexlast == -1){
				cout<<"The door cannot be opened."<<endl;
				continue;
			}
			else{
				ll startindex = oddindexfirst;
				// do dfs
				stack<ll> dfs;
				dfs.push(startindex);
				while(!dfs.empty()){
					startindex = dfs.top(); dfs.pop();
					for(j=0;j<26;j++){
						if(arr[startindex][j] > 0){
								dfs.push(j);
								arr[startindex][j] = 0;
						}
					}
				}
				startindex = 0;
				for(i=0;i<26;i++)
					for(j=0;j<26;j++){
						if(arr[i][j] > 0){
							startindex = 1;
							break;
						}
					if(startindex == 1)
						break;
				}
				if(!startindex){
					cout<<"Ordering is possible."<<endl;
				}
				else{
					cout<<"The door cannot be opened."<<endl;
				}
				continue;
			}
		}
		else{
			// oddcount is 0
			ll startindex = -1;
			for(i=0;i<26;i++){
				if(arr[i][26] > 0){
					startindex = i;
					break;
				}
			}
			if(startindex == -1){
				cout<<"The door cannot be opened."<<endl;
				continue;
			}
			// do dfs
			stack<ll> dfs;
			dfs.push(startindex);
			while(!dfs.empty()){
				startindex = dfs.top(); dfs.pop();
				for(j=0;j<26;j++){
					if(arr[startindex][j] > 0){
							dfs.push(j);
							arr[startindex][j] = 0;
					}
				}
			}
			startindex = 0;
			for(i=0;i<26;i++)
				for(j=0;j<26;j++){
					if(arr[i][j] > 0){
						startindex = 1;
						break;
					}
				if(startindex == 1)
					break;
			}
			if(!startindex){
				cout<<"Ordering is possible."<<endl;
			}
			else{
				cout<<"The door cannot be opened."<<endl;
			}
			continue;
		}

	}

	return 0;
}