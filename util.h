#include <random>
#include <limits>

template <typename T>

inline T generateQuest(T max_limit, T min_limit)
{
	std::random_device random;
	std::default_random_engine e1(random());
	std::uniform_int_distribution<T> uniform_dist(max_limit, min_limit);
	auto random_value = uniform_dist(e1);
	return random_value;
}

template<> inline float generateQuest<float>(float max_limit, float min_limit)
{
	std::random_device random;
	std::default_random_engine e1(random());
	std::uniform_real_distribution<float> uniform_dist(max_limit, min_limit);
	auto random_value = uniform_dist(e1);
	return random_value;
}

template<> inline double generateQuest<double>(double max_limit, double min_limit)
{
	std::random_device random;
	std::default_random_engine e1(random());
	std::uniform_real_distribution<double> uniform_dist(max_limit, min_limit);
	auto random_value = uniform_dist(e1);
	return random_value;
}

template<> inline bool generateQuest<bool>(bool max_limit, bool min_limit)
{
	std::random_device random;
	std::default_random_engine e1(random());
	std::uniform_int_distribution<int> uniform_dist(0, 1);
	auto random_value = uniform_dist(e1);
	return random_value;
}

template<> inline char generateQuest<char>(char max_limit, char min_limit)
{
	std::random_device random;
	std::default_random_engine e1(random());
	std::uniform_int_distribution<short> uniform_dist(-128, 127);
	short random_value = uniform_dist(e1);
	return random_value;
}

template<typename T1>
inline T1 generateQuest()
{
	return generateQuest(std::numeric_limits<T1>::min(), std::numeric_limits<T1>::max());
}

template<> inline float generateQuest<float>()
{
	return generateQuest(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
}

template<> inline double generateQuest<double>()
{
	return generateQuest(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
}

template<> inline bool generateQuest<bool>()
{
	return generateQuest(std::numeric_limits<bool>::min(), std::numeric_limits<bool>::max());
}

template<> inline char generateQuest<char>()
{
	return generateQuest(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
}
