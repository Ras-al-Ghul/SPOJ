#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int findgcd(int a, int b){
	int temp;
	if(a<b){
		temp = b; b = a; a = temp;
	}
	while(b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main(){
	string word = "";
	char c;
	int games = 0, totalwords = 0, words = 0;

	set<string> seenwords;
	while(scanf("%c", &c) == 1){
		if(isalpha(c)){
			word += c;
		}
		else{
			if(word == "BULLSHIT"){
				++games;
				totalwords += words;
				words = 0;
				seenwords.clear();
				word = "";
			}
			else if(word.length()>=1){
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				if(seenwords.find(word) == seenwords.end()){
					seenwords.insert(word);
					++words;
				}
				word = "";
			}
		}
	}
	if(word == "BULLSHIT"){
		++games;
		totalwords += words;
		words = 0;
		seenwords.clear();
		word = "";
	}
	int gcd = findgcd(totalwords, games);
	printf("%d / %d\n", totalwords/gcd, games/gcd);
	return 0;
}