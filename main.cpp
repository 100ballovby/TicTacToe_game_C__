#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// глобальные константы
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// Функции-кандидаты (прототипы функций)
void instructions();  // отображает правила игры
char askYesNo(string question);  // задает вопрос (да/нет) и возвращает y или n
int askNumber(string question, int high, int low = 0);  // запрашивает число из диапазона
char humanPiece();  // определяет символ, которым ходит игрок (Х или О)
char opponent(char piece);  // определяет символ, которым ходит компьютер, на основе выбора игрока
void displayBoard(const vector<char> &board);  // отображает поле на экране, получает вектор для поля
char winner(const vector<char> &board);  // определяет победителя игры
bool isLegal(const vector<char> &board, int move);  // определяет возможность хода
int humanMove(const vector<char> &board, char human); // узнает ход пользователя
int computerMove(const vector<char> &board, char computer); // узнает ход компьютера
void announceWinner(char winner, char computer, char human); // Поздравляет победителя или объявляет ничью

int main() {
    return 0;
}
