#include <iostream>

int function(int& x) {
    std::cout << "x = " << ++x << std::endl;
    return x;
}

int main(int argc, char const *argv[]) {
    int p = 4, q = 7;
    int y = p < q ? function(p) : function(q);
    std::cout << "y = " << y << std::endl;
    return 0;
}
