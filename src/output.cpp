#include <vector>
#include <fstream>
#include "slide.h"
#include "output.h"

void output (const char* filename, std::vector<Slide*>& slides) {
  std::ofstream fout(filename);
  fout << slides.size() << std::endl;
  for (int i = 0; i < slides.size(); i++) fout << slides[i]->index << endl;
  fout.close();
}
