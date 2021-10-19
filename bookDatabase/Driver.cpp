# include "Database.h"
# include <iostream>
int main()
{

	Database db;
	int choice;
	do
	{
		//Ask For Menu Input
		cout <<"\nEnter 1 to Add Book.\n"
			<< "Enter 2 to Remove Book.\n"
			<< "Enter 3 to Modify Book.\n"
			<< "Enter 4 to Display All Books.\n"
			<< "Enter 5 to Search Specific Book.\n"
			<< "Enter 6 to Display Books in Ascending Order(Number Of Pages).\n"
			<< "Enter 7 to Display Books in Descending Order(Number Of Pages).\n"
			<< "Enter 8 to Save All Books.\n"
			<< "Enter 9 to Remove All Books.\n"
			<< "Enter 0 to exits.\n";
		cout << "Enter Value:\n";
		bool flag1 = true;
		do
		{
			cin >> choice;
			if (cin.fail())
			{
				//If character is entered instead of integer
				flag1 = true;
				cout << "Error-non numeric or negative value, try again\n";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else
			{
				flag1 = false;
			}
		} while (flag1);

		if (choice == 1)
		{
			//Take inout for Adding book
			string date, author, title, type,isbn;
			int pages;
			cout << "Enter author name.\n";
			cin >> author;
			cout << "Enter publish date.\n";
			cin >> date;
			cout << "Enter title of book.\n";
			cin >> title;
			cout << "Enter ISBN.\n";
			cin >> isbn;
			cout << "Enter Number of pages.\n";
			bool flag2 = true;
			do
			{
				cin >> pages;
				if (cin.fail())
				{
					flag2 = true;
					cout << "Enter Valid Number of Pages\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if(pages<=0)
				{
					flag2 = true;
					cout << "Number of Pages Cannot be less than or equal to 0\n";
				}
				else
				{
					flag2 = false;
				}
			} while (flag2);

			flag2 = true;
			cout << "Enter type of book. valid Book Types Are:-\nhardcover, softcover, or digital\n";

			do {
				cin >> type;

				if (type == "hardcover" || type == "softcover" || type == "digital")
				{
					flag2 = false;
				}
				else
				{
					cout << "Please enter Again. Valid Book Types Are:-\nhardcover, softcover, or digital\n";
					flag2 = true;
				}
			} while (flag2);
			Book book(author,date,title,isbn,pages,type);
			db.addBook(book);
			cout << "Book Successfully Added\n";
		}
		else if (choice == 2)
		{
			// Display All books with index and ask for index to remove book
			int size = db.getSize();
			int index;
			db.displayAllBooks();
			cout << "Select index to remove the record\n";
			bool flag2 = true;
			do
			{
				cin >> index;
				if (cin.fail())
				{
					flag2 = true;
					cout << "Enter valid index\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if(index<=0 || index>size)
				{
					cout << "Select valid index\n";
					flag2 = true;
				}
				else
				{
					flag2 = false;
				}
			} while (flag2);
			bool record=db.removeRecord(index);
			if (record)
			{
				cout << "Record removed Succcessfully\n";
			}
			else
			{
				cout << "No Record found with this index\n";
			}
		}
		else if (choice == 3)
		{
			//Display books with index and ask for update with index 
			int index;
			db.displayAllBooks();
			cout << "Select index to Update the record\n";
			bool flag2 = true;
			do
			{
				int size = db.getSize();
				cin >> index;
				if (cin.fail())
				{
					flag2 = true;
					cout << "Enter valid index\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (index <= 0 || index>size)
				{
					cout << "Select valid index\n";
					flag2 = true;
				}
				else
				{
					flag2 = false;
				}
			} while (flag2);
			int recordUpdate;
			flag2 = true;
			// Submenu to ask further which attribute you want to update
			cout << "\nEnter 1 to Update Book Author.\n"
				<< "Enter 2 to Update Book Publish Date.\n"
				<< "Enter 3 to Update Book Title.\n"
				<< "Enter 4 to Update Book ISBN.\n"
				<< "Enter 5 to Update Book Number Of Pages.\n"
				<< "Enter 6 to Update Book Type.\n";
			cout << "Enter Value:\n";

			do
			{
				cin >> recordUpdate;
				if (cin.fail())
				{
					flag2 = true;
					cout << "Enter valid index\n";
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (recordUpdate <= 0 || recordUpdate >6)
				{
					cout << "Select valid index\n";
					flag2 = true;
				}
				else
				{
					flag2 = false;
				}
			} while (flag2);
			if (recordUpdate == 1)
			{
				string author;
				cout << "Enter author name.\n";
				cin >> author;
				bool isUpdate=db.updateAuthor(recordUpdate,author);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}
			else if(recordUpdate == 2)
			{
				string date;
				cout << "Enter Publish Date.\n";
				cin >> date;
				bool isUpdate = db.updateDate(index, date);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}
			else if (recordUpdate == 3)
			{
				string title;
				cout << "Enter Title of Book.\n";
				cin >> title;
				bool isUpdate = db.updateTitle(index, title);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}
			else if (recordUpdate == 4)
			{
				string isbn;
				cout << "Enter ISBN name.\n";
				cin >> isbn;
				bool isUpdate = db.updateISBN(index, isbn);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}
			else if (recordUpdate == 5)
			{
				int pages;
				cout << "Enter Number of Pages.\n";
				flag2 = true;
				do
				{
					cin >> pages;
					if (cin.fail())
					{
						flag2 = true;
						cout << "Enter valid integer\n";
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else if (pages <= 0 )
					{
						cout << "Pages cannot be less than zero\n";
						flag2 = true;
					}
					else
					{
						flag2 = false;
					}
				} while (flag2);
				bool isUpdate = db.updatePages(index, pages);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}
			else if (recordUpdate == 6)
			{
				string type;
				cout << "Enter Book type.\n";
				cin >> type;
				bool isUpdate = db.updateBookType(index, type);
				if (isUpdate)
				{
					cout << "Record Updated successfully\n";
				}
				else
				{
					cout << "No Record found with this index\n";
				}
			}

		}
		else if (choice == 4)
		{
			db.displayAllBooks();
		}
		else if (choice == 5)
		{
			//Ask for attribute on which basis you want to search
			vector<Book> list = db.getList();
			
			do {
				string value;
				int page=0;
				int index;
				int operatorIndex;

				cout << "\nEnter 1 to Search Book Author.\n"
					<< "Enter 2 to Search Book Publish Date.\n"
					<< "Enter 3 to Search Book Title.\n"
					<< "Enter 4 to Search Book ISBN.\n"
					<< "Enter 5 to Search Book Number Of Pages.\n"
					<< "Enter 6 to Search Book Type.\n";

				cout << "Select index on the basis of which you want to search the record\n";
				bool flag2 = true;
				do
				{
					cin >> index;
					if (cin.fail())
					{
						flag2 = true;
						cout << "Enter valid index\n";
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else if (index <= 0 || index > 6)
					{
						cout << "Select valid index\n";
						flag2 = true;
					}
					else
					{
						flag2 = false;
					}
				} while (flag2);

				if (index == 5)
				{
					//Ask for operator in on which basis to search
					cout << "\nEnter 1 to Search with Equal(=) operator.\n"
						<< "Enter 2 to Search with Not Equal(!=) operator.\n"
						<< "Enter 3 to Search with Greater Equal(>=) operator.\n"
						<< "Enter 4 to Search with Less Equal(<=) operator.\n"
						<< "Enter 5 to Search with Less (<) operator.\n"
						<< "Enter 6 to Search with Greater(>) operator.\n";

				}
				else
				{
					cout << "\nEnter 1 to Search with Equal(=) operator.\n"
						<< "Enter 2 to Search with Not Equal(!=) operator.\n";

				}
				cout << "Select operator index on the basis of which you want to search the record\n";
				flag2 = true;
				do
				{
					cin >> operatorIndex;
					if (cin.fail())
					{
						flag2 = true;
						cout << "Enter valid index\n";
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else if (index == 5 && (operatorIndex <= 0 || operatorIndex > 6))
					{
						cout << "Select valid index\n";
						flag2 = true;
					}
					else if (index != 5 && (operatorIndex <= 0 || operatorIndex > 2))
					{
						cout << "Select valid index\n";
						flag2 = true;
					}
					else
					{
						flag2 = false;
					}
				} while (flag2);
				cout << "Enter value to compare\n";
		
				if (index!=5 && index >=1 && index<=6)
				{
					cin >> value;
				}
				else if(index==5)
				{
					flag2 = true;
					do
					{
						cin >> page;
						if (cin.fail())
						{
							flag2 = true;
							cout << "Enter valid index\n";
							cin.clear();
							cin.ignore(10000, '\n');
						}
						else if (page<=0)
						{
							cout << "Select valid index\n";
							flag2 = true;
						}
						else
						{
							flag2 = false;
						}
					} while (flag2);
				}
				list = db.search(index, operatorIndex, list, page, value);
				db.displayRecords(list, 0);
				
				// Ask for order in which you want to display records
				cout << "\nEnter 1 to Apply another criteria.\n"
					<< "Enter 2 to display records in ascending order.\n"
					<< "Enter 3 to display records in descending order.\n"
					<< "Enter 4 to exit.\n";

				cout << "Select index to proceed\n";
				int proceed;
				flag2 = true;
				do
				{
					cin >> proceed;
					if (cin.fail())
					{
						flag2 = true;
						cout << "Enter valid index\n";
						cin.clear();
						cin.ignore(10000, '\n');
					}
					else if (proceed <= 0 || proceed>4)
					{
						cout << "Select valid index\n";
						flag2 = true;
					}
					else
					{
						flag2 = false;
					}
				} while (flag2);
				
				if (proceed == 1)
				{
					continue;
				}
				else if (proceed == 2)
				{
					db.ascendingOrder();
					db.displayRecords(list,1);
					break;
				}
				else if (proceed == 3)
				{
					db.descendingOrder();
					db.displayRecords(list,2);
					break;
				}
				else if (proceed == 4)
				{
					break;
				}
			} while (true);
			


		

		}
		else if (choice == 6)
		{
			db.ascendingOrder();
			db.displayAllBooks();
		}
		else if (choice == 7) {
			db.descendingOrder();
			db.displayAllBooks();
		}
		else if (choice == 8)
		{
			db.saveBooks();
		}
		else if (choice == 9) {
			db.clear();
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			cout << "Wrong choice.Enter again\n";
		}
	} while (choice != 0);
	db.saveBooks();
	return 0;
}