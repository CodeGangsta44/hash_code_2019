#include "slide.h"
#include <iostream>
#include "actions_on_sorted_sets.h"
#include "delta_counting.h"

void delta_counting (Slide* first, Slide* second, int& profit, int& delta) {
  int intersection  = count_length_of_intersection(first->tags, second->tags);
  int first_diff = count_length_of_difference(first->tags, second->tags);
  int second_diff = count_length_of_difference(second->tags, first->tags);
  profit = min(min(first_diff, second_diff), intersection);
  delta = max(max(first_diff, second_diff), intersection) - profit;
}
