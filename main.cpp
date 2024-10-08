#include <iostream>
#include <cw_tasks.h>

long long full_arr()
{
    long long ret=0;
    int ret2=0;

    std::string sum="";
    std::vector<std::string> first;
    std::vector<long long> second;
    for (int i=1;i<5;i++)
    {
        sum+=std::to_string(i);
        first.push_back(sum);
    }
    sum="";
    for (int i=0;i<first.size();i++)
    {
        second[i]=std::stoll(first[i]);
    }
    sum+="\0";
    ret2= std::stoi(sum);
    return ret2;
}

int solve(long long n){

}



int main()
{
   /* cw_tasks cw;
    std:: cout << cw.dblLinear(20) << std::endl;*/
    std:: cout << full_arr();
    return 0;
}
