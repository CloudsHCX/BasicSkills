/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
����������һ��list������������ʹ�õĽ�㣬�������£�����ͷ���������ʹ�õĽ�㣬
		��������ɾ�������һ���ڵ������ʹ�õĽ�㡣
	  ÿ��get()ʱ������list����ɾ��֮ǰ��״̬������Ϊ���ʹ��
	  ÿ��put()ʱ��1.�����ڣ������value������list����״̬����
				   2.�������ڣ��������㹻����ֱ�Ӳ���map������list����
				   3.�������ڣ�������������ɾ���������ʹ�õĽ�㣬��list��ͷ��㣬
				     ������list����
*/
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
   LRUCache(int capacity):m_capacity(capacity),cur_size(0) {}
    
    int get(int key) {
		unordered_map<int, int>::iterator iter = m_cache.find(key);
		if(iter != m_cache.end())
		{
			update_list(key);
			return iter->second;
		}
		return -1;
    }
    
    void put(int key, int value) {

		//�����ڣ�ֱ���滻
		unordered_map<int, int>::iterator iter = m_cache.find(key);
		if(iter != m_cache.end())
		{
			m_cache[key] = value;
			update_list(key);
			return;
		}
		//����ǰ�����㹻,ֱ�����
		if(cur_size < m_capacity)
		{
			cur_size++;
			m_cache[key]=value;
			m_list.push_back(key);
			return;
		}
		//����ǰ������������ɾ������ʹ�õ�pair
		int tmp_key =m_list.front();
		m_list.pop_front();
		unordered_map<int, int>::iterator iterMap = m_cache.find(tmp_key);
		if(iterMap != m_cache.end())
		{
			m_cache.erase(iterMap);
			m_cache[key] = value;
			m_list.push_back(key);
			return;
		}
    }

private:
	unordered_map<int, int> m_cache;
	int m_capacity;
	int cur_size;
	list<int> m_list;


	//����m_list����ʹ���������ʹ�õķ��ڶ������
	void update_list(int key)
	{
		for(list<int>::iterator itList = m_list.begin(); itList!=m_list.end(); ++itList)
		{
			if(*itList == key)
			{
				m_list.erase(itList);
				break;
			}
		}
			m_list.push_back(key);
	}
};

/**
 * Your LRUCache object will be instantiated and called as   such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
