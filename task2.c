#include <stdio.h>
#include <ctype.h>

// Convert input temperature to Celsius (used internally for categorization)
double toCelsius(double value, char scale) {
    switch (scale) {
        case 'C':
            return value;
        case 'F':
            return (value - 32.0) * 5.0 / 9.0;
        case 'K':
            return value - 273.15;
        default:
            return 0.0;
    }
}

// Convert a Celsius value to the desired target scale
double fromCelsius(double celsius, char scale) {
    switch (scale) {
        case 'C':
            return celsius;
        case 'F':
            return (celsius * 9.0 / 5.0) + 32.0;
        case 'K':
            return celsius + 273.15;
        default:
            return 0.0;
    }
}

// Categorize based on the Celsius value and print category + advisory
void categorize(double celsiusValue, char *category, char *advisory) {
    if (celsiusValue < 0) {
        sprintf(category, "Freezing");
        sprintf(advisory, "Wear a heavy coat and stay warm!");
    } else if (celsiusValue < 10) {
        sprintf(category, "Cold");
        sprintf(advisory, "Wear a jacket.");
    } else if (celsiusValue < 25) {
        sprintf(category, "Comfortable");
        sprintf(advisory, "Enjoy the nice weather!");
    } else if (celsiusValue < 35) {
        sprintf(category, "Hot");
        sprintf(advisory, "Drink lots of water!");
    } else {
        sprintf(category, "Extreme Heat");
        sprintf(advisory, "Stay indoors and stay hydrated!");
    }
}

int main() {
    double value, converted, celsiusEquivalent;
    char originalScale, targetScale;
    char category[20];
    char advisory[50];

    // Get temperature value
    printf("Enter the temperature value: ");
    scanf("%lf", &value);

    // Get original scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);
    originalScale = toupper(originalScale);

    // Get target scale
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);
    targetScale = toupper(targetScale);

    // Validate input scales
    if ((originalScale != 'C' && originalScale != 'F' && originalScale != 'K') ||
        (targetScale != 'C' && targetScale != 'F' && targetScale != 'K')) {
        printf("Invalid scale entered. Please use C, F, or K.\n");
        return 1;
    }

    // Convert original -> Celsius -> target
    celsiusEquivalent = toCelsius(value, originalScale);
    converted = fromCelsius(celsiusEquivalent, targetScale);

    // Display converted temperature
    printf("Converted temperature: %.2f %c\n", converted, targetScale);

    // Categorize based on the Celsius equivalent (category ranges are in Celsius)
    categorize(celsiusEquivalent, category, advisory);

    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}