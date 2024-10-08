#include "cw_tasks.h"


cw_tasks::cw_tasks() {}

std::string cw_tasks::highAndLow(const std::string& numbers)
{
    std::vector<int> arr_int;
    std::string temp;
    for (int i=0;i<numbers.length();i++)
    {
        if (numbers[i]!=' ')
        {
            temp+=numbers[i];
        }
        else
        {
            arr_int.push_back(std::stoi(temp));
            temp="";
        }
    }
    arr_int.push_back(std::stoi(temp));
    int high=arr_int[0],low=arr_int[0];
    for (auto i : arr_int)
    {
        if (i>high)
        {
            high=i;
        }
        if (i<low)
        {
            low=i;
        }
    }
    return temp=std::to_string(high) + " " + std::to_string(low);

}
// игра 4 в ряд, два цвета
bool cw_tasks::win_q(int grid[][7], int x, int y, int dx, int dy)
{
    auto &&in_bound = [](int x, int y){return x >= 0 && y >= 0 && x < 6 && y < 7;};

    int color = grid[x][y];
    int same1 = 0, same2 = 0;
    for(int i = 1; i <= 3; ++i) {
        if(in_bound(x+dx*i, y+dy*i) && grid[x+dx*i][y+dy*i] == color) ++same1;
        else break;
    }
    for(int i = 1; i <= 3; ++i) {
        if(in_bound(x-dx*i, y-dy*i) && grid[x-dx*i][y-dy*i] == color) ++same2;
        else break;
    }
    return (same1 + same2 + 1) >= 4;
}

std::string cw_tasks::who_is_winner(std::vector<std::string> pieces_position_list)
{
    const int yellow = 1, red = 2;
    int grid[6][7] = {0};
    int counter[7] = {0};

    for(const auto &s : pieces_position_list) {
        int col = s[0]-'A';
        int row = counter[col]++;
        int color = s[2] == 'R'? red: yellow;
        grid[row][col] = color;

        if(win_q(grid, row, col, 1, 0) || win_q(grid, row, col, 0, 1) ||
            win_q(grid, row, col, 1, 1) || win_q(grid, row, col, 1, -1))
            return color == red? "Red": "Yellow";
    }
    return "Draw";
}

//сложение единичек двоичного кода чисел, между двух интов.
long long cw_tasks::countOnesFromZeroTo(int n) {
    long long res = 0;
    for (int i = std::numeric_limits<int>::digits - 1; i >= 0; i--) {
        int b = 1 << i;
        if (n & b)
            res += static_cast<long long>(i) * (b >> 1) + (n & b - 1) + 1;
    }
    return res;
}

long long cw_tasks::countOnes(int left, int right) {
    return countOnesFromZeroTo(right) - countOnesFromZeroTo(left - 1);
}

// задача на разбиение купюры на мелкие монеты
unsigned long long cw_tasks::countChange(const unsigned int money, const std::vector<unsigned int>& coins)
{
    std::vector<unsigned long long> ways(money + 1, 0);

    // Initialization
    ways[0] = 1;

    for (auto &coin : coins)
    {
        for (int i = 0; i < money + 1; ++i)
        {
            if (coin <= i) {
                ways[i] += ways[i - coin];
            }
        }
    }
    return ways[money];
}
int cw_tasks::dblLinear(int n)
{
    int ai=0,bi=0,eq=0;
    std::vector<int> sequence({1});
    int y;
    int z;
    while(ai+bi<n+eq)
    {
        y=2*sequence[ai]+1;
        z=3*sequence[bi]+1;
        if (y<z)
        {
            sequence.push_back(y);
            ai++;
        }
        if (y>z)
        {
            sequence.push_back(z);
            bi++;
        }
        if (y==z)
        {
            sequence.push_back(y);
            ai++;
            bi++;
            eq++;
        }
    }
    return sequence.back();
}














