//to read each word in one line at a time, findwords that has the most consecutive vowels from words.txt file
#include <iostream>
#include <fstream>
#include <string>
#include<ctype.h> 

using namespace std;
//creates a function of return type boolean that checks if the character (parameter) is a vowel or not
bool vowelOrNot(char c) {
  //makes the character uppercase, so we can then only check for uppercase vowels 
  c = toupper(c);
  if ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
        return true;
    else
        return false;
}

int main() {
  string s;
  int numOfConsecVowels;
    char w[50];
    //creates an fstream variable so we can read in from the words.txt file 
    fstream file1;
    //opens the words.txt file
    file1.open("words.txt");
    //while its not the end of the file, it reads words one by one from the file
    while (file1.eof() == 0) {
        file1 >> w;
        numOfConsecVowels = 0;
        //loops through the word that is read in from the file 
        for (int i = 0; w[i]; i++){
          //if the number of consecutive vowels are 5 then it prints that word (has highest num of consecutive vowels)
          /* we do this at the beginning because the for loop runs for each character in the word, 
          * so if the previous character incremented the consecutive vowel count and made it up to 5, we should check for it  
          */
          if (numOfConsecVowels == 5){
            cout <<w<< endl;
            break;
          }
          //else if we check if the character at the index of that word if a vowel, and if it is we increment the variable
          else if(vowelOrNot(w[i])){
            numOfConsecVowels++;
          } 
          /* otherwise we reset the variable to 0 since if the previous else if statement was not satisfied, 
          * this means that there is a nonvowel, so there are not consecutive vowels in this word and we have to restart 
          * by setting variable equal to 0
          */
          else {
             numOfConsecVowels = 0;
          }
        }
    }
     //we then close the file 
    file1.close();

}