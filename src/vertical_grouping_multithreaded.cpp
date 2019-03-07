#include <iostream>
#include <vector>
#include <thread>
#include "actions_on_sorted_sets.h"
#include "slide.h"
#include "vertical_grouping_multithreaded.h"

void get_best_photo_in_range (std::vector<Slide*> photos, Slide* curr_photo, int start, int stop, int* result) {
  int best_length_of_union = 0;
  int curr_union_length = 0;

  for (int i = start; i < stop; i++) {
    curr_union_length = count_length_of_union(curr_photo->tags, photos[i]->tags);
    if (curr_union_length > best_length_of_union) {
      *result = i;
      best_length_of_union = curr_union_length;
    }
  }
}

std::vector<Slide*> vertical_grouping (std::vector<Slide*> photos) {
  std::vector<Slide*>* result = new std::vector<Slide*>();
  int best_index;
  int best_length_of_union;
  int curr_union_length;

  while (photos.size() > 0){
    int step = photos.size() / 1000;
    Slide* first_photo = photos[photos.size() - 1];
    photos.pop_back();
    if (step < 5) {
      best_index = -1;
      best_length_of_union = 0;
      curr_union_length = 0;

      for (int i = 0; i < photos.size(); i++) {
        curr_union_length = count_length_of_union(first_photo->tags, photos[i]->tags);
        if (curr_union_length > best_length_of_union) {
          best_index = i;
          best_length_of_union = curr_union_length;
        }
      }
      result->push_back(new Slide(first_photo->index + ' ' + photos[best_index]->index,
                                  union_of_sets(first_photo->tags, photos[best_index]->tags)));

      photos.erase(photos.begin() + best_index);
    } else {
      int** index_result = new int*[1000];
      std::thread th_array[1000];

      for (int i = 0; i < 1000; i++){
        int start = i*step;
        int stop = start + step < photos.size() ? start + step : photos.size() - 1;
        index_result[i] = new int();
        th_array[i] = std::thread(get_best_photo_in_range, photos, first_photo, start, stop, index_result[i]);
      }

      for (int i = 0; i < 1000; i++) th_array[i].join();

      best_index = -1;
      best_length_of_union = 0;
      curr_union_length = 0;
      int curr_index;

      for (int i = 0; i < 1000; i++) {
        curr_index = *(index_result[i]);
        curr_union_length = count_length_of_union(first_photo->tags, photos[curr_index]->tags);
        if (curr_union_length > best_length_of_union) {
          best_index = curr_index;
          best_length_of_union = curr_union_length;
        }
      }

      result->push_back(new Slide(first_photo->index + ' ' + photos[best_index]->index,
                                  union_of_sets(first_photo->tags, photos[best_index]->tags)));

      photos.erase(photos.begin() + best_index);

    }
  }

  return *result;
}