//задание на прогулку по городу в 10 шагов
/*
You live in the city of Cartesia where all roads are laid out in a perfect grid. You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. The city provides its citizens with a Walk Generating App on their phones -- everytime you press the button it sends you an array of one-letter strings representing directions to walk (eg. ['n', 's', 'w', 'e']). You always walk only a single block for each letter (direction) and you know it takes you one minute to traverse one city block, so create a function that will return true if the walk the app gives you will take you exactly ten minutes (you don't want to be early or late!) and will, of course, return you to your starting point. Return false otherwise.
Note: you will always receive a valid array containing a random assortment of direction letters ('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).

        Assert::That(isValidWalk(V{'n'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s','n','s'}), Equals(false));
        Assert::That(isValidWalk(V{'e','w','e','w','n','s','n','s','e','w'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'s','e','w','n','n','s','e','w','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','n'}), Equals(false));
        Assert::That(isValidWalk(V{'e','e','e','w','n','s','n','s','e','w'}), Equals(false));
}*/

bool cw_tasks::isValidWalk(std::vector<char> walk)
{
    if (walk.size()!=10) return false;
    int vertical = 0;
    int horizontal = 0;
    for (int i=0; i<10; i++)
    {
        if (walk[i]=='n') vertical++;
        if (walk[i]=='s') vertical--;
        if (walk[i]=='e') horizontal++;
        if (walk[i]=='w') horizontal--;
    }
    if ((vertical==0) && (horizontal==0)) return true;
    return false;
}

// вставляем 1 символ в конец первого слова, добавляем после ау.
std::string cw_tasks::pig_it(std::string str)
{
    auto numOfSpaces = std::count(str.begin(), str.end(), ' '); //нашли количество встраемых пробелов
    int wordStart = 0;
    // возвращаем индекс первого попавшегося пробела
    int wordEnd = str.find(" ");
    if (wordEnd == std::string::npos) //если пробелов нет то
    {
        if (str[0] == '!' || str[0] == '?' || str[0] == '.' || str[0] == ',')
        {
            return str; //возвращаем нулевой символ из перечисленных
        }
        str.append(1, str[0]); // т.к. пробелов 0, то мы нулевой символ вставляем в конец строки
        str.append("ay"); // добавляем после вставленного ау
        str.erase(0, 1); //удаляем с 0 по 1 символ у строки
        return str;
    }

    //пробелы есть, и слов несколько
    for (int word = 0; word <= numOfSpaces; ++word)
    {
        if (str[wordStart] == '!' || str[wordStart] == '?' || str[wordStart] == '.' || str[wordStart] == ',')
        {
            wordStart = wordStart + 2;
            if ((numOfSpaces - word) == 1) { wordEnd = str.size(); } //если количество пробелов равно 2, то конец слова = длинна строки
            else { wordEnd = str.find(" ", wordStart); }//конец слова = поиск пробела с момента вордстарт
            continue;
        }
        str.insert(wordEnd, 1, str[wordStart]); //в конец слова вставляем 1 символ, расположенный в строке по индексу [wordstart]
        str.insert(wordEnd + 1, "ay"); //после этого в конец слова+1 вставляем ау
        str.erase(wordStart, 1); //удаляем 1 символ начиная от вордстарт
        wordStart = wordEnd + 3; // увеличиваем вордстартна ворд енд+3
        if ((numOfSpaces - word) == 1) { wordEnd = str.size(); }//если количество пробелов равно 2, то конец слова = длинна строки
        else { wordEnd = str.find(" ", wordStart); }//конец слова = поиск пробела с момента вордстарт
    }

    return str;
}

// задание на возврат гласных букв из строки
//"abracadabra"
int cw_tasks::getCount(const std::string& inputStr)
{
    int num_vowels = 0;
    for (int i=0;i<inputStr.size();i++)
    {
        if (inputStr[i]=='a' || inputStr[i]=='e' || inputStr[i]=='i' || inputStr[i]=='o' || inputStr[i]=='u') num_vowels++;
    }
    return num_vowels;
}


