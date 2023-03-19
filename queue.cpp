#include<iostream>
using namespace std;

class queue
{
	int rear,front;
	int n;
	int arr[100];
	public:
	queue()
	{    
		rear=-1;
		front=-1;
		for( int i=0;i<100;i++)
   	    {
   	    	arr[i]=0;
		   }
		
	}
	void set_data()
   	{
   		cout<<"Enter the number of elements in the array:";
   		cin>>n;
   		
	}
	
	bool isEmpty()
	{
		if(rear==-1&&front==-1)
		return true;
		
		else
		return false;
	}
	bool isFull()
	{
		if(rear+1==n)
		return true;
		else
		return false;
	}
	void enqueue(int value)
	{
		if(isFull())
		{
		 cout<<"Sorry,the list is Full"<<endl;
		 
		}
		else if(isEmpty())
		{
			rear=0; front=0;
			arr[rear]=value;
		}
		else
		{
			rear++;
			arr[rear]=value;
		}
	}
	int dequeue()
	{
		if(isEmpty())
		{
			cout<<"Nothing in the list! "<<endl;
			return 0;
		}
		else if(rear==front)
		{   
		int m=arr[rear];
			rear=-1;
			front=-1;
			return m;
		}
		else
		{
			int x;
			x=arr[front];
			front++;
			return x;
		}
	}
	void count ()
	{
		cout<<"Number of elements in the queue is "<<rear+1-front<<endl;
	}
	void display()
	{
		for(int j=front;j<=rear;j++)
		{
			cout<<arr[j]<<endl;
		}
	}
};
int main()
{  
	int n,option,value;
	queue q1;
	q1.set_data();
	do{
		cout<<"Choose the service you wanna use.press 0 to exit:"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.isEmpty"<<endl;
		cout<<"4.isFull"<<endl;
		cout<<"5.count"<<endl;
		cout<<"6.display"<<endl;
		
		cin>>option;
		switch(option)
			{   case 0:
			{
				break;
			}
			case 1:
				{
					cout<<"Enter the value you wanna Enqueue to the queue:";
					cin>>value;
					q1.enqueue(value);
					break;
				}
			case 2:
				{
             	   int dequeuevalue=q1.dequeue();
             	   cout<<dequeuevalue;
             	   break;
				}
			case 3:
				{
					
					if(q1.isEmpty()==0)
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
						if(q1.isFull()==0)
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
					q1.count();
					break;
				}
			
			case 6:
				{
					q1.display();
					break;
				}
				
		}
		
	}while(option!=0);
	return 0;
	
}
