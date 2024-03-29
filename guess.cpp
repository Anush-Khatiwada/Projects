#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include<conio.h>
using namespace std;
 
void drawLine(int n, char symbol);
void rules();
 
int main()
{
    string playerName;
    int amount; 
    int bettingAmount; 
    int guess;
    int dice; 
    int count=0;
    char choice;
 
    srand(time(0)); 

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
    cout<<"\n\n Welcome "<<playerName<<" to our number guessing game"<<endl;
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> amount;
    
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";
        int count;
		
		
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
            count++;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "Sorry!"<<playerName<<" You have lost all your money";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout<<"\n\n You have won "<<count<<" times,comeback again to test your luck"<<endl;
    cout << "\n\n Exiting......... \n\n"<<endl;
    getch();
    drawLine(70,'=');
    
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
 