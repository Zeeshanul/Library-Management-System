#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<conio.h>
using namespace std;

int showMenu();
void printShashkaLine(char, int);

class Book{
	public:
	string id;
	string name;
	string author;
	int quantity;
	int issue;
	Book *next;
	Book()
	{
		quantity=0;
		issue=0;
		this->next = NULL;
	}
	
	void input()
	{
		printShashkaLine('+', 40);
		cout<<"\t Enter Book details"<<endl;
		printShashkaLine('+', 40);
		cout<<"Enter id: ";
		cin>>this->id;
		
		cout<<"Enter name: ";
	    cin.ignore();
		getline(cin,this->name);
		
		cout<<"Enter Author Name: ";
		getline(cin,this->author);
		
		cout<<"Enter Quantity: ";
		cin>>quantity;
	}
	
	void show()
	{
		printShashkaLine('+', 30);
		cout<<"\t Student details"<<endl;
		printShashkaLine('+', 30);
		cout<<"id: ";
		cout<<this->id<<endl;
		
		cout<<"name: ";
		cout<<this->name<<endl;
		
		cout<<"Author Name: ";
		cout<<this->author<<endl;
		
		cout<<"Quantity: ";
		cout<<quantity<<endl;
		
		cout<<"Issued: ";
		cout<<this->issue<<endl;
		
	}
};  //Class Book Ended


class Libarary{
    public:
    	Book *head;
    	int size;
    	Book *tail;
    	
    	/*
    	 * Default constructor
    	 */
    	Libarary()
    	{
    		this->head=NULL;
		}
		
			
		void addBook(Book *ptr)
		{
			readf();
			Book* temp;
			temp=find(ptr->id);
			
			if(temp==NULL||head==NULL)
			{
			  insert(ptr);
			   
		    }
		    
		    else
		    {
		    	cout<<"Book Having id "<<temp->id<<" Already Exist in Libarary"<<endl;
		    	cout<<"1. Change id"<<endl;
		    	cout<<"Any other key: to Increase Quantity of Books with id "<<temp->id<<endl;
		    	int i;
		    	cout<<"Enter Your Choice: ";
		    	cin>>i;
		    	if(i==1)
		    	{
		    		empty();
		    		return;
				}
		    	
		    	else
		    	temp->quantity++;
		    	
		    	
			}
			write();
			empty();
		    
		}  //AddBook Ended
		
		
		void write()
		{
			
				Book *temp=head;
				ofstream add;
				add.open("Admin.txt");
				
				while(temp!=NULL)
				{
					add<<temp->id<<endl;
					add<<temp->name<<endl;
					add<<temp->author<<endl;
					add<<temp->quantity<<endl;
					add<<temp->issue<<endl;
					temp=temp->next;
				}
				
				add.close();
		}
				
				
		void readf()
		{
			ifstream read;
			string s;
			Book* temp;
			read.open("Admin.txt");
			if(!read.is_open())
			{
				return;
			}
			
			else
			{     
				int i=0;
				
				while(getline(read,s))
				{

					if(i%5==0 && !read.eof())
					{
						temp= new Book;
						temp->id=s;
					
					}
					
					else if(i%5==1)
					{
						temp->name=s;
					}
					
					else if(i%5==2)
					{
						temp->author=s;
						
					}
					
					else if(i%5==3)
					{
						stringstream qty(s);
						int q=0;
						qty>>q;
						temp->quantity=q;
					}
					
					else if(i%5==4)
					{
						stringstream iss(s);
						int is=0;
						iss>>is;
						temp->issue=is;
						insert(temp);
					}
					
					else
					head=NULL;	
							
					i++;
				}
				
			
			}
		}// File to linked List conversion Ended

			
	    void insert(Book* n)
		{
	
	        if(head==NULL)
			{
				head=n;
				n->next=NULL;
			}
			else
			{
						
				Book* ptr=head;
				
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				
				ptr->next=n;
				n->next=NULL;
		    }
		    
		}  //Insertion In Linked List Ended
	
