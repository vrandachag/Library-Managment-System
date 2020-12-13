#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
struct DATE
{
   int dd,mm,yy;
};

DATE Calculate(DATE d1)
{
	DATE d2;
	if(d1.mm==1|d1.mm==3|d1.mm==5|d1.mm==7|d1.mm==8|d1.mm==10|d1.mm==12)
	{ if(d1.dd<25)
	    {
	      d2.dd=d1.dd+7;
	      d2.mm=d1.mm;
	      d2.yy=d1.yy;
	    }
	

    else
	    {
	      d2.dd=d1.mm+7-31;
	      d2.mm=d1.mm+1;
	      d2.yy=d1.yy;

	      if(d2.mm==13)
	      {
		    d2.mm=1;
		    d2.yy++;
	      }
	   }
	}
	else  if(d1.mm==2)
	      {   if((d1.yy%4)==0)
		      { if(d1.dd<23)
		        {
		          d2.dd=d1.dd+7;
		          d2.mm=d1.mm;
		          d2.yy=d1.yy;
		        }
		       



                 else
		        {
		          d2.dd=d1.mm+7-29;
		          d2.mm=d1.mm+1;
		          d2.yy=d1.yy;
		        }
		  }
		  else
		  { if(d1.dd<22)
		    {
		      d2.dd=d1.dd+7;
		      d2.mm=d1.mm;
		      d2.yy=d1.yy;
		    }
		    else
		    {
		      d2.dd=d1.mm+7-28;
		      d2.mm=d1.mm+1;
		      d2.yy=d1.yy;
		    }
		  }
	      }



	      else
	      {  if(d1.dd<24)
	      	 { d2.dd=d1.dd+7;
		       d2.mm=d1.mm;
		       d2.yy=d1.yy;
		     } 
		     else
		     { d2.dd=d1.dd+7-30;
		       d2.mm=d1.mm+1;
		       d2.yy=d1.yy;
		     }
	      }
  return d2;
}

class Book
{
	int Bookno;
	char Bookname[50],Authorname[30],Publisher[30],issued;
	float price;
  public:
  Book()


  {  	strcpy(Bookname,"NULL");
	    strcpy(Authorname,"NUlL");
	    strcpy(Publisher,"NULL");
	issued='N';
	price=0;
  }

  void Indata(int n)
  {    clrscr();
       Bookno=n;
       cout<<"\n\nBook number:"<<Bookno;
       cout<<"\nEnter name of the book:";
	gets(Bookname);
       cout<<"\nEnter name of the Author:";
	gets(Authorname);
       cout<<"\nEnter the name of publisher:";
	gets(Publisher);
       cout<<"\nEnter price of the book:";
	cin>>price;
       getch();
  }

  


void Outdata()
  {    cout<<"\n\nBook number   :"<<Bookno;
       cout<<"\nBook name     :"<<Bookname;
       cout<<"\nAuthor        :"<<Authorname;
       cout<<"\nPublished by  :"<<Publisher;
       cout<<"\nPrice         :"<<price;
       cout<<"\nIssued        :"<<issued;
  }
  
  int retBookno()
  {
	return Bookno;
  }
  
  int retIssued()
  {
	return issued;
  }
  
  void inc_issued()
  {
	issued='Y';
  }


  void dec_issued()
  {
	issued='N';
  }
  friend void modify_book_issue(int bookno);

  friend char* Read_Bookname(int bno);

};

class Member
{
	int mno,Books;
	char name[45],address[50],phone[11],email[35];
	public:
	Member()
	{
	    strcpy(name,"NULL");
	    strcpy(address,"NULL");
	    strcpy(phone,"NULL");
	    strcpy(email,"NULL");
	    Books=0;
	}


  void Input(int k)
  {
      mno=k;
      cout<<"\nMembership Number: "<<mno;
      cout<<"\nEnter name:";
	  gets(name);
      cout<<"\nEnter Address:";
	  gets(address);
      cout<<"\nEnter Phone number:";
	  cin>>phone;
      cout<<"\nEnter your email address:";
	  gets(email);
  }

