/**********|**********|**********|

Course: Programing Fundamentals 
Name: Md.Istiaq Ahmed Bhuiyan
ID: 1181302904
Lecture Section: TC04
Tutorial Section: TT08
Email: 1181302904@student.mmu.edu.my

**********|**********|**********/

#include <iostream>
#include <cstring> //To use strcpy function
using namespace std;

void rotate90Clockwise(char displayBoard[200][200]);
void noGarbage(char displayBoard[200][200]); //Function to clear the board
void display(char displayBoard[200][200], int speed); //Function to display the display board
void printString(char displayBoard[200][200], char letter[25], string text, int anchorX, int anchorY, int speed); //Function to compose and print string
void delay(int speed);  //Function to delay my movement
void clearScreen(); //Function to clear screen after every display
void switchChar(char displayBoard[200][200], char letter[], int x, int anchorX, int anchorY); //Function to Switch Character referring to the string entered by the user

char symbol; //Global variable symbol

int main()
{
    int NumberOfCharacters = 25; //The number of characters
    int anchorX; //The anchor dot for the X axis or columns
    int anchorY; //The anchor dot for the Y axis or rows
    int direction; //The direction of movement
    int time; //The number of times it moves
    int speed; //The speed of movement
    string text; //The text entered by the user
    char letter[NumberOfCharacters]; //The letters in the text entered by the user
    char displayBoard[200][200]; //Large Display Board array consisting of 200 rows and 400 columns

    cout << "Enter your desired text(Please do not exceed 25 characters): " << endl; //User prompt for text
    getline(cin, text); //Text being stored into the variable 'text', the getline function is being used so that spaces are registered as well

    cout << "Enter any symbol: " << endl; //User prompt for symbol
    cin >> symbol; //Symbol being stored into the global variable symbol

    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl; //A display of the coordinates of the display board to make it easier for the user to understand the coordinates
    cout << "       (Y)|                * <--------(39,19)" << endl;
    cout << "          |" << endl;
    cout << "          |" << endl;
    cout << "          |" << endl;
    cout << "          |" << endl;
    cout << "          |" << endl;
    cout << "(0,0) --> ---------------(X)" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;

    cout << "Set Anchor X: " << endl; //User prompt for the anchor dot for the X axis
    cin >> anchorX;

    cout << "Set Anchor Y: " << endl; //User prompt for the anchor dot for the Y axis
    cin >> anchorY;

    cout << "Which direction do you want it to move? " << endl << "- Press 0 for stationary" << endl << "- Press 1 for left" << endl << "- Press 2 for right" << endl << "- Press 3 for up" << endl << "- Press 4 for down" << endl; //User prompt for direction of movement
    cin >> direction;

    cout << "Enter your time steps (the number of times your text moves): " << endl; //User prompt for the number of times the text moves
    cin >> time;

    cout << "Enter your speed (1: for slowest and 10: for fastest): " << endl; //User prompt for the desired speed
    cin >> speed;

    strcpy(letter, text.c_str()); //The text entered by the user is being converted to the array 'letter', so that each letter can be accessed

    if(direction == 1) //When direction equals to 1, text goes left.
    {
        for(int x = 0; x < time; x++) //This for loop has the printString function to print the string
        {
            printString(displayBoard, letter, text, anchorX, anchorY, speed);
            clearScreen(); //This function clears the screen after the string has been printed
            anchorX = anchorX - 1; //This statement updates the anchor dot for X axis to move 1 space to the left and then sends the new anchor dot position to print a new string to the printString function... this continues making it seem like an animation of a moving text
        }
    }
    if(direction == 2) //When direction equals to 2, text goes right.
    {
        for(int x = 0; x < time; x++) //This for loop has the printString function to print the string
        {
            printString(displayBoard, letter, text, anchorX, anchorY, speed);
            clearScreen(); //This function clears the screen after the string has been printed
            anchorX = anchorX + 1; //This statement updates the anchor dot for X axis to move 1 space to the right and then sends the new anchor dot position to print a new string to the printString function... this continues making it seem like an animation of a moving text
        }
    }
    if(direction == 4) //When direction equals to 4, text goes down
    {
        for(int x = 0; x < time; x++) //This for loop has the printString function to print the string
        {
            printString(displayBoard, letter, text, anchorX, anchorY, speed);
            clearScreen(); //This function clears the screen after the string has been printed
            anchorY = anchorY - 1; //This statement updates the anchor dot for Y axis to move 1 space below and then sends the new anchor dot position to print a new string to the printString function... this continues making it seem like an animation of a moving text
            while(anchorY < -7) //When the anchor dot for the y axis crosses the point -7 in the display board this while keeps printing another text from below the board from the point 19 making a wrap around effect
            {
                anchorY = 19;
                printString(displayBoard, letter, text, anchorX, anchorY, speed);
                clearScreen(); //This function clears the screen after the string has been printed
                anchorY = anchorY + 1;
            }
        }
    }
    if(direction == 3) //When direction equals to 3, text goes up
    {
        for(int x = 0; x < time; x++)
        {
            printString(displayBoard, letter, text, anchorX, anchorY, speed);
            clearScreen(); //This function clears the screen after the string has been printed
            anchorY = anchorY + 1; //This statement updates the anchor dot for Y axis to move 1 space above and then sends the new anchor dot position to print a new string to the printString function... this continues making it seem like an animation of a moving text
            while(anchorY > 19) //When the anchor dot for the y axis crosses the point 19 in the display board this while keeps printing another text from above the board from the point -7 making a wrap around effect
            {
                anchorY = -7;
                printString(displayBoard, letter, text, anchorX, anchorY, speed);
                clearScreen(); //This function clears the screen after the string has been printed
                anchorY = anchorY + 1;
            }
        }
    }
    else if(direction == 0) //This is for stationary text. The anchor dots do not change for this selection
    {   while(true)
        {
            printString(displayBoard, letter, text, anchorX, anchorY, speed);
        }
    }
    else //If an invalid selection is made
    {
        cout << "Invalid direction! Restart program!";
    }

}
//This function is for composing the string then displaying it on the display board
void printString(char displayBoard[200][200], char letter[25], string text, int anchorX, int anchorY, int speed)
{
    int i = 0;
    noGarbage(displayBoard);

    for(int x = 0; x < text.length(); x++)
    {
        if(x == i)//Over here x is the index which continues to increment to the number of characters in the text inserted by the user. i is the place of the letter, i starts with 0 and will continue till it has reached to the last letter place of the string
        {
            switchChar(displayBoard, letter, x, anchorX, anchorY); //This function has a switch case mechanism to help find a suitable character design for that place of the text
            anchorX = 7 + anchorX; //This statement works on printing the next letter 7 spaces to the right of the previous letter. Making the strng come out horizontally
            i++; //Increments i to match x
        }
        if(x == (text.length() - 1)) //When the index x has reached the character length for the text inserted by the user, the display board is displayed to the user
        {
            display(displayBoard, speed); //The display board function
        }
    }
}

