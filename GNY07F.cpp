// implementation wise, this was very very tough
// from braces, finding out level of tree, as well as traversing it fully,
// as well as returning it's value
// but logic wise, this is shit

// best logic is to realize that we are forced to insert as many monkeys
// as the 2^number of plies in the deepest path - no matter balanced or unbalanced
// if balanced, already done, if unbalanced, we add
// but in both cases, number of monkeys is 2^number of plies
// for(i=n=m=0; str[i]; i++) {
// 			if(str[i]=='[') n++;
// 			else if(str[i]==']') n--;
// 			if(n > m) m = n;
// 		}
// printf("%d %d\n", x, (1<<m));

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

string input;

// will help find current level (to help in traversing the string)
// will also help in storing unbalanced values
// first is level, second is unbalanced value as of now
stack<pii > braces;
int len;

pii recurse(int index, int level){
	pii temp1, temp2;
	if(input[index] == ']'){
		// there will be a corresponding pushed '['
		braces.pop();
		// base case, return the index - i.e. the current position in the string
		// and 1 - which says 1 monkey
		// the traversal of string will continue from index+1
		return mp(index, 1);
	}
	else if(index<len and input[index] == '['){
		// push onto stack, nothing unbalanced yet
		braces.push(mp(level,0));
		// recurse from next index
		temp1 = recurse(index+1, level+1);

		// very important, if stack contains shallower values,
		// we need to get back to current stack level from our deeper depth, hence,
		// return without doing anything further
		if((not braces.empty()) and braces.top().first<level){
			// everytime we do .second*2, because binary tree
			return mp(temp1.first, temp1.second*2);
		}
		// if the level is correct and next symbol is '['
		if((not braces.empty()) and braces.top().first == level and temp1.first+1<len and input[temp1.first+1] == '['){
			// pop and push again to change .second to reflect temp1's imbalance till now
			pii temp = braces.top(); braces.pop();
			braces.push(mp(temp.first, temp.second+temp1.second));
			
			// recurse
			temp2 = recurse(temp1.first+1, level+1);
			// pop corresponding level
			temp = braces.top(); braces.pop();
			// return the difference + sum of both values
			// it can also be written as 2*max
			return mp(temp2.first+1, abs(temp2.second-(temp.second))+temp.second+temp2.second);
		}
		// if next is ']'
		else if(temp1.first+1<len and input[temp1.first+1] == ']'){
			// if we are in the same level as indicated by stack,
			// since we are returning, we will pop
			if(braces.top().first == level){
				braces.pop();
			}
			// since string traversal continues from next index, return .first+1
			return mp(temp1.first+1, temp1.second*2);
		}
		else{
			// no .first + 1 here because we're not checking for anything in if/else if part
			// hence that part of string is not yet traversed, will be done in above two
			// conditions at a higher level than now
			return mp(temp1.first, temp1.second*2);
		}
	}
	// special case of blank input
	return mp(1,1);
}

int main(){
	int n; scanf("%d", &n);
	getline(cin, input);
	for(int i=1; i<=n; ++i){
		getline(cin,input);
		len = input.length();
		cout<<i<<" "<<recurse(0, 0).second<<endl;
	}
	return 0;
}