#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class my_class {
    string label;
public:
    my_class(const string& name): label(name) {
        cout << "label = " << label << endl; 
    }

    my_class(const my_class& mc) {
        cout << "Copying: " << mc.label << endl; 
    }

    my_class(const my_class&& mc) {
        cout << "Moving: " << mc.label << endl; 
    }

    ~my_class() {
        cout << "Destroying: " << label << endl;
    }
};

my_class create_something(int id) {
    std::stringstream name;
    name <<  "Number " << id;
    my_class object(name.str());
    // maybe do something else
    return object;
}

int main() {
    std::stack<my_class> stack;
    my_class hello("hello");
    stack.push(hello);
    stack.emplace(create_something(1));
    my_class&& two = create_something(2);
    stack.emplace(two);
    stack.push({"test_push"});
    stack.emplace("test_emplace");
    //stack.emplace({"test_emplace_with_move"});
    stack.push(my_class("hello 4"));
    stack.emplace(my_class("hello 5"));
    return 0;
}