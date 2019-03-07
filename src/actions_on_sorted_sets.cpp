#include <vector>
#include <string>
#include <iostream>
#include "actions_on_sorted_sets.h"

std::vector<std::string>& union_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {
  std::vector<std::string>* result = new std::vector<std::string>();
  int n = set1.size(), m = set2.size(), i = 0, j = 0;
  while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			result->push_back(set1[i]);
			i++;
      j++;
		} else {
			if (set1[i] < set2[j]) {
        result->push_back(set1[i]);
				i++;
			} else {
        result->push_back(set2[j]);
				j++;
			}
		}
	}
  while (i < n) {
		result->push_back(set1[i]);
		i++;
	}
	while (j < m) {
		result->push_back(set2[j]);
		j++;
	}

  return *result;
}

int count_length_of_union(std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = 0;
  int n = set1.size(), m = set2.size(), i = 0, j = 0;
  while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			result++;
			i++;
      j++;
		} else {
			if (set1[i] < set2[j]) {
        result++;
				i++;
			} else {
        result++;
				j++;
			}
		}
	}
  while (i < n) {
		result++;
		i++;
	}
	while (j < m) {
		result++;
		j++;
	}

  return result;
}

std::vector<std::string>& intersection_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {

  std::vector<std::string>* result = new std::vector<std::string>();
  int n = set1.size(), m = set2.size(), i = 0, j = 0;
	while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			result->push_back(set1[i]);
			i++; j++;
		} else {
			if (set1[i] < set2[j]) {
				i++;
			} else {
				j++;
			}
		}
	}
  return *result;
}

int count_length_of_intersection (std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = 0;
  int n = set1.size(), m = set2.size(), i = 0, j = 0;
	while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			result++;
			i++; j++;
		} else {
			if (set1[i] < set2[j]) {
				i++;
			} else {
				j++;
			}
		}
	}
  return result;
}

std::vector<std::string>& difference_of_sets (std::vector<std::string> set1, std::vector<std::string> set2) {

  std::vector<std::string>* result = new std::vector<std::string>();
  int n = set1.size(), m = set2.size(), i = 0, j = 0;
	while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			i++,j++;
		} else {
			if (set1[i] < set2[j]) {
        result->push_back(set1[i]);
				i++;
			} else j++;
		}
	}
	while (i < n) {
		result->push_back(set1[i]);
		i++;
	}
  return *result;
}

int count_length_of_difference (std::vector<std::string> set1, std::vector<std::string> set2) {
  int result = 0;
  int n = set1.size(), m = set2.size(), i = 0, j = 0;

  while ((i < n) && (j < m)) {
		if (set1[i] == set2[j]) {
			i++,j++;
		} else {
			if (set1[i] < set2[j]) {
        result++;
				i++;
			} else j++;
		}
	}
	while (i < n) {
		result++;
		i++;
	}
  return result;
}
