#include<iostream>
using namespace std;


class stack
{
   int top;
   int n;
   	int arr[100];
   public:
   	 
   	stack()
   	{   top=-1;
   		for(int i=0;i<n;i++)
   	arr[i]=0;
	   }
   	void set_data()
   	{
   		cout<<"Enter the number of elements in the array:";
   		cin>>n;
	}
	bool isEmpty()
	{
		if(top==-1)
		return true;
		else 
		return false;
	}
	bool isFull()
	{
		if(top==4)
		return true;
		else 
		return false;
	}
	void push(int value)
	{
		if(isFull())
		cout<<"Stack overflow";
		else
		{
			top++;
			arr[top]=value;
		}
	}
	int pop()
	{
		if(isEmpty())
		cout<<"Stack undeflow";
		else
		{
			int popvalue=arr[top];
			arr[top]=0;
			top--;
			return popvalue;
		}
	}
	int peek(int i)
	{
		return arr[i];
		cout<<""<<endl;
	}
	void count()
	{
		cout<<top+1<<endl;
		
	}
	void change()
	{   int pos,value;
		cout<<"Enter the position:";
		cin>>pos;
		cout<<"Enter the value to which you wanna cahnge to:";
	    cin>>value;
	    
		arr[pos]=value;
		cout<<"Value changed at pos:"<<pos<<endl;
	}
	void display()
	{
		for(int i=0;i<top+1;i++)
		{
			cout<<arr[i];
		}
		cout<<""<<endl;
	}
	
};
int main()
{
	stack s1;
	int option,position,value;
	s1.set_data();
	do{
		cout<<"Choose the service you wanna use.press 0 to exit:"<<endl;
		cout<<"1.push"<<endl;
		cout<<"2.pop"<<endl;
		cout<<"3.isEmpty"<<endl;
		cout<<"4.isFull"<<endl;
		cout<<"5.peek"<<endl;
		cout<<"6.count"<<endl;
		cout<<"7.change"<<endl;
		cout<<"8.display"<<endl;
		
		cin>>option;
		switch(option)
		{   case 0:
			{
				break;
			}
			case 1:
				{
					cout<<"Enter the value you wanna push to the stack:";
					cin>>value;
					s1.push(value);
					break;
				}
			case 2:
				{
             	   int popvalue=s1.pop();
             	   cout<<popvalue;
             	   break;
				}
			case 3:
				{
					
					if(s1.isEmpty()==0)
					{
						cout<<"false";
					}
					else
					{
						cout<<"true";
					};
					cout<<""<<endl;
					break;
				}
			case 4:
				{
						if(s1.isFull()==0)
					{
						cout<<"false";
					}
					else
					{
						cout<<"true";
					};
					cout<<""<<endl;
					break;
				}
			case 5:
				{
					cout<<"Enter the location where you wanna look at:";
					cin>>position;
					value=s1.peek(position);
					cout<<value;
					break;
				}
			case 6:
				{
					s1.count();
					break;
				}
			case 7:
				{
					
					s1.change();
					break;
				}
			case 8:
				{
					s1.display();
					break;
				}
				
		}
		
	}while(option!=0);
	return 0;
}
