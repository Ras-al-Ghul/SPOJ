// centroid of polygon formula
// <https://math.stackexchange.com/questions/90463/how-can-i-calculate-the-centroid-of-polygon>


// The centroid of a polygon is indeed its center of mass --
// but the mass of a polygon is uniformly distributed over its surface,
// not only at the vertices. You're right that if the mass were split
// evenly among the vertices only, the centroid would be the arithmetic
// mean of the coordinates of the vertices. It just so happens that both
// definitions are equivalent (mass evenly distributed over the surface
// vs mass at the vertices only) for regular shapes like triangles and
// rectangles.


#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		double arr[n+1][2];
		scanf("%lf %lf", &arr[0][0], &arr[0][1]);
		arr[n][0] = arr[0][0], arr[n][1] = arr[0][1];
		double A = 0, Cx = 0, Cy = 0;
		int i;
		for(i=1; i<n; ++i){
			scanf("%lf %lf", &arr[i][0], &arr[i][1]);
			A += ((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]));
			Cx += (((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]))*(arr[i-1][0]+arr[i][0]));
			Cy += (((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]))*(arr[i-1][1]+arr[i][1]));
		}
		A += ((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]));
		Cx += (((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]))*(arr[i-1][0]+arr[i][0]));
		Cy += (((arr[i-1][0]*arr[i][1])-(arr[i][0]*arr[i-1][1]))*(arr[i-1][1]+arr[i][1]));
		printf("%.2lf %.2lf\n", (double(Cx)/(double(3)*double(A))), (double(Cy)/(double(3)*double(A))));
	}
	return 0;
}