#include <iostream>
#include "parse.h"
#include "slide.h"
#include "vertical_grouping_multithreaded.h"
#include "slide_composition_multithreaded.h"
#include "output.h"

int main(){
  std::vector<Slide*> slides, vertical_photos; // horizontal photos are already slides
  parse("d_pet_pictures.txt", slides, vertical_photos);

  std::vector<Slide*> V_grouped = vertical_grouping(vertical_photos);

  slides.insert(slides.end(), V_grouped.begin(), V_grouped.end());

  std::vector<Slide*> slide_show = slide_composition(slides);

  output("result.txt", slide_show);


  return 0;
}
