#include <iostream>
#include <cstring>
using namespace std;

int main() {
   while (true) {

      string userInput;
      cout << "Enter the race outcome: ";
      cin >> userInput;
  
      if(userInput == "done") return 0;

      for (int i = 0; i < userInput.size(); i++) userInput[i] = toupper(userInput[i]); //convert the string to uppercase

      int team = 0, biggestTeam = 0;      
      int teamScores['Z'+1] = {0}; //array that keeps track of the team score
      int teamRunners['Z'+1] = {0}; //array that keeps track of runners in a team

  for (int i = 0; i < userInput.length(); i++) {
            char index = userInput[i];
            if(teamScores[index] == 0) team++;
            teamScores[index] += (i + 1);
            teamRunners[index]++;
        if(teamRunners[index] > biggestTeam) biggestTeam = teamRunners[index];
      }

 if (biggestTeam != (userInput.length() / team)) { 
         cout << "The teams do not have the same number of runners. Please try again.\n";
         continue;
      }

cout << "\nThere are " << team << " teams." << endl;
cout << "Each team has " << biggestTeam << " runners." << endl << endl;
cout << "Team     " << "Score" << endl;
double winScore = userInput.length() * userInput.length();
string winTeam = ""; // string because there can be a tie for the first place

  for (char i = 'A'; i <= 'Z'; i++) {   
         if (teamScores[i] != 0) {              
            cout << i << "        " << (double)(teamScores[i] / biggestTeam) << endl;
            if (teamScores[i] < winScore) {
               winTeam = i;
               winScore = teamScores[i]; 
            }
            else if (teamScores[i] == winScore)
               winTeam += i;
          }
  }

cout << "The winning team is " << winTeam << " with score " << winScore / biggestTeam << endl;


   }
}
