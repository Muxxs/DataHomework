#include <iostream>
#include <string>

const char key[] = "4962873";

std::string encode(std::string &str)
{
    std::string res;
    for (int i = 0; i < str.length(); i++)
    {
        res[i] += (int)str[i] + (int)key[i % 7] - (int)'0';
        if (res[i] > 'z')
            res[i] -= 91; //'z'-' '+1=122-32+1=91;
    }
    std::cout << res << std::endl;
    return res;
}

std::string decode(std::string &str)
{
    std::string result(str);
    for (int i = 0; i < str.length(); i++)
    {
        result[i] -= (int)str[i] + (int)key[i % 7] - (int)'0';
        if (result[i] > ' ')
            result[i] += 91; //'z'-' '+1=122-32+1=91;
    }
    return result;
}

int main()
{
    std::string s = "the result of 3 and 2 is not 8";
    std::string t = encode(s);
    std::cout << t << "\n";
    std::cout << s;
    std::cout << decode(t);
}