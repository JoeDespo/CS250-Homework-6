//  Stacks (CS 250: HW6)
//  Created by: Joseph D'Esposito
//  Last updated: 12/7/23
//  Program for the user to input a word to see if it is a palindrome.
//  This program uses a recursive function call.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int wordVerify(string word) //Verify the word only contains letters
{
    char letter; //Holds iterated letter from word
    for (int i=0; i < word.length(); i++)
    {
        letter = word[i];
        if (!isalpha(letter)) //Check if the index of the string is a letter
        {
            throw "This is not a word.";
        }
    }
    return 0;
}

bool isPalindrome(string word, int start, int end) //Recursive palindrome check
{
    char firstLetter = word[start]; //Store letter of first index
    char lastLetter = word[end]; //Store letter of last index
    //cout << firstLetter << lastLetter << endl; //Debug
    
    if (start > end)
    {
        return true; //All the letters passed to the check, meaning it is a palindrome
    }
    if (firstLetter != lastLetter)
    {
        return false; //If the letters going towards the center do not match, it is not a palindrome
    }
    return isPalindrome(word, start+1, end-1); //Recursive call to check the next two letters
}


int main()
{
    string word; //Store the input word
    cout << "Enter a word: ";
    cin >> word;
    try
    {
        wordVerify(word); //Check if the word contains only letters
        //Convert to uppercase to check if letters match in the palindrome function
        transform(word.begin(),word.end(),word.begin(), ::toupper);
        if (isPalindrome(word, 0, word.length()-1))
        {
            cout << "This is a palindrome." << endl;
        }
        else
        {
            cout << "This is not a palindrome." << endl;
        }
    }
    
    //Catch the error thrown if the word does not contain only letters
    catch(const char* msg)
    {
        cout << msg << endl;
    }
    
    return 0;
}

