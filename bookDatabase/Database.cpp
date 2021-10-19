# include "Database.h"
# include <iostream>
# include<algorithm>
Database::Database()
{
	
	ifstream file("Books.txt");
	if (file.is_open())
	{
		string author;
		string date;
		string title;
		string isbn;
		int pages;
		string page;
		string type;
		while (file)
		{
			//Getting data from file
			getline(file ,author);
			getline(file, date);
			getline(file, title);
			getline(file, isbn);
			if (getline(file, page))
			{

			}
			else
			{
				break;
			}
			pages = stoi(page);
			getline(file, type);
			Book b(author, date, title, isbn, pages, type);
			list.push_back(b);
		}
		file.close();
	}


}

void Database::saveBooks()
{
	fstream fin("Books.txt", ios::out);
	if (fin.is_open())
	{
		//saving data in file
		int i = 0;
		while (i < list.size()) {
			Book book=list.at(i);
			fin << book.getAuthor() << '\n';
			fin << book.getDate() << '\n';
			fin << book.getTitle() << '\n';
			fin << book.getIsbn() << '\n';
			fin << book.getNumberOfPages() << '\n';
			fin << book.getBookType()<<"\n";
			i++;
		}
		fin.close();
	}
}

void Database::addBook(Book book)
{
	
	list.push_back(book);
}

void Database::displayRecords(vector<Book> records,int index)
{
	if (records.size() == 0)
	{
		cout << "No Book found\n";
		return;
	}
	if (index == 1)
	{
		//Display books in ascending order 
		sort(list.begin(), list.end());
		for (int i = 0; i < records.size(); i++)
		{
			cout << i + 1 << " : ";
			records.at(i).display();
			cout << "\n";
		}
	}
	else if (index == 2)
	{
		//display books in descending order
		sort(list.begin(), list.end(),greater<Book>());
		for (int i = 0; i < records.size(); i++)
		{
			cout << i + 1 << " : ";
			records.at(i).display();
			cout << "\n";
		}
	}
	else if (index == 0)
	{
		//display randomly all books
		for (int i = 0; i < records.size(); i++)
		{
			cout << i + 1 << " : ";
			records.at(i).display();
			cout << "\n";
		}
	}
}

void Database::displayAllBooks()
{
	if (list.size() == 0)
	{
		cout << "No Book found\n";
		return;
	}
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << " : ";
		list.at(i).display();
		cout << "\n";
	}
}

bool Database::removeRecord(int index)
{
	//remove book from specific index
	if (index <= list.size())
	{
		vector<Book>::iterator it;
		it = list.begin();
		list.erase(it+index-1);
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updateAuthor(int index, string author)
{
	if (index <= list.size())
	{
		Book b= list[index - 1];
		b.setAuthor(author);
		list[index-1]=b;
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updateDate(int index, string date)
{
	if (index <= list.size())
	{
		Book b = list[index - 1];
		b.setDate(date);
		list[index - 1] = b;
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updateTitle(int index, string title)
{
	if (index <= list.size())
	{
		Book b = list[index - 1];
		b.setTitle(title);
		list[index - 1] = b;
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updateBookType(int index, string type)
{
	if (index <= list.size())
	{
		Book b = list[index - 1];
		b.setBookType(type);
		list[index - 1] = b;
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updateISBN(int index, string isbn)
{
	if (index <= list.size())
	{
		Book b = list[index - 1];
		b.setIsbn(isbn);
		list[index - 1] = b;
		return true;
	}
	else
	{
		return false;
	}
}

bool Database::updatePages(int index, int pages)
{
	if (index <= list.size())
	{
		Book b = list[index - 1];
		b.setNumberOfPages(pages);
		list[index - 1] = b;
		return true;
	}
	else
	{
		return false;
	}
}

int Database::getSize()
{
	return list.size();
}

void Database::clear()
{
	list.clear();
}

void Database::ascendingOrder()
{
	sort(list.begin(), list.end());

}

void Database::descendingOrder()
{
	sort(list.begin(), list.end(),greater<Book>());

}

vector<Book> Database::search(int index, int operatorIndex, vector<Book> getList,int pageSearch,string value)
{
	//searching on criteria
	if (index == 1)
	{
		//Searching on basis of author name
		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			//Searching on basis of author name with = operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getAuthor() == value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of author name with != operator
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getAuthor() != value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		
	}

	if (index == 2)
	{
		//Searching on basis of date with = operator
		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getDate() == value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of date with != operator
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getDate() != value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}

	}

	if (index == 3)
	{
		//Searching on basis of title with = operator
		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getTitle() == value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of title with != operator
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getTitle() != value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}

	}

	if (index == 4)
	{
		//Searching on basis of isbn with = operator
		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getIsbn() == value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of isbn with != operator
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getIsbn() != value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}

	}

	if (index == 5)
	{
		//Searching on basis of page number with = operator
		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() == pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of page with != operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() != pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 3)
		{
			//Searching on basis of page with >= operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() >= pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 4)
		{
			//Searching on basis of page with <= operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() <= pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 5)
		{
			//Searching on basis of page with < operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() < pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 6)
		{
			//Searching on basis of page with > operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getNumberOfPages() > pageSearch)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}

	}
	
	if (index == 6)
	{
		//Searching on basis of Type with = operator

		vector<Book> returnList;
		if (operatorIndex == 1)
		{
			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getBookType() == value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
		else if (operatorIndex == 2)
		{
			//Searching on basis of Type with != operator

			if (getList.size() == 0)
			{
				cout << "No Record found\n";
				return returnList;
			}
			for (int i = 0; i < getList.size(); i++)
			{
				if (getList.at(i).getBookType() != value)
				{
					returnList.push_back(getList.at(i));
				}
			}
			return returnList;
		}
	}

	vector<Book> blank_list;
	return blank_list;
}

vector<Book> Database::getList()
{
	return list;
}

