#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic_int acnt;
int cnt;

void  f()
{
    for (int n = 0; n < 10000; ++n) {
        ++cnt;
        ++acnt;
    }
}

int main(void)
{
    std::vector<std::thread> thr;
    for (int n = 0; n < 10; ++n)
        thr.push_back(std::thread(f));
    for (int n = 0; n < 10; ++n)
        thr[n].join();

    std::cout << "The atomic counter is " << acnt << std::endl;
    std::cout << "The non-atomic counter is " << cnt << std::endl;
}