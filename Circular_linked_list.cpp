#include<iostream>
using namespace std;
class Node
{
	
	public:
		int key;
		int data;
		Node* next;
		
		Node()
		{
			key=0;
			data=0;
			next=NULL;
			
		}
		Node(int k,int d)
		{
			key=k;
			data=d;
			
		}
		
};
class CircularLinkedList
{
	public:
		Node* head;
		CircularLinkedList()
		{
			head=NULL;
		}
		CircularLinkedList(Node* n)
		{
			head=n;
		}
		//1.Check if Node exists
		Node* nodeExists(int k)
		{
			Node *temp=NULL;
			Node *ptr=head;
			do
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}while(ptr!=head);
			return temp;
		}
		void AppendNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists with this key value: "<<n->key<<" Try appending at another key value"<<endl;
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					n->next=head;
					cout<<"Node appended"<<endl;
				}
				else
				{
					Node *ptr=head;
			while(ptr->next!=head)
				{
				
					ptr=ptr->next;
				}
			ptr->next=n;
			n->next=head;
			cout<<"Node appended"<<endl;
			}
			}
		}
		//prepend node we attach the node at the start
		void PrependNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node already exists with this key value: "<<n->key<<"Try appending at another key value"<<endl;
			}
			else
			{
				Node* ptr=head;
				while(ptr->next!=head)
				{
					ptr=ptr->next;
				}
				n->next=head;
				head=n;
				cout<<"Node prepended"<<endl;
			}
		}
		void InsertNodeAfter(int k,Node*n)
		{
			Node* ptr = nodeExists(k);
			if(ptr==NULL)
			{
				cout<<"NO node exists with this key"<<endl;
			}
			else
			{
				if(nodeExists(n->key)!=NULL)
				{
					cout<<"Node already exists.Try another key"<<endl;
				}
				else
				{   
					Node* nextNode=ptr->next;
					if(nextNode==head)
					{
						n->next=head;
						ptr->next=n;
						
						cout<<"Node Inserted at the end."<<endl;
					}
					else
					{
						n->next=ptr->next;
						ptr->next=n;
						cout<<"Node Inserted in between ."<<endl;
					}
				}
			}
		}
		void DeleteNode(int k)
		{
			Node*ptr=nodeExists(k);
			if(ptr==NULL)
			{
				cout<<"No node exists for input key value."<<endl;
			}
			else if(ptr==head)
			{   
				if(head==NULL)
				{	
					
					cout<<"Linked list is already empty"<<endl;
				}
				else
				{
					Node*ptr=head;
					while(ptr->next!=head)
					{
						ptr=ptr->next;
					}
					ptr->next=head->next;
					head=head->next;
					cout<<"Node unlinked with the key value:"<<k<<endl;
				}
			}
			else
			{
				Node* temp=NULL;
					Node* prevptr=head;
					Node* currentptr=head->next;
					while(currentptr!=NULL)
					{
						if(currentptr->key=k)
						{
							temp=currentptr;
							currentptr=NULL;
						}
						else
						{
							prevptr=prevptr->next;
							currentptr=currentptr->next;
						}
				    }
					prevptr->next=temp->next;
					cout<<"Node unlinked with key values:"<<k<<endl;    
			}
			
		}
		void UpdateNode(int k,int d)
		{	
		Node* ptr=nodeExists(k);
			if(ptr==NULL)
			{
				ptr->data=d;
				cout<<"Node updated successfully."<<endl;
			}
			else
			{
				cout<<"Node doesn't exists with the key:"<<k<<endl;
			}
		}
		void printlist()
		{
			if(head==NULL)
			{
				cout<<"No elements in the linked list"<<endl;
			}
			else
			{
				cout<<"Your linked list elements are:"<<endl;
				Node* temp=head;
				while(temp!=NULL)
				{
					cout<<temp->data<<endl;
					temp=temp->next;
				}
				
			}
		}
};
int main()
{
	CircularLinkedList c;
	int option;
	int k1,key1,data1;
	do
	{
			cout<<"Choose the service you wanna use.press 0 to exit:"<<endl;
		cout<<"1.Append to the linked list"<<endl;
		cout<<"2.prepend to the linked list"<<endl;
		cout<<"3.Insert the node after the key"<<endl;
		cout<<"4.Delete node by key"<<endl;
		cout<<"5.Update node by key"<<endl;
		cout<<"6.Print"<<endl;
		cout<<"7.Clear Screen"<<endl;
		
		cin>>option;
		Node* n1= new Node();
		switch(option)
			{   case 0:
			{
				break;
			}
			case 1:
				{
					cout<<"Append operation,Enter key and data respectively to append"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					c.AppendNode(n1);
					break;
				}
			case 2:
				{  
					cout<<"Prepend operation,Enter key and data respectively for prepend"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					c.PrependNode(n1);
					
             	   break;
				}
			case 3:
				{   
					cout<<"Enter the key after which you wanna add nodes:";
					cin>>k1;
					cout<<"Enter the key and data of new node";
					cin>>key1;
					cin>>data1;
					n1->key=key1;
					n1->data=data1;
					c.InsertNodeAfter(k1,n1);
					break;
				}
			case 4:
				{
					cout<<"Enter the key of the node to be deleted:";
					cin>>key1;
					c.DeleteNode(key1);
					break;
				}
			case 5:
				{   cout<<"Enter the key and data you wanna update:";
					cin>>key1;
					cin>>data1;
					c.UpdateNode(key1,data1);
					break;
				}
			case 6:
				{   c.printlist();
					break;
					
				}
			case 7:
				{
					system("cls");
					break;
				}
			default:
				{
					cout<<"Enter proper option"<<endl;
				}
			
		}
		
		
	}while(option!=0);
	return 0;
}
