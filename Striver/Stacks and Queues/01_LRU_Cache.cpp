# include <bits/stdc++.h>
using namespace std ;

class LRUCache 
{
    private:
        size_t m_capacity;
        unordered_map < int , list<pair<int,int>>::iterator > m_map ;
            // m_map_iter->first: key
            // m_map_iter->second: value
        list <pair<int,int>> m_list;

    public:
    LRUCache(size_t capacity): m_capacity(capacity){}

    int get(int key)
    {
        auto found_iter = m_map.find(key);

        if (found_iter == m_map.end())  // Key doesn't exist
            return -1 ;
        
        m_list.splice(m_list.begin(), m_list, found_iter->second);
            // move the node corresponding to key to front
        return found_iter->second->second;
    }

    void set(int key, int value)
    {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end())
        {
            m_list.splice(m_list.begin(), m_list,  found_iter->second);
                // move the node corresponding to key to front
            found_iter->second->second = value;
                // update value of the node
            
            return;
        }

        if (m_map.size() == m_capacity) // reached capacity
        {
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);
        }

        m_list.emplace_front(key, value);
            // create new node in list
        m_map[key] = m_list.begin();
            // create correspondence between key and node
    }
};