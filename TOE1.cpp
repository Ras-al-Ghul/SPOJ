// tic tac toe - consider edge cases
// read question that x always starts first

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkwin(char grid [3][3], char c){
	bool flag = false;
	// rows
	for(int i=0; i<3; ++i){
		int count = 0;
		for(int j=0; j<3; ++j)
			if(grid[i][j] == c)
				count += 1;
		if(count == 3){
			flag = true; break;
		}
	}
	if(flag)
		return flag;
	// columns
	for(int i=0; i<3; ++i){
		int count = 0;
		for(int j=0; j<3; ++j)
			if(grid[j][i] == c)
				count += 1;
		if(count == 3){
			flag = true; break;
		}
	}
	if(flag)
		return flag;
	// diagonals
	if(grid[0][0] == c and grid[1][1] == c and grid[2][2] == c)
		return true;
	if(grid[0][2] == c and grid[1][1] == c and grid[2][0] == c)
		return true;
	return flag;
}

int main(){
	int ncases; string line;
	scanf("%d", &ncases);
	while(ncases--){
		int xcount = 0, ocount = 0;
		char grid[3][3];

		cin>>line;
		xcount += count(line.begin(), line.end(), 'X');
		ocount += count(line.begin(), line.end(), 'O');
		for(int i=0; i<3; ++i)
			grid[0][i] = line[i];

		cin>>line;
		xcount += count(line.begin(), line.end(), 'X');
		ocount += count(line.begin(), line.end(), 'O');
		for(int i=0; i<3; ++i)
			grid[1][i] = line[i];

		cin>>line;
		xcount += count(line.begin(), line.end(), 'X');
		ocount += count(line.begin(), line.end(), 'O');
		for(int i=0; i<3; ++i)
			grid[2][i] = line[i];

		bool xwin = checkwin(grid, 'X');
		bool owin = checkwin(grid, 'O');

		if(xwin and owin){
			cout<<"no"<<endl; continue;
		}
		if((xwin and (ocount >= xcount)) or (owin and (xcount > ocount))){
			cout<<"no"<<endl; continue;
		}
		if(abs(xcount - ocount) > 1){
			cout<<"no"<<endl; continue;	
		}
		if(ocount - xcount > 0){
			cout<<"no"<<endl; continue;	
		}
		cout<<"yes"<<endl;
	}
	return 0;
}