#include <iostream>
#include "./src/parse.h"
#include "./src/slide.h"
#include "./src/vertical_grouping_multithreaded.h"
#include "./src/slide_composition_multithreaded.h"
#include "./src/output.h"

int main(){
  std::vector<Slide*> slides, vertical_photos; // horizontal photos are already slides
  parse("./examples/a_example.txt", slides, vertical_photos);

  std::vector<Slide*> V_grouped = vertical_grouping(vertical_photos);

  slides.insert(slides.end(), V_grouped.begin(), V_grouped.end());

  std::vector<Slide*> slide_show = slide_composition(slides);

  output("./output/result.txt", slide_show);


  return 0;
}
