#ifndef Dictionary__h
#define Dictionary__h

#include <string>
#include <vector>
#include <set>

using namespace std;
class Dictionary{
 public:
  Dictionary(string filename); // filename of input words text file                                                                                                                                    
  // or:   const char *                                                                                                                                                                                
  // or: string     remember .c_str()                                                                                                                                                                  
  bool validWord(string word); // check if word is in Dictionary                                                                                                                                       
  string getLegalSecretWord(); // return a random word (w/out repeated letters)                                                                                                                        
 private:
  bool isLegalSecretWord(string word); // test if word n has only unique letters                                                                                                                       
  set<string> words;
  vector<string> secrets;
};


#endif
