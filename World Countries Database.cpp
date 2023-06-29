// S112 Kowata World Countries Database.cpp 
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Structures---------------------------------------------------------
struct Country {
    //Data members
    string name;
    string capital;
    string currency;
    string language;

    //Function members
    string stringify()
    {
        string result;
        result = " Country [ name: " + name + ", Capital: " + capital
            + ", Currency: " + currency + ", Language(s): " + language + "]";
        return result;
    }
};

//-------------------------------------------------------------------
//Prototypes

void experiment01();
void experiment02();

//-------------------------------------------------------------------
int main()
{
    //experiment01();
    experiment02();
}

//-------------------------------------------------------------------
void experiment01()
{
    Country c1;
    c1.name = "Vulcan";
    c1.capital = "Vulcan City";
    c1.currency = "Space credits";
    c1.language = "Vulcanian";

    Country c2{ "Narnia", "Narnia City", "Gold coins", "English" };

    cout << "Country: " << c2.name << ", Capital: " << c2.capital << ", Currency: " << c2.currency
        << ", Language: " << c2.language << endl;

}
//-------------------------------------------------------------------
void experiment02()
{
    vector <Country> vcountry;
    //Country c{ "Narnia", "Narnia City", "Gold Coin", "English" };
    //vcountry.push_back(c);

    string strName, strCapital, strCurrency, strLanguage;

    ifstream xcountry("c:/users/mkowata/temp/xcountry.txt");
    ifstream xcapital("c:/users/mkowata/temp/xcapital.txt");
    ifstream xcurrency("c:/users/mkowata/temp/xcurrency.txt");
    ifstream xlanguage("c:/users/mkowata/temp/xlanguage.txt");

    if (!xcountry)
    {
        cout << "Error - file not found \n";
        exit(101);
    }
    //TO DO - do the same for the other files

    while (getline(xcountry, strName))
    {
        getline(xcapital, strCapital);
        getline(xcurrency, strCurrency);
        getline(xlanguage, strLanguage);

        Country c{ strName, strCapital, strCurrency, strLanguage };
        vcountry.push_back(c);
    }

    xcapital.close();
    xcountry.close();
    xcurrency.close();
    xlanguage.close();


  for (int i = 0; i < vcountry.size(); i++)
    {
        cout << vcountry[i].stringify() << endl;
    }


    cout << "All done experiment02\n";

}

