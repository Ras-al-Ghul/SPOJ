// pq is the right DS to use here
// min heap using pq

#include <iostream>
#include <queue>

#define pq priority_queue

using namespace std;

int main(){
	int numoftestcases;
	scanf("%d", &numoftestcases);

	int NG, NM, temp;
	while(numoftestcases--){
		scanf("%d %d", &NG, &NM);
		pq <int, vector<int>, greater<int> > godzilla;
		pq <int, vector<int>, greater<int> > mecha;
		while(NG--){
			scanf("%d", &temp);
			godzilla.push(temp);
		}
		while(NM--){
			scanf("%d", &temp);
			mecha.push(temp);
		}
		while(!godzilla.empty() and !mecha.empty()){
			if(godzilla.top() < mecha.top()){
				godzilla.pop();
			}
			else if(mecha.top() <= godzilla.top()){
				mecha.pop();
			}
		}
		if(godzilla.empty())
			cout<<"MechaGodzilla"<<endl;
		else
			cout<<"Godzilla"<<endl;
	}
	return 0;
}