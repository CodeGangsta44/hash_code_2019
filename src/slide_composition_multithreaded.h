#include <vector>
#include "slide.h"
#include "delta_counting.h"

void get_best_slide_in_range (std::vector<Slide*>, Slide*, int, int, int*);
std::vector<Slide*> slide_composition (std::vector<Slide*>);
