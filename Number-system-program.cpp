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
int getRandomNumber() {
    static int counter = 17;  // Start with 17
    counter = counter + 7;    // Add 7 each time to keep the values changing
    if (counter > 200) {      // Condition to protect against giant values
        counter = counter - 150;  // Make it smaller
    }
    return (counter % 100);   // limit it t between 0-99
}
#include <iostream>

using namespace std;

// COMMIT 1: Core decimal to binary conversion function
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

// COMMIT 2: Binary to decimal conversion function
// Function 2: Convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int multiplier = 1;  // Start with 1 (which is 2^0)
    
    // Go from right to left through the binary string
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal = decimal + multiplier;
        }
        multiplier = multiplier * 2;  // Next power of 2
    }
    
    return decimal;
}

// COMMIT 3: Hexadecimal conversion functions
// Function 3: Convert decimal to hexadecimal
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

// Function 4: Convert hexadecimal to decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int multiplier = 1;  // Start with 1 (which is 16^0)
    
    // Go from right to left through the hex string
    for (int i = hex.length() - 1; i >= 0; i--) {
        int digitValue;
        
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

// COMMIT 4: Random number generator and demo functionality
// Very simple random number generator
int getRandomNumber() {
    static int counter = 17;  // Start with some number
    counter = counter + 7;    // Add 7 each time
    if (counter > 200) {      // If it gets too big
        counter = counter - 150;  // Make it smaller
    }
    return (counter % 100);   // Keep it between 0-99
}

// Function to display the menu
void showMenu() {
    cout << "\n=== Number Converter Program ===" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Binary to Decimal" << endl;
    cout << "3. Convert Decimal to Hexadecimal" << endl;
    cout << "4. Convert Hexadecimal to Decimal" << endl;
    cout << "5. Demo (Generate and convert random integers to binary)" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    cout << "Welcome to Number Converter!" << endl;
    
    // Main program loop
    while (true) {
        showMenu();
        cin >> choice;
        
        if (choice == 1) {
            // Decimal to Binary
            int number;
            cout << "Enter decimal number: ";
            cin >> number;
            cout << "Binary: " << decimalToBinary(number) << endl;
            
        } else if (choice == 2) {
            // Binary to Decimal
            string binary;
            cout << "Enter binary number: ";
            cin >> binary;
            cout << "Decimal: " << binaryToDecimal(binary) << endl;
            
        } else if (choice == 3) {
            // Decimal to Hexadecimal
            int number;
            cout << "Enter decimal number: ";
            cin >> number;
            cout << "Hexadecimal: " << decimalToHexadecimal(number) << endl;
            
        } else if (choice == 4) {
            // Hexadecimal to Decimal
            string hex;
            cout << "Enter hexadecimal number: ";
            cin >> hex;
            cout << "Decimal: " << hexadecimalToDecimal(hex) << endl;
            
        } else if (choice == 5) {
            // Demo with random number
            int randomNum = getRandomNumber();
            cout << "Random number: " << randomNum << endl;
            cout << "In binary: " << decimalToBinary(randomNum) << endl;
            
        } else if (choice == 6) {
            // Exit
            cout << "Goodbye!" << endl;
            break;
            
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
        
        // Simple pause
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}
