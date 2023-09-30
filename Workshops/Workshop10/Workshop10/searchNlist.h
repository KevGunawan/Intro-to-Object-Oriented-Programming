#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include "Collection.h"

namespace sdds {

    // search function template
    // Requirements for Template Types:
    // - CollectionT: It should be a class that implements Collection<T> and provides the following member functions:
    //   - int size() const: Returns the number of elements in the collection.
    //   - CollectionT& add(const T& element): Adds the element to the collection.
    // - ArrayT: It should be an array type (e.g., T[] or std::vector<T>) that supports the [] operator for indexing.
    //   - The elements of the array should be of the same type as the Collection elements (T).
    // - KeyT: It should support the == operator to compare with elements of the array.
    template <typename CollectionT, typename KeyT>
    bool search(CollectionT& collection, const CollectionT& arr, int size, const KeyT& key) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                found = true;
                collection.add(arr[i]);
            }
        }
        return found;
    }
    // listArrayElements function template
    // Requirements for Template Types:
    // - ArrayT: It should be an array type (e.g., T[] or std::vector<T>) that supports the [] operator for indexing.
    template <typename ArrayT>
    void listArrayElements(const char* title, const ArrayT& arr, int size) {
        std::cout << title << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i + 1 << ": " << arr[i] << std::endl;
        }
    }

} 

#endif // SDDS_SEARCHNLIST_H_

