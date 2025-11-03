#include <cctype>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

//DEFINITIONS
std::string ciphertext(std::string key, std::string plaintext);

//GLOBAL
std::string key;
std::string plaintext;
std::vector<char> alpha = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, char* argv[]){

  std::string key = argv[1];
  std::cout << key << '\n';

  //Gets input and stores key in string if exactly 26 chars;
  if(argc == 2) {

    while(true) {
    std::string key = argv[1];

      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else if(std::strlen(argv[1]) < 26 || std::strlen(argv[1]) > 26) {
        std::cout << "Key must be 26 characters.\n";
        return 1;
      } else {
        break;
      }
    }
  } else {
    std::cout << "Usage: ./substitution key\n";
  }

  while(true) {
    std::cout << "plaintext: ";
    std::getline(std::cin, plaintext);

    if(std::cin.fail()) {
      std::cin.fail();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      break;
    }
  }

  std::string encrypted = ciphertext(key, plaintext);
  std::cout << "ciphertext: " << encrypted << '\n';

  return 0;
}

std::string ciphertext(std::string key, std::string plaintext) {
  
  std::string encrypted = plaintext;
  
  for(int i  = 0; i < plaintext.length(); i++) {
    
    if(std::isupper(plaintext[i])) {
      for(int j = 0; j < alpha.size(); j++) {
        if(alpha[j] == plaintext[j]) {
          encrypted[i] = key[j]; 
        }
      }

    } else if(std::islower(plaintext[i])) {

    } else {
      encrypted[i] = plaintext[i];
    }

  }
  
  return encrypted;
}
