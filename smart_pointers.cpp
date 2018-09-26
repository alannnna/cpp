// https://en.cppreference.com/book/intro/smart_pointers
#include <memory>

void pointer1() {
	int* value_ptr = new int(15);
	int x = 45;
	if (x == 45) return;
	delete value_ptr;
}

void pointer2() {
    std::unique_ptr<int> value_ptr(new int(15));
    int x = 45;
    if (x == 45) return;
}

class Foo {
  public:
    void do_something() {}
};

class Bar {
  private:
    std::shared_ptr<Foo> foo_;
  public:
    Bar() { foo_ = std::shared_ptr<Foo>(new Foo()); }
    auto get_foo() { return foo_; }
};

int main() {
    pointer1();
    pointer2();

    Bar* bar = new Bar();
    std::shared_ptr<Foo> foo = bar->get_foo();
    foo->do_something();
    delete bar;

    return 0;
}
