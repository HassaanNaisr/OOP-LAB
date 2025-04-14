#ifndef BOOK
#define BOOK
#include<iostream>
using namespace std;
class book
{
	protected:
		string title;
	    string author;
	    string ISBN;
	
	public:
		book(string t, string a, string i) : title(t), author(a), ISBN(i){}
		
		string getTitle()
		{
			return title;
		}
		
		string getAuthor()
		{
			return author;
		}
		
		string getISBN()
		{
			return ISBN;
      	}	
};

#endif
