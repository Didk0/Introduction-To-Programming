#include <iostream>
using namespace std;

const char* strStr(const char* str, const char* substr)
{
    size_t substrLen = strlen(substr);
    size_t pos;
    const char* strEnd = str + strlen(str);

    while (str + substrLen <= strEnd) {
        for (pos = 0; pos < substrLen; ++pos) {
            if (str[pos] != substr[pos]) {
                break;
            }
        }
        if (!substr[pos]) return str;
        ++str;
    }
    return nullptr;
}

int main()
{
    std::cout << strStr("Sample Text kekW More Sampe Text", "kekW") << std::endl;

}
