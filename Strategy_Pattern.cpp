#include <iostream>
using namespace std;

// I N T E R F A C E
//---------------------
class FlyBehavior {
	public: virtual void fly() const = 0;
	public: virtual ~FlyBehavior() = default;
};

class QuackBehavior {
	public: virtual void quack() const = 0;
	public: virtual ~QuackBehavior() = default;
};
//---------------------

class FlyWithWings : public FlyBehavior {
	public: void fly() const {
		std::cout << "Can Fly with Wings !!" << std::endl;
	}
};

class FlyNoWay: public FlyBehavior {
	public: void fly() const {
		std::cout << "Can't Fly !!" << std::endl;
	}
};

class Quack : public QuackBehavior {
	public: void quack() const {
		std::cout << "Can Quack !!" << std::endl;
	}
};

class MuteQuack : public QuackBehavior {
	public: void quack() const {
		std::cout << "Can't Quack !!" << std::endl;
	}
};

//-----------------------------

class Duck {
	public: void swim() const                                     { std::cout << "All ducks can swim !!" << std::endl; }
	public: void performQuack() const                             { pFlyBehavior_->fly(); }
	public: void performFly() const                               { pQuackBehavior_->quack(); }
	public: void SetFlyBehavior (FlyBehavior* pFlyBehavior)       { pFlyBehavior_ = pFlyBehavior; }
	public: void SetQuackBehavior (QuackBehavior* pQuackBehavior) { pQuackBehavior_ = pQuackBehavior; }

	public: virtual void display() const = 0;
	public: virtual ~Duck() = default;

	private: FlyBehavior*   pFlyBehavior_;
	private: QuackBehavior* pQuackBehavior_ ;
};

class MallardDuck : public Duck {
	void display() const { std::cout << "I'm a MallardDuck !!" << std::endl; }
};

//----------------------------------
int main() {
	Duck* mallard = new MallardDuck();

	mallard->SetFlyBehavior(new FlyWithWings);
	mallard->SetQuackBehavior(new MuteQuack);
	
	mallard->display();
	mallard->performFly();
	mallard->performQuack();
	std::cout << "======================" << std::endl;
	std::cout << "Now Changing Behaviors" << std::endl;
	std::cout << "======================" << std::endl;
	mallard->SetFlyBehavior(new FlyNoWay());
	mallard->SetQuackBehavior(new Quack());
	
	mallard->display();
	mallard->performFly();
	mallard->performQuack();

	return 0;
}
