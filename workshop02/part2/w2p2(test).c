#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) 
{
	const double TAX = 0.13;
	const char patSize = 'S', salSize = 'M', tomSize = 'L';
	float Small, Medium, Large, toonie, loonie, quarter, dimes, nickels, pennies;
	int Quantity, Quantity2, Quantity3 , subTotal, subTotal2, subTotal3, Taxes, Taxes2, Taxes3, Total, Total2, Total3, SubTotal, Tax, ToTal, Toonies, Loonies, Quaters, Dimes, Nickels, Pennies;



	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf(" %f", &Small);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf(" %f", &Medium);
	printf("Enter the price for a LARGE shirt: $");
	scanf(" %f", &Large);
	printf("\n");

	printf("Shirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf", Small);
	printf("\n");
	printf("MEDIUM : $%.2f", Medium);
	printf("\n");
	printf("LARGE  : $%.2f", Large);
	printf("\n\n");

	printf("Patty's shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &Quantity);
	printf("\n");

	printf("Tommy's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &Quantity2);
	printf("\n");

	printf("Sally's shirt size is '%c'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &Quantity3);
	printf("\n");
	
	printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	subTotal = (Small +0.001 ) * 100 * Quantity ;
	Taxes = (Small + 0.002) * 100 * Quantity * TAX;
	Total = (Small + 0.001) * 100 * Quantity + Taxes;
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, Small, Quantity, (double)subTotal / 100, (double)Taxes / 100, (double)Total / 100);

	subTotal2 = (Medium + 0.001) * 100 * Quantity3;
	Taxes2 = (Medium + 0.002) * 100 * Quantity3 * TAX;
	Total2 = (Medium + 0.005) * 100 * Quantity3 + Taxes;
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, Medium, Quantity3, (double)subTotal2 / 100, (double)Taxes2 / 100, (double)Total2 / 100);

	subTotal3 = (Large + 0.001) * 100 * Quantity2;
	Taxes3 = (Large + 0.005) * 100 * Quantity2 * TAX;
	Total3 = (Large + 0.001) * 100 * Quantity2 + Taxes3;
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",	tomSize, Large, Quantity2, (double)subTotal3 / 100, (double)Taxes3 / 100, (double)Total3 / 100);

	printf("-------- ---- ----- --- --------- --------- ---------\n");
	SubTotal = (subTotal + subTotal2 + subTotal3);
	Tax = (Taxes + Taxes2 + Taxes3);
	ToTal = (Total + Total2 + Total3);
	printf("%33.4lf %9.4lf %9.4lf\n\n", (double)SubTotal /100, (double)Tax /100, (double)ToTal /100);

	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n\n");

	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	SubTotal = (subTotal + subTotal2 + subTotal3);
	printf("%22.4lf\n", (double)SubTotal / 100);

	Toonies = (double)(subTotal + subTotal2 + subTotal3) / 200;
	toonie = (subTotal + subTotal2 + subTotal3) % 200;
	printf("Toonies  %3d %9.4lf\n", Toonies, toonie / 100);

	Loonies = toonie / 100;
	loonie = (int)toonie % 100;
	printf("Loonies  %3d %9.4lf\n", Loonies, loonie / 100);

	Quaters = loonie / 25;
	quarter = (int)loonie % (int)(25);
	printf("Quarters %3d %9.4lf\n", Quaters, quarter / 100);

	Dimes = quarter / 10;
	dimes = (int)quarter % (int)(10);
	printf("Dimes    %3d %9.4lf\n", Dimes, dimes / 100);

	Nickels = dimes / 5;
	nickels = (int)dimes % (int)(5);
	printf("Nickels  %3d %9.4lf\n", Nickels, nickels / 100);
	
	Pennies = nickels / 1;
	pennies = (int)nickels % (int)(1);
	printf("Pennies  %3d %9.4lf\n\n", Pennies, pennies / 100);

	printf("Average cost/shirt: $%0.4f\n\n", (subTotal + subTotal2 + subTotal3) / (float)(Quantity + Quantity2 + Quantity3) / 100);

	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", (double)(Total + Total2 + Total3) / 100);
	Toonies = (double)(Total + Total2 + Total3) / 200;
	toonie = (Total + Total2 + Total3) % 200;
	printf("Toonies  %3d %9.4lf\n", Toonies, toonie / 100);
	Loonies = toonie / 100;
	loonie = (int)toonie % 100;
	printf("Loonies  %3d %9.4lf\n", Loonies, loonie / 100);
	Quaters = loonie / 25;
	quarter = (int)loonie % (int)(25);
	printf("Quarters %3d %9.4lf\n", Quaters, quarter / 100);
	Dimes = quarter / 10;
	dimes = (int)quarter % (int)(10);
	printf("Dimes    %3d %9.4lf\n", Dimes, dimes / 100);
	Nickels = dimes / 5;
	nickels = (int)dimes % (int)(5);
	printf("Nickels  %3d %9.4lf\n", Nickels, nickels / 100);
	Pennies = nickels / 1;
	pennies = (int)nickels % (int)(1);
	printf("Pennies  %3d %9.4lf\n\n", Pennies, pennies / 100);

	printf("Average cost/shirt: $%0.4f\n", (Total + Total2 + Total3) / (float)(Quantity + Quantity2 + Quantity3) / 100);

	return 0;
}