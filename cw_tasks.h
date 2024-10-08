#ifndef CW_TASKS_H
#define CW_TASKS_H

#include <string>
#include <vector>

#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>

class cw_tasks
{
public:
    cw_tasks();
    std::string highAndLow(const std::string& numbers); //выводит минимальное и максимальное значение из строки     std::string array = "-1 -1";

    bool win_q(int grid[][7], int x, int y, int dx, int dy);
    std::string who_is_winner(std::vector<std::string> pieces_position_list);
    long long countOnesFromZeroTo(int n);
    long long countOnes(int left, int right);
    unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins);
    static int dblLinear(int n);






    bool isValidWalk(std::vector<char> walk);
    int getCount(const std::string& inputStr);
    static int digPow(int n, int p);
    std::vector<int> deleteNth(std::vector<int> arr, int n);
    int persistence(long long n);
    int findOdd(const std::vector<int>& numbers);
    int solution(int number);
    std::string likes(const std::vector<std::string> &names);
    std::vector<char> uniqueInOrder(const std::string& iterable);
    std::string pig_it(std::string str);
    std::string add(const std::string& a, const std::string& b);
    std::vector<int> snail(const std::vector<std::vector<int>> &snail_map);
    int josephusSurvivor(int n, int k);
    std::string to_roman(int num);
    int from_roman(std::string rome_num);
    std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, size_t n);
    std::string uint32_to_ip2(uint32_t ip);
    long parse_int(std::string number);
    std::string range_extraction(std::vector<int> args);
    bool validate_battlefield(std::vector<std::vector<int> > field);
    uint32_t partitions(uint32_t n);
    std::string format_duration(int seconds);
    unsigned int countPatternsFrom(char firstDot, unsigned short length);



};

#endif // CW_TASKS_H
