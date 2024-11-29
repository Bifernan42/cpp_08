#include "MutantStack.hpp"
#include "cpplib.hpp"

int main() {
    MutantStack<int> mstack;
    test("Testing all basic stack operation should succeed");
    cmsg("Pushing 3 element on the MutantStack.. last is 30");
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    std::cout << "Top element: " << mstack.top() << std::endl;
    testOk(1);
    cmsg("Popping the top element of the stack...");
    mstack.pop();
    std::cout << "After popping, top element: " << mstack.top() << std::endl;
    testOk(1);
    cmsg("Let's evaluate the size ...");
    std::cout << "Stack size: " << mstack.size() << std::endl;

    cmsg("We then push some more elements... and reevaluate the size...");
    mstack.push(40);
    mstack.push(50);
    std::cout << "Stack size after more pushes: " << mstack.size() << std::endl;
    testOk(1);
    test("Iterators should succeed...");
    cmsg("iterating? form begining to end...");
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    testOk(1);

    cmsg("iteration from end to begining...");
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    testOk(1);
    test("Trying with a const MutantStack should succeed");
    const MutantStack<int> const_mstack = mstack; // Copy into a const stack
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    testOk(1);
    cmsg("Now trying const reverse iteration...");
    for (MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin(); crit != const_mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;
    testOk(1);

    test("Clearing the stack should succeed");
    while (!mstack.empty()) {
        std::cout << "Popping: " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::cout << "Stack is now empty. Size: " << mstack.size() << std::endl;
    testOk(1);
    test("Mandatory should succeed");

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; }
    std::stack<int> s(mstack);
    testOk(1);
    test("Mandatory with a different container should succeed");
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3); list.push_back(5); list.push_back(737); //[...] mstack.push(0);
    std::list<int>::iterator itl = list.begin(); std::list<int>::iterator itel = list.end();
    ++itl;
    --itl;
    while (itl != itel) {
        std::cout << *itl << std::endl;
    ++itl; }
    std::list<int> l(list);
    testOk(1);
    return 0;
}
