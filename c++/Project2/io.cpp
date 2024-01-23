#include <iostream>
int print(int x, int y) {
    std::cout<< x + y;
    return 0;
}
int getinput() {
    std::cout << "enter integer";
    int input{};
    std::cin >> input;
    return input;

}