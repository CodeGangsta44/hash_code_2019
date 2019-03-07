#include <vector>
#include <iostream>
#include "slide.h"
#include "delta_counting.h"
#include "slide_composition.h"

std::vector<Slide*> slide_composition (std::vector<Slide*> slides) {
  std::vector<Slide*>* result = new std::vector<Slide*>();
  int best_index, best_profit, best_delta, curr_profit, curr_delta;

  Slide* current_slide = slides[slides.size() - 1];
  slides.pop_back();
  result->push_back(current_slide);


  while (slides.size() > 0){
    best_index = -1;
    best_profit = -1;
    best_delta = 2147483647;

    curr_profit = -1;
    curr_delta = 2147483647;

    for (int i = 0; i < slides.size(); i++) {
      delta_counting(current_slide, slides[i], curr_profit, curr_delta);

      if(curr_delta < best_delta){
        best_index = i;
        best_delta = curr_delta;
      }
      else if(curr_delta == best_delta && curr_profit > best_profit){
        best_index = i;
        best_profit = curr_profit;
      }
    }
    current_slide = slides[best_index];
    result->push_back(current_slide);
    slides.erase(slides.begin() + best_index);

  }

  return *result;
}
