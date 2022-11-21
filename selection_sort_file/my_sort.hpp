template<typename iterator>

void my_selection_sort( iterator begin, iterator end) {
    for (iterator it = begin; it != end; ++it) {
        iterator minIt = it;
        for (iterator it2 = it; it2 != end; ++it2) {
            if (*it2 < *minIt) {
                minIt = it2;
            }
        }
        // swap
        auto tmp = *it;
        *it = *minIt;
        *minIt = tmp;
    }
}