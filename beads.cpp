/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: bpedrofl
TASK: beads
LANG: C++

You have a necklace of N red, white, or blue beads (3<=N<=350) some of which are 
red, others blue, and others white, arranged at random. Here are two examples for
n=29:

                1 2                               1 2
            r b b r                           b r r b
          r         b                       b         b
         r           r                     b           r
        r             r                   w             r
       b               r                 w               w
      b                 b               r                 r
      b                 b               b                 b
      b                 b               r                 b
       r               r                 b               r
        b             r                   r             r
         b           r                     r           r
           r       r                         r       b
             r b r                             r r w
            Figure A                         Figure B
                        r red bead
                        b blue bead
                        w white bead
The beads considered first and second in the text that follows have been marked 
in the picture.

The configuration in Figure A may be represented as a string of b's and r's, where 
b represents a blue bead and r represents a red one, as follows: 
brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight, and then 
collect beads of the same color from one end until you reach a bead of a different 
color, and do the same for the other end (which might not be of the same color as 
the beads collected before this).

Determine the point where the necklace should be broken so that the most number of 
beads can be collected.

Example
For example, for the necklace in Figure A, 8 beads can be collected, with the 
breaking point either between bead 9 and bead 10 or else between bead 24 and bead 25.

In some necklaces, white beads had been included as shown in Figure B above. When 
collecting beads, a white bead that is encountered may be treated as either red or 
blue and then painted with the desired color. The string that represents this 
configuration can include any of the three symbols r, b and w.

Write a program to determine the largest number of beads that can be collected from 
a supplied necklace.

*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <string>
using namespace std;
//minus 64
int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");
    int numBeads = 0;
    fin >> numBeads;
    string necklace = "";
    fin >> necklace;
    int highestCount = 0;
    int count = 0;
    bool secondColour = false;
    char currentColour = necklace[0];
    for (int i = 0; i < numBeads*2; i++){
		if (count != numBeads){
    	if (necklace[i%numBeads] == currentColour || necklace[i%numBeads] == 'w') {
			count++;
		}
    	else if (secondColour == false){
			count++;
    		secondColour = true;
    		currentColour = necklace[i%numBeads];
    	}
    	else if (secondColour == true){
    		secondColour = false;
    		highestCount = (count>highestCount)?count:highestCount;
			count = 0;
    	}
		}
		else highestCount = numBeads;
    }
    fout<<highestCount<<endl;
    return 0;
}
