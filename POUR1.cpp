// my thought process was as follows:
// couldn't get anything until I looked into GCD methods
// <http://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/>
// VERY IMP
// 'if we subtract smaller number from larger (i.e. if we reduce larger number),'
// then the GCD doesn't change - ultimately we end up with GCD
// (we could also divide, which is nothing but the Euclid's algorithm)

// so play around with this 'subtract smaller from the larger'
// Eg. get 9 using 15 and 8
// 15 - 8 = 7
// now cannot do anything useful with 7 other than transfering to 8
// Now with 7 in capacity container, we can do nothing useful other than
// transfering difference (8-1) from 15 leaving 14 in 15 capacity container
// Now we can do nothing useful other than taking out 8 from 14, leaving 6 in 15 capacity
// tranfer 6 is the only useful step
// ....
// keep repeating till you get your number c
// if you get repeated values (seen earlier), i.e. if cycling occurs, you will not find c

// Now that is where I stopped - but it doesn't give optimal number of steps '8' for our problem
// hence gave up

// Thing I was missing was other way around - start by transfering 8 to 15
// then in next iteration, transfer (15-8) = 7 leaving 1 in container with capacity 8.
// transfer that after emptying container 15. Add 8 to this 1
// You will observe reverse of the previous method in this

// So min(count1, count2) is the required answer

// It seems that c%gcd(a,b) = 0 should be satisfied i.e. linear diphontine equation solution existence condition
// ax+by = c - is there x and y which satisfy this, if yes, simulate, else -1

// see also - for solving using BFS
// <https://stackoverflow.com/questions/17869493/advice-for-pour1-on-spoj>
// Consider the set of all a priori possibles states (eg [3, 7] 
// meaning Vessel1 contains 3 litters and vessel2 contains 7 litters) 
// You have a directed graph whose vertices are those states and 
// whose edges are the possible moves. The question is to find a path 
// in the graph joining the state [0, 0] to either a state of type [c, ?] 
// or a state of type [?, c]. 
// Such a path is typically searched by a BFS

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	int a, b, c;
	while(t--){
		scanf("%d %d %d", &a, &b, &c);
		if(a == c or b == c){
			printf("1\n");
		}
		else if(c > a and c > b){
			printf("-1\n");
		}
		else if(c%__gcd(a,b) != 0){
			printf("-1\n");
		}
		else{
			if(a<b){
				int temp = b;
				b = a;
				a = temp;
			}
			int nsteps1 = 1;
			int A = a, B = 0, transfer = 0;
			while(A != c and B != c){
				transfer = min(A, b-B);
				A -= transfer;
				B += transfer;
				nsteps1++;
				if(A == c or B == c)
					break;
				if(A == 0){
					A = a;
					nsteps1++;
				}
				if(B == b){
					B = 0;
					nsteps1++;
				}
			}
			int nsteps2 = 1;
			A = b, B = 0, transfer = 0;
			while(A != c and B != c){
				transfer = min(A, a-B);
				A -= transfer;
				B += transfer;
				nsteps2++;
				if(A == c or B == c)
					break;
				if(A == 0){
					A = b;
					nsteps2++;
				}
				if(B == a){
					B = 0;
					nsteps2++;
				}
			}
			printf("%d\n", min(nsteps1, nsteps2));
		}
	}
	return 0;
}