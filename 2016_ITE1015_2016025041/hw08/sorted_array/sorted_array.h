#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
class SortedArray
{
	public:
		SortedArray()
		{
			values_=NULL;

			size_=0;

			alloc_=0;
		}

		SortedArray(const SortedArray& a)
		{
			values_=a.values_;

			size_=a.size_;

			alloc_=a.alloc_;
		}

		SortedArray(size_t size)
		{
			values_=NULL;

			size_=size;

			alloc_=0;
		}

		~SortedArray()
		{
		}

		SortedArray& operator=(const SortedArray& a)
		{
		/* Implement here*/
			values_ = a.values_;
			size_ = a.size_;
			alloc_ = a.alloc_;
			return *this;
		}

		size_t size() const
		{
			return size_;
		}

		size_t alloc() const
		{
			return alloc_;
		}

		const T& operator()(int idx) const
		{
			return values_[idx];
		}

		void Reserve(int size)
		{
		/* Implement here*/
			values_ = new T[size];
		}

		void Add(const T& value)
		{
		/* Implement here*/
			values_[alloc_] = value;
			alloc_++;
			for(int i = 0; i < alloc_; i++){
				for(int j = 0; j < alloc_; j++){
					if(values_[i] < values_[j]){
						T temp = values_[i];
						values_[i] = values_[j];
						values_[j] = temp;
					}
				}
			}
		}

		int Find(const T& value)
		{
		/* Implement here*/
			// cout << "find" << endl;
			int index = 0, temp = -1;
			for(index = 0; index < alloc_; index++){
				if(values_[index] == value){
					temp = index;
				}
			}
			return temp;
		}

	private:
		T* values_;

		int size_, alloc_;
};

template <typename T>
istream& operator>>(istream& is, SortedArray<T>& a)
{
/* Implement here*/

}

template <typename T>
ostream& operator<<(ostream& os, const SortedArray<T>& a)
{
/* Implement here*/
	for(int i = 0; i < a.alloc(); i++){
		os << " " << a(i);
	}
	return os;
}

#endif
