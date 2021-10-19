bookDatabase: Book.o Database.o Driver.o
		g++ -o bookDatabase Book.o Database.o Driver.o   # indent must be a tab

Driver: Driver.cpp
		g++ -c Driver.cpp                         		# indent must be a tab

Book: Book.h Book.cpp
		g++ -c Book.cpp                             # indent must be a tab

Database: Database.h Database.cpp
		g++ -c Database.cpp                              # indent must be a tab

clean:
		rm -f bookDatabase Driver.o Book.o Database.o    # indent must be a tab

# same compiler options as for the course makefile
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g