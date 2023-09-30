#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include "Collection.h"

namespace sdds {

    //for the logic to work, collectionT must have a valid insertion and indexing operator overload. Since ArrayT is expected to be an index it must be ArrayT must
    //recieve an array. The KeyT must also have a valid == operator overload to compare the key being passed. 
    template <typename CollectionT, typename ArrayT, typename KeyT>
    bool search(CollectionT& collection, const ArrayT& arr, int size, const KeyT& key) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                found = true;
                collection.add(arr[i]);
            }
        }
        return found;
    }
    // as mentioned above the ArrayT must be an array, if not its must have a valid index operator overload in order for the logic to work.
    template <typename ArrayT>
    void listArrayElements(const char* title, const ArrayT& arr, int size) {
        std::cout << title << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << i + 1 << ": " << arr[i] << std::endl;
        }
    }
} 

#endif // SDDS_SEARCHNLIST_H_
