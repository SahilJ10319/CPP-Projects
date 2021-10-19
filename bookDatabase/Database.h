#ifndef DATABASE_H
#define DATABASE_H
# include <string>
# include <fstream>
# include <vector>
# include "Book.h"

using namespace std;

class Database {
	
	vector<Book> list;
public:
	Database();
	void saveBooks();
	void addBook(Book book);
	void displayAllBooks();
	void displayRecords(vector<Book>,int);
	bool removeRecord(int index);
	bool updateAuthor(int index,string);
	bool updateDate(int index, string );
	bool updateTitle(int index, string );
	bool updatePages(int index, int);
	bool updateISBN(int index, string );
	bool updateBookType(int index, string );
	int getSize();
	void clear();
	void ascendingOrder();
	void descendingOrder();
	vector<Book> search(int index, int operatorIndex,vector<Book>,int,string);
	vector<Book> getList();


};
#endif

