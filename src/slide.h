#pragma once
#include <vector>
#include <string>

using namespace std;

class Slide{
  public:
    string index;
    vector<string> tags;
    Slide(string index, vector<string> tags): index(index), tags(tags) {};
};
