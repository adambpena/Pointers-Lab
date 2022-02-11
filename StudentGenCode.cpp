#include <iostream>
#include <iomanip>
using namespace std;

// Name: Adam Pena

void sort(float* scorePtr, int numOfScores){  // Function to sort scores array in ascending order
  float temp;  // Temporary float variable for swapping

  for(int i = 0; i < numOfScores; i++){  // Outer for loop iterating through scores

    for(int j = i; j < numOfScores; j++){ // Inner loop comparing first element to find smallest score, starts at i to avoid resorting first element
      if(*(scorePtr + j) < *(scorePtr + i)){ // If inner loop finds element smaller than first element...
        temp = *(scorePtr + j); // Store smallest in temp
        *(scorePtr + j) = *(scorePtr + i); // Swap where smallest was with first element
        *(scorePtr + i) = temp; // First element is the smallest element found
      }
    }
  }
}

void indexOf(float* scorePtr, int numOfScores){ // Function to search scores for a specific score
  float idNum; // Variable to take input that will be searched from scores
  cout << "Please enter an id number to be searched: "<< endl;
  cin >> idNum; // Get input to search
  for(int i = 0; i < numOfScores; i++){ // Iterate through scores for idNum
    if(idNum - *(scorePtr + i) == 0){
      cout << idNum << " is in the array." << endl;
      return; // If found, function ends
    }
  }

  cout << idNum << " is not in the array."; // If loop finishes without finding number, inform user the number isnt in the array
}

float *scores = nullptr; // Pointer to a float 
int numScores = 0; // Variable where array length will be stored
float average = 0; // Variable that will hold average of scores

int main(){
  cout << "Please input the number of scores: " << endl;
  cin >> numScores;
  
  scores = new float[numScores]; // Dynamically creating space for an array of floats of size numScores

  for(int i = 0; i < numScores; i++){ // Iterate throuogh array, inputting score sequentially in score array
    cout << "Please enter a score: " << endl;
    cin >> *(scores + i); // Incrementing through array via pointer addition
    average += *(scores + i); // Accumulating sum to calculate average
  }

  cout << fixed << setprecision(2); // Formatting floats

  cout << "The average of the scores is " << average/numScores << endl; // Print average

  sort(scores, numScores); // Calling sort function
  
  cout << "Here are the scores in ascending order: " << endl; // Printing sorted scores with following for loop
  
  for(int i = 0; i < numScores; i++){
    cout << *(scores + i) << endl;
  }

  indexOf(scores, numScores); // Callind indexOf function

  return 0;
}