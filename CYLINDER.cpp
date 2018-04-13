// Two ways to roll - one is along the width, in that case, 2(pi)r = b
// Other way is any radius along len - in that case - h = b
// but r = min(b/2, a/(2(pi)+2)) radius of circle cannot exceed b/2
// latter is as follows: 2(pi)r + 2r = a i.e. circum + 2r = len
// take max of both ways

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, t;
	while(scanf("%lf %lf", &a, &b) == 2){
		if(a==0. and b==0.)
			break;
		// a will be the bigger side
		if(a<b){
			t = a; a = b; b = t;
		}

	// THIS IS A BIG MISTAKE I WAS COMMITTING
	// NOWHERE HAVE THEY MENTIONED THAT - CUT PARALLEL TO SHORTER SIDE
	// MUST RESULT IN TWO EQUAL PIECES - a/2 length each -
	// HENCE THIS WAS WRONG LOGIC		
		// longer side will be divided into two
		// double len = a/double(2.);
		// two pieces - a/2 * b each i.e. len * b each

		// b will be bigger
		// if(len>b){
		// 	double temp = b; b = len; len = temp;
		// }
		
		double r = min(b/double(2.),a/(double(2.)*M_PI + double(2.)));
		double vol;
		vol = M_PI * r * r * b;

		r = b/(double(2.)*M_PI);
		vol = max(vol, M_PI*r*r*(a-double(2.)*r));
	
		printf("%.3lf\n", vol);
	}
	return 0;
}