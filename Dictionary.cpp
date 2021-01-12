#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

#include "Dictionary.h"
//#include "Cinco.h"                                                                                                                                                                                   

Dictionary::Dictionary(string filename){
  ifstream inF;
  inF.open(filename.c_str());
  if(inF.fail()){
    std::cerr << "Error in filename" << std::endl;
    std::exit(1);
  }

  for(std::string word; getline( inF, word);){
    words.insert(word);
    if(isLegalSecretWord(word))
       secrets.push_back(word);
  }
}




bool Dictionary::validWord(std::string word){
  if(words.count(word) == 1)
    return true;
  return false;
}



string Dictionary::getLegalSecretWord(){
  int randIndex = rand() % secrets.size();
  return secrets[randIndex];


}




bool Dictionary::isLegalSecretWord(std::string word){
  for(int i = 0; i < word.length(); i++){
    for(int j = 0; j < word.length(); j++){
      if(i!= j && word[i] == word[j])
        return false;
    }
  }
  return true;
}
