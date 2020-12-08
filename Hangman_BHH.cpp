#include <iostream>

using namespace std;

//Function prototypes
void inputLetters(int tries, int max_tries, char word[], char guessed[], int num_elem);
void fill(char word[], char guessed[], char letter);
void guessedPrint(char guessed[]);
int calcTries(int tries, char letter, int num_elem, int max_tries, char word[], char guessed[]);
void endGuesses(char guessed[], char word[]);

//Call main function
int main()
{
    char word[] = "programming";    //declare array word
    int num_elem = strlen(word);    //count number of letters in word
    char guessed[num_elem];         //declare array guessed that is the size of word

    //initialize guessed with all *'s
    for (int i = 0; i < num_elem; ++i)
    {
        guessed[i] = '*';
    }
    guessed[num_elem] = 0;
    int max_tries = 6;          //Define number of tries allowed
    int tries = 0;              //Set number of tries used to 0

    //Display beginning user message
    cout << "\n\nLet's play hangman!\n";
    cout << "You will get " << max_tries << " incorrect guesses before you are hung!\n";

    //ask for user input
    inputLetters(tries, max_tries, word, guessed, num_elem);

    //calls when max tries have been used or the whole word was guessed
    endGuesses(guessed, word);

    return 0;
}

//Asks user to guess a letter
void inputLetters(int tries, int max_tries, char word[], char guessed[], int num_elem)
{
    char letter;

    //if all the tries haven't been used, while loop will continue
    while (tries < max_tries)
    {
        cout << "\n\nGuess a lowercase letter: ";
        cin >> letter;
        cout << "\n";

        fill(word, guessed, letter);
        guessedPrint(guessed);

        //If the whole word has been guessed, end loop
        if(strcmp(guessed, word) == 0)
            {
                break;
            }

        //calculate number of tries used
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
            //Add 1 to number of tries used since letter was incorrect
            tries = tries + 1;

            //Displays user message
            cout << "\nIncorrect!";

            //If all tries have been used, it will not display how many tries are left
            if (tries < max_tries)
                {
                cout << "\nYou have only " << max_tries - tries << " tries left!" << endl;
                }
        }
    else
        {
            //Displays user message
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
        //Display a winning message
        cout << "\n\n\nCongrats! You have guessed the word \"" << word << "\" correctly!\n\n" << endl;
    }

    //If all tries have been used
    else
    {
        //Display a losing message
        cout << "\n\n\n\nYou have been hung! The correct word is \"" << word << "\".\n\n" << endl;
    }
}