		Book* find(string reg)
    	{
    		Book *temp = NULL;
    		if(this->head == NULL)
    		{
    			return NULL;
			}
			
			else
			{
				Book *temp2;
				for(temp2 = this->head; temp2 != NULL; temp2 = temp2->next)
	    		{
					if(temp2->id == reg)
					{
						temp = temp2;
						break;
					}
				}
				
				if(temp2==NULL)
			    {
			    	return NULL;
		      	}
			}
			
			
			return temp;
			
		} //find ends
		
		
		void remove(string reg)
    	{
    		readf();
    		Book *temp1 = this->find(reg);
			if(temp1 != NULL)
			{
				temp1->show();
				int confirm = 0;
				cout<<"Do you really want to delete it?"<<endl;
				cout<<"1. Yes"<<endl;
				cout<<"Anyother number. No"<<endl;
				cout<<"Enter your choice: ";
				cin>>confirm;
				if(confirm == 1)
				{
		    		Book *temp2 = this->head;
		    		if(temp1==head)
		    		{
		    			this->head=this->head->next;
		    			temp1->next=NULL;
		    			delete temp1;
		    			cout<<"Deleted Succesfully\n";
					}
					
					else
					{
						
			    		while(temp2->next != temp1)
			    		{
			    			temp2 = temp2->next;
						}
						temp2->next = temp1->next;
						delete temp1;
						cout<<"Book deleted successfuly"<<endl;
				    }
				}
				
				else
				cout<<"Process Cancelled"<<endl;
				
			}
			else
			    cout<<"BOOK NOT AVAILABALE"<<endl;
			
			write();
			empty();
		}// Remove Function Ended
		
		
		void issueBook(string x)
		{
        	readf();
    		Book *temp1 = this->find(x);
    		
    		if(temp1==NULL)
    		{
    			cout<<"Book Not Availabale"<<endl;
			}
			
			else
			{
				
	    		temp1->show();
	    		int s1=temp1->quantity;
	    		int s2=temp1->issue;
	    		if(s2<s1)
	    		{
	    			s2++;
	    			temp1->issue=s2;
	    			
	    			cout<<"\nBOOK ISSUED SUCCESSFULLY\n"<<endl;
				}
				
				else
				{
					cout<<"\nALL Books Issued\n"<<endl;
				}
		    }
		    
		   	write();
			empty();
			
		} //Issue Book Ended
		
		
	    void returnbook(string x)
		{
			readf();
		    Book *kitab=find(x);
		         
		    if(kitab==NULL)
		    {
		        cout<<"This book does not belong to giki library"<<endl;
		    } 
		    
		   else
		   {
		   	  if(kitab->issue==0)
		   	  {
		       cout<<"This book does not belong to giki library"<<endl;
			  }
			  
			  else
		       --kitab->issue;
		   }
		   write();
		   empty();
		   
		}//Return Book Ended
		
        void selectionSort()
        {
			readf();
			Book *start;
		    Book *ptr;
		    Book *temp;
		    start=head;
		    for (; start!=NULL; start=start->next) {
		
		        temp=start;
		        ptr=temp;
		        Book* min =temp ;
		
		            for (; ptr!=NULL; ptr=ptr->next) {
		                if ( ptr->id < min->id) {
		                    min = ptr;
		
		                } 
		            }
		
		            swap(temp, min);  
		    }
		    
			display();
		    empty();
	    } //Selection Sort Ended
	    
	    
		void selectionSort_name()
		{
			readf();
			Book *start;
		    Book *ptr;
		    Book *temp;
		    start=head;
		    for (; start!=NULL; start=start->next) {
		
		        temp=start;
		        ptr=temp;
		        Book* min =temp ;
		
		            for (; ptr!=NULL; ptr=ptr->next)
					 {
		                if ( ptr->name < min->name) 
						{
		                    min = ptr;
		
		                } 
		            }
		
		            swap(temp, min);
		        
		    }
		    
			  display();
		      empty();
		}
		
		
		void swap(Book *a, Book *b)
		{
			
			Book *temp;
			temp=new Book;
			
			temp->id=a->id;
			temp->name=a->name;
			temp->author=a->author;
			temp->quantity=a->quantity;
			
			a->id=b->id;
			a->name=b->name;
			a->author=b->author;
			a->quantity=b->quantity;
			
			b->id=temp->id;
			b->name=temp->name;
			b->author=temp->author;
			b->quantity=temp->quantity;
			
		}
		
		
	
	void name_Base()
	{
		readf();
        if(head->next==NULL)
		{
			display();
			return ;
		}
		
		else
		{
			
		   Book *temp=head;
			
		   Book *temp2=temp->next->next;
			
		   temp->next->next=NULL;
		   
		   while(temp2!=NULL)
		   {
				Book* pos;
				pos=temp2;
				temp=head;
			  while(temp!=NULL)
			  {
			  	Book* temp3;
			     if(pos->name<temp->next->name)
			     {
			     	
			        temp2=pos->next;
			   	    pos->next=temp->next;
			   	  
			   	    temp->next=pos;
			   	    break;
			     }
			     
			     temp=temp->next;
			     
			     if(temp->next==NULL)
			     {
			     	temp2=pos->next;
			     	temp->next=pos;
			     	pos->next=NULL;
			     	break;
			     
				 }
			   
			  }
	       }
	       
	       display();
	       empty();	       
        }
	}
	
