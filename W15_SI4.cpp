#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>


//ZAD1
int positive_sum(const std::vector<int> arr) {

    return std::accumulate(arr.begin(), arr.end(), 0, [](int a, int b) {return a + (b + std::abs(b)) / 2; });
}
//ZAD1 ALTERNATYWA
/*
int positive_sum(const std::vector<int> arr) {

    return std::accumulate(arr.begin(), arr.end(), 0, [](int a, int b) {if (b > 0) return a + b; else return a; });
}*/
//ZAD2
std::vector<int> MonkeyCount(int n) {
    std::vector<int>output(n);
    unsigned int i = 1;
    std::generate_n(output.begin(), n, [i]()mutable {return i++; });
    return output;
}

//ZAD3
std::vector<int> digitize(const int& n) {
    std::string temp1 = std::to_string(n);
    std::vector<int>output(temp1.length());
    std::transform(temp1.begin(), temp1.end(), output.begin(),
        [](char c) { return (int)c - 48; });
    return output;
}

//ZAD4
int getSum(int n)
{
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
int calc(const std::string& x) {
    std::vector<int>total1(x.length());
    std::vector<int>total2(x.length());
    std::transform(x.begin(), x.end(), total1.begin(),
        [](char c) { return (int)c; });

    std::transform(x.begin(), x.end(), total2.begin(),
        [](char c) {
            std::string s = std::to_string(int(c));
            std::replace(s.begin(), s.end(), '7', '1');
            return stoi(s); });

    int sumOfTotal1 = std::accumulate(total1.begin(), total1.end(), 0, [](int a, int b) {return a + getSum(b); });
    int sumOfTotal2 = std::accumulate(total2.begin(), total2.end(), 0, [](int a, int b) {return a + getSum(b); });
    return sumOfTotal1 - sumOfTotal2;
}

int main()

{
    std::cout << "ZAD1:\n";
    std::vector <int> myV{-1, 2, 3, 4, -5};
    std::cout << positive_sum(myV);
    std::cout << "\nZAD2:\n";
    for (auto x : MonkeyCount(5))
    {
        std::cout << x;
    }
    std::cout << "\nZAD3:\n";
    for (auto x : digitize(5312))
    {
        std::cout << x;
    }
    std::cout << "\nZAD4:\n";
    std::cout<<calc("AFHJD");
    

}
