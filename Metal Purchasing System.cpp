#include<iostream>
#include<iomanip>

using namespace std;

int main() {

//Declare Variables
   int again = 0, interaction, itNum = 0, purchasedMetals[4];
   string metal[4] = {"Zinc", "Iron", "Gold", "Silver"}, names[3], line[4], space = "              ";
   float ounces[4] = {}, price[4] = {43.97, 15.34, 146.23, 82.33}, salesTax = 0.825, totalB4Tax, total, amount;
   
   //for storage
   int metalName[4];
   float totalPurchased[4], totalSpent[4];
   
   
   //Get Salesperson and customer name
   cout << "Please enter the salesperson's first and last name: \n";
   cin >> names[1];
   cin >> names[2];
   names[0] = names[1] + " " + names[2];
   
   cout << "Please enter the customer's first and last name: \n";
   cin >> names[1];
   cin >> names[2];
   names[1] = names[1] + " " + names[2];
   

   do {
            
      //Output menu
      cout << fixed << setprecision(2);
      cout << "\nEnter number corresponding with metal type purchased.\n";
      for(int i = 0; i < 4; i++) {
      
         //Checks if metal type has already been purchased
         if(purchasedMetals[i] != 1) {
            cout << "(" << i << ")" << metal[i] << space << "$" << price[i] << "/ounce" << endl;
         }
      }
      
      cin >> interaction;
      metalName[itNum] = interaction;
      purchasedMetals[interaction] = 1;
      
      cout << fixed << setprecision(1);
      cout << "Enter purchased amount in ounces: \n";
      cin >> amount;
      totalPurchased[itNum] = amount;
      
      totalB4Tax = amount * price[interaction];
      totalSpent[itNum] = totalB4Tax;
      
      cout << fixed << setprecision(1) << "\nSuccessfully logged a purchase of:\n" << totalPurchased[itNum] << "oz of " << metal[interaction]; 
      cout << fixed << setprecision(2) << ", at $" << price[interaction] << "/oz for a total of $" << totalSpent[itNum] << endl;
      
      cout << "\n(1)Add another product (2)Finish Transaction\n";
      cin >> interaction;
      
      if(interaction == 2) {
         again = 1;
         
         //Print receipt
         cout << "\nCustomer: " << names[1] << space << " Salesperson: " << names[0] << endl;
         cout << "--------------------------------------------------------------------" << endl;
         cout << "Ounces     |     Metal Type     |     Price/oz     |     Cost" << endl;
         
         for(int i = 0; i <= itNum; i++) {
            //Print Ounces
            cout << fixed << setprecision(1) << totalPurchased[i] << space;
            
            //Print Metal Type
            cout << metal[metalName[i]] << space;
            
            //Print Price/oz
            cout << fixed << setprecision(2) << "$" <<  price[metalName[i]] << space;
            
            //Print Cost
            cout << fixed << setprecision(2) << "$" << totalSpent[i] << endl;
            
            total += totalSpent[i];
         }
         
         cout << "--------------------------------------------------------------------" << endl;
            cout << fixed << setprecision(3);
            
            //Calculate Sales Tax
            float tax = total * salesTax;
            cout << fixed << setprecision(2) << "Sales Tax: $" << tax << endl;
            
            cout << "--------------------------------------------------------------------" << endl;
            
            //Display Total
            cout << "Sales Total: $" << total + tax << endl;
      }
      else {
         itNum++;
      }
   
   } while(again == 0);
   
   return 0;
}