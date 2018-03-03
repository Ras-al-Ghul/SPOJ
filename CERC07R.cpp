#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map<string, int> cs = {{"Kamen",0},{"Nuzky",1},{"Papir",2}};
map<string, int> en = {{"Rock",0},{"Scissors",1},{"Paper",2}};
map<string, int> fr = {{"Pierre",0},{"Ciseaux",1},{"Feuille",2}};
map<string, int> de = {{"Stein",0},{"Schere",1},{"Papier",2}};
map<string, int> hu = {{"Ko",0},{"Ollo",1},{"Papir",2},{"Koe",0},{"Olloo",1}};
map<string, int> it = {{"Sasso",0},{"Forbice",1},{"Carta",2},{"Roccia",0},{"Rete",2}};
map<string, int> jp = {{"Guu",0},{"Choki",1},{"Paa",2}};
map<string, int> pl = {{"Kamien",0},{"Nozyce",1},{"Papier",2}};
map<string, int> es = {{"Piedra",0},{"Tijera",1},{"Papel",2}};

map<string, int> *retval(string ip){
		if(ip=="cs")
			return &cs;
		if(ip=="en")
			return &en;
		if(ip=="fr")
			return &fr;
		if(ip=="de")
			return &de;
		if(ip=="hu")
			return &hu;
		if(ip=="it")
			return &it;
		if(ip=="jp")
			return &jp;
		if(ip=="pl")
			return &pl;
		if(ip=="es")
			return &es;
}

int getwinner(int first, int second){
	if(first == 0){
		if(second == 0) return 0;
		else if(second == 1) return 1;
		else return 2;
	}
	else if(first == 1){
		if(second == 0) return 2;
		else if(second == 1) return 0;
		else return 1;
	}
	else{
		if(second == 0) return 1;
		else if(second == 1) return 2;
		else return 0;
	}
}

int main(){
	string input, input1;
	int i = 1;
	int score1 = 0, score2 = 0;
	string player1, player2;
	string l1, l2;

	getline(cin, input, ' '); l1 = input;
	getline(cin, input, '\n'); player1 = input;
	getline(cin, input, ' '); l2 = input;
	getline(cin, input, '\n'); player2 = input;
	map<string, int> *temp1, *temp2;
	temp1 = retval(l1); temp2 = retval(l2);
	char cstr1[500], cstr2[500];
	while(scanf("%s ", cstr1)){
		if(strcmp(cstr1,"-") != 0 and strcmp(cstr1,".") != 0){
			scanf("%s\n", cstr2);
			input = cstr1; input1 = cstr2;
			
			int win = getwinner((*temp1)[input],(*temp2)[input1]);
			if(win==1)++score1;
			if(win==2)++score2;
		}
		else{
			input = cstr1;
		}
		if(input=="."){
			printf("Game #%d:\n", i++);
			cout<<player1; if(score1!=1) printf(": %d points\n", score1); else printf(": %d point\n", score1);
			cout<<player2; if(score2!=1) printf(": %d points\n", score2); else printf(": %d point\n", score2);
			if(score1>score2)
				cout<<"WINNER: "<<player1<<endl;
			else if(score2>score1)
				cout<<"WINNER: "<<player2<<endl;
			else
				cout<<"TIED GAME"<<endl;
			printf("\n");
			break;
		}
		if(input=="-"){
			printf("Game #%d:\n", i++);
			cout<<player1; if(score1!=1) printf(": %d points\n", score1); else printf(": %d point\n", score1);
			cout<<player2; if(score2!=1) printf(": %d points\n", score2); else printf(": %d point\n", score2);
			if(score1>score2)
				cout<<"WINNER: "<<player1<<endl;
			else if(score2>score1)
				cout<<"WINNER: "<<player2<<endl;
			else
				cout<<"TIED GAME"<<endl;
			score1 = 0; score2 = 0;
			printf("\n");
			getline(cin, input, ' '); l1 = input;
			getline(cin, input, '\n'); player1 = input;
			getline(cin, input, ' '); l2 = input;
			getline(cin, input, '\n'); player2 = input;
			temp1 = retval(l1); temp2 = retval(l2);
		}
	}
	return 0;
}