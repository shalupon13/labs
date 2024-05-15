#include "lr.h"
#define maxWord (4096)
#define maxString (4096)
#define ARRAY_SIZE (10)
#define N (3)
#define K (10)
#define QSORT_ARRAY_SIZE (16)
#define QSORT_ARRAY_SIZE_X (3)
#define QSORT_ARRAY_SIZE_Y (3)

void lab1()
{
        float A, B, C, P; 
    printf("Input A:"); 
    if (scanf("%f", &A) != 1) 
    { 
        printf("Error"); 
    } 
    printf("Input B:"); 
    if (scanf("%f", &B) != 1) 
    { 
        printf("Error"); 
    } 
    printf("Input C:"); 
    if (scanf("%f", &C) != 1) 
    { 
        printf("Error"); 
    } 
    P = (A + B*B)/(C - A); 
    printf("\nResult: %.2f", P); 

}


void lab2()
{
     float s, a, n, i, eps;
    int sign;
    printf("eps=");
    scanf ("%f", &eps);
    s=0;
    sign=1;
    i=1;
    n=1;
    a= (i+2)/(n);
    while (a>eps)
    {
        s= s+sign*a;
        sign= -sign;
        i= i+1;
        n= n+3;
        a= (i+2)/(n);
    }
    printf ("s=%f", s);
   
}

void dop2()
{
  float s, a, n, i;
  double eps;
  int sign, c;
  printf ("eps=");
  scanf ("%lf", &eps);
  c=0;
  s = 0;
  sign = 1;
  i = 1;
  n = 1;
  a = (i + 2) / (n);
  while (a > eps)
	{
	  s = s + sign * a;
	  sign = -sign;
	  i = i + 1;
	  n = n + 3;
	  a = (i + 2) / (n);
	  c++;
	  printf ("%d)= %f\n",c , s);
	}
  printf ("s=%f", s);
}

void lab3()
{
    int cnt = 0; // Счетчик слов
    int lastChar; // Крайний символ
    int currentChar = getchar(); // Текущий символ
    int wordChar = currentChar; // Крайний символ последнего слова
    while (currentChar != EOF) { // Пока не закончится ввод (Ctrl+D)
        lastChar = currentChar;
        currentChar = getchar(); // получаем новый символ, сохранив предыдущий

        // Проверка, является ли предыдущий символ разделителем
        // Если да, то началось новое слово, сохраняем его первую букву
        if (lastChar == ' ' || lastChar == '.' || lastChar == ',' || lastChar == '\n') {wordChar = currentChar;}

        // Опять проверка, разделитель ли символ ИЛИ если ввод кончился
        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n' || currentChar == EOF)
        {
            // Если последний символ совпадает с первым символом слова, то увеличиваем счетчик
            if (lastChar == wordChar) {
                cnt++;
            }
        }
    }
    // Цикл закончился, а значит и ввод закончился
  printf ("Resalt: %d", cnt);
}

void dop3()
{
 int cnt = 0; // Счетчик слов
    int lastChar; // Крайний символ
    int currentChar = getchar(); // Текущий символ
    int wordChar = currentChar; // Крайний символ последнего слова
    int wordLength = 1;

    while (currentChar != EOF) { // Пока не закончится ввод (Ctrl+D)
        lastChar = currentChar;
        currentChar = getchar(); // Получаем новый символ, сохранив предыдущий
        // Проверка, является ли предыдущий символ разделителем
        // Если да, то началось новое слово, сохраняем его первую букву
        if (lastChar == ' ' || lastChar == '.' || lastChar == ',' || lastChar == '\n') {wordChar = currentChar; wordLength=0;}

        // Опять проверка, разделитель ли символ ИЛИ если ввод кончился
        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n' || currentChar == EOF) {
            // Если последний символ совпадает с первым символом слова, то увеличиваем счетчик
            if (lastChar == wordChar && wordLength > 3) {
                cnt++;
            }
        }
        wordLength += 1;
    }
    // Цикл закончился, а значит и ввод закончился
    printf("Resalt: %d", cnt); // Выводим результат
}

void lab4()
{
    printf("Enter the text:\n");
    char wordBuffer[maxWord]; // Сюда формируется слово
    char stringBuffer[maxString]; // А сюда строка

    short wordLength = 0; // Считаем длину слова и строки
    short stringLength = 0;

    char currentChar = (char)getchar();
    char previousChar;

    int flag = 0; // Не было ли это слово отделено запятой
    int first = 1; // Первое ли это слово

    while (currentChar != EOF) {
        previousChar = currentChar; // Считываем символ и сохраняем предыдущий
        currentChar = (char)getchar();

        if (!(previousChar == ' ' || previousChar == '.' || previousChar == ',' || previousChar == '\n')){
            // Слово не кончилось, записываем следущую букву
            wordBuffer[wordLength] = previousChar;
            wordLength++;
        }

        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n' || currentChar == EOF) {
            // Слово закончилось, проверяем, стоит ли добавлять его в строку
            if ((!flag || !first) && wordBuffer[0] != '\0') {
                for (short i = 0; i < wordLength; ++i) {
                    stringBuffer[stringLength + i] = wordBuffer[i];
                }
                stringBuffer[stringLength + wordLength] = ';';
                stringBuffer[stringLength + wordLength + 1] = ' ';
                stringLength += wordLength + (short)2;
            }

            if (flag && first) {first = 0;}

            // Обнуляем слово
            wordBuffer[0] = '\0';
            wordLength = 0;
            flag = 0;

        }

        if (currentChar == ',') {
            flag = 1;
        }
    }

    printf("\nResult: %s\n", stringBuffer);
}

