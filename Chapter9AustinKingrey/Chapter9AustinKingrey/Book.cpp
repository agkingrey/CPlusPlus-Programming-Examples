#include "stdafx.h"
#include "Book.h"


Book::Book(std::string lvIsbn, std::string lvTitle, std::string lvAuthor, time_t lvCopyright)
{
	//set all of my values equal to the parameters
	isbn = lvIsbn;
	title = lvTitle;
	author = lvAuthor;
	copyright = lvCopyright;
	checkedOut = false; //set checkout to false, as its not checked out on creation
}

void Book::getIsbn()
{
	std::cout << "ISBN: " <<isbn << std::endl;
}

void Book::getTitle()
{
	std::cout << "Title: " << title << std::endl;
}

void Book::getAuthor()
{
	std::cout << "Author: " << author << std::endl;
}

void Book::getCheckedOut()
{
	if (checkedOut == 0)
	{
		std::cout << title << " is not checked out." << std::endl;
	}
	else if (checkedOut == 1)
	{
		std::cout << title << " is checked out." << std::endl;
	}
}

void Book::getCopyright()
{
	std::cout << "Copyright date: " << copyright << std::endl;
}

void Book::checkIn()
{
	checkedOut = 0;
}

void Book::checkOut()
{
	checkedOut = 1;
}
