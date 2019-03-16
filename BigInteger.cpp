#include "BigInteger.h"

BigInteger::BigInteger(std::string s) : _isPositive(s.front() != '-') {
    uint64_t temp_MOD = 1;
    uint32_t number = 0;
    for (size_t i = s.length(); i-- && std::isalnum(s[i]);) {
        if (std::isdigit(s[i])) {
            number += (s[i] - '0') * temp_MOD;
        } else {
            number += (std::tolower(s[i]) - 'a' + 10) * temp_MOD;
        }
        temp_MOD *= 10;
        if (temp_MOD * 10 > _MOD) {
            _data.push_back(number);
            number = 0;
            temp_MOD = 1;
        }
    }
}