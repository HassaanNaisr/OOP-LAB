#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	book b1("Harry pottar", "JK rowling", "183232423");
	
	cout << "Book title : " << b1.getTitle() << endl;
	cout << "Book author : " << b1.getAuthor() << endl;
	cout << "Book ISBN number : " << b1.getISBN() << endl;	
}
