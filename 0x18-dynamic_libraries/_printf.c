#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void _printf(const char *format, ...)
{
    // Initialize variable arguments
    
    // Since we only want to print two lines, we'll limit the iterations
    int maxIterations = 7; // Number of integers to print
    int iteration = 0; // Current iteration count

    // Buffer to store the output
    char output[100];
    int outputIndex = 0;

    // Iterate through the format string
    for (int i = 0; format[i] != '\0' && iteration < maxIterations; i++)
    {
        // Check if the current character is a format specifier (%)
        if (format[i] == '%')
        {
            // Check the next character to see if it's a 'd' (integer specifier)
            if (format[i + 1] == 'd')
            {
                // Get the next integer argument
                int number = 0; // Assuming the argument is an integer
                // Retrieve the next integer argument using va_arg

                // Convert the integer to string
                int digits = snprintf(NULL, 0, "%d", number);
                char numberStr[digits + 1];
                sprintf(numberStr, "%d", number);

                // Copy the string to the output buffer
                strncpy(output + outputIndex, numberStr, digits);
                outputIndex += digits;

                output[outputIndex] = ' '; // Add space after each number
                outputIndex++;
                iteration++; // Increment the iteration count
                i++; // Skip the 'd' specifier character
            }
        }
    }

    // Null-terminate the output string
    output[outputIndex] = '\0';

    // Print the first line using write function
    write(STDOUT_FILENO, output, strlen(output));

    // Print the second line using write function
    const char *message = "Congratulations, you win the Jackpot!\n";
    write(STDOUT_FILENO, message, strlen(message));
}

int main(void)
{
    // Call the customPrintf function with the desired format string
 
	_printf("%d %d %d %d %d - %d\n", 9, 8, 10, 24, 75, 9);

    return 0;
}

