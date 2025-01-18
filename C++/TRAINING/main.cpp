#include <iostream>
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

int main()
{
    cout << flush;
    return 0;
}