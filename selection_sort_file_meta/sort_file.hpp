// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>
#include <tuple>
#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template <class T, class cont>
void read_file_to_cont(std::ifstream& f, cont& c) {
    T elem;
    if constexpr (std::is_same_v<char, T>) {
        while (f.get(elem)) {
            c.push_back(elem);
            f.get(elem);
        }
    }
    else {
        while (f >> elem) {
            c.push_back(elem);
        }
    }

}

template <class T, class cont>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
  cont c = {};
  read_file_to_cont<T, cont>(fi, c);
  if constexpr (std::is_integral_v<type>) {
        my_selection_sort(c.begin(), c.end(), [](T l, T r)->bool {
            return std::make_tuple(l%2, l) < std::make_tuple(r%2, r);
        });
    }
    else {
        my_selection_sort(c.begin(), c.end(), [](T l, T r)->bool { return l > r;});

  } 
  for (T &elem : c)
      fo << elem << std::endl;
}

template<class T>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  // read second line to decide container
  char secondLine;
  fi >> secondLine;
  fo << secondLine << std::endl;
  switch (secondLine) {
    case 'l':
      read_and_sort<T, std::list<T>>(fi, fo);
      break;
    case 'v':
      read_and_sort<T, std::vector<T>>(fi, fo);
      break;
    case 'd':
      read_and_sort<T, std::deque<T>>(fi, fo);
      break;
    default:
      throw std::runtime_error("Unknown container");
  }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
    char firstLine;
    fi >> firstLine;
    fo << firstLine << std::endl;
    switch(firstLine)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned >(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
    }
}



