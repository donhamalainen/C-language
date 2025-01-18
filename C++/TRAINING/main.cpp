#include <iostream>
#include <string>
#include <random>

using namespace std;

int reverseNumber(int number)
{
    int reversed = 0;
    while (number > 0)
    {
        reversed = reversed * 10 + number % 10;
        number = number / 10;
    }
    return reversed;
}
int wordCounter(const string &word)
{
    int count = 0;
    bool inWord = false;

    for (char c : word)
    {
        if (isspace(c))
        {
            count++;
            inWord = false;
        }
        else
        {
            inWord = true;
        }
    }

    if (inWord)
    {
        count += 1;
    }

    return count;
}
vector<int> find_lowest_and_highest_number(vector<int> &list)
{
    int lowest = list[0];
    int highest = list[0];
    for (int i = 0; i <= list.size() - 1; i++)
    {
        int current = list[i];
        if (current < lowest)
        {
            lowest = current;
        }
        else if (current > highest)
        {
            highest = current;
        }
    };
    cout << lowest << " " << highest << endl;
    return {lowest, highest};
};

string password_gen()
{
    srand(time(0));
    signed int characterCount = rand() % 15 + 6;
    cout << characterCount << endl;
    string password = "";

    // Lisätään vähintään yksi pieni kirjain, iso kirjain ja numero
    password += 'a' + rand() % 26;
    password += 'A' + rand() % 26;
    password += '0' + rand() % 10;

    for (signed int i = 3; i < characterCount; i++)
    {
        signed int randomMethod = rand() % 3;
        switch (randomMethod)
        {
        case 0:
        {
            char lowercase = 'a' + rand() % 26;
            password += lowercase;
            break;
        }
        case 1:
        {
            char uppercase = 'A' + rand() % 26;
            password += uppercase;
            break;
        }
        case 2:
        {
            char numbercase = '0' + rand() % 10;
            password += numbercase;
            break;
        }
        }
    }
    return password;
}
int main()
{
    string password = password_gen();
    cout << password << endl;
    cout << flush;
    return 0;
}