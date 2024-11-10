#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void numberGuessingGame()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand() % 100 + 1;
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    do
    {

        cout << "Enter your guess (1-100) : ";
        cin >> guess;
        if (guess > number)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < number)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number " << number << "!" << endl;
        }
    } while (guess != number);
}
void numberGuessingGamewithbet()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand() % 100 + 1;
    int guess;
    int bet;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Enter your bet amount: ";
    cin >> bet;

    int maxAttempts = 8;
    int attempts = 0;

    do
    {
        cout << "Enter your guess (1-100): ";
        cin >> guess;
        attempts++;
        if (guess > number)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < number)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number " << number << "!" << endl;
            cout << "You won " << bet * 3 << "!" << endl;
            return;
        }

        if (attempts >= maxAttempts)
        {
            cout << "Sorry, you've used all your attempts. The number was " << number << "." << endl;
            cout << "You lost your bet of " << bet << "." << endl;
            return;
        }

    } while (true);
}

void rockPaperScissors()
{
    string choices[3] = {"Rock", "Paper", "Scissors"};
    string userChoice;

    srand(static_cast<unsigned int>(time(0)));
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (Rock, Paper, Scissors): ";
    cin >> userChoice;

    int computerRandom = rand() % 3;
    string computerChoice = choices[computerRandom];
    cout << "Computer chose: " << computerChoice << endl;

    if (userChoice == computerChoice)
    {
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == "Rock" && computerChoice == "Scissors") ||
             (userChoice == "Paper" && computerChoice == "Rock") ||
             (userChoice == "Scissors" && computerChoice == "Paper"))
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You Lose!" << endl;
    }
}

void ticTacToe()
{
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    int moveCount = 0;

    while (moveCount < 9)
    {
        cout << "Current board:\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << " " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << "\n";
            if (i < 2)
                cout << "---|---|---\n";
        }

        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        move--;

        if (move < 0 || move >= 9 || board[move] != ' ')
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[move] = currentPlayer;
        moveCount++;

        if ((board[0] == currentPlayer && board[1] == currentPlayer && board[2] == currentPlayer) ||
            (board[3] == currentPlayer && board[4] == currentPlayer && board[5] == currentPlayer) ||
            (board[6] == currentPlayer && board[7] == currentPlayer && board[8] == currentPlayer) ||
            (board[0] == currentPlayer && board[3] == currentPlayer && board[6] == currentPlayer) ||
            (board[1] == currentPlayer && board[4] == currentPlayer && board[7] == currentPlayer) ||
            (board[2] == currentPlayer && board[5] == currentPlayer && board[8] == currentPlayer) ||
            (board[0] == currentPlayer && board[4] == currentPlayer && board[8] == currentPlayer) ||
            (board[2] == currentPlayer && board[4] == currentPlayer && board[6] == currentPlayer))
        {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            return;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    std::cout << "It's a draw!" << std::endl;
}
void slotMachine()
{
    srand(static_cast<unsigned int>(time(0)));
    int bet;
    cout << "Enter your bet amount: ";
    cin >> bet;

    int symbol1 = rand() % 10;
    int symbol2 = rand() % 10;
    int symbol3 = rand() % 10;

    std::cout << "Slot Machine Results: " << symbol1 << " | " << symbol2 << " | " << symbol3 << std::endl;

    if (symbol1 == symbol2 && symbol2 == symbol3)
    {
        cout << "Congratulations! You won " << bet * 3 << "!" << std::endl;
    }
    else if (symbol1 == symbol2 || symbol1 == symbol3 || symbol2 == symbol3)
    {
        cout << "You won " << bet * 1.5 << "! You matched two symbols!" << std::endl;
    }
    else
    {
        cout << "Sorry, you lost your bet of " << bet << "." << std::endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=======================================" << endl;
        cout << "\nWelcome to the Casino Game!\n";
        cout << "1) Parivarik Games\n";
        cout << "2) Casino Games\n";
        cout << "3) Couple Games\n";
        cout << "4) Gaming Info\n";
        cout << "5) Programmer's Info\n";
        cout << "6) Exit\n";
        cout << "========================================\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int gameChoice;
            do
            {
                cout << "\n=======================================" << endl;
                cout << "\nParivarik Games:\n";
                cout << "1) Simple Number Guessing Game\n";
                cout << "2) Rock Paper Scissors\n";
                cout << "3) Tic Tac Toe\n";
                cout << "4) Go Back\n";
                cout << "=======================================\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> gameChoice;

                switch (gameChoice)
                {
                case 1:
                    numberGuessingGame();
                    break;
                case 2:
                    rockPaperScissors();
                    break;
                case 3:
                    ticTacToe();
                    break;
                case 4:
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (gameChoice != 4);
            break;
        }
        case 2:
        {
            int gameChoice;
            do
            {
                cout << "\n=======================================" << endl;
                cout << "\nCasino Games:\n";
                cout << "1) Number Guessing Game (with bet)\n";
                cout << "2) Slot Machine\n";
                cout << "3) Go Back\n";
                cout << "=======================================\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> gameChoice;

                switch (gameChoice)
                {
                case 1:
                    numberGuessingGamewithbet();
                    break;
                case 2:
                    slotMachine();
                    break;
                case 3:
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (gameChoice != 3);
            break;
        }
        case 3:
            cout << "\n=======================================" << endl;
            cout << "Sorry, you are still single, so you can't play these games. Go home, baby boi!" << endl;
            cout << "=======================================\n"
                 << endl;
            break;
        case 4:
            cout << "\n=======================================" << endl;
            cout << "Gaming Info: This is a fun casino game simulation." << endl;
            cout << "=======================================\n"
                 << endl;
            break;
        case 5:
            cout << "\n=======================================" << endl;
            cout << "Name: Vivek Tripathi\n";
            cout << "Email: tripathivivek2018@gmail.com\n";
            cout << "Course: BTech (CSE)\n";
            cout << "College: Narula Institute of Technology\n";
            cout << "LinkedIn--www.linkedin.com/in/vivek-tripathi-3b27a72ba\n";
            cout << "Knows: HTML, CSS, JavaScript, C++, C, Java\n";
            cout << "=======================================\n"<< endl;
            break;
        case 6:
            cout << "Thank you for playing! Goodbye!" << std::endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
