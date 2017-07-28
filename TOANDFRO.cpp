// indexing can be weird sometimes
// might become tough without trial and error

#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	int numofcols;
	int numofrows;
	while(true){
		scanf("%d", &numofcols);
		if(numofcols == 0)
			break;
		cin>>line;
		
		if((line.length()%numofcols) == 0)
			numofrows = line.length()/numofcols;
		else
			numofrows = int(line.length()/numofcols) + 1;

		char *arrofchararrs[numofrows];
		bool lefttoright = true;
		for(int i=0; i<numofrows; i++){
			arrofchararrs[i] = new char[numofcols];
			if(lefttoright){
				for(int j=0; j<numofcols; j++){
					arrofchararrs[i][j] = line[(i*numofcols)+j];
				}
			}
			else{
				for(int j=numofcols-1; j>=0; j--){
					arrofchararrs[i][j] = line[((i+1)*numofcols)-1-j];
				}
			}
			lefttoright = !lefttoright;
		}

		for(int i=0; i<numofcols; i++){
			for(int j=0; j<numofrows; j++){
				printf("%c", arrofchararrs[j][i]);
			}
		}
		for(int i=0; i<numofrows; i++)
			delete[] arrofchararrs[i];
		printf("\n");
	}
	return 0;
}