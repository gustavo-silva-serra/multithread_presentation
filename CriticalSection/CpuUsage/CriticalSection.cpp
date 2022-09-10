#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// mutex m;

int main()
{
	int threads_count = 30;
	
	vector<thread> thrs;
	for (int i = 0; i < threads_count; ++i) {
		thrs.push_back(thread([&] {
			// m.lock();
			cout << "Sou a thread " << std::this_thread::get_id() << endl;
			// m.unlock();
		}));
	}
	for (int i = 0; i < threads_count; ++i) {
		thrs[i].join();
	}
}
