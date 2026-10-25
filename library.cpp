#include<iostream>
#include<string>
using namespace std;

class Book{
	private:
		string title;
		string author;
		string isbn;
		int bookID;
		bool isBorrowed;
		int borrowCount;
	public:
		static int nextID;
		Book(string t, string a, string i) : title(t), author(a), isbn(i), isBorrowed(false),borrowCount(0) {
			bookID = nextID++;
		}
		string getTitle()const{
			return title;
		}
		string getAuthor()const{
			return author;
		}
		string getISBN()const{
			return isbn;
		}
		int getBookID() const{
			return bookID;
		}
		bool IsAvailable()const{
			return !isBorrowed;
		}
		int getBorrowCount()const{
			return borrowCount;
		}
			
		virtual void displayInfo(){
			cout<<"\nBook ID:       "<<bookID<<endl;
			cout<<"Book:          "<<title<<endl;
			cout<<"Author:        "<<author<<endl;
			cout<<"ISBN:          "<<isbn<<endl;
			cout<<"Status:        "<<(isBorrowed ? "Borrowed":"Available")<<endl;
		}
		void borrow(){
			if(isBorrowed){
				cout<<"Book has already been Borrowed."<<endl;
				return;
			}
			if(borrowCount>50){
				cout<<"Book is too old and can't be borrowed!\n";
				return;
			}
			else{
				isBorrowed = true;
				borrowCount++;
				cout<<"Book borrowed successfully!(Borrow#"<<borrowCount<<")"<<endl;
			}
			
		}
		void returnBook(){
			if(!isBorrowed){
				cout<<"Book wasn't Borrowed."<<endl;
				return;
			}
			else{
				isBorrowed = false;
				cout<<"Book has been returned Successfully...!"<<endl;
			}
		}
		virtual ~Book(){}
		virtual double getLateFee()const = 0;
		
};


class PrintedBook : public Book{
	private:
		int pageCount;
	public:
		PrintedBook( const string& t,const string& a,const string& i, int pages): Book(t, a, i ){
			pageCount = pages;
		}
		
		int getPageCount()const{
			return pageCount;
		}
		void displayInfo() override {
			Book::displayInfo();
			cout<<"Pages:         "<<pageCount<<endl;
			cout<<"Book Type:    \"Printed Book\"\n";

		}
		double getLateFee()const override{
			return 2.0;
		}
};

class Ebook: public Book{
	private:
		double fileSize;
	public:
		Ebook(const string& t,const string& a,const string& i,double size ): Book(t, a, i){
			fileSize = size;
		}
		double getFileSize()const{
			return fileSize;
		}
		void displayInfo() override {
			Book::displayInfo();
			cout<<"File Size:     "<<fileSize<<"MB"<<endl;
			cout<<"Book Type:    \"Ebook\"\n";

		}
		double getLateFee()const override{
			return 1.0;
		}
};

class Audiobook: public Book{
	private:
		double duration;
	public:
		Audiobook(const string& t,const string& a,const string& i, double dur ):Book(t, a, i){
			duration = dur;
		}
		double getDuration()const{
			return duration;
		}
		void displayInfo()override{
			Book::displayInfo();
			cout<<"Duration Len:  "<<duration<<"min\n";
			cout<<"Book Type:    \"AudioBook\"\n";
		}
		double getLateFee()const override{
			return 1.5;
		}
};


int Book::nextID = 0;

int main(){
	Book* books[3];
	
	books[0] = new PrintedBook("Coding", "MR.Chips", "748-234", 17);
	books[1] = new Ebook("Coding", "MR.Chips", "748-234", 17);
	books[2] = new Audiobook("Music", "Fadimatic", "156-089", 7.25);
	
	for(int i=0; i<3; i++){
		books[i]->displayInfo();
		cout<<"Late Fee: $"<<books[i]->getLateFee()<<"/day\n";
	}

	cout<<"Is Available?"<<(books[1]->IsAvailable()? "Yes" : "No")<<endl;
	
//	for(int i=0; i<3; i++){
//		delete books[i];
//	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	Book book1("OOP", "Khan", "123456");
//	PrintedBook pbook1("Coding", "MR.Chips", "748-234", 17);
//	Ebook ebook1("AI", "Coder", "783-276", 23.5);
//	Audiobook abook1("Music", "Fadimatic", "156-089", 7.25);
//	
//	pbook1.displayInfo();
//	ebook1.displayInfo();
//	abook1.displayInfo();
//	
//	pbook1.borrow();
//	pbook1.displayInfo();
	
	
	
	
	
	
	
	
	
	
//	Book book2("Math", "Ali", "765432");
//	Book book3("English", "Taha", "987650");
//	book1.displayInfo();
//	book2.displayInfo();
//	book3.displayInfo();
//	book1.borrow();
//	book1.displayInfo();
//	book2.borrow();
//	book2.displayInfo();
//	book1.borrow();
//	book2.returnBook();
//	book2.displayInfo();
	return 0; 
}
