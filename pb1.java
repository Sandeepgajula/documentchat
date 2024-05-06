import java.util.*;
import java.lang.*;
class borrowedExceededException extends Exception{
	public String toString(){
		return "Books borrowedExceededinNumber";
	}
}
class bookCopyException extends Exception{
	public String toString(){
		return "Only one copy of a book can be borrowed";
	}
}
class credentialsException extends Exception{
	public String toString(){
		return "credentials mismatch";
	}
}
class Book{
	String Book_Title,Book_Author,Book_ISBN;
	int count;
	Book(String Book_Title,String Book_Author,String Book_ISBN,int count){
		this.Book_Title=Book_Title;
		this.Book_Author=Book_Author;
		this.Book_ISBN=Book_ISBN;
		this.count=count;
	}
}
class CSE extends Book{
	CSE(String Book_Title,String Book_Author,String Book_ISBN,int count){
		super(Book_Title,Book_Author,Book_ISBN,count);
	}
	String getTitle(){
		return Book_Title;
	}
	int getCount(){
		return count;
	}
}
class ECE extends Book{
	ECE(String Book_Title,String Book_Author,String Book_ISBN,int count){
		super(Book_Title,Book_Author,Book_ISBN,count);
	}
	String getTitle(){
		return Book_Title;
	}
	int getCount(){
		return count;
	}
}
class EEE extends Book{
	EEE(String Book_Title,String Book_Author,String Book_ISBN,int count){
		super(Book_Title,Book_Author,Book_ISBN,count);
	}
	String getTitle(){
		return Book_Title;
	}
	int getCount(){
		return count;
	}
}
class Student{
	String Username,Password;
	Set<String> s=new HashSet<>();
	int borrowCount=0;
	Student(String Username,String Password){
		this.Username=Username;
		this.Password=Password;
	}
	boolean checkCredentials(String Username,String Password){
		if(this.Username==Username&&this.Password==Password)
			return true;
		return false;
	}
	boolean borrowBook(String Book_Title) throws Exception{
		if(s.size()==3)
			throw new borrowedExceededException();
		for(String i:s)
			if(i.equals(Book_Title))
				throw new bookCopyException();
		s.add(Book_Title);
		this.borrowCount++;
		return true;
	}
}
class pb1{
	static CSE c[]=new CSE[10];
	static ECE e[]=new ECE[10];
	static EEE ee[]=new EEE[10];
	static Student s[]=new Student[10];
	static int cseIndex=-1,eceIndex=-1,eeeIndex=-1,studentIndex=-1;
	static void display_catalog(){
		System.out.println("Books available: ");
		System.out.println("CSE: ");
		for(int i=0;i<=cseIndex;i++)
			System.out.println(c[i].getTitle());
		System.out.println("ECE: ");
		for(int i=0;i<=eceIndex;i++)
			System.out.println(e[i].getTitle());
		System.out.println("EEE: ");
		for(int i=0;i<=eeeIndex;i++)
			System.out.println(ee[i].getTitle());
	}
	static int checkLogin(String Username,String Password){
		for(int i=0;i<=studentIndex;i++)
			if(s[i].checkCredentials(Username,Password))
				return i;
		
		//	throw new credentialsException();
		return -1;	
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		String Username="",Password="",Book_Title="",Branch="";
		s[++studentIndex]=new Student("vignesh","rgukt");
		s[++studentIndex]=new Student("shivaram","rgukt");
		s[++studentIndex]=new Student("sricharan","rgukt");
		c[++cseIndex]=new CSE("dbms","nagalaxmi","CSE1",3);
		c[++cseIndex]=new CSE("Oops","surender","CSE2",4);
		e[++eceIndex]=new ECE("Oop","latha","ECE1",4);
		e[++eceIndex]=new ECE("LIM","srinivas","ECE2",2);
		ee[++eeeIndex]=new EEE("OopBeginner","prasad","EEE1",4);
		ee[++eeeIndex]=new EEE("Power","pravalika","EEE2",2);
		while(true){
			System.out.println("1.Login 2.Exit: ");
			int m=sc.nextInt();
			if(m==2)
				break;
			else{
				System.out.println("Enter Username: ");
				Username=sc.next();
				System.out.println("Enter Password: ");
				Password=sc.next();
				try{
					int studentIndex=checkLogin(Username,Password);
					display_catalog();
					System.out.println("1.Purchase 2.Return: ");
					int no=sc.nextInt();
					switch(no){
						case 1:
							System.out.println("enter Book_Tile and Branch to purchase: ");
							Book_Title=sc.next();
							Branch=sc.next();
							try{
								s[studentIndex].borrowBook(Book_Title);
								if(Branch.equals("CSE"))
								for(int i=0;i<=cseIndex;i++)
									if(c[i].getTitle().equals(Book_Title))
										c[i].count--;
								if(Branch.equals("ECE"))
								for(int i=0;i<=eceIndex;i++)
									if(e[i].getTitle().equals(Book_Title))
										e[i].count--;
								if(Branch.equals("EEE"))
								for(int i=0;i<=eeeIndex;i++)
									if(ee[i].getTitle().equals(Book_Title))
										ee[i].count--;
								
							}	
//							catch(bookCopyException e){
//								System.out.println(e);
//							}
//							catch(borrowedExceededException e){
//								System.out.println(e);
//							}
							catch(Exception e){
								System.out.println(e);
							}
							break;
						case 2:
							if(Branch.equals("CSE"))
							for(int i=0;i<=cseIndex;i++)
								if(c[i].getTitle().equals(Book_Title))
									c[i].count++;
							if(Branch.equals("ECE"))
								for(int i=0;i<=eceIndex;i++)
									if(e[i].getTitle().equals(Book_Title))
										e[i].count++;
							if(Branch.equals("EEE"))
								for(int i=0;i<=eeeIndex;i++)
									if(ee[i].getTitle().equals(Book_Title))
										ee[i].count++;
					}
					
				}
				catch(Exception e){
					System.out.println(e);
				}
			}
		}
	}
}
