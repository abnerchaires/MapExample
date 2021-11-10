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
void MapT<K, T>::Add(K key, T value) {

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

}

template<class K, class T>
T MapT<K, T>::operator[](K key) {
    return nullptr;
}

template<class K, class T>
void MapT<K, T>::ResetIterator() {

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



