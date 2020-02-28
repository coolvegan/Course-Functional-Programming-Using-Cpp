#include <vector>
#include <iostream>

using namespace std;
typedef vector<int> Intvec;
template <typename F, typename T>
vector<T> keep_if(F f, const vector<T> &vec)
{
  vector<T> result;
  result.reserve(vec.size());
  for (T element : vec)
  {
    if (f(element)){
      result.push_back(element);
    }
  }
  return result;
}
template <typename T>
void ausgabe(const vector<T> &vec)
{
  for (T x : vec)
  {
    std::cout << x << ", ";
  }
  std::cout << std::endl;
}
int main()
{
  auto is_even = [](int i){ return i % 2 == 0; };
  Intvec v = {1,2,3,4,5,6,7,8,9,10};
  Intvec v2 = keep_if(is_even, v);
  ausgabe(v);
  ausgabe(v2);
}
