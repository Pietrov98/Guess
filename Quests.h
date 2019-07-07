#include "util.h"
#include <vector>
template <typename T>

class Quests
{
public:
	Quests(int first_size)
	{
		if (first_size < 0)
			throw std::bad_alloc();
		else
		{
			for (size_t i = 0; i < static_cast<size_t>(first_size); i++)
			{
				quests_container.push_back(generateQuest<T>());
			}
		}
	}

	void newQuestion()
	{
		quests_container.push_back(generateQuest<T>());
	}
	unsigned size()
	{
		return quests_container.size();
	}

	T operator [](int i) 
	{
		return quests_container[i];
	}

	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;

	iterator begin() 
	{
		return quests_container.begin();
	}

	const_iterator cbegin() 
	{
		return quests_container.cbegin();
	}

	iterator end() 
	{
		return quests_container.end();
	}

	const_iterator cend() 
	{
		return quests_container.cend();
	}

private:
	std::vector<T> quests_container;
};
