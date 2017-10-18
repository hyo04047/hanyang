#include <iostream>
#include <string>
#include <map>
#include "sorted_array.h"

using namespace std;

typedef SortedArray<int> IntSortedArray;

typedef SortedArray<double> DoubleSortedArray;

typedef SortedArray<string> StringSortedArray;

int main()
{
	map<string, IntSortedArray> int_arrays;

	map<string, DoubleSortedArray> double_arrays;

	map<string, StringSortedArray> string_arrays;

	string cmd, str;
	int size;

	while(cmd!="quit")
	{
		cin>>cmd;

		if(cmd=="int")
		{
			/* Implement here*/
			cin >> str;
			cin >> size;
			int_arrays[str].Reserve(size);
			for(int i = 0; i < size; i++){
				int temp;
				cin >> temp;
				int_arrays[str].Add(temp);
			}
			cout << str << " :" << int_arrays[str] << endl;;
		}

		else if(cmd=="double")
		{
			/* Implement here*/
			cin >> str;
			cin >> size;
			double_arrays[str].Reserve(size);
			for(int i = 0; i < size; i++){
				double temp;
				cin >> temp;
				double_arrays[str].Add(temp);
			}
			cout << str << " :" << double_arrays[str] << endl;;
		}

		else if(cmd=="string")
		{
			/* Implement here*/
			cin >> str;
			cin >> size;
			string_arrays[str].Reserve(size);
			for(int i = 0; i < size; i++){
				string temp;
				cin >> temp;
				string_arrays[str].Add(temp);
			}
			cout << str << " :" << string_arrays[str] << endl;;
		}

		else if(cmd=="list")
		{
			/* Implement here*/
			for(std::map<string, IntSortedArray>::iterator it = int_arrays.begin(); it != int_arrays.end(); it++){
				cout << "int " << it->first << " :" << it->second << endl;
			}
			for(std::map<string, DoubleSortedArray>::iterator it = double_arrays.begin(); it != double_arrays.end(); it++){
				cout << "double " << it->first << " :" << it->second << endl;
			}
			for(std::map<string, StringSortedArray>::iterator it = string_arrays.begin(); it != string_arrays.end(); it++){
				cout << "string " << it->first << " :" << it->second << endl;
			}
		}

		else if(cmd=="find")
		{
			/* Implement here*/
			cin >> str;
			for(std::map<string, IntSortedArray>::iterator it = int_arrays.begin(); it != int_arrays.end(); it++){
				int value;
				if(it->first == str){
					cin >> value;
					cout << it->second.Find(value) << endl;
				}
			}
			for(std::map<string, DoubleSortedArray>::iterator it = double_arrays.begin(); it != double_arrays.end(); it++){
				double value;
				if(it->first == str){
					cin >> value;
					cout << it->second.Find(value) << endl;
				}
			}
			for(std::map<string, StringSortedArray>::iterator it = string_arrays.begin(); it != string_arrays.end(); it++){
				string value;
				// cout << "for" << endl;
				if(it->first == str){
					// cout << "1" << endl;
					cin >> value;
					cout << it->second.Find(value) << endl;
					// break;
				}
			}
		}
	}

	return 0;
}
