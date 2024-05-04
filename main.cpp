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
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    while (winner(board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        } else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winner(board), computer, human);
    return 0;
}


void instructions() {
    cout << "Tic Tac Toe machine game\n";
    cout << "--where human brain is pit against silicon processor!!!\n\n";
    cout << "Make your move known by entering a number from 0 to 8. The number\n";
    cout << "corresponds to the desired boar position, as illustrated\n\n";
    cout << " 0 | 1 | 2 \n";
    cout << "------------";
    cout << " 3 | 4 | 5 \n";
    cout << "------------";
    cout << " 6 | 7 | 8 \n\n";
    cout << "Prepare yourself! The battle is about to begin!\n\n";
}

char askYesNo(string question) {
    /* Функция запрашивает у пользователя вопрос и ожидает
     * от него получения ответа в виде букв y/n. Пока
     * пользователь не введет один из этих символов,
     * функция продолжит задавать вопрос.*/
    char response;
    do {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');
    return response;
}

int askNumber(string question, int high, int low) {
    /* Запрашивает у пользователя число из определенного
     * диапазона. Запрашивает числа, пока пользователь не
     * введет число, удовлетворяющее условию.*/
    int number;
    do {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);
    return number;
}

char humanPiece() {
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y') {
        cout << "\nThen take the first move. You will need it!\n";
        return X;
    } else {
        cout << "\nYour bravery will be your undoing...I will go first!\n";
        return O;
    }
}

char opponent(char piece) {
    /* Эта функция возвращает фигуру, которой будет ходить оппонент */
    switch (piece) {
        case X:
            return O;
        case O:
            return X;
    }
}
