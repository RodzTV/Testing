#include <stdio.h>
#define LABOR_COST 0.35
#define TAX_RATE 0.085

int readDataLength(void);
int readDataWidth(void);
double readDataDiscount(void);
double readDataCost(void);
double calculateInstalledPrice(int length, int width, double cost);
double calculateSubtotal(double installed_price, double discount);
double calculateTotalPrice(double subtotal, double tax);
void printMeasurements(int length, int width);
void printCharges(double cost, double labor, double installed_price, double discount, double subtotal, double tax, double total_price, double area_cost);
void printBox1(void);
void printBox2(int number, int length, int width, double discount, double cost);

int main(void)
{
    int length, width, number;
    double cost, labor, discount, installed_price, subtotal, tax, total_price, carpet_cost, area_cost;

    length = readDataLength();
    width = readDataWidth();
    discount = readDataDiscount();
    cost = readDataCost();

    installed_price = calculateInstalledPrice(length, width, cost);
    labor = LABOR_COST * (length * width);
    subtotal = calculateSubtotal(installed_price, discount);
    tax = subtotal * TAX_RATE;
    total_price = calculateTotalPrice(subtotal, tax);
    carpet_cost = cost * (length * width); 
    area_cost = cost * (length * width);  
    
    printMeasurements(length, width);
    printCharges(cost, labor, installed_price, discount, subtotal, tax, total_price, area_cost);

    printBox1();
    number = 1;
    printBox2(number, length, width, discount, cost);

    return 0;
}
// Function to read the length of the carpet
int readDataLength(void)
{
    int value;
    printf("Enter the Length: ");
    scanf("%d", &value);
    return value;
}

// Function to read the width of the carpet
int readDataWidth(void)
{
    int value;
    printf("Enter the width: ");
    scanf("%d", &value);
    return value;
}

// Function to read the discount percentage
double readDataDiscount(void)
{
    double value;
    printf("Enter discount (percent): ");
    scanf("%lf", &value);
    return value;
}

// Function to read the cost per square foot
double readDataCost(void)
{
    double value;
    printf("Enter cost per square foot: ");
    scanf("%lf", &value);
    return value;
}

// Function to calculate the installed price of the carpet
double calculateInstalledPrice(int length, int width, double cost)
{
    double area = length * width;
    double carpet_cost = cost * area;
    double labor = LABOR_COST * area;
    return carpet_cost + labor;
}

// Function to calculate the subtotal after applying the discount
double calculateSubtotal(double installed_price, double discount)
{
    return installed_price - (installed_price * discount / 100.0);
}
// Function to calculate the total price including tax
double calculateTotalPrice(double subtotal, double tax)
{
    return subtotal + tax;
}

// Function to print the carpet measurements
void printMeasurements(int length, int width)
{
    printf("\n");
    printf("\tMEASUREMENT\n");
    printf("Length\t\t\t\t%d ft\n", length);
    printf("Width\t\t\t\t%d ft\n", width);
    printf("Area\t\t\t\t%d square ft\n", length * width);
}

// Function to print the charges and the bill details
void printCharges(double cost, double labor, double installed_price, double discount, double subtotal, double tax, double total_price, double area_cost)
{
    printf("\n");
    printf("\t\tCHARGES\n");
    printf("\n");
    printf("DESCRIPTION\t COST/SQ.FT.\tCHARGE\n");
    printf("----------\t--------------\t------------\n");
    printf("Carpet\t\t%.2lf\t\t$%.2lf\n", cost, area_cost);  // Print area times carpet cost
    printf("Labor\t\t0.35\t\t$%.2lf\n", labor);
    printf("INSTALLED PRICE\t\t\t$%.2lf\n", installed_price);
    printf("Discount\t%.2lf%%\n", discount);
    printf("SUBTOTAL\t\t\t$%.2lf\n", subtotal);
    printf("Tax$\t\t\t\t$%.2lf\n", tax);
    printf("TOTAL\t\t\t\t$%.2lf\n", total_price);
}

// Function to print the first part of the bill box
void printBox1(void)
{
    printf("\n _____________________________________________________________________________\n");
    printf("|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("|\ttest\t|\tlength\t|\twidth\t|   discount     |    cost      |\n");
    printf("|_______________|_______________|_______________|_______________|_______________|\n");
}   
// Function to print the second part of the bill box using provided values
void printBox2(int number, int length, int width, double discount, double cost)
{
    printf("\n");
    printf("_________________________________________________________________________________\n");
    printf("|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("|\t%d\t|\t%d\t|\t%d\t|\t%.2lf\t|\t%.2lf\t|\n", number, length, width, discount, cost);
    printf("|_______________|_______________|_______________|_______________|_______________|\n");
}