/**
 * This main.cpp file contains various small functions that I implemented while practicing the C++ language.
 * 2025, Created by Don Hämäläinen
 */

#include <iostream>
#include <random>
#include <vector>
#include <string>

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

/*
Clock shows h hours, m minutes and s seconds after midnight.
Your task is to write a function which returns the time since midnight in milliseconds.

h = x * 60^2 * 1000
m = x * 60 * 1000
s = x * 1000
*/
int past(int h, int m, int s)
{
    // First we check the input is correct
    if (!(h <= 23 && h >= 0) || !(m <= 59 && m >= 0) || !(s <= 59 && s >= 0))
    {
        cout << "Wrong format" << endl;
        return 0;
    };
    return (h * 60 * 60 * 1000) + (m * 60 * 1000) + (s * 1000);
}

/*
There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.
You receive an array with your peers' test scores. Now calculate the average and compare your score!
Return true if you're better, else false!

Note: Your points are not included in the array of your class's points. Do not forget them when calculating the average score!
*/
bool betterThanAverage(std::vector<int> classPoints, int yourPoints)
{
    int totalpoint = 0;
    int average = 0;
    for (int num : classPoints)
    {
        totalpoint += num;
    };
    average = totalpoint / classPoints.size();
    if (yourPoints > average)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
Given an array of integers.
Return an array, where the first element is the count of positives numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.
If the input is an empty array or is null, return an empty array.

Example
For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].


 */
std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    int countPositive = 0;
    int sumNegative = 0;
    if (input.size() == 0)
    {
        return {};
    }
    for (int num : input)
    {
        if (num > 0)
        {
            countPositive++;
        }
        if (num < 0)
        {
            sumNegative += num;
        }
    }
    return {countPositive, sumNegative};
}

/*
In this kata you have to correctly return who is the "survivor", ie: the last element of a Josephus permutation.
Basically you have to assume that n people are put into a circle and that they are eliminated in steps of k elements, like this:

n=7, k=3 => means 7 people in a circle
one every 3 is eliminated until one remains
[1,2,3,4,5,6,7] - initial sequence
[1,2,4,5,6,7] => 3 is counted out
[1,2,4,5,7] => 6 is counted out
[1,4,5,7] => 2 is counted out
[1,4,5] => 7 is counted out
[1,4] => 5 is counted out
[4] => 1 counted out, 4 is the last element - the survivor!
The above link about the "base" kata description will give you a more thorough insight about the origin of this kind of permutation, but basically that's all that there is to know to solve this kata.

Notes and tips: using the solution to the other kata to check your function may be helpful, but as much larger numbers will be used, using an array/list to compute the number of the survivor may be too slow; you may assume that both n and k will always be >=1.
 */

int josephusSurvivor(int n, int k)
{
    vector<int> list;
    list.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        list.push_back(i);
    }

    int currentIndex = 0;
    while (list.size() > 1)
    {
        currentIndex = ((currentIndex + k) - 1) % list.size();
        list.erase(list.begin() + currentIndex);
    }
    return list[0];
}

/*
How can you tell an extrovert from an introvert at NSA?
Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it?
According to Wikipedia, ROT13 is frequently used to obfuscate jokes on USENET.

For this task you're only supposed to substitute characters. Not spaces, punctuation, numbers, etc.

Test examples:

"EBG13 rknzcyr." -> "ROT13 example."

"This is my first ROT13 excercise!" -> "Guvf vf zl svefg EBG13 rkprepvfr!"
*/

std::string rot13(const std::string &str)
{
    std::string result = "";
    // upperCase = A = 65 and Z = 90
    // lowerCase = a = 97 and z = 122
    // new_char=(current_char − ′A′+ 13) % 26 + ′A′
    //  INPUT:  ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz
    //  OUTPUT: NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm
    for (char letter : str)
    {
        if (letter >= 'A' && letter <= 'Z')
        {
            result += (letter - 'A' + 13) % 26 + 'A';
        }
        else if (letter >= 'a' && letter <= 'z')
        {
            result += (letter - 'a' + 13) % 26 + 'a';
        }
        else
        {
            result += letter;
        }
    };

    return result;
}

bool checkNumber(int x)
{
    return (x > 1);
}

/*
Consider a Bayesian network for avalanche risk analysis where
the occurence of avalanche (A, +a: yes, -a: no) depends on the steepness of the
mountain area (S, +s: steep, -s: gently) and the snow conditions (C, +c: unstable, -c: stable). Furthermore, snow conditions depends on the recent weather (W,
+w: unfavourable, -w: favourable), where unfavourable weather increases the unstability of snow conditions. The marginal and conditional probability tables are
given below.

(a) Construct a Bayesian network for a given problem.
(b) Calculate P(A | +s), i.e., the probability distribution of avalanche occurence
when skiing on a steep mountain area. Use variable elimination to perform the
inference (i.e., performing join and eliminate/marginalize operations by turns).

S = Steepness of the mountain area (S, +s: steep, -s: gently)
A = Avalance condition (A, +a: yes, -a: no)
C = Snow conditions (C, +c: unstable, -c: stable)
W = Recent weather (W, +w: unfavourable, -w: favourable)

S P(S) | W P(W)
-------|--------
+s 0.1 | +w 0.6
-s 0.9 | -w 0.4
----------------
S C A    | P(A | S,C)
---------|------------
+s +c +a | 0.90
+s +c -a | 0.10
+s -c +a | 0.30
+s -c -a | 0.70
-s +c +a | 0.20
-s +c -a | 0.80
-s -c +a | 0.02
-s -c -a | 0.98
----------------------
W C   | P(C | W)
------|----------
+w +c | 0.8
+w -c | 0.2
-w +c | 0.3
-w -c | 0.7
-----------------
 */
