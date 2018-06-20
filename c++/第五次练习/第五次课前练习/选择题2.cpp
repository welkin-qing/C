#include "iostream"
using namespace std;
class Test {
public:
static int square(int n)
{
  return n * n;
}

int getAge()
{
  return age;
}

//static int k = 5;
//static int::k=5;
//int k=5;
//const static int k =5;
private:
int age;
};
int main() {
cout << Test::square(4);
}
