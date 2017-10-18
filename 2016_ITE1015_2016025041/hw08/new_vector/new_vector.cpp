
#include "new_vector.h"
#include <sstream>

using namespace std;

//template <typename T>


void NewVector::addTo(int _value)
{
/* Implement here*/
	intMap_.insert(make_pair(count_, _value));
}

void NewVector::addTo(double _value)
{
/* Implement here*/
	doubleMap_.insert(make_pair(count_, _value));
}

void NewVector::addTo(char _value)
{
/* Implement here*/
	charMap_.insert(make_pair(count_, _value));
}

template <typename T>
string NumberToString ( T Number )
{
/* Implement here*/

}

ostream& operator << (ostream& _os, const NewVector _nv)
{
/* Implement here*/
	for(int i = 0; i < _nv.count_; i++){
		for(std::map<int, int>::const_iterator it = _nv.intMap_.begin(); it != _nv.intMap_.end(); it++){
			if(i == it->first){
				_os << it->second << " ";
			}
		}
		for(std::map<int, double>::const_iterator it = _nv.doubleMap_.begin(); it != _nv.doubleMap_.end(); it++){
			if(i == it->first){
				_os << it->second << " ";
			}
		}
		for(std::map<int, char>::const_iterator it = _nv.charMap_.begin(); it != _nv.charMap_.end(); it++){
			if(i == it->first){
				_os << it->second << " ";
			}
		}
	}
	_os << endl;
	return _os;
}