void noGarbage(char displayBoard[200][200]) //When this function is called it clears the board for any garbage values
{
    for(int x = 0; x < 200; x++)
    {
        for(int y = 0; y < 200; y++)
        {
            displayBoard[x][y] = ' ';
        }
    }
}

void display(char displayBoard[200][200], int speed) //This is the display function, it displays the board to the user when called
{
    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 80; y++)
        {
            cout << displayBoard[9 + x][156 + y]; //In here x is being added with 9 and y is bring added with 156 because I want the board to display 9 rows below and 156 columns to the right so that there is enough space above and to the left of the board for text to flow
        }
        cout << endl;
        //clearScreen();
    }
    delay(speed); //After the board is displayed this function delays the movement
    clearScreen(); //The clearScreen function clears the board after display
}

void delay(int speed) //This is the delay function, it works in delaying the movement so that it doesn't run too fast
{
    speed = 30000000 / speed; //The number gets divided by the speed inserted by the user. The smaller the number is the slower the movement is because the for loop needs to run for a longer time
    for( int i = 0; i < speed; ++i )
    { }
}

void clearScreen() //This function clears up the screen
{
   system( "cls" );
}

void rotate90Clockwise(char displayBoard[200][200])
{
    for (int i = 0; i < 200 / 2; i++)
    {
        for (int j = i; j < 200 - i - 1; j++)
        {
            int temp = displayBoard[j][i];
            displayBoard[j][i] = displayBoard[200 - 1 - i][j];
            displayBoard[200 - 1 - j][i] = displayBoard[200 - 1 - j][200 - 1 - i];
            displayBoard[200 - 1 - j][200 - 1 - i] = displayBoard[i][200 - 1 - j];
            displayBoard[i][200 - 1 - j] = temp;
        }
    }
}

