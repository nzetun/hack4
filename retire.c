/**
 * Noah Zetocha
 * nzetocha2@unl.edu
 *
 * This program prints an amortization table to track monthly savings in a 401k based on an average rate of return,
 * inflation rate, monthly contribution and number of years until retirement.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    if(argc != 6) {
        fprintf(stderr, "Usage: Starting balance | Monthly contribution | Rate of return | Rate of Inflation | Years until retirement\n");
        exit(1);
    }

    double startBal = atof(argv[1]);
    double monthlyAdd = atof(argv[2]);
    double returnRate = atof(argv[3]);
    double inflateRate = atof(argv[4]);
    int yearToRetire = atoi(argv[5]);

    int i;
    int m = yearToRetire * 12;
    double interest, newBal1, nestEgg, intTotal;
    double adjReturn = (((1 + returnRate) / (1 + inflateRate)) - 1) / 12;         //adjusted interest rate based on inflation rate calculation
    newBal1 = startBal;

    if (monthlyAdd >= 1541.67) {
        printf("Illegal: Monthly contributions exceed $18,500 annual Limit\n");
    } else if (startBal < 0) {
        printf("Error: Illegal Input\n");
    } else {
        printf("\n               401k Table                 \n");
        printf("------------------------------------------\n");
        printf("  Month        Interest          Balance\n");

        for (i=1; i<=m; i++) {
            interest = adjReturn * newBal1;                                             //interest adjusted
            newBal1 = interest + newBal1;                                               //interest added to principle
            newBal1 += monthlyAdd;                                                      //Monthly addition amount added after interest calculated
            intTotal += interest;                                                       //Running total of interest
            printf("     %d      |   $  %.2f    |    $  %.2f\n", i, interest, newBal1);
        }
        nestEgg = newBal1;
        printf("\n  Total Interest Earned :  $  %.2f\n", intTotal);
        printf("  Total Nest Egg:          $  %.2f\n\n", nestEgg);
    }

    return 0;
}