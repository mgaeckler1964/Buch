// virtuald.cc: demostrate virtual destructors
#include <iostream>
struct Base {
	virtual void perform() = 0;
	virtual ~Base() {}
};

class Derived : public Base {
	void perform() {
		std::cout << "Performed" << std::endl;
	}
	~Derived() {
		std::cout << "Destroyd" << std::endl;
	}
};

int main() {
	Base *ptr = new Derived;
	ptr->perform();
	delete ptr;
	return 0;
}
