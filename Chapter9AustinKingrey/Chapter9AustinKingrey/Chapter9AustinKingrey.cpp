// Chapter9AustinKingrey.cpp : Defines the entry point for the console application.
//This program will allow you to create a book object, check it in and out, and
//display the various components of what the book is(isbn, title, author, etc)

#include "stdafx.h"
#include "Book.h"
#include <string>
#include <ctime>

int main()
{
	//simply set our time parameter to current (you can put whatever you want using ctime)
	time_t exTime = time(0);
	//create book object
	Book exBook("34kj3434kj", "The coolest Book ever", "Austin Kingrey",exTime);
	//return the variables using my getter functions
	exBook.getIsbn();
	exBook.getTitle();
	exBook.getAuthor();
	exBook.getCheckedOut();
	exBook.getCopyright();

	//check the book out and back in displaying the results
	exBook.checkOut();
	exBook.getCheckedOut();
	exBook.checkIn();
	exBook.getCheckedOut();
    return 0;
}

