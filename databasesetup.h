#ifndef DATABASESETUP_H
#define DATABASESETUP_H


#include "nationalparks.h"
#include "parks.h"
#include "customer.h"

const int SEED_CUSTOMER_COUNT = 11;

// Original data for customer list
const Customer SEED_CUSTOMERS[SEED_CUSTOMER_COUNT] = {
    Customer("Acadia", "Maine", 3437286,49076.63),
    Customer("Badlands", "South Dakota", 970998, 242755.94),
    Customer("Bryce Canyon", "Utah", 2594904, 35835.08),
    Customer("Everglades", "Florida", 1118300, 1508938.57),
    Customer("Glacier", "Montana", 3049839, 1013125.99),
    Customer("Great Smokey Mountain", "North Carolina", 12547743, 522426.88),
    Customer("Mount Rainer", "Washington ", 1501621, 236807.25),
    Customer("Rocky Mountain", "Colorado", 4670053, 265807.25),
    Customer("Yellowstone", "Wyoming", 4422861, 2219790.71),
    Customer("Yosemite", "California", 4020288, 761747.50),
    Customer("Zion", "Utah", 4488268, 147242.66)};


void setupDB();
void addDBEntry();
#endif // DATABASESETUP_H
