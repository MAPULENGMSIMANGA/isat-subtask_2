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
string decimalToHexadecimal(int decimal) {
    // Handle special case of 0
    if (decimal == 0) {
        return "0";
    }
    
    string hex = "";
    
    // Keep dividing by 16 and add remainders to front
    while (decimal > 0) {
        int remainder = decimal % 16;
        
        // Convert remainder to hex character
        if (remainder < 10) {
            // For 0-9, just convert to character
            char digit = '0' + remainder;
            hex = digit + hex;
        } else {
            // For 10-15, use A-F
            char letter = 'A' + (remainder - 10);
            hex = letter + hex;
        }
        
        decimal = decimal / 16;  // Divide by 16
    }
    
    return hex;
}
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int multiplier = 1;  // Start with 1 (which is 16^0)
    
    // Go from right to left through the hex string
    for (int i = hex.length() - 1; i >= 0; i--) {
        int digitValue; //indicate data type
        
        // Convert hex character to number value
        if (hex[i] >= '0' && hex[i] <= '9') {
            digitValue = hex[i] - '0';  // For digits 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digitValue = (hex[i] - 'A') + 10;  // For A=10, B=11, etc.
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digitValue = (hex[i] - 'a') + 10;  // For lowercase a=10, b=11, etc.
        }
        
        decimal = decimal + (digitValue * multiplier);
        multiplier = multiplier * 16;  // Next power of 16
    }
    
    return decimal;
}
