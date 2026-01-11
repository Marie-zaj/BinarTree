#include "TrafficDatabase.h"
int main()
{
    TrafficDatabase db;

    db.addTicket("AA1234BB", "Speeding");
    db.addTicket("AA1234BB", "Red light");
    db.addTicket("BC5678CC", "No seatbelt");
    db.addTicket("AB0001AA", "Wrong parking");
    db.addTicket("AC9999DD", "Speeding");

    db.printAll();

    db.printByNumber("AA1234BB");

    db.printByRange("AB0000AA", "AC9999ZZ");

    return 0;
}
