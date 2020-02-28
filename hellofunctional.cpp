#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> Ints;
typedef vector<double> Doubles;


int intsquare(int x)
{
  return x*x;
}

double doublesquare(double x)
{
  return x*x;
}

Ints square_vec_for(const Ints& xs)
{
  Ints ys;
  ys.reserve(xs.size());
  for (auto it = begin(xs); it != end(xs); ++it)
  {
    ys.push_back(intsquare(*it));
  }
  return ys;
}

Ints ranged_base_for(const Ints& xs)
{
  Ints ys;
  ys.reserve(xs.size());
  for (int x : xs)
  {
    ys.push_back(intsquare(x));
  }
  return ys;
}
template<typename T>
void Ausgabe(const vector<T> &xs)
{
  for (T x : xs)
  {
    cout << x << " ";
  }
  cout << endl;
}

template <typename F, typename T>
vector<T> transform_vec(F f, const vector<T>& xs)
{
  vector<T> ys;
  ys.reserve(xs.size());
  transform(begin(xs), end(xs), back_inserter(ys), f);
  return ys;
}


int main()
{
  Doubles d = {3.4,34.4,10.3,3.14};
  Ints v = {2,4,5,5,23,42,234,2};
  Ints v2 = transform_vec([](int x){return x+1;}, v);
  Ints v3 = transform_vec([](int x){return x-1;}, v);
  Ausgabe(v);
  Ausgabe(v2);
  Ausgabe(v3);
}
