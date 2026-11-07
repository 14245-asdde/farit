#include <iostream>
#include <limits>
#define NOMINMAX
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int vibor;
    do
    {
        std::cout << "\n========== МЕНЮ ==========\n";
        std::cout << "1 — Задание 1 (Счастливое число)\n";
        std::cout << "2 — Задание 2 (Обмен цифр)\n";
        std::cout << "3 — Задание 3 (Максимум из 7)\n";
        std::cout << "0 — Выход\n";
        std::cout << "Выберите задание: ";
        std::cin >> vibor;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число от 0 до 3!\n";
            continue;
        }

        if (vibor == 1)
        {
            int i;
            std::cout << "\n--- Задание 1: Счастливое число ---\n";
            std::cout << "Введите шестизначное число: ";
            std::cin >> i;

            if (i < 100000 || i > 999999)
            {
                std::cout << "Ошибка: введено не шестизначное число!\n";
            }
            else
            {
                int sum1 = 0, sum2 = 0;
                int num = i;
                for (int j = 0; j < 3; j++)
                {
                    sum2 += num % 10;
                    num /= 10;
                }
                for (int j = 0; j < 3; j++)
                {
                    sum1 += num % 10;
                    num /= 10;
                }

                std::cout << "Сумма первых трёх цифр: " << sum1 << "\n";
                std::cout << "Сумма последних трёх цифр: " << sum2 << "\n";

                if (sum1 == sum2)
                {
                    std::cout << "Это счастливое число!\n";
                }
                else
                {
                    std::cout << "Это не счастливое число.\n";
                }
            }
        }
        else if (vibor == 2)
        {
            int i;
            std::cout << "\n--- Задание 2: Обмен цифр четырёхзначного числа ---\n";
            std::cout << "Введите четырёхзначное число: ";
            std::cin >> i;

            if (i < 1000 || i > 9999)
            {
                std::cout << "Ошибка: введено не четырёхзначное число!\n";
            }
            else
            {
                int d1 = i / 1000;
                int d2 = (i / 100) % 10;
                int d3 = (i / 10) % 10;
                int d4 = i % 10;

                int result = d3 * 1000 + d4 * 100 + d1 * 10 + d2;

                std::cout << "Исходное число: " << i << "\n";
                std::cout << "Результат: " << result << "\n";
            }
        }
        else if (vibor == 3)
        {
            std::cout << "\n--- Задание 3: Максимум из 7 чисел ---\n";
            std::cout << "Введите 7 целых чисел:\n";

            int value;
            std::cout << "1-е число: ";
            std::cin >> value;
            int maximum = value;

            for (int j = 2; j <= 7; j++)
            {
                std::cout << j << "-е число: ";
                std::cin >> value;
                if (value > maximum)
                {
                    maximum = value;
                }
            }

            std::cout << "Максимальное число: " << maximum << "\n";
        }
        else if (vibor == 0)
        {
            std::cout << "Программа завершена. До свидания!\n";
        }
        else
        {
            std::cout << "Ошибка: неверный выбор! Введите от 0 до 3.\n";
        }
    } while (vibor != 0);

    return 0;
}
