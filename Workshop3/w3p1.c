/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    //Product Price
    const double product1 = 111.49;
    const double product2 = 222.99;
    const double product3 = 334.49;

    //Product ID
    const int id1 = 111;
    const int id2 = 222;
    const int id3 = 111;

    //Product tax
    const char p1Tax = 'Y';
    const char p2Tax = 'N';
    const char p3Tax = 'N';

    //Average price
    double averagePrice = ((product1 + product2 + product3) / 3);

    //Product Info Chart  
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", id1);
    printf("  Taxed: %c\n", p1Tax);
    printf("  Price: $%.4lf\n\n", product1);

    printf("Product-2 (ID:%d)\n", id2);
    printf("  Taxed: %c\n", p2Tax);
    printf("  Price: $%.4lf\n\n", product2);

    printf("Product-3 (ID:%d)\n", id3);
    printf("  Taxed: %c\n", p2Tax);
    printf("  Price: $%.4lf\n\n", product3);

    printf("The average of all prices is: $%.4lf\n\n", averagePrice);

    // TRUE = 1 FALSE = 0
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", p1Tax == 'Y');

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", p2Tax && p3Tax != 'Y');

    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, product3 < testValue);
    //p3 is greater than p2+p1
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", product3 > (product1 + product2));
    //p1 equal or more than (p3-p2)
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", product1 >= (product3 - product2), (product3-product2));

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", product2 >= averagePrice);
    //Id1 does not equal id2,3
    printf("7. Based on product ID, product 1 is unique -> %d\n\n",(id1 != id2) && (id1 != id3));
    //id2 does not equal id1,3
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (id2 != id1) && (id2 != id3));
    //id3 does not equal id1,2
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (id3 != id1) && (id3 != id2));

    return 0;
}