	void display()
	{
		cout<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
		cout<<"S#"<<" | "<<"       ID| "<<"     Name|"<<"Author Name |"<<endl;
		cout<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;	
		
		if(head==NULL)
		{
			cout<<"Empty"<<endl;
			return ;
		}
		
		else
		{
			int i = 1;
			for(Book* temp = this->head; temp != NULL; temp=temp->next)
    		{
				cout<<setw(2)<<i++<<" | "<<setw(8)<<temp->id<<" | "<<setw(8)<<temp->name<<" | ";
				cout<<setw(8)<<temp->author<<"   | "<<endl;
			}

		}
	} //Display Function Ends



		
		
		void empty()
		{
			if(head==NULL)
			{
				return;
			}
			
			else
			{
				
				
				Book *temp1 = this->head;
				Book *temp2;
				this->head = NULL;
				
				while(temp1->next != NULL)
				{
					temp2 = temp1;
					temp1  = temp1->next;
					delete temp2;
				}
		    }
			
		}
		
		void showBook()
		{
			readf();
			string x;
			Book* ptr;
			cout<<"Enter Id: ";
			cin>>x;
			ptr=find(x);;
			cout<<endl;
			if(ptr==NULL)
			{
				return;
			}
			cout<<"ID   "<<" Book Name "<<"   Author Name "<<"  Issue Statues "<<endl;
			cout<<ptr->id<<"\t"<<ptr->name<<" \t\t "<<ptr->author<<"\t";
			if(ptr->issue<ptr->quantity)
			{
				cout<<"Available"<<endl;
			}
			else
			{
				cout<<"Not Available"<<endl;
			}
			
			empty();
			
		}// Show Book Details for a specific Book Ended
		
		
		void displayIssued()
		{
			readf();
			Book* temp;
			temp=head;
			cout<<setfill('-')<<setw(30)<<"-"<<setfill(' ')<<endl;
			cout<<"Book Name:| "<<"ID  |"<<" Author Name  "<<endl;
			cout<<setfill('-')<<setw(30)<<"-"<<setfill(' ')<<endl;
			while(temp!=NULL)
			{
				if(temp->issue>0)
				{
					cout<<setw(10)<<temp->name<<"|"<<setw(4)<<temp->id<<" | "<<setw(8)<<temp->author<<endl;
					temp=temp->next;
				}
				
				else
				temp=temp->next;
			}
			empty();
		} //Display All Issued Books Ended


		/*
		 * Display all Books
		 */
    	void showAll(){
    		
    		readf();
    		if(this->head == NULL)
    		{
    			cout<<"No Book in Our Libarary"<<endl;
    			return;
			}
			
			cout<<setfill('-')<<setw(70)<<"-"<<setfill(' ')<<endl;
			cout<<"S#"<<" | "<<"    ID | "<<"Book Name | "<<"Author Name | ";
			cout<<"Quantity | "<<"  Issued Books  "<<endl;
			cout<<setfill('-')<<setw(70)<<"-"<<setfill(' ')<<endl;
			
			int i = 1;
			for(Book *temp = this->head; temp != NULL; temp = temp->next)
    		{
				cout<<setw(2)<<i++<<" | "<<setw(6)<<temp->id<<" | "<<setw(8)<<temp->name<<"  | ";
				cout<<setw(11)<<temp->author<<" | "<<setw(8)<<temp->quantity<<" | ";
				cout<<setw(10)<<temp->issue<<endl;
			}
			empty();
			
		} //showAll BOOKS And Details ends
		


}; // Libarary class ends here
	
int Menu();
int userMenu();
string password();

