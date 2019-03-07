#include <vector>
#include <thread>
#include <iostream>
#include <fstream>
#include "slide.h"
#include "delta_counting.h"
#include "slide_composition_multithreaded.h"

void get_best_slide_in_range(std::vector<Slide*> slides, Slide* current_slide, int start, int stop, int* result){
  int best_index = -1;
  int best_profit = -1;
  int best_delta = 2147483647;

  int curr_profit = -1;
  int curr_delta = 2147483647;

  for (int i = start; i < stop; i++) {
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
  *result = best_index;
}

std::vector<Slide*> slide_composition (std::vector<Slide*> slides) {
  std::vector<Slide*>* result = new std::vector<Slide*>();
  int best_index, best_profit, best_delta, curr_profit, curr_delta;

  Slide* current_slide = slides[slides.size() - 1];
  slides.pop_back();
  result->push_back(current_slide);

  while (slides.size() > 0){
    //cout << current_slide->index << endl;
    int step = slides.size() / 1000;
    best_index = -1;
    best_profit = -1;
    best_delta = 2147483647;

    curr_profit = -1;
    curr_delta = 2147483647;

    if(step < 5){

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


    } else {
      int** index_result = new int*[1000];
      std::thread th_array[1000];

      for (int i = 0; i < 1000; i++){
        int start = i * step;
        int stop = start + step < slides.size() ? start + step : slides.size() - 1;
        index_result[i] = new int();
        th_array[i] = std::thread(get_best_slide_in_range, slides, current_slide, start, stop, index_result[i]);
      }

      for (int i = 0; i < 1000; i++) th_array[i].join();

      for (int i = 0; i < 1000; i++) {
        delta_counting(current_slide, slides[*(index_result[i])], curr_profit, curr_delta);

        if(curr_delta < best_delta){
          best_index = *(index_result[i]);
          best_delta = curr_delta;
        }
        else if(curr_delta == best_delta && curr_profit > best_profit){
          best_index = *(index_result[i]);
          best_profit = curr_profit;
        }
      }
    }

    current_slide = slides[best_index];
    result->push_back(current_slide);
    slides.erase(slides.begin() + best_index);

  }

  return *result;
}
