#include "Span.hpp"
#include <exception>

int main(void)
{
    test("Adding less numbers than required should fail");
    try {
        Span s(10);
        s.addNumber(23);
        s.addNumber(23);
        s.addNumber(210);
        s.addNumber(223);
        s.addNumber(232);
        s.addNumber(21);
        s.addNumber(23);
        s.addNumber(22);
        s.print();
    } catch (std::exception &e) {
       errLog(e.what());
    }
    testOk(0);
 test("Adding more numbers than required should fail");
            try {
            Span s(10);
            s.addNumber(23);
            s.addNumber(23);
            s.addNumber(210);
            s.addNumber(223);
            s.addNumber(232);
            s.addNumber(21);
            s.addNumber(23);
            s.addNumber(22);
            s.addNumber(22);
            s.addNumber(0);
            s.addNumber(12);
            s.addNumber(34);
            s.addNumber(4);
            s.addNumber(31);
            s.addNumber(1);
            s.addNumber(34);
            s.print();
        } catch (std::exception &e) {
           errLog(e.what());
        }
	testOk(0);
	test("Size 0 should fail");
            try {
            Span s(0);
        } catch (std::exception &e) {
           errLog(e.what());
        }
	testOk(0);
	test("Size 1 should fail");
            try {
            Span s(1);
        } catch (std::exception &e) {
           errLog(e.what());
        }
	testOk(0);
	test("Mandatory should succeed");
	try{
	Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
           errLog(e.what());
        }
testOk(1);
    test("20,000 should succeed");
    try {
    Span s(20000);
    s.addMany();
    s.print();
} catch (std::exception &e) {
   errLog(e.what());
}
	testOk(1);
	return (0);
}
