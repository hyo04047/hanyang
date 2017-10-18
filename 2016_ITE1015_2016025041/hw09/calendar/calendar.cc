#include "calendar.h"
#include <vector>
#include <sstream>
#include <cstdlib>

enum months { 
	JANUARY = 1, 
	FEBRUARY, 
	MARCH, 
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER 
};

const int common_month_date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int special_month_date[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

/* set the next N day from the current date.
 * @param[in]	n	n days from the current. */
void Date::NextDay(int n) {
	int days = 0;
	if(GetDaysInYear(year_) == 365){
		// cout << "if" << endl;
		for(int i = 0; i < month_; i++){
			days += common_month_date[i];
		}
		days += day_;
		// cout << days << endl;
		days += n;
		if(days > GetDaysInYear(year_)){
			days -= GetDaysInYear(year_);
			year_++;
			// cout << "ifif" << endl;
			// cout << days << endl;
		}
		if(days < 1){
			year_--;
			days += GetDaysInYear(year_);
		}

		if(GetDaysInYear(year_) == 365){
			// cout << "ififif" << endl;
			for(int i = 0; days > common_month_date[i]; i++){
				month_ = i + 1;
				days -= common_month_date[i];
			}
			day_ = days;
		}
		else if(GetDaysInYear(year_) == 366){
			// cout << "ifififif" << endl;
			// cout << days << endl;
			for(int i = 0; days > special_month_date[i]; i++){
				month_ = i + 1;
				// cout << i << month_ << endl;
				days -= special_month_date[i];
			}
			day_ = days;
		}
	}
	else{
		for(int i = 0; i < month_; i++){
			days += special_month_date[i];
		}
		days += day_;
		days += n;
		if(days > GetDaysInYear(year_)){
			days -= GetDaysInYear(year_);
			year_++;
		}
		if(days < 1){
			year_--;
			days += GetDaysInYear(year_);
		}

		if(GetDaysInYear(year_) == 365){
			for(int i = 0; days > common_month_date[i]; i++){
				month_ = i + 1;
				days -= common_month_date[i];
			}
			day_ = days;
		}
		else if(GetDaysInYear(year_) == 366){
			for(int i = 0; days > special_month_date[i]; i++){
				month_ = i + 1;
				days -= special_month_date[i];
			}
			day_ = days;
		}
	}
}

/* fills the date instance with given year, month, day from user input
 * and returns true only when the input date is valid.
 * @param[in]	year	year
 * @param[in]	month	month
 * @param[in]	day		day
 * returns true if the input date is valid */
bool Date::SetDate(int year, int month, int day) {
	/* TODO: implements here */
	if(year < 0 || month < 1 || month > 12){
		return false;
	}
	if(GetDaysInYear(year) == 365){
		// cout << "1" << endl;
		if(day > common_month_date[month] || day < 1){
			// cout << "if" << endl;
			return false;
		}
	}
	if(GetDaysInYear(year) == 366){
		if(day > special_month_date[month] || day < 1){
			// cout << "if2" << endl;
			return false;
		}
	}
	year_ = year, month_ = month, day_ = day;
	return true;
}

/* getter member function to return year */
int Date::GetYear() const { 
	/* TODO: implements here */
	return year_;
}

/* getter member function to return month */
int Date::GetMonth() const { 
	return month_; 
}

/* getter member function to return day */
int Date::GetDay() const { 
	/* TODO: implements here */
	return day_;
}

/* returns how many days this year has.
 * @param[in]	year	year to set
 * @return number of days of this year	*/
int Date::GetDaysInYear(int year) {
	/* TODO: implements here */
	if(year % 4 == 0){
		if(year % 100 == 0){
			if(year % 400 == 0){
				return 366;
			}
			else
				return 365;
		}
		else
			return 366;
	}
	else
		return 365;
}

/* operator overloading for std::ostream to print date instance
 * @param[in] 	os 		ostream instance to std::cout
 * @param[in] 	date	date instance to print out on this ostream
 * @return 		os		ostream instance */
ostream& operator<<(ostream& os, const Date& date) {
	/* TODO: implements here */
	os << date.GetYear() << "." << date.GetMonth() << "." << date.GetDay() << endl;
    return os;
}

/* operator overloading for std::istream, which takes user input 
 * to fill the Date instance and throws exception when
 * 1. user input was not a valid format of YYYY.MM.DD 
 * 2. user input was invalid date i.e., 2011.2.29 which is not a real day.
 * @param[in] 	is 		stream instance which we are using as std::cin
 * @param[in] 	date	date instance to fill with user input
 * @return 		is		istream instance */
istream& operator>>(istream& is, Date& c) {
	string date, token, d;
	cin >> date;
	d = date;
	int index, temp1, temp2, temp3;
	MyDateException* error;

	if(date.find(".") == std::string::npos){
		error = new InvalidDateFormatException(date);
		throw error;
	}

	index = date.find(".");
	token = date.substr(0, index);
	istringstream buffer(token);
	buffer >> temp1;
	// c.year_ = temp;

	date = date.substr(index + 1);
	index = date.find(".");
	token = date.substr(0, index);
	istringstream buffer2(token);
	buffer2 >> temp2;
	// c.month_ = temp2;
	date = date.substr(index + 1);
	istringstream buffer3(date);
	buffer3 >> temp3;
	// c.day_ = temp3;

	if(!(c.SetDate(temp1, temp2, temp3))){
		// cout << "1" << endl;
		error = new InvalidDateException(d);
		throw error;
	}

    return is;
}

MyDateException::MyDateException(const string& msg){
	input_date = msg;
}

string InvalidDateException::GetMessage(){
	return "InvalidDateException: " + input_date;
}

string InvalidDateFormatException::GetMessage(){
	return "InvalidDateFormatException expected: YYYY.MM.DD but was " + input_date;  
}