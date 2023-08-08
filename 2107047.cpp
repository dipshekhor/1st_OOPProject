#include<bits/stdc++.h>
#include <string>
using namespace std;
class Agency;
class Package;
class Booking ;
class Customer;
class Customer
{
    string name;
    int id;
    string phone;
 public:
    Customer(string a,int b,string c)
    {
          name=a;
          id=b;
          phone=c;
    }
    Customer()
    {

    }
    void display1()
    {
       cout<<"NAME: "<<name<<"  \t"<<"CUSTOMER ID: "<<id<<"\t"<<"PHONE NUMBER: "<<phone<<endl;
    }
    friend Agency;

};
class Package
{
//number of package agency have
    int packagecode[8];
    string destination[8];
    int prices[8];//3 day per head
    public:
    void addpackages()
    {
        packagecode[0]=1;
        packagecode[1]=2;
        packagecode[2]=3;
        packagecode[3]=4;
        packagecode[4]=5;
        packagecode[5]=6;
        packagecode[6]=7;
        packagecode[7]=8;
        prices[0]= 7000;
        prices[1]= 5000;
        prices[2]= 5500;
        prices[3]= 6500;
        prices[4]= 5600;
        prices[5]= 7500;
        prices[6]= 7000;
        prices[7]= 6000;
        destination[0]="Bandarban,Rangamati,Khagrachari";
        destination[1]="Rajshahi,Chapai,Natore,Bogura";
        destination[2]="Kuakata,Barishal,Pirojpur";
        destination[3]="Srimanagal,Moulavibazar,Chatok";
        destination[4]="Bhola,Chandpur,Cumilla,B-Baria";
        destination[5]="Cox's bazar,Saint-Martin,Teknaf";
        destination[6]="Sunamganj,Sylhet,Habiganj";
        destination[7]="Sundarban,Bagerhat,Khulna";
    }
    Package()
    {
          cout<<"Package"<<"\t"<<"\t"<<"\t"<<"Destination"<<"\t"<<"\t "<<"Prices-Per-Head"<<endl;
    }
    void displaypackage()
    {

    for(int i=0;i<8;i++)
    {
        cout<<packagecode[i]<<"\t"<<"\t"<<destination[i]<<"\t"<<"\t"<<prices[i]<<endl;
    }
    }
    friend Agency;
};
class Booking
{
   long long int bookingid;
   long long int nationalId;
   public:
   Booking(){

        cout<<"Give your national id card number"<<endl;
        cin>>nationalId;
        bookingid=nationalId;
        cout<<"Your booking is completed"<<endl;
        cout<<"BOOKINGID :"<<"880BD"<<bookingid<<"\t"<<"NATIONAL ID: "<<nationalId<<" \t";
   }
   friend Agency;

};

class Agency
{
    
    int numberofperson;
    int numberofchild;
    public:
    Agency(int a,int b)
    {
        numberofperson=a;
        numberofchild=b;
    }
        void paymentmethod(){
          int choose;
         do
         {
        cout<<"Please choose your payment method :"<<endl;
        cout<<"1.Cash payment"<<endl<<"2.Online payment"<<endl;
        cin>>choose;
        if(choose==1)
        {
            cout<<"please contact to our agency in person within 3 days";
        }
        if(choose==2)
        {

            int u;

            do{
            cout<<"Choose the online options :"<<endl;
            cout<<"1.Bkash"<<endl<<"2.Nagad"<<endl<<"3.Rocket"<<endl<<"4.Card"<<endl;
            cin>>u;
           if(u==1 || u==2 || u==3)
           {
               cout<<"Make payment in this number using payment option :01789654236546"<<endl;
               cout<<"Drop your transaction id here :"<<endl;
               string tran;
               cin>>tran;

           }
           if(u==4)
           {
               cout<<"Give your card number :"<<endl;
               string num;
               cin>>num;
           }
           if(u>4)
               cout<<"Your payment is not found "<<endl;
            }while(u>4);

        }
        if(choose>2)
          cout<<"YOUR PAYMENT OPTION IS NOT FOUND"<<endl;

    }while(choose>2);
}
 void packagesum(Package &obj,int n)
   {
        float sum=0;
        if(numberofperson>1){
             sum+=obj.prices[n]*numberofperson-(obj.prices[n]*numberofperson*(.1));
             if(numberofchild){
               sum+=obj.prices[n]*numberofchild-(obj.prices[n]*numberofchild*(.3));
             }
         }
         else if(numberofperson==1){
          sum+=obj.prices[n];
           if(numberofchild){
               sum+=obj.prices[n]*numberofchild-(obj.prices[n]*numberofchild*(.3));
             }
         }
         cout<<"Your Total cost for this trip will be: ";
         cout<<sum<<"TK only"<<endl;
         string s;
         Customer obj4;
         cout<<"Tap to continue"<<endl;
         cout<<"Type Yes/yes if you are interested to continue to book,otherwise type NO/no"<<endl;
         cin>>s;
         if(s=="Yes" || s=="yes")
         {
              char yesno;
              cout<<"Give your information"<<endl;
              string name;
              int id;
              string phone;
              do{
              cout<<"Enter your customer id"<<endl;
              cin>>id;
              cout<<"Enter your phone number"<<endl;
              getchar();
              getline(cin,phone);
              cout<<"Enter your name"<<endl;
              getline(cin,name);
              Customer obj2(name,id,phone);
              cout<<"Check your information"<<endl;
              obj2.display1();
              obj4=obj2;

              cout<<"Type 'y' if it is ok otherwise type 'n' "<<endl;
              cin>>yesno;
         }while(yesno=='n');
         cout<<"Press for booking"<<endl;
         Booking obj3;
         obj4.display1();
         cout<<"Your booking is successful,thanks for the visit"<<endl;
        paymentmethod();
        cout<<"\t\t\t\t\t" <<"HERE IS YOUR MONEY RECEIPT...."<<endl;
        chrono::seconds delayDuration(2);
        this_thread::sleep_for(delayDuration);
        cout<<"NAME :"<<obj4.name<<endl;
        cout<<"BOOKING ID: 880BD"<<obj3.bookingid<<endl;
        cout<<"PHONE NUMBER: "<<obj4.phone<<endl;


         cout<<"\t\t\t\t\t"<<"HAPPY TRAVELLING"<<endl;
         cout<<"\n";
    }
    else{
     cout<<"Thanks for the inquiry,Keep supporting us."<<" "<<"THANK U"<<endl;
    }
   }
};


int main()
{
    Package obj;
    obj.addpackages();
    obj.displaypackage();
    cout<<"choose your package giving the package code: ";
    int n,person,child;
    cin>>n;
    switch(n)
    {
        case 1:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 2:
             {
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
             }
        case 3:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 4:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 5:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 6:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 7:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        case 8:{
        cout<<"Enter the total number of person"<<endl;
        cin>>person;
        cout<<"Enter the total number of child"<<endl;
        cin>>child;
        Agency obj1(person,child);
        obj1.packagesum(obj,n-1);
        break;
        }
        default:
        cout<<"Package not found"<<endl;
    }
    cout<<"For any inneed please contact us in 01772895851"<<endl;
    return 0;

}
