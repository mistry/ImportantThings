/* Cesarian Cypher code
 *
 *
 * 
 */
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
bool decode = false;
int GetWeek()
{
    int weeknum = 0;
    
    time_t gettime;
    struct tm * timeinfo;
    char buffer[3];

    time(&gettime);
    timeinfo = localtime (&gettime);
    
    strftime(buffer,3,"%U", timeinfo);
    weeknum = (buffer[0] - '0')*10 + (buffer[1] - '0');
    return weeknum;
}
string GetInput()
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
    string words = GetInput();
    if(decode) week = 26-week;
    
    int strLength = (int)words.length();
    int temp =0; 
    
    for(int i = 0; i < strLength; i++)
    {
        if(isalpha(words[i]))
        {

            temp = (int)words[i];
            if(islower(words[i]) && (temp-97+week > 25))
            {
                temp = abs(26-week);
                temp = temp%26;
                words[i] = words[i]-temp;
            }
            else if(isupper(words[i]) && (temp-65+week > 25))
            {
                temp = abs(26-week);
                temp = temp%26;
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

