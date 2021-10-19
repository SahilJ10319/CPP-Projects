#ifndef BOOK_H
#define BOOK_H
# include <string>
# include <iostream>
using namespace std;
class Book {
	string title;
	string date;
	string author;
	string isbn;
	int numberOfPages;
	string book_type;
public:
	Book();
	Book(string,string,string,string,int,string);
	
	void setTitle(string);
	void setDate(string);
	void setAuthor(string);
	void setNumberOfPages(int);
	void setIsbn(string);
	void setBookType(string);

	string getTitle();
	string getIsbn();
	int getNumberOfPages();
	string getAuthor();
	string getDate();
	string getBookType();

	void display();

	bool operator < (const Book& book) const
	{
		return (numberOfPages < book.numberOfPages);
	}

	bool operator > (const Book& book) const
	{
		return (numberOfPages > book.numberOfPages);
	}

	
};
#endif

