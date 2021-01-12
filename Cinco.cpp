#include <iostream>
#include <string>

#include "Cinco.h"
#include "Dictionary.h"
using std::cout;
using std::endl;

Cinco::Cinco(string filename){


  dict = new Dictionary(filename);
  secret =  dict->getLegalSecretWord();
  numguesses  = 0;
  cheated = false;
}


Cinco::~Cinco(){
  delete dict;
  dict = 0;

}




void Cinco::play(){
  string guess;
  cout << "I'm thinking of a five letter word..." << endl;

  while(cin && countInPlaceLetters(guess) != secret.length()){
    cout << "Your Guess? ";
    std::cin >> guess;

    if(guess == "xxxxx"){
      cheated = true;
      //cout << "cheat code " << cheated << endl;                                                                                                                                                      
      cout << "Secret Word is: " << secret << endl;
    }
    else if(!dict->validWord(guess)){
      cout << "I don't know that word." << endl;
      numguesses++;
    }
    else if(dict->validWord(guess)){
      cout << "Matching: " << countMatchingLetters(guess) << endl;
      cout << "In-Place: " << countInPlaceLetters(guess) << endl;
      numguesses++;
    }
  }
  if(countInPlaceLetters(guess) == secret.length()){
    if(cheated == true)
      cout << "Correct! You got it in " << numguesses << " guesses, but only by cheating." << endl;
    else
      cout << "Correct!  You got it in " << numguesses << " guesses." << endl;

  }

}

int Cinco::countMatchingLetters(std::string guess){
  int count = 0;
  int repeated = 0;
  int matching = 0;
  for(int i = 0; i < guess.length(); i++){
    for(int j = 0; j < guess.length(); j++){
      if(guess[i] == secret[j])
        count++;
    }
  }
  for(int i = 0; i < guess.length(); i++){
    for(int j = i + 1; j < guess.length(); j++){
      if(guess[i] == guess[j]){
        repeated++;
      }
    }
  }
  //  cout << "count: " << count << endl;                                                                                                                                                              
  // cout << "repeated: " << repeated << endl;                                                                                                                                                         
  if(count == 0)
    return 0;
  else if(repeated == 3)
    return count - repeated - 1;
  return count - repeated;

}

int Cinco::countInPlaceLetters(std::string guess){
  int count = 0;
   for(int i = 0; i < guess.length(); i++){
    if(guess[i] == secret[i]){
      count++;
    }
   }


  return count;
}