  void Output()
  {   cout<<"\n\nMembership Number         :"<<mno;
      cout<<"\nName                      :"<<name;
      cout<<"\nAddress                   :"<<address;
      cout<<"\nPhone Number              :"<<phone;
      cout<<"\nEmail Address             :"<<email;
      cout<<"\nNumber of Bookes issued   :"<<Books;
  }



  friend void modify_member_issue(int mno);

  friend char* Read_Membername(int mno);

  int retmno()
  {
	return mno;
  }

  int retBooks()
  {
	return Books;
  }

  int inc_Books()
  {
	Books++;
	return Books;
  }
  





int dec_Books()
  {
	Books--;
	return Books;
  }

};

class Transaction
{     int bookno,memno;
      char returned;
      DATE dt_issue,dt_ret;
    public:
      void init(int k,int m,char r)
      {   bookno=k;
	      memno=m;
	      returned=r;
	      struct date dt;
	      getdate(&dt);
	      dt_issue.dd=dt.da_day;
	      dt_issue.mm=dt.da_mon;
	      dt_issue.yy=dt.da_year;
	      dt_ret=Calculate(dt_issue);

	      cout<<"\nDate of Issue : "<<dt_issue.dd<<"/"<<dt_issue.mm<<"/"<<dt_issue.yy;
      	  cout<<"\nDate of Return : "<<dt_ret.dd<<"/"<<dt_ret.mm<<"/"<<dt_ret.yy;

	  getch();

      }

    /*  void Display ()
      { cout<<"\n"<<bookno;
	cout<<"\n"<<memno;
	cout<<"\n"<<returned;
      }
    */

    friend void modify_transct(int bookno,int memno);

    friend int Pending();

    friend void Notreturned();

    friend void Max_Bookissued();


    friend void Deposit();
};
void AddBook()
{     clrscr();
      Book b;
      int n;
      fstream f("BOOK.DAT",ios::binary|ios::in);
      if(f==0)
	n=1;
      else
	{
	  long int l=sizeof(b);
	  f.seekg(-l,ios::end);
	  f.read((char*)&b,sizeof(b));
	  n=b.retBookno()+1;
	}
      f.close();
      f.open("Book.DAT",ios::app|ios::binary);
      b.Indata(n);
      f.write((char*)&b,sizeof(b));
      f.close();
      getch();
}


void AddMember()
{     clrscr();
      Member m;
      int n;
      fstream f("MEMBERS.DAT",ios::in|ios::binary);
      if(f==0)
	  n=1001;
      else
	  {
	    long int l=sizeof(m);
	    f.seekg(-l,ios::end);
	    f.read((char*)&m,sizeof(m));
	    n=m.retmno()+1;
	  }
      f.close();
      f.open("MEMBERS.DAT",ios::app|ios::binary);
      m.Input(n);
      f.write((char*)&m,sizeof(m));
      f.close();
      getch();
}




void Search_book(int b)
{     clrscr();
      Book b1;
      int flag;
      ifstream f("Book.dat",ios::binary|ios::in);
      f.read((char*)&b1,sizeof(b1));
      while(!f.eof())
      { if(b1.retBookno()==b)
     	{ cout<<"\nElement found";
	      b1.Outdata();
	      flag=1;
	      break;
	    }
	   f.read((char*)&b1,sizeof(b1));
      }
      if(flag==0)
	    cout<<"\nElement not found";
      f.close();
      getch();
}





void searchmember(int m)
{     clrscr();
      Member m1;
      int flag=0;
      ifstream f("Members.DAT",ios::binary|ios::in);
      f.read((char*)&m1,sizeof(m1));
      while(!f.eof())
      {
	    if(m1.retmno()==m)
	    {  cout<<"\nElement found";
	       flag=1;
	       m1.Output();
      	   break;
	    }
	   f.read((char*)&m1,sizeof(m1));
      }

      if(flag == 0)
	    cout<<"Element not found!!";
	    f.close();
	    getch();
}



