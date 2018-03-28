// FINALLY :D
// also, check below for segment tree lazy propagation without cordinate compression approach
// cordinate compression is pretty easy - consider only edge points - in between ones can be ignored

// <https://stackoverflow.com/questions/529831/returning-the-greatest-key-strictly-less-than-the-given-key-in-a-c-map>
// two approaches - segment tree with data compression OR sweep approach using map or sets
// <zobayer.blogspot.in/2011/01/spoj-posters.html>
// <http://codeforces.com/blog/entry/18588>
// <https://github.com/ChrisEelmaa/SPOJ/blob/master/POSTERS.cpp>

// my approach is to come from last, check if next backward poster lies outside already
// existing posters, then increment counter, else counter remains same.
// In both cases the map will store only continuous, mutually exclusive poster endings - so will have to
// readjust poster endings as we go from the end of the list to the beginning.
// the key was to use two 'greatest_less' queries, one with 'end', one with 'beg'

// An improvisation to the above:
// 1. Compress input numbers. Let's say M is the greatest number now.
// 2. Keep a set which contains free positions. Initially it contains all numbers from 1 to M.
// 3. Process the posters in reverse order. If there is a number between ai and bi in the set (you can check this
// with set.lower_bound() function), then this poster is not entirely covered by the posters after it.
// In this case, remove all numbers that are between ai and bi from the set. 

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <cmath>

#define mp make_pair
#define pb push_back

using namespace std;

template<typename Map> typename Map::const_iterator 
greatest_less(Map const& m, typename Map::key_type const& k) {
    typename Map::const_iterator it = m.lower_bound(k);
    if(it != m.begin() and it->first != k) {
        return --it;
    }
    // else if(it == m.begin() and it->first == k)
    // 	return it;
    else if(it->first == k)
    	return it;
    return m.end();
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int arr[n][2];
		for(int i=0; i<n; ++i)
			scanf("%d %d", &arr[i][0], &arr[i][1]);

		map<int,int> poster;
		poster.insert(mp(arr[n-1][0], arr[n-1][1]));
		int c = 1;
		for(int i=n-2; i>=0; --i){
			// printf("\n");
			// for(auto itera = poster.begin(); itera != poster.end(); ++itera)
			// 	printf("%d %d   ", itera->first, itera->second);
			// printf("\n");
			// printf("%d ind\n", i);
			int beg = arr[i][0], end = arr[i][1];
			auto it = greatest_less(poster,end);
			if(it != poster.end()){
				if(it->first == end){
					if(it != poster.begin()){
						if(prev(it)->second > beg)
							it = prev(it);
						else{
							if(prev(it)->second == beg or (prev(it)->second + 1 == beg)){
								if(prev(it)->second == beg and beg != end-1){
									// printf("1if\n");
									++c;
									end = it->second; beg = prev(it)->first;
									poster.erase(prev(it)); poster.erase(it);
									poster.insert(mp(beg,end));
								}
								else if(prev(it)->second + 1 == beg){
									// printf("1ifif\n");
									++c;
									end = it->second; beg = prev(it)->first;
									poster.erase(prev(it)); poster.erase(it);
									poster.insert(mp(beg,end));
								}
							}
							else{
								// printf("1else\n");
								++c;
								end = it->second;
								poster.erase(it); poster.insert(mp(beg,end));
							}
							continue;
						}
					}
					else{
						// printf("2\n");
						++c; end = it->second;
						poster.erase(it);
						poster.insert(mp(beg, end));
						continue;
					}
				}
				if(it->second > beg){
					//   ----------
					// -----    (-------)
					// first < end and second > beg
					auto tempit = greatest_less(poster,beg);
					if(tempit == poster.end()){
						// printf("3\n");
						++c;
						auto temptemp = poster.begin();
						while(temptemp != it){
							poster.erase(temptemp);
							temptemp++;
						}

						beg = min(it->first, beg); end = max(it->second, end);
						poster.erase(it); poster.insert(mp(beg,end));
					}
					else{
						// cout<<"YO"<<endl;
						while(tempit->second < beg and tempit != it)
							++tempit;
						// at this point, tempit->second >= beg or tempit == it
						if(tempit == it){
							if(not(tempit->first <= beg and tempit->second >= end)){
								// printf("4\n");
								++c; beg = min(beg, tempit->first); end = max(end, tempit->second);
								
								if(tempit != poster.begin() and prev(tempit)->second + 1 == beg){
									beg = prev(tempit)->first; poster.erase(prev(tempit));
								}

								auto tmpo = poster.lower_bound(end);
								if(tmpo != poster.end() and tmpo->first == end+1){
									end = tmpo->second; poster.erase(tmpo);
								}

								poster.erase(tempit); poster.insert(mp(beg,end));
							}
						}
						else{
							// tempit->second >= beg
							auto temptemp = tempit;
							beg = min(beg, tempit->first); end = max(end, it->second);
							bool flag = false; int previous = tempit->first;
							while(tempit != it){
								if(previous + 1 < tempit->first){
									flag = true; break;
								}
								previous = tempit->second; tempit++;
							}
							if(tempit == it){
								if(previous + 1 < tempit->first)
									flag = true;
							}

							if(temptemp != poster.begin() and prev(temptemp)->second + 1 == beg){
								beg = prev(temptemp)->first; poster.erase(prev(temptemp));
							}
							auto tmpo = poster.lower_bound(end);
							if(tmpo != poster.end() and tmpo->first == end+1){
								end = tmpo->second; poster.erase(tmpo);
							}

							if(flag){
								while(temptemp != it){
									poster.erase(temptemp);
									temptemp++;
								}
								poster.erase(it);
								// printf("5\n");
								++c; poster.insert(mp(beg, end));
							}
							else{
								while(temptemp != it){
									poster.erase(temptemp);
									temptemp++;
								}
								poster.erase(it);
								poster.insert(mp(beg, end));
							}
						}
					}
				}
				else{
					if(it->second == beg){
						// printf("6\n");
						++c; beg = it->first;
						auto tmpo = poster.lower_bound(end);
						if(tmpo != poster.end() and tmpo->first == end+1){
							end = tmpo->second; poster.erase(tmpo);
						}
						poster.erase(it); poster.insert(mp(beg,end));
					}
					else{
						// printf("7\n");
						if(it->second + 1 == beg){
							beg = it->first; poster.erase(it);
						}
						auto tmpo = poster.lower_bound(end);
						if(tmpo != poster.end() and tmpo->first == end+1){
							end = tmpo->second; poster.erase(tmpo);
						}
						++c; poster.insert(mp(beg,end));
					}
				}
			}
			else{
				// printf("8\n");	
				if(end+1 == poster.begin()->first){
					end = poster.begin()->second;
					poster.erase(poster.begin());
				}
				++c; poster.insert(mp(beg, end));
			}
		}
		printf("%d\n", c);
	}
	return 0;
}


