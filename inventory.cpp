#include<iostream>
using namespace std;

class item
{
    private:
        char name[20];
        int code[20];
        float price[20];
        int z;
    public:
        void add_(void);
        void delete_(void);
        void sell_(void);
        void display_(void);
        void initial(void){z=0;}

};
     void item :: add_(void)
       {
    clrscr();
    cout<<"\nEnter the item category    : ";
    cin>>name[z];
    cout<<"Enter the item code        : ";
    cin>>code[z];
    cout<<"Enter the price of the item: ";
    cin>>price[z];
    z++;
       }


       void item :: delete_(void)
       {
     int i,j;
     clrscr();

     cout<<"\nPlease enter the item code:";
     cin>>i;
     for(j=0;j<z;j++)
    {
      if(code[j]==i)
      {
        price[j]=0;
        cout<<"\nThe item is deleted from the list.";
        getch();
        break;
      }
    }
       }

      void item :: sell_(void)
      {
    char a;
    int i,j;
    float total_price=0;
    clrscr();

    cout<<"\nEnter the item code:";
    cin>>i;
    for(j=0;j<z;j++)
    {
      if (code[j]==i)
      {
        if(price[j]==0)
        {
          cout<<"\nSorry.There is no item left in this catefory.";
          cout<<"\nDo you want to buy another item? y\\n"<<endl;
          cin>>a;
          if (a=='y')
          {
        cout<<"\nEnter the item code:";
        cin>>i;
        j=-1;
          }
          else if (a=='Y')
          {
        cout<<"\nEnter the item code:";
        cin>>i;
        j=-1;
          }
          else
          {
        if (total_price!=0)
        {
          cout<<"\nYour total price is: ";
          cout<<total_price<<" Taka."<<"\nThank You.";
        }
        cout<<"Bye...bye...";
        break;
          }
        }
        else
        {
          cout<<"Item category is: "<<name[j];
          cout<<"\nItem price is   : "<<price[j]<<"tk."<<endl;
          total_price+=price[j];
          price[j]=0;
          cout<<"\nDo you want to buy another item:y\\n";
          cin>>a;
          if (a=='y')
          {
        cout<<"\nEnter the item code:";
        cin>>i;
        j=-1;
          }
          else if (a=='Y')
          {
        cout<<"\nEnter the item code:";
        cin>>i;
        j=-1;
          }
          else
          {  clrscr();
        cout<<"\nYour total price is: ";
        cout<<total_price<<"Taka."<<"\nThank You.";
        break;
          }
        }
      }
    }
    getch();
    }

    void item :: display_()
     {
       int i,j=1;
       clrscr();

       for(i=0;i<z;i++)
      {
        cout<<j<<".Item category is: "<<name[i];
        cout<<"\n  Item code is    : "<<code[i];
        cout<<"\n  Item price is   : "<<price[i]<<"tk."<<endl<<endl;
        j++;
       }
        getch();
      }


 int main ()

   {
    int i;
    item shoping_mall;
    clrscr();

    shoping_mall.initial();

    while(1)
    {
      cout<<"\n   What do you want to do?"<<endl;
      cout<<"\n1: Add a new item.";
      cout<<"\n2: Delete an item.";
      cout<<"\n3: Sale an item.";
      cout<<"\n4: Display all items.";
      cout<<"\n5: Exit"<<endl;
      cout<<"\n\n Choose a number:";
      cin>>i;

      switch(i)
      {
        case 1:
        {
          shoping_mall.add_();
          break;
        }
        case 2:
        {
          shoping_mall.delete_();
          break;
        }
        case 3:
        {
          shoping_mall.sell_();
          break;
        }
        case 4:
        {
          shoping_mall.display_();
          break;
        }

           case 5:
        {
          cout<<"Good Bye! Thank you.";
          break;
        }
      }
      if (i==5)
        break;
      clrscr();
    }
    getch();
    return 0;
}