void delete_book()
{     clrscr();
      Book b;
      int k,flag;
      cout<<"\nEnter book number to be deleted:";
      cin>>k;
      flag=0;
      fstream f("Book.DAT",ios::in|ios::binary);
      fstream g("Temp.DAT",ios::out|ios::binary);
      f.read((char*)&b,sizeof(b));
      while(!f.eof())
      {
      	if(b.retBookno()==k)
	    {
	      f.read((char*)&b,sizeof(b));
	      flag=1;
	    }
	    else
	    { g.write((char*)&b,sizeof(b));
	      f.read((char*)&b,sizeof(b));
	    }
      }
      


      if(flag==0)
       cout<<"\nElement not found";
      f.close();
      g.close();
      remove("Book.DAT");
      rename("Temp.DAT","Book.DAT");
      getch();
}
void delete_member()
{     clrscr();
      Member m;
      int k,flag=0;
      cout<<"\nEnter Membership Number to be deleted:";
      cin>>k;
      fstream f("Members.DAT",ios::in|ios::binary);
      fstream g("Temp1.DAT",ios::out|ios::binary);
      f.read((char*)&m,sizeof(m));
      while(!f.eof())
      {
	    if(k==m.retmno())
	    {  f.read((char*)&m,sizeof(m));
	       flag=1;
	    }

	    else
	    {  g.write((char*)&m,sizeof(m));
	       f.read((char*)&m,sizeof(m));
	    }
      }
      if(flag==0)
       cout<<"Element not found";
      f.close();
      g.close();
      remove("Members.DAT");
      rename("Temp1.DAT","Members.DAT");
      getch();
}
void Display_book()
{     clrscr();
      Book b;
      ifstream f("Book.DAT",ios::binary);
      f.read((char*)&b,sizeof(b));
      while(!f.eof())
      { b.Outdata();
	    f.read((char*)&b,sizeof(b));
      }
      getch();


      f.close();
}
void Display_member()
{     clrscr();
      Member m;
      fstream f("Members.DAT",ios::binary|ios::in);
      f.read((char*)&m,sizeof(m));
      while(!f.eof())
      { m.Output();
	    getch();
	    f.read((char*)&m,sizeof(m));
      }
      getch();
      f.close();
}
int search_bookno(int bookno)
{     Book b;
      ifstream g("Book.Dat",ios::binary|ios::in);
      g.read((char*)&b,sizeof(b));
      while (!g.eof())
      { if(b.retBookno()==bookno)
	    { if(b.retIssued()=='Y'|| b.retIssued()=='y')
	      { cout<<"Already Issued";


	        g.close();
	        return 1;
	      }
	      else
	      { g.close();
	        return 2;
	      }
	    }
        g.read((char*)&b,sizeof(b));
      }
      g.close();
      return 0;
}
int search_member(int memno)
{     Member m;
      fstream f("Members.dat",ios::binary|ios::in);
      f.read((char*)&m,sizeof(m));
      while(!f.eof())
      { if(m.retmno()==memno)
	    {  if(m.retBooks()==3)
	       {	cout<<"Sorry cannot issue";
		    f.close();
		    return 1;


	      } 

	      else if(m.retBooks()==0)
	           { f.close();
	             return 3;
	           }
	      else
	      { f.close();
	        return 2;
	      }
	}
	f.read((char*)&m,sizeof(m));
      }
      f.close();
      return 0;
}