void switchChar(char displayBoard[200][200], char letter[], int x, int anchorX, int anchorY) //This function finds the suitable character design according to the letters stored in the variable letter and assigns it to the display bosrd
{
            switch(letter[x])
            {
                case 'a':
                case 'A':
                {
                    displayBoard[20 - anchorY + 0][anchorX + 3] = symbol;
                    displayBoard[20 - anchorY + 1][anchorX + 2] = symbol;
                    displayBoard[20 - anchorY + 1][anchorX + 4] = symbol;
                    displayBoard[20 - anchorY + 2][anchorX + 1] = symbol;
                    displayBoard[20 - anchorY + 2][anchorX + 5] = symbol;
                    displayBoard[20 - anchorY + 3][anchorX + 1] = symbol;
                    displayBoard[20 - anchorY + 3][anchorX + 5] = symbol;
                    displayBoard[20 - anchorY + 4][anchorX + 1] = symbol;
                    displayBoard[20 - anchorY + 4][anchorX + 2] = symbol;
                    displayBoard[20 - anchorY + 4][anchorX + 3] = symbol;
                    displayBoard[20 - anchorY + 4][anchorX + 4] = symbol;
                    displayBoard[20 - anchorY + 4][anchorX + 5] = symbol;
                    displayBoard[20 - anchorY + 5][anchorX + 1] = symbol;
                    displayBoard[20 - anchorY + 5][anchorX + 5] = symbol;
                    displayBoard[20 - anchorY + 6][anchorX + 1] = symbol;
                    displayBoard[20 - anchorY + 6][anchorX + 5] = symbol;
                    break;
                }
                case 'b':
                case 'B':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol;
                    displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'c':
                case 'C':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol;
                    displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'd':
                case 'D':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'e':
                case 'E':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol;
                    displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'f':
                case 'F':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol;
                    displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'g':
                case 'G':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol;
                    displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'h':
                case 'H':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol;
                    displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol;
                    displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'i':
                case 'I':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 158] = symbol, displayBoard[22 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'j':
                case 'J':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'k':
                case 'K':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 159] = symbol;
                    displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol;
                    displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 158] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 159] = symbol;
                    displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'l':
                case 'L':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    break;
                }
                case 'm':
                case 'M':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol;
                    displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol;
                    displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 158] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 157] = symbol, displayBoard[22 - anchorY][anchorX + 159] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'n':
                case 'N':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol;
                    displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol;
                    displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 159] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 157] = symbol;
                    break;
                }
                case 'o':
                case 'O':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'p':
                case 'P':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'q':
                case 'Q':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 159] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol;
                    displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 'r':
                case 'R':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 159] = symbol;
                    displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol;
                    displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 's':
                case 'S':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case 't':
                case 'T':
                {
                    displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[26 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 158] = symbol, displayBoard[22 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'u':
                case 'U':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'v':
                case 'V':
                {
                    displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[26 - anchorY][anchorX + 157] = symbol, displayBoard[26 - anchorY][anchorX + 159] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol;
                    displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'w':
                case 'W':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 157] = symbol;
                    displayBoard[26 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol;
                    displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'x':
                case 'X':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol;
                    displayBoard[25 - anchorY][anchorX + 157] = symbol, displayBoard[25 - anchorY][anchorX + 159] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[23 - anchorY][anchorX + 157] = symbol;
                    displayBoard[23 - anchorY][anchorX + 159] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'y':
                case 'Y':
                {
                    displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[26 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 157] = symbol, displayBoard[23 - anchorY][anchorX + 159] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case 'z':
                case 'Z':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 159] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case ' ':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = ' ', displayBoard[27 - anchorY][anchorX + 160] = ' ', displayBoard[26 - anchorY][anchorX + 156] = ' ', displayBoard[26 - anchorY][anchorX + 160] = ' ';
                    displayBoard[25 - anchorY][anchorX + 156] = ' ', displayBoard[25 - anchorY][anchorX + 160] = ' ', displayBoard[24 - anchorY][anchorX + 156] = ' ', displayBoard[24 - anchorY][anchorX + 157] = ' ';
                    displayBoard[24 - anchorY][anchorX + 158] = ' ', displayBoard[24 - anchorY][anchorX + 159] = ' ', displayBoard[24 - anchorY][anchorX + 160] = ' ', displayBoard[23 - anchorY][anchorX + 156] = ' ';
                    displayBoard[23 - anchorY][anchorX + 160] = ' ', displayBoard[22 - anchorY][anchorX + 156] = ' ', displayBoard[22 - anchorY][anchorX + 160] = ' ', displayBoard[21 - anchorY][anchorX + 156] = ' ';
                    displayBoard[21 - anchorY][anchorX + 160] = ' ';
                    break;
                }
                case '1':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 158] = symbol, displayBoard[22 - anchorY][anchorX + 157] = symbol, displayBoard[22 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol;
                    break;
                }

                case '2':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol;
                    displayBoard[27 - anchorY][anchorX + 160] = symbol, displayBoard[26 - anchorY][anchorX + 157] = symbol, displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }

                case '3':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol;
                    displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }

                case '4':
                {
                    displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 159] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 157] = symbol;
                    displayBoard[25 - anchorY][anchorX + 158] = symbol, displayBoard[25 - anchorY][anchorX + 159] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 157] = symbol, displayBoard[23 - anchorY][anchorX + 159] = symbol;
                    displayBoard[22 - anchorY][anchorX + 158] = symbol, displayBoard[22 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }

                case '5':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol;
                    displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol;
                    displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case '6':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 156] = symbol;
                    displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case '7':
                {
                    displayBoard[27 - anchorY][anchorX + 156] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol;
                    displayBoard[23 - anchorY][anchorX + 159] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 156] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol;
                    displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol, displayBoard[21 - anchorY][anchorX + 160] = symbol;
                    break;
                }
                case '8':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol;
                    displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol;
                    displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol;
                    displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case '9':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 160] = symbol;
                    displayBoard[25 - anchorY][anchorX + 160] = symbol, displayBoard[24 - anchorY][anchorX + 157] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 159] = symbol;
                    displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol;
                    displayBoard[22 - anchorY][anchorX + 160] = symbol, displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
                case '0':
                {
                    displayBoard[27 - anchorY][anchorX + 157] = symbol, displayBoard[27 - anchorY][anchorX + 158] = symbol, displayBoard[27 - anchorY][anchorX + 159] = symbol, displayBoard[26 - anchorY][anchorX + 156] = symbol;
                    displayBoard[26 - anchorY][anchorX + 160] = symbol, displayBoard[25 - anchorY][anchorX + 156] = symbol, displayBoard[25 - anchorY][anchorX + 159] = symbol, displayBoard[25 - anchorY][anchorX + 160] = symbol;
                    displayBoard[24 - anchorY][anchorX + 156] = symbol, displayBoard[24 - anchorY][anchorX + 158] = symbol, displayBoard[24 - anchorY][anchorX + 160] = symbol, displayBoard[23 - anchorY][anchorX + 156] = symbol;
                    displayBoard[23 - anchorY][anchorX + 157] = symbol, displayBoard[23 - anchorY][anchorX + 160] = symbol, displayBoard[22 - anchorY][anchorX + 156] = symbol, displayBoard[22 - anchorY][anchorX + 160] = symbol;
                    displayBoard[21 - anchorY][anchorX + 157] = symbol, displayBoard[21 - anchorY][anchorX + 158] = symbol, displayBoard[21 - anchorY][anchorX + 159] = symbol;
                    break;
                }
            }
}
