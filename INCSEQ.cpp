// a very good problem to demonstrate using two concepts
// dp and BIT
// pure dp code is at the bottom - see the description for why it is slow

// you can see that it kinda resembles INVCNT - ans depends answers to the right, etc.
// convert it into prefix sum problem and use Fenwick Tree/BIT

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define MOD 5000000

using namespace std;

pair<int,int> arr[10000] = {};
int newarr[10000] = {};
int minn = 1, maxn = 1;

void normalize(int n){
	sort(arr, arr+n);
	int counter = 1;
	newarr[arr[0].second] = 1;
	for(int i=1; i<n; ++i){
		if(arr[i].first == arr[i-1].first){
			newarr[arr[i].second] = counter; 
		}
		else{
			newarr[arr[i].second] = (++counter);
		}
	}
	maxn = counter;
	
	// for(int i=0; i<n; ++i)
	// 	cout<<newarr[i]<<" ";
	// cout<<endl;
	return;
}

// index, value, fenwick tree, size of fenwick tree
void update(int i, int v, int a[], int alen) {
    while (i < alen){
    	a[i] = (a[i] + v)%MOD;
    	i |= i + 1;
    }
}
// index, fenwick tree
int prefixsum(int n, int a[]){
    int sum = 0;
    while (n > 0){
    	sum += a[n - 1];
    	n &= n - 1;
    }
    return sum;
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i){
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}

	normalize(n);

	int ans = 0;
	int dp[n][k] = {};
	int fenwick[n] = {};
	for(int j=n-1; j>=0; --j){
		// number of larger elements to the right - suffix sum
		// if it was newarr[j],
		// have to do suffix sum, now can do prefix sum
		// because it is n-newarr[j]
		dp[j][1] = prefixsum(n-newarr[j], fenwick);
		update(n-newarr[j], 1, fenwick, n);
		if(k==2){
			ans = (ans+dp[j][1])%MOD;
		}
	}

	for(int i=2; i<k; ++i){
		int newfenwick[n] = {};
		for(int j=n-1; j>=0; --j){
			dp[j][i] = prefixsum(n-newarr[j], newfenwick);
			// insert answer at relevant index instead of update by '1'
			update(n-newarr[j], dp[j][i-1], newfenwick, n);
			if(i == k-1)
				ans = (ans + (dp[j][i]))%MOD;
		}
	}

	if(k==1)
		printf("%d\n", n);
	else
		printf("%d\n", ans);

	// arr[i] was just arr with n values
	// vector<int> largesttoright[n];

	// // first is value, second is index
	// multiset<pair<int,int> > done;
	// done.insert(mp(arr[n-1],n-1));
	// for(int i=n-2; i>=0; --i){
	// 	done.insert(mp(arr[i],i));
	// 	auto it = done.find(mp(arr[i],i));
	// 	while(it->first == arr[i] and it != done.end())
	// 		++it;
	// 	if(it != done.end() and it->first > arr[i]){
	// 		largesttoright[i].pb(it->second);
	// 		int cur = it->first;
	// 		while(++it != done.end() /*and it->first == cur*/)
	//			// you have to insert all elements to the right which are larger than this
	//			// and calculate for each of them
	// 			largesttoright[i].pb(it->second);
	// 	}
	// }
	// // for(auto it = done.begin(); it!=done.end(); ++it)
	// // 	cout<<it->first<<" "<<it->second<<endl;
	// // for(int i=0; i<n; ++i)
	// // 	if(not largesttoright[i].empty())
	// // 		cout<<largesttoright[i][0]<<" ";
	// // cout<<endl;
	
	// int ans = 0;
	// for each index and each sublength of k
	// int dp[n][k] = {};
	// sublength 1 handled separately
	// for(int j=n-2; j>=0; --j){
	// 	if(not largesttoright[j].empty()){
	// 		// for(int k=0; k<largesttoright[j].size(); ++k)
	// 		// 	dp[j][1] += /*dp[largesttoright[j][k]][1] + */1;
	//		// basically number of larger elements to the right of this
	// 		dp[j][1] = largesttoright[j].size()%MOD;
	// 	}
	// 	if(k==2)
	// 		ans += dp[j][1];
	// }
	
	// sublength 2 to k-1
	// for(int i=2; i<k; ++i){
	// 	for(int j=n-2; j>=0; --j){
	// 		if(not largesttoright[j].empty()){
	// 			// cout<<largesttoright[j].size()<<endl;
	//			// ans[curlen] = ans for each greater element to right[curlen-1]
	//			// like this number + sequences of that greater number of curlen-1
	//			// like mentioned earlier, have to do this calculation for each larger element to the right
	//			// hence it becomes O(n^3) kinda complexity
	//			// have to reduce this
	// 			for(int k=0; k<largesttoright[j].size(); ++k)
	// 				dp[j][i] = (dp[j][i] + (dp[largesttoright[j][k]][i-1] /*+ dp[largesttoright[j][k]][i]*/))%MOD;
	// 		}
	// 		if(i == k-1)
	// 			ans = (ans + (dp[j][i]))%MOD;
	// 	}
	// }
	// // for(int i=0; i<n; ++i)
	// // 	cout<<dp[i][k-1]<<" ";
	// // cout<<endl;
	// if(k==1)
	// 	printf("%d\n", n);
	// else
	// 	printf("%d\n", ans);
	return 0;
}