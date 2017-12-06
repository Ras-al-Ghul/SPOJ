// I was almost there, but almost doesn't count

// Firstly, other approach: write the string and its reverse
// observe - appending reverse to string makes it a palindrome
// but all characters of reversed string are not needed
// strike out the not needed ones from string||revstring where || indicates concatenation
// you'll notice that ans = strlen - LCS(str, revstr)
// i.e. you need to add only those chars which are not there in the Longest Common Subsequence

// DP approach - bottom up
// I tried using locks - had got i,col depends on i+1,col and i,col-1
// but had not got that it may also depend on i+1,col-1
// like all DP problems, look into a few examples, then you might find patterns
// if all chars are different, you need to insert all chars except middle one - n-1 chars
// if a x..z a first and last are same, you need to add x..z
// if a x..z b first and last are diff, then a may be equal to z and x may be equal to b min((i+1,col),(i,col-1) case
// handle base cases - locks not required because first and last same case handled separately
// <https://www.quora.com/What-is-the-best-way-to-solve-SPOJ-AIBOHP>

// converting everything to lowercase was stupid

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int ncases;
	string data;
	scanf("%d", &ncases);
	while(ncases--){
		cin>>data;
		// transform(data.begin(), data.end(), data.begin(), ::tolower);

		int length = data.length();
		int arr[length][length] = {};
		// 0 indicates it is free
		// 1 means can't use as left
		// 2 means can't use as down
		// 3 means can't use both
		int isfree[length][length] = {};

		int begin = 0, column = 0;
		while(begin != length){
			for(int i=begin-1; i>=0; --i){
				// temp1 is for left, temp2 is for bottom
				int temp1 = arr[i][column-1], temp2 = arr[i+1][column];
				// left is free
				if(isfree[i][column-1] == 0 or isfree[i][column-1] == 2){
					if(data[column] == data[i])
						temp1 = max(0, temp1-1);
					else
						temp1 += 1;

					// bottom is free
					if(isfree[i+1][column] == 0 or isfree[i+1][column] == 1){
						if(data[column] == data[i])
							temp2 = max(0, temp2-1);
						else
							temp2 += 1;

						if(temp1 < temp2){
							arr[i][column] = temp1;
							if(data[column] == data[i])
								isfree[i][column] = 3;
						}
						else{
							arr[i][column] = temp2;
							if(data[column] == data[i])
								isfree[i][column] = 3;
						}
					}
					// bottom is not free
					else{
						temp2 += 1;

						if(temp1 < temp2){
							arr[i][column] = temp1;
							if(data[column] == data[i])
								isfree[i][column] = 3;
						}
						else{
							arr[i][column] = temp2;
							isfree[i][column] = 2;
						}
					}
				}
				// left is not free
				else{
					temp1 += 1;
					// bottom is free
					if(isfree[i+1][column] == 0 or isfree[i+1][column] == 1){
						if(data[column] == data[i])
							temp2 = max(0, temp2-1);
						else
							temp2 += 1;

						if(temp1 < temp2){
							arr[i][column] = temp1;
							isfree[i][column] = 1;
						}
						else{
							arr[i][column] = temp2;
							if(data[column] == data[i])
								isfree[i][column] = 3;
						}
					}
					// bottom is not free
					else{
						temp2 += 1;

						if(temp1 < temp2){
							arr[i][column] = temp1;
							isfree[i][column] = 1;
						}
						else{
							arr[i][column] = temp2;
							isfree[i][column] = 2;
						}
					}
				}
				if((column-1) >= (i+1)){
					int tempmin = arr[i+1][column-1];
					if(data[i] == data[column]){
						if(tempmin < arr[i][column]){
							arr[i][column] = tempmin;
							isfree[i][column] = 3;
						}
					}
					else{
						if(tempmin + 2 < arr[i][column]){
							arr[i][column] = tempmin + 2;
							isfree[i][column] = 0;
						}
					}
				}
				// char t = data[i];bool flag = false;
				// for(int j=i+1; j<=column; ++j){
				// 	if(data[j] != t){
				// 		flag = true;
				// 		break;
				// 	}
				// }
				// if(not flag)
				// 	arr[i][column] = max(0, arr[i][column]-1);
			}
			++begin; ++column;
		}
		cout<<arr[0][length-1]<<endl;
		// for(int i=0; i<length; ++i){
		// 	for(int j=0; j<length; ++j)
		// 		cout<<arr[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<endl;
		// for(int i=0; i<length; ++i){
		// 	for(int j=0; j<length; ++j)
		// 		cout<<isfree[i][j]<<" ";
		// 	cout<<endl;
		// }
	}
	return 0;
}