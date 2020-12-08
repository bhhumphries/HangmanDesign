#include <iostream>

using namespace std;

void inputLetters(int tries, int max_tries, char word[], char guessed[], int num_elem);
void fill(char word[], char guessed[], char letter);
void guessedPrint(char guessed[]);
int calcTries(int tries, char letter, int num_elem, int max_tries, char word[], char guessed[]);
void endGuesses(char guessed[], char word[]);

int main()
{
    char word[] = "cody";
    int num_elem = strlen(word);
    char guessed[num_elem];

    for (int i = 0; i < num_elem; ++i)
    {
        guessed[i] = '*';
    }

    guessed[num_elem] = 0;
    int max_tries = 6;
    int tries = 0;

    cout << "\n\nLet's play hangman!\n";
    cout << "You will get " << max_tries << " incorrect guesses before you are hung!";

    inputLetters(tries, max_tries, word, guessed, num_elem);

    endGuesses(guessed, word);

    return 0;
}

//Asks user to guess a letter
void inputLetters(int tries, int max_tries, char word[], char guessed[], int num_elem)
{
    char letter;
    while (tries < max_tries)
    {
        cout << "\n\n\nGuess a letter: ";
        cin >> letter;

        cout << "\n";

        fill(word, guessed, letter);

        guessedPrint(guessed);

        //If the whole word has been guessed, end loop
        if(strcmp(guessed, word) == 0)
            {
                break;
            }

        tries = calcTries(tries, letter, num_elem, max_tries, word, guessed);
    }
}

//Replaces stars in guessed[] with its respective letter when it is guessed correctly
void fill(char word[], char guessed[], char letter)
{
    int i = 0;
    while(word[i])
    {
        if(word[i] == letter)
        {
            guessed[i] = letter;
        }
      i++;
    }
}

//Displays array guessed after each guess
void guessedPrint(char guessed[])
{
   int i = 0;
   while(guessed[i])
   {
      cout << guessed[i] << " ";
      i++;
   }
   cout << endl;
}

//Displays if letter is correct or incorrect
//Calculates the number of tries used
//Displays number of tries left
int calcTries(int tries, char letter, int num_elem, int max_tries, char word[], char guessed[])
{
    int index = 0;
    int position = -1;
    bool found = false;

    //Search for letter in word through linear search
    while (index < num_elem && !found)
    {
        if (word[index] == letter)
            {
                found = true;
                position = index;
                break;
            }
        else
            {
                index++;
            }
    }

    //If guessed letter is not in the word
    if (position == -1)
        {
            tries = tries + 1;
            cout << "\nIncorrect!";
            cout << "\nYou have only " << max_tries - tries << " tries left!" << endl;;
        }
    else
        {
            cout << "\nYou guessed correct!";
            cout << "\nYou have " << max_tries - tries << " tries left." << endl;;
        }
    return tries;
}

//When the whole word has been guessed or all tries have been used
void endGuesses(char guessed[], char word[])
{
    //If whole word has been guessed
    if(strcmp(guessed, word) == 0)
    {
        cout << "\n\n\nCongrats! You have guessed the word " << word << " correctly!\n\n" << endl;
    }

    //If all tries have been used
    else
    {
        cout << "\n\n\n\nYou have been hung! The correct word is " << word << ".\n\n" << endl;
    }
}
