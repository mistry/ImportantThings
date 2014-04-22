/* Cesarian Cypher code
 * Khilesh Mistry
 * April 2014
 *  Cesarian Cypher code with interesting user functionality 
 */
#include <stdio.h> // std stuff
#include <time.h> // for week number
#include <iostream> // cin/cout formalism
#include <string> // for being silly
#include <cmath> //its matematical 

using namespace std;
bool decode = false; // need global here to ensure decoding/encoding capabilites
int GetWeek() // function to get the week number
{
    int weeknum = 0;
    
    time_t gettime;
    struct tm * timeinfo;
    char buffer[3];

    time(&gettime);
    timeinfo = localtime (&gettime);
    
    strftime(buffer,3,"%U", timeinfo); //%U gets week number with first sunday of year as begining of week 1
    weeknum = (buffer[0] - '0')*10 + (buffer[1] - '0');
    return weeknum;
}
string GetInput() //Gets the input string, without showing characters
{
    string in1, in2;
    cout << "Enter Encode or Decode mode: (e/d) " << endl;
    getline(cin, in1);
  
    while(in1 != "d" && in1 != "e")
    {
        cout << "\nTry again, and type better" << endl;
        cout << "Enter Encode or Decode mode: (e/d) " << endl;
        getline(cin, in1);
    }
    if(in1 == "d") decode = true;
    
    if(decode)
    {
        cout << "\nEnter text to be decoded: " << endl;
        char *s = getpass("");
        if( s != NULL) in2 = s;
    }
    else
    {
        cout << "\nEnter text to be encoded: " << endl;
        char *s = getpass("");
        if( s != NULL) in2 = s;
    }
    return in2;    
}

int main()
{
    int week = GetWeek();
    int numLet_Alpha = 26;
    string words = GetInput();
    if(decode)
    {
        week = abs(numLet_Alpha-week);  
        week = week%numLet_Alpha;
    }
    
    int strLength = (int)words.length();
    int temp =0; 
    
    for(int i = 0; i < strLength; i++)
    {
        if(isalpha(words[i]))
        {

            temp = (int)words[i];
            if(islower(words[i]) && (temp-97+week > (numLet_Alpha-1))) // 97 = char 'a' 
            {
                temp = abs(numLet_Alpha-week);
                temp = temp%numLet_Alpha;
                words[i] = words[i]-temp;
            }
            else if(isupper(words[i]) && (temp-65+week > (numLet_Alpha-1))) //65 = char 'A'
            {
                temp = abs(numLet_Alpha-week);
                temp = temp%numLet_Alpha;
                words[i] = words[i] - temp;
            }
            else
            {
                words[i] = words[i]+week;
            }
        }
    }

    if(decode) cout << "Decoded text: " <<  words << endl;
    else cout << "Encoded text: " << words << endl;
}

