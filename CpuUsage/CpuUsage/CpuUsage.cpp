#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

int main()
{
	int threads_count = 0;
	cout << "hardware_concurrency() = " << std::thread::hardware_concurrency() << endl;
	cout << "Informar numero de threads: ";
	cin >> threads_count;

	mutex m;

	vector<thread> thrs;
	for (int i = 0; i < threads_count; ++i) {
		thrs.push_back(thread([&] {
			m.lock();
			cout << "Sou a thread " << std::this_thread::get_id() << " filha de " << _getpid() << endl;
			m.unlock();
			int count = 0;
			while (true) count++;
			}));
	}
	thrs[0].join();
}