void modify_book_issue(int bookno)
{
      Book b;
      fstream f("Book.dat",ios::binary|ios::in);
      fstream g("Temp.dat",ios::binary|ios::out);
      f.read((char*)&b,sizeof(b));

      while(!f.eof())
      { if(b.retBookno()==bookno)
	    {   b.inc_issued();
	        g.write((char*)&b,sizeof(b));
	    }
	    else
	        g.write((char*)&b,sizeof(b));
	        f.read((char*)&b,sizeof(b));
       }
      g.close();
      f.close();
      remove("Book.DAT");
      rename("Temp.DAT","Book.DAT");
}
void modify_book_deposit(int bookno)
{     Book b;
      fstream f("Book.dat",ios::binary|ios::in);
      fstream g("Temp.dat",ios::binary|ios::out);
      f.read((char*)&b,sizeof(b));
      while(!f.eof())
      { if(b.retBookno()==bookno)





	    {   b.dec_issued();
	        g.write((char*)&b,sizeof(b));
	    }
	    else
	        g.write((char*)&b,sizeof(b));
	        f.read((char*)&b,sizeof(b));
      }
      g.close();
      f.close();
      remove("Book.DAT");
      rename("Temp.DAT","Book.DAT");
}

void modify_member_issue(int mno)
{     Member m;
      fstream f("Members.dat",ios::binary|ios::in);
      fstream g("Temp.dat",ios::binary|ios::out);
      f.read((char*)&m,sizeof(m));
      while(!f.eof())
      { if(m.retmno()==mno)
	    {  m.inc_Books();
	       g.write((char*)&m,sizeof(m));
	    }


	   else
	       g.write((char*)&m,sizeof(m));
	     f.read((char*)&m,sizeof(m));
      }
      g.close();
      f.close();
      remove("Members.dat");
      rename("Temp.dat","Members.dat");
}
void modify_member_deposit(int mno)
{     Member m;
      fstream f("Members.dat",ios::binary|ios::in);
      fstream g("Temp.dat",ios::binary|ios::out);
      f.read((char*)&m,sizeof(m));
      while(!f.eof())
      { if(m.retmno()==mno)
	    {  m.dec_Books();
	       g.write((char*)&m,sizeof(m));
	    }
	   else
	       g.write((char*)&m,sizeof(m));
	       f.read((char*)&m,sizeof(m));
    }
      g.close();
      f.close();
      remove("Members.dat");
      rename("Temp.dat","Members.dat");
}

void modify_transct(int bno,int memno)
{
 Transaction T;
 fstream f("Transact.DAT",ios::binary|ios::in|ios::out);
	while(!f.eof())
	{
	  if(T.memno==memno && T.bookno==bno)
	  {
	      T.returned='Y';
	      long int size=sizeof(T);
	      f.seekp(-size,ios::cur);
	      f.write((char*)&T,sizeof(T));
	      break;
	  }
	  f.read((char*)&T,sizeof(T));
	}
	f.close();
}


