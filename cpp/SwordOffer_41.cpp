# include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class DynamicArray {

private:
	vector<T> min;
	vector<T> max;

public:
	void Insert(T num) {

		if (((min.size() + max.size()) & 1) == 0) {

			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>);
				num = max[0];
				pop_heap(max.begin(), max.end(), less<T>);
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min, end(), greater<T>);
		}

		else {
			if (min.size() > 0 && num > min[0]) {

				min.push_back(num);
				push_heap(min.begin(), min, end(), greater<T>);

				num = min[0];

				pop_heap(min.begin(), min.end(), less<T>);
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>);
		}
	}

	T GetMedian() {

		int size = min.size() + max.size();
		if (size = 0) {
			throw exception("no number")
		}

		T median = 0;

		if (size & 1 == 0) {
			return min[0];
		}
		else {
			return (min[0] + max[0]) / 2;
		}
	}

};