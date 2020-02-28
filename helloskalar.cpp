#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef std::vector<int> Vektor;

template <typename T>
T skalarprodukt(const std::vector<T> &vektor1,const std::vector<T> &vektor2)
{
  if (vektor1.size() != vektor2.size())
  {
    throw std::invalid_argument("Vektordimensionen sind unpassend!");
  }
  int result = 0;
  for (int i = 0; i < vektor1.size();i++)
  {
    result += vektor1[i] * vektor2[i];
  }
  return result;
}

template <typename T>
T vektorbetrag(const std::vector<T> &vektor)
{
  return std::sqrt(skalarprodukt(vektor, vektor));
}

int main()
{
  Vektor r4_1 = {1,2,5,3};
  Vektor r4_2 = {5,3,5,2};
  Vektor r3 = {3,4,5};
  std::cout << "Skalarprodukt(r4) = " << skalarprodukt(r4_1, r4_2) << std::endl;
  std::cout << "Vektorbetrag(r3) = " << vektorbetrag(r3) << std::endl;

}