// задача про забавные числа и их разложение
int cw_tasks::digPow(int n, int p)
{
    long sum=0;
    char c=0;
    std::string stroka=std::to_string(n);
    for (int i=0; i<stroka.size();i++)
    {
        c=stroka[i];
        sum+=std::pow(atoi(&c), p+i); //возведение в степень
    }
    if (sum%n==0)
    {
        return sum/n;
    }
    return -1;
}

// задача на удаление дубликатов из вектора, который встречается n раз
std::vector<int> cw_tasks::deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> newarr;
    std::unordered_map<int, int> ns;
    for (int x : arr)
        if (ns[x]++ < n)// записываем в унордеред мап значение: map[0]=first,second
            // first=значение, а second количество раз, сколько значение встретилось при добавлении
            //когда добавляется новое значение, то map[0]=1,1 ->map[1]=1,1 а на map[0] записывается новое значение
            // map[0]=3,1, если добавляем еще раз 3, то станет map[0]=3,2, а если добавить 1, то map[1]=1,2
            newarr.push_back(x);
    return newarr;
}

//задача на умножение цифр числа
int cw_tasks::persistence(long long n)
{
    std::string num_string=std::to_string(n);
    std::vector<int> vec_num;
    int step=0;
    char simv1;
    long long sum=1;
    for (unsigned int i=0;i<num_string.size();i++)
    {
        simv1=num_string[i];
        vec_num.push_back(atoi(&simv1));
    }
    while (vec_num.size()>1)
    {
        for (unsigned int  i=0;i<vec_num.size();i++)
        {
            sum*=vec_num[i];
        }
        num_string=std::to_string(sum);
        vec_num.clear();
        sum=1;
        step++;
        for (unsigned int i=0;i<num_string.size();i++)
        {
            simv1=num_string[i];
            vec_num.push_back(atoi(&simv1));
        }
    }
    return step;
    // your code here
}
// задача на поиск значения в векторе, которые встречается нечет количество раз
int cw_tasks::findOdd(const std::vector<int>& numbers)
{
    for (auto elem: numbers){
        if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) //количество встречаемых елементов в векторе
        {
            return elem;
        }
    }
    return 0;
}
// задача на сложение натурльынх числе ниже number кратных 3 и 5
int cw_tasks::solution(int number)
{
    int sum = 0;
    for (int n = 3; n < number; n++) {
        if ((n%3 == 0) || (n%5 == 0))
            sum += n;
    }
    return sum;
}

