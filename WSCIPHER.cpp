// if size of set is 0, then it is corner case;
// do not do anything, just return; k%sizeofset will throw SIGFPE otherwise
// since rotation, you can use queue

#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;
string input;

set<char> first;
set<char> second;
set<char> third;

void decrypt(int n, int k){
	set<char> current;
	switch(n){
		case 1:
			current = first;break;
		case 2:
			current = second;break;
		case 3:
			current = third; break;
	};
	int len = input.length();
	queue<char> rotate;
	int i;
	int count = 0;
	for(i=0; i<len; ++i)
		if(current.find(input[i]) != current.end())
			count += 1;
	if(count == 0)
		return;
	k = k%count;
	set<int> indices;
	for(i=0; i<len; ++i){
		if(current.find(input[i]) != current.end()){
			rotate.push(input[i]);
			indices.insert(i);
			if(rotate.size() == k){
				++i;
				break;
			}
		}
	}
	for(; i<len; ++i){
		if(current.find(input[i]) != current.end()){
			rotate.push(input[i]);
			input[i] = rotate.front();
			rotate.pop();
		}
	}
	for(auto it = indices.begin(); it!= indices.end(); ++it){
		input[*it] = rotate.front();
		rotate.pop();
	}
}

int main(){
	for(int i=97; i<=105; ++i)
		first.insert(char(i));
	for(int i=106; i<=114; ++i)
		second.insert(char(i));
	for(int i=115; i<=122; ++i)
		third.insert(char(i));
	third.insert('_');

	int k1, k2, k3;
	while(true){
		scanf("%d %d %d", &k1, &k2, &k3);
		if(k1 == 0 and k2 == 0 and k3 == 0)
			break;
		cin>>input;
		decrypt(1,k1); decrypt(2,k2); decrypt(3,k3);
		cout<<input<<endl;
	}
	return 0;
}