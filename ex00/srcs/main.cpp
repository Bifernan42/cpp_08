#include "easyfind.hpp"
#include "cpplib.hpp"
#include <vector>
#include <list>

int main() {
        test("Testing with vector should succeed");
        std::vector<int> vec(5);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;
        try {
            cmsg("searching for 10 should fail...");
            easyfind(vec, 10);
        } catch (const IntegerNotFound &e) {
            std::cerr << e.what() << std::endl;
        }
        testOk(1);
        test("Testing with list should succeed");
        std::list<int> lst(5);
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Found in list: " << *easyfind(lst, 20) << std::endl;

        try {
            cmsg("searching for 99 should fail...");
            easyfind(lst, 99);
        } catch (const IntegerNotFound &e) {
            std::cerr << e.what() << std::endl;
        }
        testOk(1);
    return (0);
}
