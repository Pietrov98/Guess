#include "Quests.h"
#include <limits>
class Player
{
public:
	Player();
	~Player();
	template<typename T>
	void feedback(int);
	template<typename T>
	T guess();
	unsigned GetID();
private:
	static unsigned ID_number_counter;
	unsigned ID_number;
	void *min_ptr, *max_ptr, *actual_ptr;
};

template<typename T>
void Player::feedback(int a)
{
	static T max_limit, min_limit;
	T * actual_limit = reinterpret_cast<T*>(actual_ptr);
	if (a == 2)
	{
		max_limit = std::numeric_limits<T>::max();
		min_limit = std::numeric_limits<T>::min();
		min_ptr = reinterpret_cast<void*>(&min_limit);
		max_ptr = reinterpret_cast<void*>(&max_limit);
	}
	else if (a == 1)
	{
		max_limit = *actual_limit;
	}
	else if (a == -1)
	{
		min_limit = *actual_limit;
	}
}

template<typename T>
T Player::guess()
{
	static T random_value;
	T *max_limit_tmp, *min_limit_tmp;
	max_limit_tmp = reinterpret_cast<T*>(max_ptr);
	min_limit_tmp = reinterpret_cast<T*>(min_ptr);
	random_value = generateQuest<T>(*min_limit_tmp, *max_limit_tmp);
	actual_ptr = reinterpret_cast<void*>(&random_value);
	return random_value;
}


