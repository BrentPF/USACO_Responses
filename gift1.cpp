/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: bpedrofl
TASK: gift1
LANG: C++

A group of NP (2 ≤ NP ≤ 10) uniquely named friends has decided to exchange 
gifts of money. Each of these friends might or might not give some money to 
some or all of the other friends (although some might be cheap and give to no
 one). Likewise, each friend might or might not receive money from any or all 
 of the other friends. Your goal is to deduce how much more money each person 
 receives than they give.

The rules for gift-giving are potentially different than you might expect. Each 
person goes to the bank (or any other source of money) to get a certain amount 
of money to give and divides this money evenly among all those to whom he or she
is giving a gift. No fractional money is available, so dividing 7 among 2 friends
 would be 3 each for the friends with 1 left over – that 1 left over goes into 
 the giver's "account". All the participants' gift accounts start at 0 and are 
 decreased by money given and increased by money received.

In any group of friends, some people are more giving than others (or at least may 
have more acquaintances) and some people have more money than others.

Given:

a group of friends, no one of whom has a name longer than 14 characters,
the money each person in the group spends on gifts, and
a (sub)list of friends to whom each person gives gifts,
determine how much money each person ends up with.

*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main() {
    ifstream fin ("gift1.in");
	ofstream fout("gift1.out");
	string name = "";
	int cost = 0, np = 0, divisor = 1;
	map<string,int> bank;
	fin >> np;
	string nameSet[np];
	for (int i = 0; i < np; i++){
		fin >> name;
		nameSet[i] = name;
		bank[name]=0;
	}
	
	while (fin>>name){
	fin >> cost;
	fin >> divisor;
	if (divisor != 0){
	bank[name] -= cost - (cost%divisor);
	cost /= divisor;
	}
	for (int j = 0; j < divisor; j++){
	fin >> name;
	bank[name] += cost;
	}
	}
	
	for (int j = 0; j < np; j++){
		fout << nameSet[j] << " " << bank[nameSet[j]] << endl;
	}
    return 0;
}
