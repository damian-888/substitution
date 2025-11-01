#include <cstring>
#include <iostream>
#include <limits>
#include <string>

int main(int argc, char* argv[]){
  
  //Gets input and stores key in string if exactly 26 chars;
  if(argc == 2) {
    while(true) {
      std::string key = argv[1];
      std::cout << "(Debug)Key: " << key << '\n';

      if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else if(std::strlen(argv[1]) < 26 || std::strlen(argv[1]) > 26) {
        std::cout << "Key must be 26 characters.\n";
        break;
      } else {
        break;
      }
    }
  } else {
    std::cout << "Usage: ./substitution key\n";
  }


  return 0;
}
