#include <set>
#include <string>
#include <iostream>

std::set<int> operator+(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> output;
    for (auto s : s1)
        output.insert(s);
    for (auto s : s2)
        output.insert(s);
    return output;
}

std::set<int> operator-(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> output;
    for (auto s : s1)
        output.insert(s);
    for (auto s : s2)
        output.erase(s);
    return output;
}

std::set<int> operator^(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> output;
    for (auto s : s1)
        output.insert(s);
    for (auto s : s2)
    {
    	if (output.count(s) == 0)
            output.insert(s);
        else
            output.erase(s);
    }
    return output;
}

std::set<int> operator*(const std::set<int>& s1,const std::set<int>& s2)
{
    std::set<int> output;
    for (auto s : s1)
    {
        for (auto sd : s2)
    	    output.insert(s + sd);
    }
    return output;
}

std::set<int> operator^(const std::set<int>& s1,const int n)
{
    std::set<int> output = s1;
    for(int i = 1; i < n; i++)
        output = output * s1;
    return output;
}

std::set<std::string> operator*(const std::set<std::string>& s1,const std::set<std::string>& s2)
{
    std::set<std::string> output;
    for (auto s : s1)
    {
        for (auto sd : s2)
    	    output.insert(s + sd);
    }
    return output;
}

std::set<std::string> operator^(const std::set<std::string>& s1,const int n)
{
    if(n < 0)
        throw std::invalid_argument( "Negative value !" );
    if(n == 0)
        return std::set<std::string>{""};
    std::set<std::string> output = s1;
    for(int i = 1; i < n; i++)
        output = output * s1;
    return output;
}