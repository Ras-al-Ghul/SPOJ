// once you get the idea, rest is just implementation - 
// maintain boolean array to keep track of line segments -
// two cases i) one intersect, new polygon is formed
// ii) second time intersect in same direction, that means line divides
// existing polygon into two which is nothing but equivalent to new
// polygon gets formed - hence keep track of direction and number
// of polygons formed

#include <iostream>
#include <string>

using namespace std;

int main(){
	string ip;
	while(true){
		cin>>ip; if(ip=="Q") break;
		int ans = 0;
		bool arr[2003][2003] = {};
		int i = 1001, j = 1001;
		int cur = 0; char dir = '0'; arr[i][j] = 1;
		while(ip[cur] != 'Q'){
			if(ip[cur] == 'U'){
				if(arr[i+1][j] == 1){
					++ans; dir = 'U';
				}
				else{
					arr[i+1][j] = 1;
					if(dir != 'U')
						dir = '0';
				}
				++i;
			}
			else if(ip[cur] == 'R'){
				if(arr[i][j+1] == 1){
					++ans; dir = 'R';
				}
				else{
					arr[i][j+1] = 1;
					if(dir != 'R')
						dir = '0';
				}
				++j;
			}
			else if(ip[cur] == 'D'){
				if(arr[i-1][j] == 1){
					++ans; dir = 'D';
				}
				else{
					arr[i-1][j] = 1;
					if(dir != 'D')
						dir = '0';
				}
				--i;
			}
			else{
				if(arr[i][j-1] == 1){
					++ans; dir = 'L';
				}
				else{
					arr[i][j-1] = 1;
					if(dir != 'L')
						dir = '0';
				}
				--j;
			}
			++cur;
		}
		printf("%d\n", ans);
	}
	return 0;
}