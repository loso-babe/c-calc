#include <stdio.h>
#include <math.h>

// funtion prototyping
double calculate(double num1, double num2, double num3, int operator);
void factorial(double num1);
void quadratic(double num1, double num2, double num3);

int current_result_state = 0;
int num2_not_needed_state = 0;
int num3_needed_state = 0;

int main()
{

    double num1, num2;
    double num3 = 0;
    int operator;

    printf("Simple Calulator\n");
    printf("Choose opertor::\n");
    printf("1 -> Addition\n");
    printf("2 -> Subtraction\n");
    printf("3 -> Multiply\n");
    printf("4 -> Division\n");
    printf("5 -> Square\n");
    printf("6 -> Cube\n");
    printf("7 -> Power\n");
    printf("8 -> Factorial\n");
    printf("9 -> Quadratic Roots\n");

    printf("Operator >> ");
    scanf("%d", &operator);

    switch (operator)
    {
    case 5:
        num2_not_needed_state = 1;
        break;
    case 6:
        num2_not_needed_state = 1;
        break;
    case 8:
        num2_not_needed_state = 1;
        break;
    case 9:
        printf("num1 is x^2 coefficient and num2 is x coefficient and num3 is constant term\n");
        num3_needed_state = 1;
        current_result_state = 1;
        break;

    default:
        break;
    }

    printf("Num1 >> ");
    scanf("%lf", &num1);

    if (num2_not_needed_state == 0)
    {
        printf("Num2 >> ");
        scanf("%lf", &num2);
    }


    if (num3_needed_state == 1)
    {
        printf("Enter the constant term >> ");
        scanf("%lf", &num3);
    }

    double result = calculate(num1, num2, num3 , operator);

    if (current_result_state == 0)
    {
        printf("Result ->> %f\n", result);
    }

    return 0;
}

double calculate(double num1, double num2,double num3 ,int operator)
{
    double result;

    switch (operator)
    {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        result = num1 / num2;
        break;
    case 5:
        result = num1 * num1;
        break;
    case 6:
        result = pow(num1, 3);
        break;
    case 7:
        result = pow(num1, num2);
        break;
    case 8:
        num2_not_needed_state = 1;
        current_result_state = 1;
        factorial(num1);
        break;
    case 9:
        quadratic(num1 , num2 , num3);
        break;

    default:
        printf("INVALID operator >> %d", operator);
        break;
    }

    return result;
}

double temp = 1;

void factorial(double num1)
{
    // using the recursion for factorial
    temp *= num1;

    if (num1 == 1)
    {
        printf("Result -> %lf", temp);
        return;
    }
    factorial(num1 - 1);
}

void quadratic(double num1, double num2, double num3)
{
    double temp;
    double root1, root2;
    float x = 0.5;
    float y = 2 * num1;

    temp = pow((pow(num2, 2) - 4 * num1 * num3), x);

    root1 = (-num2 + temp) / y;
    root2 = (-num2 - temp) / y;

    printf("Root1 is -> %lf \nRoot2 is -> %lf\n", root1, root2);
}
