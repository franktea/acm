/*
 * 146 LRU Cache.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: frank
 */
#include <unordered_map>
#include <iostream>
#include <list>
#include <cassert>

class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {}

    int get(int key)
    {
        auto it = data_.find(key);
        if(it == data_.end())
        	return -1;

        // now this key is the newest, move to list tail
        lru_list_.erase(it->second.first);
        lru_list_.push_back(key);
        it->second.first = Last();

        return it->second.second;
    }

    void put(int key, int value)
    {
    	auto it = data_.find(key);
    	if(it != data_.end())
    	{
    		it->second.second = value;

    		// now this key is the newest
            lru_list_.erase(it->second.first);
            lru_list_.push_back(key);
            it->second.first = Last();

            return;
    	}

    	// new key, insert
    	if(data_.size() >= capacity_)
    	{
    		auto front = lru_list_.front();
    		data_.erase(front);
    		lru_list_.pop_front();
    	}

    	lru_list_.push_back(key);
    	data_.insert(std::make_pair(key, std::make_pair(Last(), value)));
    }
private:
    std::list<int>::iterator Last()
    {
    	auto it = lru_list_.end();
    	--it;
    	return it;
    }
private:
    std::unordered_map<int, std::pair<std::list<int>::iterator, int>> data_; // key: iterator, value
    std::list<int> lru_list_; // keys
    int capacity_;
};

int main()
{
	LRUCache* cache_ = new LRUCache( 2 /* capacity */ );
	LRUCache& cache = * cache_;

	cache.put(1, 1);
	cache.put(2, 2);
	auto c = cache.get(1);       // returns 1
	assert(c == 1);
	cache.put(3, 3);    // evicts key 2
	c = cache.get(2);       // returns -1 (not found)
	assert(c == -1);
	cache.put(4, 4);    // evicts key 1
	c = cache.get(1);       // returns -1 (not found)
	assert(c == -1);
	c = cache.get(3);       // returns 3
	assert(c == 3);
	c = cache.get(4);       // returns 4
	assert(c == 4);

	return 0;
}
