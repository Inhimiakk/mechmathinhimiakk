#include <iostream>
#include <string>
#include <map>
#include <set>

int task20_1()
{
    // let our file be open on stdin
    std::map<std::string, unsigned> nums;
    std::string w;
    while (std::cin >> w)
        nums[w]++;
    for (const auto &[w, num] : nums)
    {
        std::cout << w << ": " << num << std::endl;
    }
}

int task20_2()
{
    size_t n;
    std::cin >> n;

    std::set<int> s;
    for (size_t i = 0; i < n; i++)
    {
        int v;
        std::cin >> v;
        s.insert(v);
    }

    while (s.size() > 1)
    {
        std::set<int> s0;
        auto iter = s.begin();
        int prev = *iter++;
        while (iter != s.end())
        {
            int cur = *iter++;
            s0.insert(cur + prev);
            prev = cur;
        }
        s = std::move(s0);
    }

    // assume that s not empty
    std::cout << *s.begin() << std::endl;
}

int task20_3(){

}

int main(){
    task20_1();
    task20_2();
    task20_3();
}