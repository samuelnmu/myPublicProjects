#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function prototypes
double evaluateExpression(const char *expression);
double factorial(int n);
double performOperation(char operator, double operand1, double operand2);
int isOperator(char c);
int precedence(char operator);

// Main function
int main()
{
    // Output the HTTP header
    printf("Content-Type: text/html\n\n");

    // Start the HTML content
    printf("<html><head><title>Calculator in C</title></head><body>\n");
    printf("<h1>Calculator in C</h1>\n");

    char expression[256];
    printf("Enter your calculation: ");
    fgets(expression, 256, stdin); // Get input from user

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    // Evaluate the expression
    double result = evaluateExpression(expression);
    printf("<p>Result: %.2f</p>\n", result); // Output result in HTML

    printf("</body></html>\n");

    return 0;
}

// Function to evaluate a mathematical expression
double evaluateExpression(const char *expression)
{
    // A very basic implementation to evaluate simple expressions.
    // For complex parsing, consider using stacks or an expression parser.

    char operator;
    double operand1, operand2;
    if (sscanf(expression, "%lf %c %lf", &operand1, &operator, & operand2) == 3)
    {
        return performOperation(operator, operand1, operand2);
    }
    else if (strstr(expression, "sin"))
    {
        sscanf(expression, "sin(%lf)", &operand1);
        return sin(operand1 * M_PI / 180.0); // Convert to radians
    }
    else if (strstr(expression, "cos"))
    {
        sscanf(expression, "cos(%lf)", &operand1);
        return cos(operand1 * M_PI / 180.0);
    }
    else if (strstr(expression, "tan"))
    {
        sscanf(expression, "tan(%lf)", &operand1);
        return tan(operand1 * M_PI / 180.0);
    }
    else if (strstr(expression, "!"))
    {
        sscanf(expression, "%lf!", &operand1);
        return factorial((int)operand1);
    }
    else
    {
        printf("Invalid input!\n");
        return 0;
    }
}

// Function to perform basic arithmetic operations
double performOperation(char operator, double operand1, double operand2)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0)
        {
            printf("Error: Division by zero!\n");
            return 0;
        }
        return operand1 / operand2;
    default:
        printf("Unsupported operator: %c\n", operator);
        return 0;
    }
}

// Function to calculate factorial
double factorial(int n)
{
    if (n < 0)
    {
        printf("Error: Factorial of a negative number is undefined.\n");
        return 0;
    }
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Helper functions (if needed)
// Check if a character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Get precedence of operators (for complex expressions, not used here)
int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
