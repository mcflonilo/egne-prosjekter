#include <cstdint> 
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "creature.h"
#include "Point2D.h"
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <array>
#include <numeric>
#include <vector>
#include <random>
#include <ctime>
#include <cassert>
#include <functional>
#include "IntArray.h"
#include <initializer_list>
#include <string_view>
#include <chrono>

template <typename T, typename G>
class Pair
{
private:
    T m_first;
    G m_second;
public:

    Pair(const T& first, const G& second)
    {
        m_first = first;
        m_second = second;
    }
    const T& first() const {
        return m_first;
    }
    const G& second() const {
        return m_second;
    }
};

template <typename G>
class StringValuePair : public Pair<std::string, G>
{
public:

    StringValuePair(const std::string& first, const G& second)
        :Pair<std::string, G> {first, second}
    {
    } 
};


int main()
{
    StringValuePair<int> svp{ "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}