enum Weather
{
    W_FAVOURABLE,
    W_UNFAVOURABLE
}; // -w +w
enum Steepness
{
    S_GENTLE,
    S_STEEP
}; // -s +s
enum SnowCond
{
    C_STABLE,
    C_UNSTABLE
}; // -c +c
enum Avalanche
{
    A_NO,
    A_YES
}; // -a +a

// CPT
struct BayesianNetwork
{
    // P(W)
    double P_W[2];

    // P(S)
    double P_S[2];

    // P(C | W) -> 2 x 2 table
    // C can be [C_STABLE, C_UNSTABLE] and W [W_FAVOURABLE, W_UNFAVOURABLE]
    double P_C_given_W[2][2];

    // P(A | S, C) -> 2 x 2 x 2 table
    // A can be [A_NO, A_YES]
    // S can be [S_GENTLE, S_STEEP]
    // C can be [C_STABLE, C_UNSTABLE]
    double P_A_given_S_C[2][2][2];
};
//
double calculate(BayesianNetwork BN)
{
    // P(C+) = P(C+ | W+) * P(W+) + P(C+ | -W) * P(W-)
    double P_C_plus = BN.P_C_given_W[C_UNSTABLE][W_UNFAVOURABLE] * BN.P_W[W_UNFAVOURABLE] + BN.P_C_given_W[C_UNSTABLE][W_FAVOURABLE] * BN.P_W[W_FAVOURABLE];
    double P_C_minus = 1 - P_C_plus;

    // P(A+ | S+) = P(A+ | S+, C+) * P(S+, C+) + P(A+ | S-, C+) * P(S-, C+)
    double P_A_Plus_with_S = BN.P_A_given_S_C[A_YES][S_STEEP][C_UNSTABLE] * P_C_plus + BN.P_A_given_S_C[A_YES][S_STEEP][C_STABLE] * P_C_minus;
    double P_A_Minus_with_S = 1 - P_A_Plus_with_S;

    // P(C+ ∣ W+) = 0.8, P(C- ∣ W+) = 0.2

    // Tulosta debuggausta varten
    cout << "P(A+ | S=+s) = " << P_A_Plus_with_S << endl;
    cout << "P(A- | S=+s) = " << P_A_Minus_with_S << endl;
    return 0;
};
void Bayesian_network_for_avalanche()
{
    BayesianNetwork BN;

    // P(W = +w) = 0.4, P(W = -w) = 0.6 tms.
    BN.P_W[W_FAVOURABLE] = 0.6;   // P(W = -w)
    BN.P_W[W_UNFAVOURABLE] = 0.4; // P(W = +w)

    // P(S = +s) = 0.1, P(S = -s) = 0.9
    BN.P_S[S_GENTLE] = 0.9; // P(S = -s)
    BN.P_S[S_STEEP] = 0.1;  // P(S = +s)

    // P(C | W)
    BN.P_C_given_W[W_FAVOURABLE][C_STABLE] = 0.8;     // +w +c | 0.8
    BN.P_C_given_W[W_FAVOURABLE][C_UNSTABLE] = 0.2;   // +w -c | 0.2
    BN.P_C_given_W[W_UNFAVOURABLE][C_STABLE] = 0.3;   // -w +c | 0.3
    BN.P_C_given_W[W_UNFAVOURABLE][C_UNSTABLE] = 0.7; // -w -c | 0.7

    // P(A | S, C)
    BN.P_A_given_S_C[S_STEEP][C_UNSTABLE][A_YES] = 0.9;  // +s +c +a | 0.90
    BN.P_A_given_S_C[S_STEEP][C_UNSTABLE][A_NO] = 0.1;   // +s +c -a | 0.10
    BN.P_A_given_S_C[S_STEEP][C_STABLE][A_YES] = 0.3;    // +s -c +a | 0.30
    BN.P_A_given_S_C[S_STEEP][C_STABLE][A_NO] = 0.7;     // +s -c -a | 0.70
    BN.P_A_given_S_C[S_GENTLE][C_UNSTABLE][A_YES] = 0.2; // -s +c +a | 0.20
    BN.P_A_given_S_C[S_GENTLE][C_UNSTABLE][A_NO] = 0.8;  // -s +c -a | 0.80
    BN.P_A_given_S_C[S_GENTLE][C_STABLE][A_YES] = 0.02;  // -s -c +a | 0.02
    BN.P_A_given_S_C[S_GENTLE][C_STABLE][A_NO] = 0.98;   // -s -c -a | 0.98

    calculate(BN);
}
int main()
{
    int num1 = 42;
    int num2 = -7;
    int num3 = 0;

    std::cout << "Is " << num1 << " positive? " << (checkNumber(num1) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << num2 << " positive? " << (checkNumber(num2) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << num3 << " positive? " << (checkNumber(num3) ? "Yes" : "No") << std::endl;

    return 0;
}