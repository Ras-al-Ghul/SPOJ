// beautiful problem on the concept of defining a total ordering
// map was too slow, hence I saw online that the method used was
// sorting - so if you think carefully, you'll see that for two
// similar snowflakes to exist, two conditions need to be satisfied
// i) the two must contain same 6 integers
// ii) they must be contained in the same order (forward or reverse)
// first is easy to check by sorting, now how to do second by sorting?
// see carefully to see that if you define a total ordering between
// any two snowflakes, you will have them next to each other on sorting
// if they're alike - the key being how to define a total ordering
// how to do it? - consider all possible combinations, choose the
// smallest - 12 combinations, 6 start points, 2 - one forward, one
// backward for each of the 6

#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

typedef struct Node{
	int arr[6];
}NODE;

vector<NODE> all;

const inline bool compare(const NODE& first, const NODE& second){
	if(first.arr[0] != second.arr[0])
		return first.arr[0] < second.arr[0];
	else if(first.arr[1] != second.arr[1])
		return first.arr[1] < second.arr[1];
	else if(first.arr[2] != second.arr[2])
		return first.arr[2] < second.arr[2];
	else if(first.arr[3] != second.arr[3])
		return first.arr[3] < second.arr[3];
	else if(first.arr[4] != second.arr[4])
		return first.arr[4] < second.arr[4];
	else
		return first.arr[5] < second.arr[5];
}

inline void canonicalize(NODE& x){
	vector<NODE> arrs(12);
	for(int i=0; i<6; ++i){
		NODE temparr1, temparr2;
		for(int j=0; j<6; ++j){
			temparr1.arr[j] = x.arr[(i+j)%6];
			temparr2.arr[j] = x.arr[(i-j+6)%6];
		}
		arrs[2*i] = temparr1; arrs[2*i+1] = temparr2;
	}
	sort(arrs.begin(), arrs.end(), compare);
	x.arr[0] = arrs[0].arr[0];
	x.arr[1] = arrs[1].arr[1];
	x.arr[2] = arrs[2].arr[2];
	x.arr[3] = arrs[3].arr[3];
	x.arr[4] = arrs[4].arr[4];
	x.arr[5] = arrs[5].arr[5];
}

inline bool equals(NODE& first, NODE& second){
	if(first.arr[0]==second.arr[0])
		if(first.arr[1]==second.arr[1])
			if(first.arr[2]==second.arr[2])
				if(first.arr[3]==second.arr[3])
					if(first.arr[4]==second.arr[4])
						if(first.arr[5]==second.arr[5])
							return true;
	return false;
}

int main(){
	int n, i; scanf("%d", &n);
	while(n--){
		NODE temp;
		scanf("%d %d %d %d %d %d", &temp.arr[0], &temp.arr[1], &temp.arr[2], &temp.arr[3], &temp.arr[4], &temp.arr[5]);
		canonicalize(temp);
		all.pb(temp);
	}
	sort(all.begin(), all.end(),compare);
	bool flag = false;
	for(i=0; i<all.size()-1; ++i)
		if(equals(all[i],all[i+1])){
			printf("Twin snowflakes found.\n");
			flag = true; break;
		}
	if(not flag)
		printf("No two snowflakes are alike.\n");
	return 0;
}

// // this works but gets TLE
// // map is too slow for a sort based problem

// #include <iostream>
// #include <map>

// #define mp make_pair

// using namespace std;

// typedef struct Node{
// 	int arr[5];
// }NODE;

// multimap<int,NODE> store;
// int temparr[6];

// inline void inserts(){
// 	NODE temp;
// 	temp.arr[0] = temparr[1];
// 	temp.arr[1] = temparr[2];
// 	temp.arr[2] = temparr[3];
// 	temp.arr[3] = temparr[4];
// 	temp.arr[4] = temparr[5];
// 	store.insert(mp(temparr[0],temp));
// }

// int main(){
// 	int n, i, j; scanf("%d", &n);
// 	scanf("%d %d %d %d %d %d", &temparr[0], &temparr[1], &temparr[2], &temparr[3], &temparr[4], &temparr[5]);
// 	inserts(); n--;
// 	bool flag = false;
// 	while(n--){
// 		scanf("%d %d %d %d %d %d", &temparr[0], &temparr[1], &temparr[2], &temparr[3], &temparr[4], &temparr[5]);
// 		if(flag == false){
// 			for(i=0; i<6; ++i){
// 				typedef multimap<int,NODE>::iterator MMapIter;
// 				pair<MMapIter,MMapIter> result = store.equal_range(temparr[i]);
// 				for(auto it=result.first; it!=result.second; ++it){
// 					if(it->second.arr[0] == temparr[(i+1)%6]){
// 						bool tempflag = true;
// 						for(j=1; j<5; ++j){
// 							tempflag = tempflag and (it->second.arr[j]==temparr[(i+j+1)%6]);
// 						}
// 						if(tempflag){
// 							flag = true; break;
// 						}
// 					}
// 					if(it->second.arr[4] == temparr[(i+1)%6]){
// 						bool tempflag = true;
// 						for(j=1; j<5; ++j){
// 							tempflag = tempflag and (it->second.arr[4-j]==temparr[(i+j+1)%6]);
// 						}
// 						if(tempflag){
// 							flag = true; break;
// 						}
// 					}
// 				}
// 				if(flag==true)
// 					break;
// 				inserts();
// 			}
// 		}
// 	}
// 	if(flag)
// 		printf("Twin snowflakes found.\n");
// 	else
// 		printf("No two snowflakes are alike.\n");
// 	return 0;
// }