void Issue()
{
      clrscr();
      cout<<"\n\tIssue";
      Transaction T;
      fstream f;
      int t1,t2,mno,bno,ch;
      cout<<"\nEnter Membership Number:";
      cin>>mno;
      t1=search_member(mno);
      if (t1==2 || t1==3) /*t1=2->books issued<3, t1=3->0 books issued*/
      {
	    cout<<"\nEnter Book number to be issued:";
	    cin>>bno;
	    t2=search_bookno(bno);
	   if(t2==2)			//book found and not issued
	   { modify_member_issue(mno);
	     modify_book_issue(bno);
	     cout<<"\nBook Issued!";
	     T.init(bno,mno,'N');
	     f.open("Transact.DAT",ios::binary|ios::app);
	     f.write((char*)&T,sizeof(T));
	  // T.Display();
	     getch();
      	 f.close();
	   }
	   else if(t2==1)		//book found and issued
	        cout<<"\nAlready Issued";
	   else
	        cout<<"\nNot Found";
     }
      else if(t1==1)	              //books issued = 3 
	        cout<<"\nCannot issue more";
      else
      {  cout<<"\nYou are not a member!!";
	     cout<<"\n1.For Membership";
	     cout<<"\n2.Exit";
	     cout<<"\nEnter your choice:";
	     cin>>ch;

	     switch(ch)
	     { case 1: AddMember();
		           break;
	       case 2: break;
	       default: cout<<"Wrong Choice";
	     }
      }
      getch();
}
void Deposit()
{     clrscr();
      cout<<"\n\t\tDeposit";
      Transaction T;
      fstream f;
      f.open("Transact.DAT",ios::in|ios::binary);
      int t1,t2,mno,bno,ch;
      cout<<"\nEnter Membership Number:";
      cin>>mno;
      t1=search_member(mno);
      if(t1==1 || t1==2)	 /*t1==1 ->3 books are issued, t1==2 ->less than 3 are issued*/
      {
	    cout<<"\nEnter Book number to be deposited:";
	    cin>>bno;
	    t2=search_bookno(bno);	
	    if(t2==1)			//book already issued
	    {   f.read((char*)&T,sizeof(T));
	      while(!f.eof())
	      {
	        if( (T.bookno==bno) && (T.memno==mno))
	        {  modify_book_deposit(bno);
		       modify_member_deposit(mno);
		       f.close();
		       modify_transct(bno,mno);
		    // T.Display();
		       getch();
		       break;
	       }
	     f.read((char*)&T,sizeof(T));
	    }
	    f.close();
	 }
      }
      else if( t1==3)			//zero books issued				
	       cout<<"\nZero Books Issued";
	  else
	  {
	     cout<<"\nYou are not a member!!";
	     cout<<"\n1.For Membership";
	     cout<<"\n2.Exit";
	     cout<<"\nEnter your choice:";
	     cin>>ch;
	     switch(ch)
	     {  case 1 : AddMember();
		          	 break;
		    case 2 : break;
		    default: cout<<"Wrong Choice";
	     }
      }

}
char* Read_Bookname(int bno)
{	Book b;
	ifstream f("Book.DAT",ios::binary);
	f.read((char*)&b,sizeof(b));
	while(!f.eof())
	{  if(b.retBookno()==bno)
	   {
	      f.close();
	      return b.Bookname;
	   }
	   f.read((char*)&b,sizeof(b));
	}
	f.close();
	return "NULL";
}

char* Read_Membername(int mno)
{	Member m;
	ifstream f("Members.DAT",ios::binary);
	f.read((char*)&m,sizeof(m));
	while(!f.eof())
	{  if(m.retmno()==mno)
	   {
	      f.close();
	      return m.name;
	   }
	   f.read((char*)&m,sizeof(m));
	}
	f.close();
	return "NULL";
}

int Pending()
{
   clrscr();
   Transaction T;
   int count=1;
   ifstream f("Transact.DAT",ios::binary);
   if(!f)
     return 0;
   f.read((char*)&T,sizeof(T));
   clrscr();
   cout<<"\nSr.No     Book Name         MemberName ";
                                                                                                                                                                                        cout<<"\n__________________________________________";


   while(!f.eof())
   {
     if(T.returned == 'N'|| T.returned == 'n' )
     {
       char temp[50],temp1[45];
       strcpy(temp,Read_Bookname(T.bookno));
       strcpy(temp1, Read_Membername(T.memno));
       cout<<"\n"<<count<<"       "<<temp<<"          "<<temp1;
       count++;
     }
     f.read((char*)&T,sizeof(T));
   }
   f.close();
    cout<<"\n__________________________________________";
  getch();
  return (count-1);
}
void Max_Bookissued()
{       int A[100]={0};
	clrscr();
	Transaction T;
	fstream f("Transact.DAT",ios::in|ios::binary);
	f.read((char*)&T,sizeof(T));
	while(!f.eof())
	{
	     A[T.bookno-1]++;
	     f.read((char*)&T,sizeof(T));
	}
	f.close();
	getch();
	int max=A[0];
	int pos=0;
	for(int i=0;i<100;i++)
	{
	    if(max < A[i])
	    {
		max = A[i];
		pos = i;
	    }
	}
	cout<<"\nBook Issued Maximum Times:";

	cout<<"\nDetails of Book Issued Maximum Times";
	for(i=0;i<100;i++)
	{
	    if(A[i]==max)
	    {
	       Search_book(i+1);
     //	       getch();
	     }
       }
	getch();
}
void Notreturned()
{
   clrscr();
   int count=1;
   Transaction T;
   fstream f("Transact.DAT",ios::binary|ios::in);
   char temp1[45];
   f.read((char*)&T,sizeof(T));
   while(!f.eof())
   {	if(T.returned=='n'||T.returned=='N')
	{
	  strcpy(temp1, Read_Membername(T.memno));
	  cout<<"\n"<<count<<"  "<<temp1;
	  count++;
	}
	f.read((char*)&T,sizeof(T));
   }
   getch();
}

