
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <typeinfo>

using namespace std;

class Animal {
public:
	Animal(string theName) {
		name = theName;
	}

	string getName() {
		return name;
	}

	void setOrder(int theOrder) {
		order = theOrder;
	}

	int getOrder() {
		return order;
	}

	operator int() const {
		return order;
	}

private:
	string name;
	int order;
};

class Cat: public Animal {
public:
	Cat(string theName): Animal(theName) {}
};

class Dog: public Animal {
public:
	Dog(string theName): Animal(theName) {}
};

class AnimalQueue {
public:
	AnimalQueue() {
		order = 0;
	}

	void enqueue(Animal a) {
		a.setOrder(order);
		order++;
		if (typeid(a) == typeid(Cat)) {
			catQueue.push(a);  // 出错，父类对象无法转为子类对象
		} else {
			dogQueue.push(a);
		}
	}

	Animal dequeueAny() {
		Animal theDog = dogQueue.front();
		Animal theCat = catQueue.front();
		if (theCat < theDog) {
			catQueue.pop();
			return theCat;
		}
		else {
			dogQueue.pop();
			return theDog;
		}                 
	}

	Animal dequeueDog() {
		Animal theDog = dogQueue.front();
		dogQueue.pop();
		return theDog;
	}

	Animal dequeueCat() {
		Animal theCat = catQueue.front();
		catQueue.pop();
		return theCat;
	}

private:
	queue<Cat> catQueue;
	queue<Dog> dogQueue;
	int order;
};

void test() {
	AnimalQueue animalQueue;
	Cat cat1("cat1");
	Cat cat2("cat2");
	Cat cat3("cat3");
	Dog dog1("dog1");
	Dog dog2("dog2");
	animalQueue.enqueue(cat1);
	animalQueue.enqueue(dog1);
	animalQueue.enqueue(cat2);
	animalQueue.enqueue(dog2);
	animalQueue.enqueue(cat3);
	cout << animalQueue.dequeueAny().getName() << endl;
	cout << animalQueue.dequeueCat().getName() << endl;
	cout << animalQueue.dequeueDog().getName() << endl;
	cout << animalQueue.dequeueAny().getName() << endl;
}

int main() {
	test();
	return 0;
}