void dop4()
{
    printf("Enter character stream:\n");
    char wordBuffer[maxWord]; // Сюда формируется слово
    char stringBuffer[maxString]; // А сюда строка

    short wordLength = 0; // Считаем длину слова и строки
    short stringLength = 0;

    char currentChar = (char)getchar();
    char previousChar;

    int flag = 0; // Не было ли это слово отделено запятой

    while (currentChar != EOF) {
        previousChar = currentChar; // Считываем символ и сохраняем предыдущий
        currentChar = (char)getchar();

        if (!(previousChar == ' ' || previousChar == '.' || previousChar == ',' || previousChar == '\n')){
            // Слово не кончилось, записываем следущую букву
            wordBuffer[wordLength] = previousChar;
            wordLength++;
        }

        if (currentChar == ' ' || currentChar == '.' || currentChar == ',' || currentChar == '\n' || currentChar == EOF) {
            // Слово закончилось, проверяем, стоит ли добавлять его в строку
            if ((!flag)&& wordBuffer[0] != '\0') {
                for (short i = 0; i < wordLength; ++i) {
                    stringBuffer[stringLength + i] = wordBuffer[i];
                }
                stringBuffer[stringLength + wordLength] = ';';
                stringBuffer[stringLength + wordLength + 1] = ' ';
                stringLength += wordLength + (short)2;
            }
            else {
                stringBuffer[stringLength] = ',';
                stringBuffer[stringLength + 1] = ';';
                stringBuffer[stringLength + 2] = ' ';
                stringLength += (short)3;
            }

            // Обнуляем слово
            wordBuffer[0] = '\0';
            wordLength = 0;

        }

        if (currentChar == ',') {
            if (flag) {flag = 0;} // Заканчиваем удалять
            else {flag = 1;} // Начинаем удалять
        }
    }

    printf("\nResult: %s\n", stringBuffer);
}

void lab5()
 {
    int array[ARRAY_SIZE];
    printf("Enter %d integers for the array:\n", ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (scanf("%d", &array[i]) != 1) { printf("Error: Wrong value"); return;}
    }

    int currentDelta;
    int delta = array[0] - array[1];

    for (short x = 2; x < ARRAY_SIZE; ++x) {
        // Проходимся по всем остальным элементам
        currentDelta = array[x-1] - array[x];

        if (currentDelta != delta) {
            printf("Array isn't arithmetic progression\n");
            return;
        }
    }

    printf("Array is arithmetic progression\n");
    return;
 
}

int isArithmeticProgression(int array[], int size);
int findOutsider(int array[]);

void dop5() {
    int array[ARRAY_SIZE];
    printf("Enter %d integers for the array:\n", ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (scanf("%d", &array[i]) != 1) { printf("Error: Wrong value"); return ;}
    }

    int indexOutsider = findOutsider(array);
    printf("Array is");
    if ((indexOutsider == -2 || indexOutsider == -1) && !isArithmeticProgression(array, ARRAY_SIZE)) {
        printf("n't");
    }
    printf(" arithmetic progression");

    if (indexOutsider >= 0) {
        printf(", but with one exception on position %d", indexOutsider + 1);
    }
    printf(".\n");
    return ;
}

int isArithmeticProgression(int array[], int size) {
    if (size <= 2)
        return 1;

    int common_diff = array[1] - array[0];
    for (int i = 2; i < size; i++) {
        if (array[i] - array[i - 1] != common_diff)
            return 0; // Нет
    }
    return 1; // Да
}

int findOutsider(int array[]) {
    int size = ARRAY_SIZE;

    int outsider_index = -1;
    for (int i = 0; i < size; i++) {
        int temp[size - 1], j = 0;
        for (int k = 0; k < size; k++) {
            if (k != i) {
                temp[j] = array[k];
                j++;
            }
        }

        if (isArithmeticProgression(temp, size-1)) {
            if (outsider_index >= 0) {return -2;} // Много аутсайдеров
            else {outsider_index = i;}
        }
    }

    return outsider_index; // Или 1 аутсайдер или 0, как повезет
}



int matrix[N][K] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}};

