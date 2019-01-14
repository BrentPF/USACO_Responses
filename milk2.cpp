/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: bpedrofl
TASK: milk2
LANG: C++

Three farmers rise at 5 am each morning and head for the barn to milk three cows. 
The first farmer begins milking his cow at time 300 (measured in seconds after 
5 am) and ends at time 1000. The second farmer begins at time 700 and ends at time 
1200. The third farmer begins at time 1500 and ends at time 2100. The longest 
continuous time during which at least one farmer was milking a cow was 900 seconds 
(from 300 to 1200). The longest time no milking was done, between the beginning and 
the ending of all milking, was 300 seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning and ending 
times for N (1 <= N <= 5000) farmers milking N cows and compute (in seconds):

The longest time interval at least one cow was milked.
The longest time interval (after milking starts) during which no cows were being
milked.

*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//minus 64
int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

    vector<pair<int,int> > timeSlots;
    int numTimes = 0;
	int startVal=5000;
    int endVal = 0;
    int longestMilking = 0;
    int longestIdle = 0;

    fin>>numTimes;
    for(int i = 0; i < numTimes; i++){
    	pair<int,int> timeSlot;
    	fin>>timeSlot.first;
    	fin>>timeSlot.second;
    	if (timeSlot.second > endVal) endVal = timeSlot.second;
		if (timeSlot.first < startVal) startVal = timeSlot.first;
    	timeSlots.push_back(timeSlot);
    }

    int timeLine[endVal];
    for (int z = 0; z < endVal; z++) timeLine[z] = 0;

    for (unsigned int j = 0; j < timeSlots.size(); j++){
		if (timeSlots[j].first == startVal && timeSlots[j].second == endVal) longestMilking = endVal-startVal;
    	for (int k = timeSlots[j].first-1; k < timeSlots[j].second-1; k++){
    		if (timeLine[k] == 0) timeLine[k]=1;
    		else if (timeLine[k]==1 || timeLine[k] ==2) timeLine[k]=2;
    	}
    }

    int counter = 0;
    for (int c = 0; c < endVal; c++) {
    	if (timeLine[c] == 2 || timeLine[c] == 1){
    		counter++;
    	}
    	else {
    		longestMilking=(counter>longestMilking)?counter:longestMilking;
			counter = 0;
    	}
    }
	longestMilking=(counter>longestMilking)?counter:longestMilking;
    counter = 0;
    for (int d=startVal; d < endVal-1; d++) {
        	if (timeLine[d] == 0){
        		counter++;
        	}
        	else {
        		longestIdle=(counter>longestIdle)?counter:longestIdle;
				counter = 0;
        	}
        }
	longestIdle=(counter>longestIdle)?counter:longestIdle;
    fout<<longestMilking << " " << longestIdle<< endl;
    return 0;
}


