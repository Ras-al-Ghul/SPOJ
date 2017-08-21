// while(r--) saved my ass
#include <iostream>
using namespace std;int r,n,i,j;main(){cin>>n;while(n--){cin>>r;int a[100][100]={0};for(i=0;i<r;i++)for(j=0;j<i+1;j++)cin>>a[i][j];while(r--)for(j=0;j<i+1;j++)a[r-1][j]=max(a[r][j]+a[r-1][j],a[r][j+1]+a[r-1][j]);cout<<a[0][0]<<endl;}}