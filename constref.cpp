// constref.cpp: demostrate const reference to temporaries
#include <iostream>

class MyClass {
	public:
	void perform() const {
		std::cout << "Performed" << std::endl;
	}
	~MyClass() {
		std::cout << "Destroyd" << std::endl;
	}
};

const MyClass &getObject() {
	const Base &base = Derived();
	base.perform();
	return base;
}

const int &perform( int a, int b ) {
	return a+b;
}

int main() {
	const int &result = perform( 2, 3 );
	std::cout << result << std::endl;
	return 0;
}
