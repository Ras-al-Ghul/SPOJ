// generating and classifying into cases is the key
// reduce the grid to a small size after full traversals
// in reduced grid size, dimensions can be (1,1), (1,2), (2,1), (2,2), ((1,2),other), (other,(1,2))
// handle case by case
// <http://xoptutorials.com/index.php/2017/01/01/spojtrgrid/>

#include <iostream>

using namespace std;

int main(){
	int ncases;
	scanf("%d", &ncases);
	while(ncases--){
		int rows, cols;
		scanf("%d %d", &rows, &cols);
		int i = rows, j = cols;

		int temp = min(i,j);
		int fullcount = temp%2 == 0? (temp/2) - 1: temp/2;
		j = j-(2*fullcount);
		i = i-(2*fullcount);

		if(i==1 and j==1)
			cout<<"R"<<endl;
		else if(i==1 and j==2)
			cout<<"R"<<endl;
		else if(i==2 and j==1)
			cout<<"D"<<endl;
		else if(i==2 and j==2)
			cout<<"L"<<endl;
		else if(i>2){
			if(j == 2)
				cout<<"U"<<endl;
			else
				cout<<"D"<<endl;
		}
		else{
			if(i == 1)
				cout<<"R"<<endl;
			else
				cout<<"L"<<endl;
		}
		
	}
	return 0;
}