// this problem is an important motif to remember
// greedy won't work similar to Huffman coding, see below why
// hence dp

// idea is:
// let j+k1 = l+k2 = HAHA
// if dp[i-1][j] is optimal, assigning k1 letters to ith key - in order
// dp[i][j+k1] = dp[i-1][j] + cost of assigning k1 letters to last key i.e. ith key
// dp[i][HAHA] = above
// then if dp[i-1][l] + cost of assign k2 letters to last key < dp[i][HAHA],
// update dp[i][HAHA] with new reduced cost
// another array to store starting letter indices

// <https://github.com/andersonvom/spoj/blob/master/0014-ikeyb/0014-ikeyb.c>
// looking for a O(kl^2) dp solution - given this, still it is not easy
#include <iostream>
#include <climits>

using namespace std;

const int MAXKEY = 100;
const int MAXLEN = 100;
char keys[MAXKEY], letters[MAXLEN];

int main(){
	int t, j, m, n; scanf("%d", &t);
	for(int i=1; i<=t; ++i){
		int k,l; scanf("%d %d %s %s", &k, &l, keys, letters);
		
		int freq[l];
		for(j=0; j<l; ++j)
			scanf("%d", &freq[j]);
		
		// 0th index is keylength, 1th index is stringlength
		// see initialization to get it quickly
		// stores best value for that keylength and that stringlength
		int dp[MAXKEY][MAXLEN];
		for(m=0; m<MAXKEY; ++m)
			for(n=0; n<MAXLEN; ++n)
				// dp[m][n] = 1000000;
				dp[m][n] = INT_MAX;
		// holds start of index for that keylength and that stringlength
		// used for printing later
		int startind[MAXKEY][MAXLEN] = {};

		// initializing
		dp[0][0] = freq[0];
		// startind is already initialized to 0
		for(j=1; j<l; ++j)
			dp[0][j] = dp[0][j-1] + (freq[j]*(j+1));
			// startind is already initialized to 0

		// for(int f=0; f<k; ++f){
		// 	for(int g=0; g<l; ++g){
		// 		printf("%d ", dp[f][g]);
		// 	}
		// 	printf("\n");
		// }

		int curprice = 0, newprice;
		// for each key length
		for(m=1; m<k; ++m){
			// for each string length
			for(n=0; n<l; ++n){
				if(dp[m-1][n] < INT_MAX){ // this if is very very important, else overflow occurs
				// can also initialize dp[][] to safe value like 1000000 to prevent it and not use this 'if'
					curprice = 0;
					// candidates for efficient update
					for(j=n+1; j<l; ++j){
						// the chunk from n+1 to j is assigned to 1 key
						// previous, keylen: m-1, stringlen: 0 to n
						// hence dp[m-1][n] which is optimal
						// basic idea is optimal + (j-n letters to last key)
						curprice += (freq[j]*(j-n));
						newprice = dp[m-1][n] + curprice;
						// not <= verify this with k=2, n=4, 1112
						// this is because, then you will assign n+1 to j to last key
						// and <= means, this n is occuring later than previous n
						// that means this |n to j| is < |prev n to j| as this n > prev n
						// from n loop, hence you'll end up assigning less characters which
						// is not wanted as per question - needs most characters for last key, etc.
						if(newprice < dp[m][j]){
							dp[m][j] = newprice;
							startind[m][j] = n+1;
						}
					}
				}
			}
		}

		// for(int f=0; f<k; ++f){
		// 	for(int g=0; g<l; ++g){
		// 		printf("%d ", dp[f][g]);
		// 	}
		// 	printf("\n");
		// }

		// printf("%d\n", dp[k-1][l-1]);

		// this works because dp[][] stores optimal value for
		// given key length and string length
		int starts[k+1] = {}; int temp = l-1; // temp starts with entire string length
		for(j=k-1; j>=0; --j){
			// j indicates key length, which keeps reducing
			starts[j] = startind[j][temp];
			// reduce the string length to just before start of next key,
			// because from there to end of string is already accounted for
			temp = starts[j]-1;
		}
		// so that print loop works without needing a special case for last key character
		starts[k] = l;

		printf("Keypad #%d:\n", i); temp = 0; // temp indicates start with 0th char in string
		for(m = 0; m<k; ++m){
			printf("%c: ", keys[m]);
			for(n=temp; n<starts[m+1]; ++n)
				printf("%c", letters[n]);
			// start with this char in string for next iteration
			temp = n;
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

// don't know why greedy doesn't work for this
// but if everyone says dp, it has to be dp, greedy fails on some test case
// well, found a case:
// 1
// 2 4
// 23
// ABCD
// 1
// 2
// 2
// 3
// wrong ans: 14
// 2: ABC - 11
// 3: D - 3
// correct ans: 13
// 2: AB - 5
// 3: CD - 8
// hence DP needed
// #include <iostream>
// #include <map>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <climits>

// #define pb push_back
// #define mp make_pair

// using namespace std;

// const int MAX = 100;
// char letters[MAX], keys[MAX];

// typedef struct node{
// 	int label;
// 	vector<char> chars;
// 	vector<int> freqs;
// 	int curind = 1;
// 	int sum = 0;

// 	bool operator<(const struct node & n) const{
// 		return this->label < n.label;
// 	}
// }NODE;

// int main(){
// 	int t; scanf("%d", &t);
// 	for(int i=1; i<=t; ++i){
// 		int k,l; scanf("%d %d %s %s", &k, &l, keys, letters);
		
// 		int freq;
// 		map<int, NODE *> index;

// 		int totalsum = 0;
// 		for(int j=0; j<l; ++j){
// 			scanf("%d", &freq);
// 			NODE *temp = new NODE;
// 			temp->label = j;
// 			temp->chars.pb(letters[j]);
// 			temp->freqs.pb(freq);
// 			temp->sum += (freq*(temp->curind));
// 			temp->curind++;
// 			index[temp->label] = temp;
// 			totalsum += temp->sum;
// 		}
		
// 		while(index.size() != k){
// 			int minsum = INT_MAX, lab = -1, nextlab = -1;
// 			for(auto it = index.begin(); it != prev(index.end()); ++it){
// 				int tempsum = it->second->sum;
// 				auto ne = next(it); int ti = 0;
// 				for(int k = it->second->curind; ti<ne->second->chars.size(); ++k){
// 					tempsum += (ne->second->freqs[ti++]*k);
// 				}
// 				if(totalsum-it->second->sum-ne->second->sum+tempsum<=minsum){
// 					minsum = totalsum-it->second->sum-ne->second->sum+tempsum; lab = it->first; nextlab = ne->first;
// 				}
// 			}
// 			auto it = index[lab], ne = index[nextlab]; int ti = 0;
// 			for(; ti<ne->chars.size(); ++(it->curind)){
// 				it->chars.pb(ne->chars[ti]);
// 				it->freqs.pb(ne->freqs[ti]);
// 				it->sum += (ne->freqs[ti++]*it->curind);
// 			}
// 			index.erase(nextlab);
// 		}

// 		printf("Keypad #%d:\n", i);
// 		int ti = 0;
// 		for(auto it = index.begin(); it != index.end(); ++it){
// 			printf("%c: ", keys[ti++]);
// 			for(int k=0; k<it->second->chars.size(); ++k)
// 				printf("%c", it->second->chars[k]);
// 			printf("\n");
// 		}

// 		printf("\n");
// 	}
// 	return 0;
// }