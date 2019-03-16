#ifndef BIGINTEGER_LIBRARY_H
#define BIGINTEGER_LIBRARY_H

#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

class BigInteger {
    std::vector<uint32_t> _data;
    bool _isPositive;
    static const uint64_t _MOD = 1000000000;
    static const size_t _cell_size = 9;
 public:
    BigInteger() : _data(1, 0), _isPositive(true) {}

    BigInteger(std::string s);

    template<typename T,
            typename = typename std::enable_if<std::is_integral<T>::value>::type>
    BigInteger(T a) {
        if (std::is_signed<T>::value) {
            _isPositive = a >= 0;
            if (!_isPositive) a = -a;
        } else {
            _isPositive = true;
        }
        do {
            _data.push_back(a % _MOD);
            a /= _MOD;
        } while (a != 0);

    }

    std::string to_string() {
        if (_data.empty()) {
            return {};
        }
        std::string result;
        if (!_isPositive) result.push_back('-');
        result += std::to_string(_data.back());
        char buf[9];
        for (size_t i = _data.size() - 1; i--;) {
            sprintf(buf, "%09d", _data[i]);
            result += buf;
        }
        return result;
    }
};

#endif
