#include "Book.h"

Book::Book()
{
	title = "";
	author = "";
	isbn = "";
	numberOfPages = 0;
	book_type = "";
	date = "";
}

Book::Book(string author, string date, string title, string isbn, int numberOfPages, string book_type)
{
	this->author = author;
	this->date = date;
	this->title = title;
	this->isbn = isbn;
	this->book_type = book_type;
	this->numberOfPages = numberOfPages;

}
void Book::display()
{
	cout << "Author Name : " << author << "\n";
	cout << "Publish Date : " << date << "\n";
	cout << "Title of Book: " << title << "\n";
	cout << "Isbn : " << isbn << "\n";
	cout << "Type Of Book : " << book_type << "\n";
	cout << "Number of Pages : " << numberOfPages << "\n";
}
void Book::setTitle(string title) {
	this->title = title;
}
void Book::setAuthor(string author)
{
	this->author = author;
}
void Book::setDate(string date)
{
	this->date = date;
}
void Book::setIsbn(string isbn)
{
	this->isbn = isbn;
}
void Book::setNumberOfPages(int pages)
{
	this->numberOfPages = pages;
}
void Book::setBookType(string book_type )
{
	this->book_type = book_type;
}

string Book::getIsbn()
{
	return isbn;
}
string Book::getTitle()
{
	return title;
}
string Book::getDate() {
	return date;
}
string Book::getAuthor() {
	return author;
}
int Book::getNumberOfPages() {
	return this->numberOfPages;
}
string Book::getBookType() {
	return this->book_type;
}