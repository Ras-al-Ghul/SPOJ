// stack based solution from Coursera Algo 1 notes Sedgewick Wayne is easier to understand than wiki one

// convex hull - Graham's scan

// orientation function is important - remember det of [[ax ay 1][bx by 1][cx cy 1]]
// signed area of triangle - >0 --> Counterclockwise, == 0 --> collinear

// choose lowest, leftmost point as starting point for scan
// sort remaining points based on polar angle wrt the above starting point
// don't actually calculate the angle, but find orientation(first, p1, p2)
// if 0, then if p1 lies to left of p2, then it is lesser, if > 0, ccw, hence p1 lesser than p2
// because first, p1, p2 lie in Counterclockwise manner
// use stack to consider points in order and do Graham scan -
// discard points unless they create ccw turns

// convex hull can also be used for finding two farthest points given a set of 2D points, 
// coz they will lie on the convex hull
// also robot traversal while avoiding obstacles

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

typedef struct point{
	int x, y;
	int index;
}POINT;

POINT first;

int distSq(const POINT p1, const POINT p2){
	return ((p1.x-p2.x)*(p1.x-p2.x)) + ((p1.y-p2.y)*(p1.y-p2.y));
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// <0 --> Clockwise
// >0 --> Counterclockwise
int orientation(const POINT p, const POINT q, const POINT r){
	return ((q.x-p.x)*(r.y-p.y)) - ((q.y-p.y)*(r.x-p.x));
}

bool operator<(const POINT p1, const POINT p2){
    int orient = orientation(first, p1, p2);
    if(orient == 0){
    	int dists = distSq(first, p2) - distSq(first, p1);
    	if(dists > 0)
    		return true;
    	else if(dists < 0)
    		return false;
    	else{
    		if(p1.index < p2.index)
    			return false;
    		else
    			return true;
    	}
    }
    return orient>0?true:false;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		vector<POINT> arr(n+1);
		vector<POINT> duparr(n+1);
		for(int i=1; i<=n; ++i){
			scanf("%d %d", &arr[i].x, &arr[i].y);
			duparr[i].x = arr[i].x; duparr[i].y = arr[i].y;
			arr[i].index = i;
			duparr[i].index = i;
		}
		POINT temp;
		for(int i=2; i<=n; ++i){
			if(arr[i].y < arr[1].y){
				temp = arr[i];
				arr[i] = arr[1];
				arr[1] = temp;
			}
			else if(arr[i].y == arr[1].y){
				if(arr[i].x < arr[1].x){
					temp = arr[i];
					arr[i] = arr[1];
					arr[1] = temp;
				}
			}
		}
		
		first = arr[1];
		sort(arr.begin()+2, arr.end());

		if(n<3){
			if(n==1)
				printf("%.2f\n%d\n\n", 0.0, 1);
			else
				printf("%.2lf\n%d %d\n\n", 2.0*sqrt(distSq(arr[1], arr[2])), arr[1].index, arr[2].index);
			continue;
		}

		vector<int> indices;
		indices.pb(arr[1].index);
		arr[0] = arr[n];
		int M = 1;
		for(int i=2; i<=n; ++i){
			while(orientation(arr[M-1], arr[M], arr[i]) <= 0){
				if(M > 1){
					indices.pop_back();
					M -= 1;
					continue;
				}
				// all points are collinear
				else if(i == n)
					break;
				else
					i += 1;
			}
			M += 1;
			indices.pb(arr[i].index);
			temp = arr[M]; arr[M] = arr[i]; arr[i] = temp;
		}

		if(indices.size() == 2 and (distSq(duparr[indices[0]], duparr[indices[1]])==0)){
			printf("%.2lf\n", 0.0);
			printf("%d\n\n", 1);
			continue;
		}

		double perimeter = 0.0;
		for(int i=1; i<indices.size(); ++i)
			perimeter += sqrt(distSq(duparr[indices[i]], duparr[indices[i-1]]));
		perimeter += sqrt(distSq(duparr[indices[indices.size()-1]], duparr[indices[0]]));
		printf("%.2lf\n", perimeter);
		for(int i=0; i<indices.size(); ++i){
			printf("%d ", indices[i]);
		}
		printf("\n\n");
	}

	return 0;
}