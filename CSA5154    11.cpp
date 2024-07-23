#include <stdio.h>

int main() {
    int n = 25; // Total number of positions in the Playfair matrix
    unsigned long long int possible_keys = 1; // Using unsigned long long int to handle large numbers

    // Calculate factorial 25 (25!)
    for (int i = 1; i <= n; i++) {
        possible_keys *= i;
    }

    // Print the approximate number of possible keys without considering key uniqueness
    printf("Approximate number of possible keys (without considering uniqueness): %llu\n", possible_keys);

    // Estimate the number of effectively unique keys considering symmetry
    // This is a rough estimation based on typical analysis of Playfair cipher key space
    unsigned long long int unique_keys_estimate = 1e13; // This can vary, usually between 10^13 to 10^14

    printf("Approximate number of effectively unique keys: %llu\n", unique_keys_estimate);

    return 0;
}

