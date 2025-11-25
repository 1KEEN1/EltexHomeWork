#include <stdio.h>

void binary() {
  unsigned int number;
  unsigned int shift = 1 << 31;
  int space = 0;
  printf("Введите положительное целое число: ");
  scanf("%u", &number);
  printf("Двоичное представление %u : ", number);
  while (shift > 0) {
    if (shift & number) {
      printf("1");
      space++;
    } else {
      printf("0");
      space++;
    }

    if (space == 8) {
      printf("  ");
      space = 0;
    }
    shift = shift >> 1;
  }
  printf("\n");
}

void negativeBinary() {
  int number = 1, space = 0;
  unsigned int shift = 1 << 31;
  while (number > 0) {
    printf("Введите отрицательное целое число: ");
    scanf("%d", &number);
  }
  while (shift > 0) {
    if (shift & number) {
      printf("1");
      space++;
    } else {
      printf("0");
      space++;
    }

    if (space == 8) {
      printf("  ");
      space = 0;
    }
    shift = shift >> 1;
  }
  printf("\n");
}

void countBinary() {
  unsigned int number, count = 0, shift = 1 << 31;
  printf("Введите положительное целое число: ");
  scanf("%u", &number);
  while (shift > 0) {
    if (shift & number) {
      count++;
    }
    shift = shift >> 1;
  }
  printf("Количество единиц в двоичном представлении %u : %u\n", number, count);
}

void changeByte() {
  unsigned int number, newByte;
  int mask = 0xFF00FFFF;
  int space = 0;
  unsigned int shift = 1 << 31;

  printf("Введите исходное целое положительное число: ");
  scanf("%u", &number);
  printf("Введите число от 0 до 255: ");
  scanf("%u", &newByte);
  newByte = newByte << 16;
  number = number & mask;
  number = number | newByte;
  while (shift > 0) {
    if (shift & number) {
      printf("1");
      space++;
    } else {
      printf("0");
      space++;
    }

    if (space == 8) {
      printf("  ");
      space = 0;
    }
    shift = shift >> 1;
  }
  printf("\n");
  printf("Число в десятичном виде - %u\n", number);
}

int main() {
  char a;
  printf(" 1. Вывести двоичное представление целого положительного числа, "
         "используя битовые операции (число вводится с клавиатуры).\n 2. "
         "Вывести двоичное представление целого отрицательного числа, "
         "используя битовые операции (число вводится с клавиатуры).\n 3. Найти "
         "количество единиц в двоичном представлении целого "
         "положительного числа (число вводится с клавиатуры).\n 4. Поменять в "
         "целом положительном числе (типа int) значение третьего "
         "байта на введенное пользователем число (изначальное число также "
         "вводится с клавиатуры).\n -------------------------\n Напишите цифру "
         "соответствующего задания\n");

  scanf("%c", &a);

  switch (a) {
  case '1':
    binary();
    break;
  case '2':
    negativeBinary();
    break;
  case '3':
    countBinary();
    break;
  case '4':
    changeByte();
    break;

  default:
    break;
  }
  return 0;
}