#include <iostream>
#include <string>

using namespace std;

// Function Prototype
bool isCardValid(int digits[], int size);

int main() {
    const int SIZE = 8;
    int digits[SIZE];
    string input;

    while (true) {
        cout << "Enter 8-digit credit card # or Q to quit: ";
        cin >> input;

        if (input == "Q" || input == "q") {
            break;
        }

        // Convert input to an integer as specified
        int cardNumber = stoi(input);

        // Extract digits from right to left into the array
        for (int i = SIZE - 1; i >= 0; i--) {
            digits[i] = cardNumber % 10;
            cardNumber /= 10;
        }

        if (isCardValid(digits, SIZE)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }

    return 0;
}

bool isCardValid(int digits[], int size) {
    int sumUnchanged = 0;
    int sumDoubled = 0;

    // Traverse from right to left
    for (int i = size - 1; i >= 0; i--) {
        int positionFromRight = (size - 1) - i;

        if (positionFromRight % 2 == 0) {
            // Every other digit starting from the rightmost
            sumUnchanged += digits[i];
        }
        else {
            // Remaining digits: double and sum their individual digits
            int doubled = digits[i] * 2;
            sumDoubled += (doubled / 10) + (doubled % 10);
        }
    }

    int totalSum = sumUnchanged + sumDoubled;
    return (totalSum % 10 == 0);
}