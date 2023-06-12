#include <stdio.h>

char green[] = "\033[0;32m";
char red[] = "\033[0;31m";
char yellow[] = "\033[0;33m";
char blue[] = "\033[0;34m";
char reset[] = "\033[0m";



int calculator() {
  printf("%s%s%s\n", yellow, "Welcome to the calculator\n", reset);
  printf("%s%s%s\n", blue, "1. Add", reset);
  printf("%s%s%s\n", blue, "2. Subtract", reset);
  printf("%s%s%s\n", blue, "3. Multiply", reset);
  printf("%s%s%s\n", blue, "4. Divide", reset);
  printf("%s%s%s\n", blue, "5. Exit\n", reset);
  printf("%s%s%s\n", yellow, "Enter your choice: ", reset);
  int choice;
  scanf("%d", &choice);

  return choice;
}


int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int main() {
  while (1) { 
  int choice = calculator();

  if (choice == 5) {
    printf("%s%s%s\n", red, "Exiting...", reset);
    return 0;
  }

  int a, b;
  printf("%s%s%s\n", yellow, "Enter first number: ", reset);
  scanf("%d", &a);
  printf("%s%s%s\n", yellow, "Enter second number: ", reset);
  scanf("%d", &b);

  int result;

  switch (choice) {
  case 1:
    result = add(a, b);
    break;
  case 2:
    result = subtract(a, b);
    break;
  case 3:
    result = multiply(a, b);
    break;
  case 4:
    result = divide(a, b);
    break;
  default:
    printf("%s%s%s\n", red, "Invalid choice", reset);
    return 1;
  }

  printf("%s%s%d%s%d%s%d%s\n", green, "Result of ", a, " and ", b, " is ", result, reset);
  }
  
}



