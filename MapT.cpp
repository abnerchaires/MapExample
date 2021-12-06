#include "MapT.h"
#include <unordered_map>
//using namespace std;

const int DEFAULT_BUCKETS = 10;
const double DEFAULT_LOAD = 1.0;

template<class K, class T>
MapT<K, T>::MapT() {
    buckets = new forward_list<pair<K, T>>[DEFAULT_BUCKETS];
    numBuckets = DEFAULT_BUCKETS;
    numKeys = 0;
    maxLoad = DEFAULT_LOAD;
}

template<class K, class T>
MapT<K, T>::MapT(int numBuckets) {
    buckets = new forward_list<pair<K, T>>[numBuckets];
    this->numBuckets = numBuckets;
    numKeys = 0;
    maxLoad = DEFAULT_LOAD;




}

template<class K, class T>
void MapT<K, T>::Add(K key, T value) {

    int bucket = GetHashIndex(key); // find bucket index.

    // Look at each element in the link list of the bucket.
    for(auto it = buckets[bucket].begin(); it != buckets[buckets].end(); ++it) {

        // Found an item with the same key.
        if (it->first == key) {
            it->second = value; // set to the new value
            return;
        }
    }

    // If the key does not already exist, add the key value pair.
    pair<K, T> keyValuePair;
    keyValuePair.first = key;
    keyValuePair.second = value;

    buckets[bucket].push_front(keyValuePair); // Places the new value in front of the linked list.
    ++numKeys;

    if (LoadFactor() > maxLoad) {
        Rehash(numBuckets*2);
    }
}

template<class K, class T>
void MapT<K, T>::Remove(K key) {

}

template<class K, class T>
bool MapT<K, T>::Contains(K key) {
    return false;
}

template<class K, class T>
double MapT<K, T>::LoadFactor() {
    return 0;
}

template<class K, class T>
void MapT<K, T>::SetMaxLoad(double maxLoad) {


}

template<class K, class T>
void MapT<K, T>::Rehash(int numBuckets) {
    MapT::MapT<K, T> newMap(numBuckets); // creates a new map.

    ResetIterator(); // Iterate through "this"
    for (int i = 0; i < numKeys; i++) {
        pair<K, T> keyValue = GetNextPair();
        newMap.Add(keyValue.first, keyValue.second);
    }

    *this = newMap;
}

template<class K, class T>
T MapT<K, T>::operator[](K key) {
    return nullptr;
}

template<class K, class T>
void MapT<K, T>::ResetIterator() {
    mapIter = buckets[0].begin();
    currBucket = 0;
}

template<class K, class T>
pair<K, T> MapT<K, T>::GetNextPair() {
    return pair<K, T>();
}

template<class K, class T>
int MapT<K, T>::GetHashIndex(const K &key) {
    unordered_map<K,T> mapper;
    typename unordered_map<K,T>::hasher hashFunction = mapper.hash_function();
    return static_cast<int>(hashFunction(key) % numBuckets);
}

template<class K, class T>
MapT<K, T> MapT<K, T>::operator=(const MapT<K, T> &otherMap) {
    return MapT<K, T>();
}





