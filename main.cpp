#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
 private :
  int pcode;
  float price;
  float dis;
  string pname;
  
 public :
  void menu();
  void administrator();
  void buyer();
  void add();
  void edit();
  void rem();
  void list();
  void receipt();
  
};

void shopping::menu()
{
    m :
    int choice;
    string email;
    string password;
    cout<< "\t\t\t\t___________________________\n";
    cout<< "\t\t\t\t                           \n";
    cout<< "\t\t\t\t   Supermarket Main Menu   \n";
    cout<< "\t\t\t\t                           \n";
    cout<< "\t\t\t\t___________________________\n";
    cout<< "\t\t\t\t                           \n";
    cout<< "\t\t\t\t|  1)Administrator  |\n";
    cout<< "\t\t\t\t|                   |\n";
    cout<< "\t\t\t\t|  2)Buyer          |\n";
    cout<< "\t\t\t\t|                   |\n";
    cout<< "\t\t\t\t|  3)Exit           |\n";
    cout<< "\t\t\t\t|                   |\n";
    cout<< "\n\t\t\t  Please select : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
        {
          cout <<"\t\t\t Please login \n";
          cout <<"\t\t\t Enter Email  \n";
          cin>>email;
          cout <<"\t\t\t Enter Password\n";
          cin>>password;
          
          if(email=="hima@gmail.com" && password=="hima@pro")
           {
               administrator();
           }
           else
           {
               cout<< "Invalid email/password ";
           }
        }
        case 2:
        {
           buyer();
        }
        case 3 :
        {
            exit(0);
        }
        default :
        {
            cout<< " Please select from the given options ";
            
        }
    }
    goto m;
}
void shopping :: administrator()
{
    m:
    int choice;
    cout << "\n\n\n\n\t\t\t Administrator Menu ";
    cout << "\n\t\t\t|____.1)Add the product___|";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____.2)Modify the product|";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____.3)Delete the product|";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|____.4)Back to main menu |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\n\t  Please Enter your choice ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
        {
            add();
            break;
        }
        case 2 :
        {
            edit();
            break;
        }
        case 3 :
        {
            rem();
            break;
        }
        case 4 :
        {
            menu();
            break;
        }
        default :
        {
            cout << "Invalid choice ";
        }
    }
    goto m;
}
void shopping :: buyer()
{
    m:
    int choice;
    cout << "\t\t\t   Buyer   \n";
    cout << "\t\t\t___________\n";
    cout << "\t\t\t           \n";
    cout << "\t\t\t 1)Buy Product   \n";
    cout << "\t\t\t                 \n";
    cout << "\t\t\t 1)Back to main menu   \n";
    cout << "\t\t\t                       \n";
    cout << "\t\t\t Please Enter your choice ";
    cin >>choice;
    switch(choice)
    {
        case 1 :
        {
            receipt();
            break;
        }
        case 2 :
        {
            menu();
            break;
        }
        default :
        {
            cout << "Invalid choice";
        }
    }
    goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t  Add new product  ";
    cout << "\n\n\t product code of Product ";
    cin >>pcode;
    cout << "\n\n\t name of product ";
    cin >> pname;
    cout << "\n\n\t price of product";
    cin >> price;
    cout << "\n\n\t discount on product ";
    cin >> dis;
    
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data << "  " << pcode << "  " << pname << "  " << price << "  " << dis  <<"\n";
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
       if(token==1)
       {
          goto m;
       }
       else
       {
       data.open("database.txt",ios::app|ios::out);
       data << "  " << pcode << "  " << pname << "  " << price << "  " << dis  <<"\n";
       data.close();
       }
    }
    cout << "\n\n\t\t Record inserted";
}
void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout << "\n\t\t\t  Modify the product  ";
    cout << "\n\t\t\t  product code  ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "\n\n File doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout << "\n\n\t product code of Product ";
                cin >>c;
                cout << "\n\n\t name of product ";
                cin >> n;
                cout << "\n\n\t price of product";
                cin >> p;
                cout << "\n\n\t discount on product ";
                cin >> d;
                data<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
                cout<<"\n\n\t\t Record exist ";
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n Record not found sorry! ";
        }
    }
}
void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t  Delete Product  ";
    cout<<"\n\n\t  Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File dosen't exist ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
           if(pcode==pkey)
           {
               cout<<"\n\n\t Product deleted successfully ";
               token++;
           }
           else
           {
               data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
           }
           data>>pcode>>pname>>price>>dis;
           
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
         {
             cout<<"\n\n Record not found sorry! ";
         }
    }
}
void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_____________________________________\n";
    cout<<"product code \t\t product name \t\t price \n";
    cout<<"\n\n|_____________________________________\n";
    data>>price>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>price>>pname>>price>>dis;
    }
    data.close();
}
void shopping ::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t\t     RECEIPT     ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Storage ";
    }
    else
    {
        data.close();
        list();
        cout<<"\n _______________________________________________\n";
        cout<<"\n|                                              |\n";
        cout<<"\n|           Please place the order             |\n";
        cout<<"\n|                                              |\n";
        cout<<"\n _______________________________________________\n";
        do
        {
            m:
            cout<<"\n\n  Enter Product Code :  ";
            cin>>arrc[c];
            cout<<"\n\n  Enter Product Quantity :  ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want another product?(y/n)";
            cin>>choice;
        }while(choice=='y');
        cout<<"\n\n\t\t\t\t________RECEIPT_______\n";
        cout<<"\n product code \t\t product name \t\t product quantity \t\t price \t Amount \t Amountwith discount \n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=amount +dis;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
                    
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
  cout<<"\n\n_____________________________________________________________________________________________________";
  cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}
