// good approach here for adhoc
// maybe can be optimized further
// creating a square grid and simulating dfs/bfs - graph search
// do not go further on a path if you don't improve the minimum distance

#include <iostream>
#include <vector>
#include <string>

#define MAX 400
#define MAXELE 190
#define pb push_back

using namespace std;

int rows,cols;
int grid[MAXELE][MAXELE];

void monster(int i, int j, int dist, bool flag=false){
	if(grid[i][j] != -1){
		grid[i][j] = dist;
	}
	// top
	if(i-1 >= 0){
		if(grid[i-1][j] != -1){
			if(grid[i-1][j] > dist+1)
				monster(i-1,j,dist+1);
		}
	}
	// bottom
	if(i+1 < rows){
		if(grid[i+1][j] != -1){
			if(grid[i+1][j] > dist+1)
				monster(i+1,j,dist+1);
		}
	}
	// left
	if(j-1 >= 0){
		if(grid[i][j-1] != -1){
			if(grid[i][j-1] > dist+1)
				monster(i,j-1,dist+1);
		}
	}
	// right
	if(j+1 < cols){
		if(grid[i][j+1] != -1){
			if(grid[i][j+1] > dist+1)
				monster(i,j+1,dist+1);
		}
	}
	return;
}

int main(){
	int ncases;
	scanf("%d", &ncases);
	int i,j;
	string row;
	while(ncases--){
		scanf("%d %d", &rows, &cols);
		vector<vector<int> > ones;

		getline(cin,row);
		for(i=0;i<rows;++i){
			getline(cin,row);
			for(j=0;j<cols;++j){
				if(row[j] == '1'){
					vector<int> temp; temp.pb(i); temp.pb(j);
					ones.pb(temp);
					grid[i][j] = -1;
				}
				else
					grid[i][j] = MAX;
			}
		}
		while(!ones.empty()){
			vector<int> temp = ones.back();
			ones.pop_back();
			monster(temp[0], temp[1], 0, true);
		}
		for(i=0;i<rows;i++){
			for(j=0;j<cols-1;j++)
				if(grid[i][j] == -1)
					cout<<0<<" ";
				else
					cout<<grid[i][j]<<" ";
			if(grid[i][j] == -1)
				cout<<0;
			else
				cout<<grid[i][j];
			cout<<endl;
		}
	}
	return 0;
}