void Report()
{
	int P,ch;
	clrscr();
	while(ch!=4)
	{  clrscr();
	   cout<<"\n\tREPORT";
	   cout<<"\n1.Name of the Books Not Returned";
	   cout<<"\n2.Book issued maximum time";
	   cout<<"\n3.Members -> not returned books";
	   cout<<"\n4.Go Back";

	   cout<<"\n\nEnter your choice:";
	   cin>>ch;
	   switch(ch)
	   { case 1: P=Pending();
		         cout<<"\n\nTOTAL NUMBER OF PENDING           BOOKS :  "<<P;
		         break;
	     case 2: Max_Bookissued();
		         break;
	     case 3: Notreturned();
		         break;
	     case 4: return;
	   }
	  // goto l;
	}
}

void BookMaster()
{     int BM,k,l,bookno;
      while(BM!=5)
      {
	    clrscr();
	cout<<"\n\t\tBook Master";
	cout<<"\n1.Add a Book";
	cout<<"\n2.Search a Book";
	cout<<"\n3.Display";
	cout<<"\n4.Delete";
	cout<<"\n5.Go Back";
	cout<<"\nEnter your choice:";
	cin>>BM;
	switch(BM)
	{  case 1: AddBook();
	      	   break;
	   case 2: cout<<"\nEnter the book number to be searched:";
		       cin>>bookno;
		       Search_book(bookno);
		       break;
	   case 3: Display_book();
		       break;
	   case 4: delete_book();
		       break;
	   case 5: return;
	   default: cout<<"\nWrong Choice!!!";
	 }
       }
}

void MemberMaster()
{   int MM,no,l;
    while(MM!=5)
    { clrscr();
      cout<<"\n\t\tMember Master";
      cout<<"\n1.Add Member";
      cout<<"\n2.Search a Member";
      cout<<"\n3.Display";
      cout<<"\n4.Delete";
      cout<<"\n5.Go Back";

      cout<<"\nEnter your choice(1-5):";
      cin>>MM;


      switch(MM)
      {  case 1: AddMember();
		         break;
	     case 2: cout<<"\nEnter the membership number to be searched:";
		         cin>>no;
		         searchmember(no);
		         break;
	     case 3: Display_member();
		         break;
	     case 4: delete_member();
		         break;
	     case 5: return;
	     default: cout<<"\nWrong Choice!!!";
      }
    }
}

void MainMenu()
{     Book b;
	  int ch=1;
	  while(ch!=6)
	  {
	     clrscr();
	     cout<<"\n\t\tMENU";
	     cout<<"\n\t1.Book Master";
	     cout<<"\n\t2.Member Master";
	     cout<<"\n\t3.Issue";
	     cout<<"\n\t4.Deposit";
	     cout<<"\n\t5.Report";
	     cout<<"\n\t6.Exit";

	     cout<<"\nEnter your choice(1-6):";
	     cin>>ch;

      	switch(ch)
     	{ case 1: BookMaster();
		          break;
	      case 2: MemberMaster();
		          break;	                            
	      case 3: Issue();
		          break;                            
	      case 4: Deposit();
		          break;				
	      case 5: Report();
		          break; 				
	      case 6: return;				
	  }
	 } 
}
void main()
{
 clrscr();
 MainMenu();
 getch();
}