//задача на перечисление векторных значений
std::string cw_tasks::likes(const std::vector<std::string> &names)
{
    std::string like_text;
    switch(names.size()){
    case 0: like_text = "no one likes this";
    case 1: like_text = names[0] + " likes this";
    case 2: like_text = names[0] + " and " + names[1] + " like this";
    case 3: like_text = names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default: like_text = names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
    return like_text; // Do your magic!
}

std::vector<char> cw_tasks::uniqueInOrder(const std::string& iterable)
{
    std::vector<char> res;
    std::unique_copy (iterable.begin(), iterable.end(), std::back_inserter(res));
    return res;
}

// задача на сложение очень больших чисел полученных из строк и вернувшееся строкой
std::string cw_tasks::add(const std::string& a, const std::string& b) {
    bool temp=false;
    int sum=0;
    int raznica_length;
    std::string str= a;
    std::string str2= b;
    std::string return_str;
    std::string temp_str;
    if (str2.length()>str.length())
    {
        temp_str=str2;
        str2=str;
        str=temp_str;
    }
    raznica_length=str.size()-str2.size();
    return_str.resize(str.size());
    for (int i=str2.size();i>-1;i--)
    {
        if (temp)
        {
            sum=int(str[i+raznica_length])+int(str2[i])+1-96;
            if (sum>9)
            {
                sum=sum-10;
                temp=true;
            } else {temp=false;}
        } else
        {
            sum=int(str[i+raznica_length])+int(str2[i])-96;
            if (sum>9)
            {
                sum=sum-10;
                temp=true;
            } else {temp=false;}
        }
        return_str[i+raznica_length]=(char)(((int)'0')+sum);
    }
    for (int j=raznica_length-1;j>-1;j--)
    {
        if (temp)
        {
            sum=int(str[j])+1-48;
            if (sum>9)
            {
                sum=sum-10;
                temp=true;
            } else {temp=false;}
        } else
        {
            sum=int(str[j])-48;
            temp=false;
        }
        return_str[j]=(char)(((int)'0')+sum);
    }
    if (temp) return_str.insert(return_str.begin(),'1');
    return return_str;
}

//задача на змейку по векторам векторов
std::vector<int> cw_tasks::snail(const std::vector<std::vector<int>> &snail_map)
{
    int ogr_verh=0,
        ogr_niz=snail_map.size(),
        ogr_lev=0,
        ogr_pr=snail_map[0].size();
    bool turn_horz=1; //0-движемся влево, 1-движемся вправо
    bool turn_vert=1; //0-движемся вверх, 1-движемся вниз
    std::vector<int> return_vec;
    while ((ogr_verh<=ogr_niz) || (ogr_lev<=ogr_pr))
    {
        while(turn_horz&&turn_vert) //движение вправо в верхнем ряду
        {
            for (int i=ogr_lev;i<ogr_pr;i++)
            {
                return_vec.push_back(snail_map[ogr_verh][i]);
            }
            turn_horz=0;
            ogr_verh++;
        }
        while(!turn_horz&&turn_vert) //движение вниз в правом ряду
        {
            for (int i=ogr_verh;i<ogr_niz;i++)
            {
                return_vec.push_back(snail_map[i][ogr_pr-1]);
            }
            turn_vert=0;
            ogr_pr--;
        }

        while(!turn_horz&&!turn_vert) //двжиение влево в нижнем ряду
        {
            for (int i=ogr_pr-1;i>ogr_lev-1;i--)
            {
                return_vec.push_back(snail_map[ogr_niz-1][i]);
            }
            turn_horz=1;
            ogr_niz--;
        }
        while(turn_horz&&!turn_vert) //движение вверх в левом ряду
        {
            for (int i=ogr_niz-1;i>ogr_verh-1;i--)
            {
                return_vec.push_back(snail_map[i][ogr_lev]);
            }
            turn_vert=1;
            ogr_lev++;
        }
    }
    return return_vec;
}

int cw_tasks::josephusSurvivor(int n, int k)
{
    std::vector<int> rome_soldier(n);
    for (int i=0;i<n;i++)
        rome_soldier[i]=i+1;
    unsigned int last=0;
    for (int i=k-1;rome_soldier.size()>1;i+=(k-1)) //от 1 удаления, равного номеру "к", до тех пор, пока размер вектора больше 1, будем увеличивать на шаг равный "к-1"
    {
        last=i%rome_soldier.size();
        rome_soldier.erase(rome_soldier.begin()+last); // а удаляем тот элемент, который остался от деления на размер
        i=last;
    }
    return rome_soldier.at(0);
}
//конвертирование в римские числа
std::string cw_tasks::to_roman(int num)
{
    //создание азбуки соответствия
    std::string r[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string rome_num = "";
    for (int i = 0 ; i < 13; ++i)
    {
        //до тех пор, пока число на входе будет меньше числа из азбуки
        while (num >= n[i])
        {
            num -= n[i];    //вычитаем число из азбуки
            rome_num += r[i]; //добавляем букву соответствующую
        }
    }
    return rome_num;
}
//конвертирование из римских чисел
int cw_tasks::from_roman(std::string rome_num)
{
    //создали мапу соответствия, начиная с самого младшего
    std::unordered_map<char, int> ri = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int n = rome_num.size(), res = 0;
    //до тех пор, пока не дошли до конца строки
    for (int i = 0; i < n; ++i) {
        //i+1<n условие если не конец строки и число из мапы меньше следующего числа из мапы
        if (i + 1 < n && ri[rome_num[i]] < ri[rome_num[i+1]])
            res -= ri[rome_num[i]];
        else res += ri[rome_num[i]];
    }
    return res;
}
// перемножение векторов
std::vector<std::vector<int> > cw_tasks::matrix_multiplication(std::vector<std::vector<int> > &a, std::vector<std::vector<int> > &b, size_t n)
{
    std::vector<std::vector<int>> c(n, std::vector<int>(n));
    for (unsigned int i=0;i<a.size();i++)
    {
        for (unsigned int j=0;j<a[0].size();j++)
        {
            for(int t=0;t<n;t++)
                c[i][j]+=a[i][t]*b[t][j];
        }
    }
    return c;
}

// инвертирование ipадреса в строку
std::string cw_tasks::uint32_to_ip2(uint32_t ip)
{
    return
        std::to_string(ip>>24 & 255) + "." + //сдвиг старшего байта ip адреса на 24 бита вправо,
        //побитово выполняем операцию "И" с числом 255(1111 11111)
        std::to_string(ip>>16 & 255) + "." +
        std::to_string(ip>>8 & 255) + "." +
        std::to_string(ip & 255);

    /*
    std::vector<int> test;
    int temp=0;
    std::string ip_addr = "";
    if (ip==0) ip_addr="0.0.0.0"; else
    {while (ip > 0)
    {
    for (int i = 31; i >= 0; i--)
        {
            if (pow(2, i) <= ip)
            {
                ip -= pow(2, i);
                test.push_back(1);
            } else
            {
                test.push_back(0);
            }
        }
    }
    for (int var = 0; var < 8; var++)
    {
        temp+=test[var]*pow(2,7-var);
    }
    ip_addr+=std::to_string(temp);
    ip_addr+='.';
    temp=0;
    for (int var = 8; var < 16; var++)
    {
        temp+=test[var]*pow(2,15-var);
    }
    ip_addr+=std::to_string(temp);
    ip_addr+='.';
    temp=0;
    for (int var = 16; var < 24; var++)
    {
        temp+=test[var]*pow(2,23-var);
    }
    ip_addr+=std::to_string(temp);
    ip_addr+='.';
    temp=0;
    for (int var = 24; var < 32; var++)
    {
        temp+=test[var]*pow(2,31-var);
    }
    ip_addr+=std::to_string(temp);
    temp=0;}
    return ip_addr;*/
}

//делим строку пробелом и не только, после чего ищем совпадение с мапой
long cw_tasks::parse_int(std::string number)
{
    std::map<std::string,int> vals =
        { //важно добавить еще слово "and"
            {"and",0}, {"zero",0},  {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9},
            {"ten",10}, {"eleven",11}, {"twelve",12}, {"thirteen",13}, {"fourteen",14}, {"fifteen",15}, {"sixteen",16}, {"seventeen",17}, {"eighteen",18}, {"nineteen",19},
            {"twenty",20}, {"thirty",30}, {"forty",40}, {"fifty",50}, {"sixty",60}, {"seventy",70}, {"eighty",80}, {"ninety",90},
            {"hundred",100}, {"thousand",1000}, {"million",1000000}
        };
    for( auto &c : number ) //очень важно не потерять адрес итератора
    { //меняем дефис на пробел
        if( c == '-' ) c = ' ';
    }
    std::stringstream ss(number);
    std::string word;
    int num = 0, totalNum = 0;
    // начинаем считывать слова из входного потока "ss" который был создан с помощь конструктора stringstream
    while(ss>>word)
    {   // ищем в мапе слово и находим его значение
        auto it = vals.find(word);
        if( it != vals.end() )
        {
            if( it->second == 100 ) {
                num *= 100;
            } else if( it->second == 1000 ) {
                totalNum += num * 1000;
                num = 0;
            } else if ( it->second == 1000000 ) {
                totalNum += num * 1000000;
                num = 0;
            } else {
                num += it->second;
            }
        }
    }
    totalNum += num;
    return totalNum;
}
//удаление подряд идущих значений, и запись строки интов
std::string cw_tasks::range_extraction(std::vector<int> args)
{
    std::string str_return="";
    bool numb_is=false;
    if (args.size()==0)
        return "empty";
    std::sort(args.begin(),args.end());
    for (unsigned int i=0;i<args.size();i++)
    {
        if (args[i]==args[i+1]-1 && args[i]==args[i+2]-2)
        {
            if (!numb_is)
            {
                str_return+=std::to_string(args[i]);
                numb_is=true;
                str_return+="-";
            }
        } else
        {
            if (numb_is)
            {
                i++;
                str_return+=std::to_string(args[i]);
                str_return+=",";
                numb_is=false;
            } else
            {
                numb_is=false;
                str_return+=std::to_string(args[i]);
                str_return+=",";
            }
        }
    }
    str_return.pop_back();
    return str_return;
}
// морской бой правила расстановки кораблей
bool cw_tasks::validate_battlefield(std::vector<std::vector<int> > field)
{
    int ship_4cel=0, ship_3cel=0, ship_2cel=0, ship_1cel=0;
    int temp=0;
    for (unsigned int x=0;x<field.size();x++)
    {
        for (unsigned int y=0;y<field[x].size();y++)
        {
            //определение типа корабля и количества кораблей
            if (field[y][x])
            {
                temp++;
            } else
            { if (temp!=0)
                {
                    if (temp>4) return false;
                    if (temp==4) {ship_4cel++; temp=0;}
                    if (temp==3) {ship_3cel++; temp=0;}
                    if (temp==2) {ship_2cel++; temp=0;}
                    if (temp==1) {temp=0;}
                }
            }
        }
    }
    for (unsigned int x=0;x<field.size();x++)
    {
        for (unsigned int y=0;y<field[x].size();y++)
        {
            //проверка на то, чтоб по диагонали от корабля не было пересечений
            if (field[x][y])
            {
                if (x>0 && y>0 && field[x-1][y-1]) return false;
                if (x>0 && y<field.size()-1 && field[x-1][y+1]) return false;
                if (x<field.size()-1 && y>0 && field[x+1][y-1]) return false;
                if (x<field.size()-1 && y<field.size()-1 && field[x+1][y+1]) return false;
            }
            //определение типа корабля и количества кораблей
            if (field[x][y])
            {
                temp++;
            } else
            { if (temp!=0)
                {
                    if (temp>4) return false;
                    if (temp==4) {ship_4cel++; temp=0;}
                    if (temp==3) {ship_3cel++; temp=0;}
                    if (temp==2) {ship_2cel++; temp=0;}
                    if (temp==1) {temp=0;}
                }
            }
            if (field[x][y]) {ship_1cel++;}
        }
    }
    ship_1cel-=ship_4cel*4+ship_3cel*3+ship_2cel*2;
    if (ship_4cel!=1) return false;
    if (ship_3cel!=2) return false;
    if (ship_2cel!=3) return false;
    if (ship_1cel!=4) return false;
    return true;
}
//задача на полиндром, раскладываем числа 5=5,4+1,3+2,3+1+1,2+2+1,2+1+1+1,1+1+1+1+1 итого 7 разложений
uint32_t cw_tasks::partitions(uint32_t n)
{
    std::vector<uint32_t> c(n+1,0); // создали вектор длинною n+1, заполненный нулями
    c[0]=1;  // первый элемент делаем равным 1
    for (unsigned int k = 1; k <= n; ++k) // прибавляем к элементу вектора под номеном [i+k]
        //значение вектора расположенного под номером [i]
        for (unsigned int i = 0; (i + k) <= n; ++i)
            c[i + k]+=c[i];
    return c[n];
}

//преобразование секунд в обычный формат(год,день,час, минута, секунда)
std::string cw_tasks::format_duration(int seconds)
{
    std::string str_ret="";
    if (seconds==0) return "now";
    int y_ret=0, d_ret=0, h_ret=0, m_ret=0, s_ret=0;
    int flag_all=0,flag_now=0;
    s_ret=seconds%60;
    m_ret=((seconds-s_ret)/60)%60;
    h_ret=((seconds-s_ret-m_ret*60)/3600)%24;
    d_ret=((seconds-h_ret*3600-m_ret*60-s_ret)/86400)%365;
    y_ret=(seconds-d_ret*86400-h_ret*3600-m_ret*60-s_ret)/31536000;
    if (y_ret!=0) flag_all++;
    if (d_ret!=0) flag_all++;
    if (h_ret!=0) flag_all++;
    if (m_ret!=0) flag_all++;
    if (s_ret!=0) flag_all++;
    switch(y_ret){
    case 0:
    {
        str_ret += "";
        break;

    }
    case 1:
    {
        str_ret +=std::to_string(y_ret)+" year";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    default:
    {
        str_ret += std::to_string(y_ret)+" years";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    }
    switch(d_ret){
    case 0:
    {
        str_ret += "";
        break;

    }
    case 1:
    {
        str_ret +=std::to_string(d_ret)+" day";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    default:
    {
        str_ret += std::to_string(d_ret)+" days";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    }
    switch(h_ret){
    case 0:
    {
        str_ret += "";
        break;

    }
    case 1:
    {
        str_ret +=std::to_string(h_ret)+" hour";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    default:
    {
        str_ret += std::to_string(h_ret)+" hours";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    }
    switch(m_ret){
    case 0:
    {
        str_ret += "";
        break;

    }
    case 1:
    {
        str_ret +=std::to_string(m_ret)+" minute";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    default:
    {
        str_ret += std::to_string(m_ret)+" minutes";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    }
    switch(s_ret){
    case 0:
    {
        str_ret += "";
        break;

    }
    case 1:
    {
        str_ret +=std::to_string(s_ret)+" second";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    default:
    {
        str_ret += std::to_string(s_ret)+" seconds";
        flag_now++;
        if ((flag_all-flag_now)==1) str_ret += " and ";
        if ((flag_all-flag_now)>1) str_ret += ", ";
        break;
    }
    }
    return str_ret;
}

//кодовый замок из букв, подобрать количество комбинаций возможных, в зависиомсти от длинны
int maze[3][3];
int dfs(int x, int y, int length, long long val)
{
    if (length == 0) return 1;
    int ret = 0;
    for (int i=0; i < 3; ++i)
        for (int j=0; j < 3; ++j) {
            if (maze[i][j]) continue;
            int a = abs(x+i), b = abs(y+j);
            maze[i][j] = 1;
            if (((a|b)&1) || maze[a>>1][b>>1]) {
                ret += dfs(i, j, length-1, (val+i)*10+j);
            }
            maze[i][j] = 0;
        }
    return ret;
}

unsigned int cw_tasks::countPatternsFrom(char firstDot, unsigned short length)
{
    if (length <= 0 || length >= 10) return 0;
    static int dp[5][10] = {0};
    firstDot -= 'A';
    firstDot = firstDot == 4 ? 4 : firstDot&1;
    int x = firstDot/3, y = firstDot%3;
    if (dp[firstDot][length])
        return dp[firstDot][length];
    maze[x][y] = 1;
    dp[firstDot][length] = dfs(x, y, length-1, 10 + firstDot);
    maze[x][y] = 0;
    return dp[firstDot][length];
}



// задача на азбуку морзе
/*class Node {
public:
    std::string data;
    Node* dash; //подчеркивание
    Node* dot; // точка

    Node(std::string val)
    {
        data = val;
        dash = nullptr;
        dot = nullptr;
    }
};

void deleteTree(Node* node)
{
    if (node == nullptr) return;
    deleteTree(node->dot);
    deleteTree(node->dash);
    delete node;
}

std::string decodeMorse(const std::string morseCode) {
    std::cout << morseCode << std::endl;
    bool space = false;
    bool first = false;
    std::string decoded;
    Node* root = new Node(" ");
    root->dot  = new Node("E");
    root->dash = new Node("T");
    root->dot->dot = new Node("I");
    root->dot->dash = new Node("A");
    root->dash->dot = new Node ("N");
    root->dash->dash = new Node("M");
    root->dot->dot->dot = new Node("S");
    root->dot->dot->dash = new Node("U");
    root->dot->dash->dot = new Node("R");
    root->dot->dash->dash = new Node("W");
    root->dash->dot->dot = new Node ("D");
    root->dash->dot->dash = new Node ("K");
    root->dash->dash->dot = new Node("G");
    root->dash->dash->dash = new Node("O");
    root->dot->dot->dot->dot = new Node("H");
    root->dot->dash->dot->dot = new Node("L");
    root->dot->dash->dash->dot = new Node("P");
    root->dot->dash->dash->dash = new Node("J");
    root->dot->dot->dash->dot = new Node("F");
    root->dot->dot->dot->dash = new Node("V");
    root->dash->dot->dot->dot = new Node ("B");
    root->dash->dot->dot->dash = new Node ("X");
    root->dash->dot->dash->dot = new Node ("C");
    root->dash->dot->dash->dash = new Node ("Y");
    root->dash->dash->dot->dot = new Node("Z");
    root->dash->dash->dot->dash = new Node ("Q");
    root->dot->dot->dash->dash = new Node (" ");
    root->dash->dash->dash->dot = new Node (" ");
    root->dash->dash->dash->dash = new Node (" ");
    root->dot->dash->dash->dash->dash = new Node ("1");
    root->dot->dot->dash->dash->dash = new Node ("2");
    root->dot->dot->dot->dash->dash = new Node ("3");
    root->dot->dot->dot->dot->dash = new Node ("4");
    root->dot->dot->dot->dot->dot = new Node ("5");
    root->dash->dot->dot->dot->dot = new Node ("6");
    root->dash->dash->dot->dot->dot = new Node ("7");
    root->dash->dash->dash->dot->dot = new Node ("8");
    root->dash->dash->dash->dash->dot = new Node ("9");
    root->dash->dash->dash->dash->dash = new Node ("0");
    root->dot->dot->dot->dash->dash->dash = new Node (" ");
    root->dot->dot->dot->dash->dash->dash->dot = new Node (" ");
    root->dot->dot->dot->dash->dash->dash->dot->dot = new Node (" ");
    root->dot->dot->dot->dash->dash->dash->dot->dot->dot = new Node ("SOS");
    root->dot->dash->dot->dash = new Node (" ");
    root->dot->dash->dot->dash->dot = new Node (" ");
    root->dot->dash->dot->dash->dot->dash = new Node (".");
    root->dash->dot->dash->dot->dash = new Node (" ");
    root->dash->dot->dash->dot->dash->dash = new Node ("!");


    Node* adress = root;
    for (auto i : morseCode) {
        if (i == ' ' && space){space = false; continue;}
        else if (i == '.'){adress = adress->dot; space = false; first = true;}
        else if (i == '-'){adress = adress->dash; space = false; first = true;}
        else if (i == ' ' && first){decoded += adress->data; adress = root; space = true;}
    }
    decoded += adress->data;
    while (decoded[decoded.size() - 1] == ' '){
        decoded.erase(decoded.end() - 1);
    }
    deleteTree(root);
    return decoded;
}
*/