void lab6()
{
    int minRow;
    int maxRow;
    int min = 0;
    int max = 512;

    for (int y; y < N; ++y) {
        for (int x = 0; x < K; ++x) {
            if (matrix[y][x] < min) {
                min = matrix[y][x];
                minRow = y;
            }
            if (matrix[y][x] > max) {
                max = matrix[y][x];
                maxRow = y;
            }
        }
    }

    if (minRow != maxRow) {
        int maxRowCopy[K];
        for (int i = 0; i < K; ++i) {
            maxRowCopy[i] = matrix[maxRow][i];
        }

        for (int i = 0; i < K; ++i) {
            matrix[maxRow][i] = matrix[minRow][i];
        }
        for (int i = 0; i < K; ++i) {
            matrix[minRow][i] = maxRowCopy[i];
        }
    }

    printf("Resulting array:\n");

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < K; ++x) {
            printf("%d; ", matrix[y][x]);
        }
        printf("\n");
    }
    return ;
}






// Поменять местами два элемнта в памяти
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция разделения массива вокруг "центрального" значения
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partition2D(int arr[QSORT_ARRAY_SIZE_X][QSORT_ARRAY_SIZE_Y], int low, int high) {
    int pivot = arr[high / QSORT_ARRAY_SIZE_Y][high % QSORT_ARRAY_SIZE_Y];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j / QSORT_ARRAY_SIZE_Y][j % QSORT_ARRAY_SIZE_Y] < pivot) {
            i++;
            swap(&arr[i / QSORT_ARRAY_SIZE_Y][i % QSORT_ARRAY_SIZE_Y], &arr[j / QSORT_ARRAY_SIZE_Y][j % QSORT_ARRAY_SIZE_Y]);
        }
    }
    swap(&arr[(i + 1) / QSORT_ARRAY_SIZE_Y][(i + 1) % QSORT_ARRAY_SIZE_Y], &arr[high / QSORT_ARRAY_SIZE_Y][high % QSORT_ARRAY_SIZE_Y]);
    return (i + 1);
}

void qsort(int arr[], int low, int high) {
    if (low < high) { // Пока не доделимся до момента, когда половинки состоят из 1 элемента
        // Пи это индекс центрального значения
        int pi = partition(arr, low, high);

        // Берем обе половинки и отдельно сортируем
        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
}

void qsort2D(int arr[QSORT_ARRAY_SIZE_X][QSORT_ARRAY_SIZE_Y], int low, int high) {
    if (low < high) {
        int pi = partition2D(arr, low, high);

        qsort2D(arr, low, pi - 1);
        qsort2D(arr, pi + 1, high);
    }
}

int qsortTest() {
    int array[QSORT_ARRAY_SIZE];
    for (int i = 0; i < QSORT_ARRAY_SIZE; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Wrong number!");
            --i;
            continue;
        }
    }

    qsort(array, 0, QSORT_ARRAY_SIZE-1);
    printf("Resulting array: ");
    for (int i = 0; i < QSORT_ARRAY_SIZE; ++i) {
        printf("%d;", array[i]);
    }
}

void dop6() {
    int array[QSORT_ARRAY_SIZE_Y][QSORT_ARRAY_SIZE_X] = {{1, 2, 3},
                                                         {1, 2, 3},
                                                         {1, 2, 3}};

    qsort2D(array, 0, QSORT_ARRAY_SIZE_X*QSORT_ARRAY_SIZE_Y);

    for (int y = 0; y < QSORT_ARRAY_SIZE_Y; ++y) {
        for (int x = 0; x < QSORT_ARRAY_SIZE_X; ++x) {
            printf("%d; ", array[y][x]);
        }
        printf("\n");
    }
}


// Функция расчета установленных бит слева от данного индекса
int countSetLeft(unsigned long long int num, int position) {
    int count = 0;
    unsigned long long mask = 1ull << position; // Ставим маску на данную позицию
    while (mask) {
        count += !!(num & mask); // Проверяем установлен ли бит
        mask <<= 1; // И сдвигаем влево до упора
    }
    return count;
}

// Функция расчета установленных бит справа от данного индекса
int countSetRight(unsigned long long int num, int position) {
    int count = 0;
    unsigned long long mask = 1ull << position; // Ставим маску на данную позицию
    while (mask) {
        count += !!(num & mask); // Проверяем установлен ли бит
        mask >>= 1; // И сдвигаем вправо до упора
    }
    return count;
}

int findEqualBitsPosition(unsigned long long int Nn) {
    for (int i = 0; i < 64; ++i) {
        int leftOnes = countSetLeft(Nn, i);
        int rightOnes = countSetRight(Nn, i);

        if (leftOnes == rightOnes) {
            return i; // Возвращаем искомую позицию
        }
    }
    return -1; // Нет такой позиции
}

void lab7() {
    unsigned long long int input;
    printf("Enter unsigned number: ");
    if (scanf("%llu", &input) != 1) {
        printf("Wrong number!\n");
        lab7();
        return;
    }
    int result = findEqualBitsPosition(input);
    if (result != -1) {
        printf("Wanted position: %d\n", result);
    } else {
        printf("Wanted position not found");
    }
}