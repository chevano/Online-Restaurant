/*
 -----------------------------------------------------------------------------------------------------------------
            Restaurant owner: Ask customers what they want to order, compute tips and taxes.
            This short program displays a main menu at the beginning after greetings with a
            variety of choices, within the main menu are separate functions that play
            different roles such as calculating the total expense of a customer order.
            The program encourage interaction between the user and the computer by
            trying to fix a complaint a customer may have upon ordering or walking in.
            The function that had the highest level of difficulty level is the total function.
 
 -----------------------------------------------------------------------------------------------------------------
 */
#include <iostream>
#include <vector>
#include <iomanip>                     // to manipuate the output with the usage of the setw function
using namespace std;
const double TAX = 8.625;


struct data
{
    vector <int> Litem;
    vector <int> LitemPrice;
    vector <int> Lamount;
    int Ltips;
    int counter = 0;
};
data *list = new data; // allocated memory for efficiency


void   menu(int);
void   display(int);
void   mainMenu(int);
void   receipt();
double total();
void   complaint();


int main()
{
    int x = 0;
    
    cout << "Welcome to Garbin Restaurant !!!\nPlease select the choice that best suits you." << endl;
    display(x);
    delete list; // de-allocting the pointer to list of type data
    return 0;
}

void display(int num)
{
    
         cout << "01. ..... Menu"         << endl;
         cout << "02. ..... Total"        << endl;
         cout << "03. ..... Receipt"      << endl;
         cout << "04. ..... Complains"    << endl;
         cout << "-1. ..... To quit"      << endl;
         cout << endl << "Response: ";
         cin  >> num;
         cout << endl;
    
        if(num == -1)
            cout << "Thanks for making it Garbin Restaurant, please come again! " << endl;
        else
            mainMenu(num);
    
        cout << endl;
    
    
}
void mainMenu(int number)
{
    
    switch(number)
    {
    
        case 1:
            cout << endl;
            menu(number);
            display(number);
            break;
        case 2:
             cout << total();
             cout << endl;
             display(number);
             break;
        
        case 3:
             receipt();
            break;
        
        case 4:
            complaint();
            break;

        default:
            cout << "Please enter a number within the given range" << endl;
            display(number);
            break;
    
    }
}

void menu(int item)
{
    cout <<  " ---------------------SALAD---------------------"  << endl;
    cout << "01.Mayonnaise                        ....... $5"    << endl;
    cout << "02.Roquefort                         ....... $5"    << endl;
    cout << "03.Caesar                            ....... $5"    << endl;
    cout <<  " ---------------------ENTREE---------------------" << endl;
    cout << "04.Chicken Scallopinir               ....... $15"   << endl;
    cout << "05.Braised Chuck Roast in Red Wine   ....... $15"   << endl;
    cout << "06.Brodetto (Fish Stew) Ancona-Style ....... $15"   << endl;
    cout <<  " ---------------------DESSERT--------------------" << endl;
    cout << "07.Tiramisu                          ....... $10"   << endl;
    cout << "08.Amaretto Biscotti                 ....... $10"   << endl;
    cout << "09.Chocolate Amaretti Cake           ....... $10"   << endl;
    cout <<  " ---------------------BEVERAGES------------------" << endl;
    cout << "10.Aperitivo                         ....... $12"   << endl;
    cout << "11.Grappa                            ....... $12"   << endl;
    cout << "12.Fernet-Branca                     ....... $12"   << endl;
   
    int amount, tips;
    int count = 0;
    char response = 'n';
    
    
    do
    {
        cout << endl;
        cout <<"Please enter the number of your desire dish or beverage" << endl;
        cin  >> item;
        
        if(item > 12)
        {
            cout << "Please select a number from the given range" << endl;
            response = 'n';
            display(item);
        }
        else
        {
            cout << "How many orders of number " << item << " would you like to order" << endl;
            cin  >> amount;
            count++;
        
            list->Litem.push_back(item);    // storing the item number the user entered in a vector located in struct data
            list->Lamount.push_back(amount);// storing the number of orders of a particlular order
            list->counter = count;          // checks to see how many times the user was prompt to give his/her order.
        
        
        
            if((item <=3) && (item >=1)) // assigning a price to items on the list that are between 1 and 3
            {
                    item = 5;
                
                    // storing the prices of a particle order in a vector located in struct data

                    list->LitemPrice.push_back(item);
            }
            else if ((item <=6) && (item >=4))
            {
                item = 15;
        
                list->LitemPrice.push_back(item);
        
            }
            else if ((item <=9) && (item >=7))
            {
                item = 10;
        
                list->LitemPrice.push_back(item);
            }
            else
            {
                item = 12;
        
                list->LitemPrice.push_back(item);
            }
        
            cout << "Would you like to make another order"    << endl;
            cout << "Press Y for yes or anything else for no" << endl;
            cin >> response;

            
        }
        
        
    } while((response == 'y') || (response == 'Y'));
    
    
    
    cout << "Please state how much you would like to contribute to tips" << endl;
    cin  >> tips;
    
    list->Ltips = tips; // stores the tip collected from the user to the struct data in the field Ltips


}

double total()
{
    double sum = 0;
    
     // prints the string in such a way that the output gets manipulated to have a certain length of spacing.
    
       cout << "Total\t\t\t" << setw(3) <<"= $";
    
    
    if(list->counter == 0)  // checks to see how many times the user was prompt to give his/her order.
        return sum;
    
    else
    {
        for(int i = 0; i < list->counter; i++)
            sum += list->Litem.at(i) * list->Lamount.at(i);
        
        sum += list->Ltips + TAX;
        return sum;
    }
}

void receipt()
{
    int number = 0;
    cout << "Thanks for shopping at Garbin Restaurant" << endl;
    cout <<  " ---------------------RECEIPT---------------------"  << endl;
    if(list->counter == 0)
        cout<< "You havent made a selection as yet your total is $0" << endl << endl;
    else
    {
        for(int i = 0; i< list->counter; i++)
            cout << list->Lamount.at(i) << " orders of #" << list->Litem.at(i) << setw(3) << "  = $" << list->LitemPrice.at(i)*list->Lamount.at(i) << endl;
        
        cout << total() <<endl;
       
    }
     display(number);   // displays the main menu to the screen after the receipt have been printed
    
}

void complaint()
{
    char response = 'y';
    string problem, solution;
    int number;
    
    do
    {
        cout << "What seems to be the problem?" << endl;
        cin.ignore();
        getline(cin,problem);
        
        cout << "I am sorry to hear that how may I help" << endl;
        getline(cin,solution);
        cout << "Okay so your complaint is " << problem << " and your solution is " << solution << " ?" << endl;
        cout << "Press y for yes or n to make your complaint clear." << endl;
        cin >> response;
        if((response == 'y') || (response == 'Y'))
        {
            cout << "Okay I will make sure my manger hear about this, again I am really sorry and I hope to see you again"    << endl;
            display(number);
        }
       
    }while((response == 'n' )|| (response == 'N'));
    
   
}

