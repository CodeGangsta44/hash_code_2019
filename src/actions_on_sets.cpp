#include <vector>
#include <string>
#include "actions_on_sets.h"

bool find_item (std::vector<std::string> set, std::string item) {
  for (int i = 0; i < set.size(); i++) {
    if (set[i] == item) return true;
  }
  return false;
}

std::vector<std::string>& union_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {
  std::vector<std::string>* result = new std::vector<std::string>(set1);
  for (int i = 0; i < set2.size(); i++){
    if (!find_item(*result, set2[i])) result->push_back(set2[i]);
  }
  return *result;
}

std::vector<std::string>& intersection_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {
  std::vector<std::string>* result = new std::vector<std::string>();
  for (int i = 0; i < set1.size(); i++){
    if (find_item(set2, set1[i])) result->push_back(set1[i]);
  }
  return *result;
}

std::vector<std::string>& difference_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {
  std::vector<std::string>* result = new std::vector<std::string>();
  for (int i = 0; i < set1.size(); i++){
    if (!find_item(set2, set1[i])) result->push_back(set1[i]);
  }
  return *result;
}

int count_length_of_union (std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = set1.size();
  for (int i = 0; i < set2.size(); i++){
    if (!find_item(set1, set2[i])) result++;
  }
  return result;
}

int count_length_of_intersection (std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = 0;
  for (int i = 0; i < set1.size(); i++){
    if (find_item(set2, set1[i])) result++;
  }
  return result;
}

int count_length_of_difference (std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = 0;
  for (int i = 0; i < set1.size(); i++){
    if (!find_item(set2, set1[i])) result++;
  }
  return result;
}
