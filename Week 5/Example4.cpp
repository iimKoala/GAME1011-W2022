//// This program demonstrates the SimpleVector template.
//#include <iostream>
//#include "SimpleVector.h"
//using namespace std;
//
//int main()
//{
//    const int SIZE = 10; // Number of elements
//    int amtToPrnt = 10;
//    int count; // Loop counter
//
//// Create a SimpleVector of ints.
//    SimpleVector<int> intTable(SIZE);
//
//    // Store values in the two SimpleVectors.
//    for (count = 0; count < SIZE; count++)
//    {
//        intTable[count] = (count * 2);
//    }
//
//    // Display the values in the SimpleVectors.
//    cout << "These values are in intTable:\n";
//    for (count = 0; count < amtToPrnt; count++)
//        cout << intTable[count] << " ";
//    cout << endl;
//
//    intTable.push_back(20);
//    amtToPrnt++;
//
//    cout << "These values are in intTable after adding one more value:\n";
//    for (count = 0; count < amtToPrnt; count++)
//        cout << intTable[count] << " ";
//    cout << endl;
//
//
//
//
//
//    cout << "These values are in intTable:\n";
//    for (count = 0; count < amtToPrnt; count++)
//        cout << intTable[count] << " ";
//    cout << endl;
//
//    intTable.pop_back(20);
//    amtToPrnt--;
//
//    cout << "These values are in intTable after removing one more value:\n";
//    for (count = 0; count < amtToPrnt; count++)
//        cout << intTable[count] << " ";
//    cout << endl;
//
//
//
//    
//    
//     
//    return 0;
//}