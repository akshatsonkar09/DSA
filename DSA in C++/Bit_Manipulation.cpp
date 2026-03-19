#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*Basically you have to left shift 1 by ith position and then use (&,|,^) based on need and change the bit for all ith bit questions*/

/*VVV IMP
n/2 = n>>1
n%2=1 == n&1 This is odd check*/

/*Set = 1
Not Set = 0*/

string decimal_to_binary(int n)
{
    string res = "";
    while (n != 1)
    {
        res += n % 2;
        n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int binary_to_decimal(string s)
{
    int num, p2 = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '1')
            num += p2;
        p2 *= 2;
    }
    return num;
}

void swap_number_without_third_variable (int a, int b) {
    a = a^b;
    b = a^b;        //(a^b)^b = a^(b^b) = a^0 = a       ^ =is XOR
    a = a^b;        //(a^b)^a = (a^a)^b = 0^b = b
    cout << "Numbers are swapped " << a << " " << b;
}

//brute force methods are converting them to binary, iterating till ith and changing
void Check_if_ith_number_is_set (int N, int pos) {
    /*left shift number 1 by i position and do & operation. Since all numbers due left shift are zero except the 1 at ith place. If & operation gives zero then ith is 0(Not set) if it gives 1 then ith is 1(Set)*/
    if (N & (1<<pos) == 1)
    {
        cout << "It is Set";
    }
    else
    {
        cout << "Not set";
    }

    /*For right shift
    if((N>>pos)&1==0) return true
    else return false*/
}

void Set_ith_bit(int N, int pos) {
    /*left shift number 1 by i position and do | operation. Since all numbers due left shift are zero except the 1 at ith place.| operation make 1 then ith is 0(Not set) and it makes 1 when ith is 1(Set)*/
    cout << (N | (1<<pos));
}

void Clear_ith_bit (int N, int pos) {
    cout << (N & ~(1<<pos));
}

void Toggle_ith_bit (int N, int pos) {
    cout << (N ^ (1<<pos));
}

void remove_last_set_bit (int N, int pos) {
    cout << (N & (N-1));
}

void check_if_power_of_2 (int N) {
    if((N&(N-1 == 0))) cout << " yes";
    else cout << "No";
}

void count_set_bits(int N) {
    int cnt = 0;
    while (N>1)
    {
        cnt += N&1;     //cnt += n%2
        N = N>>1;       //n/=2;
    }
}

int main()
{

    return 0;
}