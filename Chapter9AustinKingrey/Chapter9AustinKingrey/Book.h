
#pragma once
#include <ctime>
#include <string>
#include <iostream>

class Book
{
public:
	//constructor
	Book(std::string lvIsbn, std::string lvTitle, std::string lvAuthor,time_t lvopyright);

	//display functions (getters)
	void getIsbn();
	void getTitle();
	void getAuthor();
	void getCheckedOut();
	void getCopyright();

	//checking in and out functions
	void checkIn();
	void checkOut();
private:
	std::string isbn; //holds isbn number
	std::string title; //holds title of book
	std::string author; //author of book
	bool checkedOut; //checkout status
	time_t copyright; //copyright date of the book
};