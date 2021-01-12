#ifndef Cinco__h
#define Cinco__h

#include <string>
#include <vector>
#include <set>
#include "Dictionary.h"

class Cinco{
 public:
  Cinco(std::string filename="cinco-words.txt");  // or char * or const char *                                                                                                                         
  ~Cinco();
  void play(); // public interface to play game of cinco                                                                                                                                               
 private:
  // count functions compare string param with the secret word                                                                                                                                         
  int countMatchingLetters(std::string); // find common letters in any order                                                                                                                           
  int countInPlaceLetters(std::string);  // find common letters in place                                                                                                                               
  Dictionary *dict; // legal words for the game                                                                                                                                                        
  int numguesses; // track number of guesses used                                                                                                                                                      
  bool cheated; // flag set to true if cheat code is used                                                                                                                                              
  std::string secret; // word to guess                                                                                                                                                                 
};

#endif
