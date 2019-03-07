#include <iostream>
#include <vector>
#include "actions_on_sorted_sets.h"
#include "slide.h"
#include "vertical_grouping.h"


std::vector<Slide*> vertical_grouping (std::vector<Slide*> photos) {
  std::vector<Slide*>* result = new std::vector<Slide*>();
  int best_index;
  int best_length_of_union;
  int curr_union_length;

  while (photos.size() > 0){
    Slide* first_photo = photos[photos.size() - 1];
    photos.pop_back();
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
    std::cout << "grouped" << std::endl;
    result->push_back(new Slide(first_photo->index + ' ' + photos[best_index]->index,
                                union_of_sets(first_photo->tags, photos[best_index]->tags)));

    photos.erase(photos.begin() + best_index);
  }

  return *result;
}
