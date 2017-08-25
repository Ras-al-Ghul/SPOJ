#include <iostream>

using namespace std;

int main(){
	int ncases, rows, cols, i, j;
	scanf("%d", &ncases);
	while(ncases--){
		scanf("%d %d", &rows, &cols);
		int arr[cols]={0};
		int temparr[cols];
		int temptemparr[cols];
		for(i=0;i<rows;i++){
			for(j=0;j<cols;j++){
				scanf("%d", &temparr[j]);
				temptemparr[j] = arr[j];
			}
			arr[0] = max(temparr[0]+temptemparr[0], temparr[0]+temptemparr[1]);
			for(j=1;j<cols-1;j++)
				arr[j] = max(temparr[j]+temptemparr[j-1],max(temparr[j]+temptemparr[j], temparr[j]+temptemparr[j+1]));
			arr[cols-1] = max(temparr[cols-1]+temptemparr[cols-2], temparr[cols-1]+temptemparr[cols-1]);
		}
		i = arr[0];
		for(j=1;j<cols;j++)
			i = max(i, arr[j]);
		cout<<i<<endl;
	}

	return 0;
}