// The segment tree approach - beautifully coded
#include <iostream>
#include <cstdio>

// RELATED TO PROB
#define MAX_ELEMENTS 10000000
#define MAX_NODES 33554432
#define MAX_POSTERS 40000

using namespace std;

int T, N;

bool NODES[MAX_NODES];

int POSTERS[MAX_POSTERS][2] = {0};
bool LAZY[MAX_NODES] = {0};

inline void propagate(int index, bool val)
{
	// setting children nodes to be lazy
  LAZY[2*index] = val;
	LAZY[2*index+1] = val;
}


inline void handle_lazy(int index, int low, int high)
{
	// check if current index lazy is true
	if(LAZY[index]){
		// if yes, then update NODES[index]
		NODES[index] = true;

		// if children exist, make them lazy i.e. set their lazy
		if(low != high)
			propagate(index, true);
		// now this is not lazy anymore
		LAZY[index] = 0;
	}
}

inline void combine(int index)
{
	// used to update parent value using two children node value
	NODES[index] = NODES[2*index] && NODES[2*index+1];
}


// notice that query is not looking for a number, because tree node can only be true or false
// so we always query if true and update to true, so we need not pass that info
int query(int index, int range1, int range2, int low, int high)
{
	// always check if lazy index is true and update accordingly
	handle_lazy(index, low, high);

	// out of bounds
	if(range1 > high || range2 < low)   return -1;
	// within query range
	if(low >= range1 && high <= range2) return NODES[index];

	// left child and right child
	int mid = (low + high) >> 1;
	int f1 = index << 1;
	int f2 = f1 + 1;

	int w = query(f1, range1, range2, low,   mid);
	int w1 = query(f2, range1, range2,  mid+1, high);
	// if one is out of bounds, return answer from the other child
	if(w == -1) return w1;
	if(w1 == -1) return w;

	// we always do &&
	return w && w1;
}

void update(int index, int range1, int range2, int low, int high)
{
	// always check if lazy index is true and update accordingly
	// here only change is false becomes true, hence it is easy to handle
	// if some index is lazy, then just change it's value to true
	handle_lazy(index, low, high);

	// out of bounds
	if(range1 > high || range2 < low) return;
	if(low >= range1 && high <= range2){
		// set to true - within range
		NODES[index] = true;

		// if kids exist, then make the kids' lazy index = true
		if(low != high) 
			propagate(index, true);
		return;
	}

	// left child and right child
	int mid = (low + high) >> 1;
	int f1 = index << 1;
	int f2 = f1 + 1;

	update(f1, range1, range2, low, mid);
	update(f2, range1, range2, mid+1, high);
	// take an && for results from both children - because we need to check if entire range is ones/true
	combine(index);
}


int main()
{
	// parse_data();
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);

		int i = N;

		// max left and max right
		// they haven't used cordinate compression, instead used bool arrays
		int rBoundary = 0;
		int lBoundary = -1;
		// store from last to first, so that you can process in that order
		while(i--){
			scanf("%d %d", &POSTERS[i][0], &POSTERS[i][1]);
			if(lBoundary == -1) 
				lBoundary = POSTERS[i][0];

			lBoundary = min(lBoundary, POSTERS[i][0]);
			rBoundary = max(rBoundary, POSTERS[i][1]);
		}

		int t =  (1 << (rBoundary - lBoundary + 1));
		for(int w = 0; w < MAX_NODES; w++){
			// initialize tree and lazy tree
			LAZY[w] = 0;
			NODES[w] = 0;
		}

		int visible_posters = 0;
		// process from last
		for(i = 0; i < N; i++){
			// if 'not all ones' (&& used) in given range, then poster is seen, update count
			if(!query(1, POSTERS[i][0], POSTERS[i][1], lBoundary, rBoundary)){
				// make the entire range 1
				update(1, POSTERS[i][0], POSTERS[i][1], lBoundary, rBoundary);
				visible_posters++;
			}
		}
		printf("%d\n", visible_posters);
	}

	return 0;
}