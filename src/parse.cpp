#include "parse.h"
#include <fstream>
#include <string>
#include <algorithm>

void parse(const char* filename, std::vector<Slide*>& horizontal, std::vector<Slide*>& vertical) {
  std::ifstream fin(filename);
  int photo_counter;
  fin >> photo_counter;
  for(int i = 0; i < photo_counter; i++){
    char orientation;
    int tags_counter;
    std::vector<std::string> tags;
    fin >> orientation >> tags_counter;

    for (int j = 0; j < tags_counter; j++){
      std::string tag;
      fin >> tag;
      tags.push_back(tag);
    }
    std::sort(tags.begin(), tags.end());
    switch (orientation){
      case 'H': horizontal.push_back(new Slide(std::to_string(i), tags)); break;
      case 'V': vertical.push_back(new Slide(std::to_string(i), tags)); break;
    }
  }
}
