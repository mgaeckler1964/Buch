/* thread.cpp - demonstration of concurrent library */
#include <iostream>
#include <chrono>
#include <ctime>
#include <mutex>
#include <future>

using namespace std::chrono_literals;

thread_local clock_t s_clockTime;

static void syncConsoleOut(const char* text, std::ostream& handle) {
	static std::mutex s_mutex;
	std::lock_guard		lock(s_mutex);
	handle << text;
}

static void setData() {
	s_clockTime = clock();
}

static clock_t readData() {
	clock_t	result = s_clockTime;
	return result;
}

static void theThreadFunc(void* arg) {
	std::promise<std::clock_t>& thePromise = *reinterpret_cast<std::promise<std::clock_t>*>(arg);

	setData();
	thePromise.set_value(readData());
}

int main(void) {

	setData();

	std::this_thread::sleep_for(1s);

	std::promise<std::clock_t>	thread1promise;
	std::future<std::clock_t>	thread1future = thread1promise.get_future();
	std::thread myThread1(theThreadFunc, &thread1promise);

	std::this_thread::sleep_for(1s);

	std::promise<std::clock_t>	thread2promise;
	std::future<std::clock_t>	thread2future = thread2promise.get_future();
	std::thread myThread2(theThreadFunc, &thread2promise);

	clock_t timer = readData();

	std::cout << "Main: " << timer << " Thread1 " << thread1future.get() << " Thread2 " << thread2future.get() << std::endl;

	myThread1.join();
	myThread2.join();

	return 0;
}