int main()
{
        int choice;
        string pass="";
        start:
	    choice=Menu();
		Libarary lib;
		Book *newBook;
		
		bool again = true;
		string key;
		int index;
		int confirm = 0;
		
	    system("cls");
	
        if(choice==1)
	    {
		  
		  string pass=password();
		  string s;
		  ofstream admnpswrd1;
		  ifstream admnpswrd;
		  admnpswrd.open("Adminpassword.txt");
		  admnpswrd>>s;
          admnpswrd.close();
		   
		   if(pass==s)
		   {
		   	
	        cout<<"\nAccess Granted"<<endl;
	        system("pause");
	        system("cls");
	      	while(again)
			 {
				choice = showMenu();
				switch(choice)
				{
					case 0: //exit program
						system("pause");
						system("cls");
						goto start;
						
						break;
						
					case 1: // Add Book
						newBook = new Book;
						newBook->input();
						lib.addBook(newBook);
						break;
						
					case 2: //Remove Book
					    cout<<"Enter Id: ";
					    cin>>key;
						lib.remove(key);
		
						break;
		
					case 3: //show all Books
						
						lib.showAll();
						break;
						
					case 4: // Issue a Book
					     cout<<"Enter id: ";
					     cin>>key;
					     lib.issueBook(key);
		
						break;
						
					case 5: //show all Issued		
						lib.displayIssued();
						break;	
						
					case 6: // Return a Book
					     cout<<"Enter id: ";
					     cin>>key;
					     lib.returnbook(key);
						 break;
						 
					case 7://Password Change for Admin 		
						 
						 admnpswrd1.open("Adminpassword.txt");
						 cout<<"Enter New Password: ";
						 cin>>s;
						 admnpswrd1<<s;
				         admnpswrd1.close();

						 break;
								
					default:
						cerr<<"Invalid choice"<<endl;
						cout<<"Kindly select a valid number from menu"<<endl;
						break;
				}
				system("pause");
				system("cls");
		    	
	
	         }
	
	
	
		   }
		   
		   else
		   {
		   	cout<<"\nWrong Password"<<endl;
		   	cout<<"Access Denied"<<endl;
		    system("pause");
		    system("cls");
		    goto start;
		   }
        }
	
     	else if(choice==2)
		{
			ifstream userpswrd;
			string s;
			ofstream userpswrd1;
		    userpswrd.open("Userpassword.txt");
		    userpswrd>>s;
            userpswrd.close();

			string pass=password();
			
			if(pass==s)
			{
	
				cout<<"\nAccess Granted\n";
				system("pause");
				system("cls");	
				Book* ptr;
				int x;
				int choice;
				bool again = true;
				
				while(again)
				{
					choice = userMenu();
					switch(choice)
					{
						case 0: //Logout From User Menue
						    system("pause");
						    system("cls");
						    goto start;
							again = false;
							break;
							
						case 1://Selection Sort Id Base
							
							lib.selectionSort();
	
							break;
			
						case 2://Selection Sort Name
							
							lib.selectionSort_name();
							break;
	
						case 3://Show a specific Book

							lib.showBook();
							
							break;
							
					   case 4:// Change User Password
							userpswrd1.open("Userpassword.txt");
						    cout<<"Enter New Password: ";
						    cin>>s;
						    userpswrd1<<s;
				            userpswrd1.close();	
				            break;
					
						default:
							cerr<<"Invalid choice"<<endl;
							cout<<"Kindly select a valid number from menu"<<endl;
							break;
				    }
					system("pause");
					system("cls");
					
		       }
			}
			
			else
			{
				cout<<"\nWrong Password\nAccess Denide"<<endl;
				system("pause");
				system("cls");
				goto start;
			}
		
	    }
	
	cout<<"Thank you for using our program"<<endl;
	return 0;
}


	
void printShashkaLine(char element, int noOfTimes)
{
	for(int i=0; i < noOfTimes; i++)
	{
		cout<<element;
	}
	cout<<endl;
}

int Menu()
{
	int choice;
	printShashkaLine('=', 50);
	cout<<"\t\t LIBARARY MANAGEMENT SYSTEM"<<endl;
	printShashkaLine('=', 50);
	
	cout<<"0. Exit Program"<<endl;
	cout<<"1. Admin Login"<<endl;
	cout<<"2. Student Login"<<endl;

	printShashkaLine('=', 50);
	cout<<"Enter your choice: ";
	cin>>choice;
	return choice;
}

int showMenu()
{
	int choice;
	printShashkaLine('=', 50);
	cout<<"\t\t ADMIN LOGIN"<<endl;
	printShashkaLine('=', 50);
	
	cout<<"0. LogOut"<<endl;
	cout<<"1. Add A Book"<<endl;
	cout<<"2. Remove A Book"<<endl;
	cout<<"3. Show all Books"<<endl;
	cout<<"4. Issue a Book"<<endl;
	cout<<"5. Display Issued Books"<<endl;
	cout<<"6. Return a Book "<<endl;
	cout<<"7. Change Password "<<endl;
	
	printShashkaLine('=', 50);
	cout<<"Enter your choice: ";
	cin>>choice;
	return choice;
}
int userMenu()
{
	int choice;
	printShashkaLine('=', 50);
	cout<<"\t\t STUDENT LOGIN"<<endl;
	printShashkaLine('=', 50);
	
	cout<<"0. Logout"<<endl;
	cout<<"1. Display ID base"<<endl;
	cout<<"2. Display Name Base"<<endl;
	cout<<"3. Display Book Details"<<endl;
	cout<<"4. Change Password"<<endl;
	printShashkaLine('=', 50);
	cout<<"Enter your choice: ";
	cin>>choice;
	return choice;
}

string password()
{
	 string pass="";
	 char ch;
	 cout << "Enter password: ";
		   
	 ch = _getch();
	 cout<<endl;
	 while(ch != 13)
		   
	 {//character 13 is enter
		pass.push_back(ch);
	    cout << '*';
        ch = _getch();
     }
		return pass;
}
