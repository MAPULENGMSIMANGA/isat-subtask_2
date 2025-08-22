#include <iostream>

using namespace std;


// Function 1: Convert decimal to binary
string decimalToBinary(int decimal) {
    // Handle special case of 0
    if (decimal == 0) {
        return "0";
    }
    
    string binary = "";
    
    // Keep dividing by 2 and add remainders to front
    while (decimal > 0) {
        int remainder = decimal % 2;  // Get remainder (0 or 1)
        if (remainder == 0) {
            binary = "0" + binary;
        } else {
            binary = "1" + binary;
        }
        decimal = decimal / 2;  // Divide by 2
    }
    
    return binary;
}
int binaryToDecimal(string binary) {
    int decimal = 0;
    int multiplier = 1;  // Start with 1 (which is 2^0)
    
    // Go from right to left in the binary string
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal = decimal + multiplier;
        }
        multiplier = multiplier * 2;  // Next power of 2
    }
    
    return decimal;
}
