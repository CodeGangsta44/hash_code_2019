#include <vector>
#include <string>
#include "slide.h"

using namespace std;

class Slide{
  protected:
    string index;
    vector<string> tags;
  public:
    Slide(string index, vector<string> tags): index(index), tags(tags) {};
};
