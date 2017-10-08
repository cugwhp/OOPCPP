#include <iostream>

using namespace std;

enum game_result {WIN, LOSE, TIE, CANCEL};

int main()
{
    int     i;
    game_result     result;
//    enum game_result omit = CANCEL;

    do
    {
        cout << "Input a game result(0-WIN, 1-LOSE, 2-TIE, 3-CANCEL): ";
        cin >> i;

        result = (game_result)i;
        switch(result)
        {
        case WIN:
            cout << "The game was played and we won!" << endl;
            break;
        case LOSE:
            cout << "The game was played and we lost!" << endl;
            break;
        case TIE:
            cout << "The game was played and we tied!\n";
            break;
        case CANCEL:
            cout << "The game was canceled!\n";
            break;
        default:
            cout << "The game result is invalid!\n";
            break;
        }
    }while(i>=0 && i<4);

    return 0;
}
/*
int main()
{
    game_result result;
    enum game_result omit = CANCEL;
    int count;

    for (count = WIN ; count <= CANCEL ; count++)
    {
        result = (game_result)count;
        if (result == omit)
        {
            cout << "The game was canceled\n";
        }
        else
        {
            cout << "The game was played ";
            if (result == WIN)   cout << "and we won!";
            if (result == LOSE)  cout << "and we lost.";
            cout << "\n";
        }
    }

    return 0;
}
*/
