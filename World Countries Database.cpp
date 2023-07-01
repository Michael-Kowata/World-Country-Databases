// S112 Kowata Country Database App.cpp 
//Author: Michael Kowata
//Goal: Create a database held in parallel vectors
//      with data regarding: country name, capital(s), currencies, languages
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototypes-----------------------------------------------------------------
void populateVector(vector<string>& v, string fileName);
void printVector(vector<string>& v, string caption);
void findValueVector(vector<string> v, string key, int& pos, int& counter);
void testSequentialSearch(vector <string>vcountry, vector <string> vcapital, vector <string> vlanguage, vector <string> vcurrency);
void testBinarySearch(vector <string>vcountry, vector <string> vcapital, vector <string> vlanguage, vector <string> vcurrency);
void myBinarySearch(vector<string> v, string key, int& pos, int& counter);
int main()
{
    //Data Declaration
    vector<string> vcountry;
    vector<string> vcapital;
    vector<string> vcurrency;
    vector<string> vlanguage;

    //Populate the World Countries Database :
    populateVector(vcountry, "c:/users/mkowata/temp/xcountry.txt");
    //printVector(vcountry, "This is the COUNTRY list ");

    populateVector(vcapital, "c:/users/mkowata/temp/xcapital.txt");
    //printVector(vcapital, "This is the CAPITAL list ");

    populateVector(vcurrency, "c:/users/mkowata/temp/xcurrency.txt");
   // printVector(vcurrency, "This is the CURRENCY list ");

    populateVector(vlanguage, "c:/users/mkowata/temp/xlanguage.txt");
   // printVector(vlanguage, "This is the LANGUAGE list ");

    if (vcountry.size() == vcapital.size() && vcountry.size() == vcurrency.size() && vcountry.size() == vlanguage.size())
    {
        cout << "World Country Database successfully created\n";
    }
    else
    {
        cout << "ERROR - database is corrupted - different sizes\n";
        exit(2);
    }
    ////Expose a menu to retrieve by country
    //int pos = 0, counter = 0;
    //findValueVector(vcountry, "Brazil", pos, counter);
    //if (pos >= 0)
    //{
    //    cout << "\tCapital: " << vcapital[pos] << endl;
    //    cout << "\tCountry: " << vcountry[pos] << endl;
    //}
    //cout << "Pos: " << pos << " Counter: " << counter << endl;

    testSequentialSearch(vcountry, vcapital, vlanguage, vcurrency);

    testBinarySearch(vcountry, vcapital, vlanguage, vcurrency);
}

//---------------------------------------------------------------------------
//User-defined methods
void populateVector(vector<string>& v, string fileName)
{
    ifstream infile(fileName);
    if (!infile)
    {
        cout << "Error - File not found";
        exit(1);
    }
    string line;
    while (getline(infile, line))
    {
        v.push_back(line);
    }
    infile.close();
}

void printVector(vector<string>& v, string caption)
{
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << "\t" << v[i] << endl;
    }
}

//---------------------------------------------------------
void findValueVector(vector<string> v, string key, int& pos, int& counter)
{
    counter = 0;
    for (pos = 0; pos < v.size(); pos++)
    {
        counter++;
        if (v[pos] == key)
        {
            return;
        }
    }
    pos = -1;
}

void testSequentialSearch(vector <string>vcountry, vector <string> vcapital, vector <string> vlanguage, vector <string> vcurrency)
{
    //Expose a menu to retrieve by country
    do
    {
        string countryName;
        cout << "Enter a country name [xxx to end]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;
        int pos = 0, counter = 0;
        findValueVector(vcountry, countryName, pos, counter);
        if (pos >= 0)
        {
            cout << "\tSEQ - Capital: " << vcapital[pos] << endl;
            cout << "\tSEQ - Country: " << vcountry[pos] << endl;
            cout << "\tSEQ - Language: " << vlanguage[pos] << endl;
            cout << "\tSEQ - Currency: " << vcurrency[pos] << endl;
        }
        cout << "\tSEQ - Pos: " << pos << " Counter: " << counter << endl;
    } while (true);
    //ctrl+k+s to make a do while 
}

void testBinarySearch(vector <string>vcountry, vector <string> vcapital, vector <string> vlanguage, vector <string> vcurrency)
{
    do
    {
        string countryName;
        cout << "Enter a country name [xxx to end]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;
        int pos = 0, counter = 0;
        myBinarySearch(vcountry, countryName, pos, counter);
        if (pos >= 0)
        {
            cout << "\tBIN - Capital: " << vcapital[pos] << endl;
            cout << "\tBIN - Country: " << vcountry[pos] << endl;
            cout << "\tBIN _ Language: " << vlanguage[pos] << endl;
            cout << "\tBIN - Currency: " << vcurrency[pos] << endl;
        }
        cout << "\tBIN - Pos: " << pos << " Counter: " << counter << endl;
    } while (true);
}

void myBinarySearch(vector<string> v, string key, int& pos, int& counter)
{
    counter = 0;
    int first = 0;
    int last = v.size() - 1;
    while (first <= last)
    {
        counter++;
        pos = (first + last) / 2;
        if (v[pos] == key)
        {
            return;
        }
        if (v[pos] > key)
        {
            last = pos - 1;  //explore left size
        }
        else
        {
            first = pos + 1;
        }
    }   
    pos = -1;
}

