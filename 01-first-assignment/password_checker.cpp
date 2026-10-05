/*
1,数字判断：原来的判断函数中使用的是严格大于或小于，这致使后面的数字判断层面在输入2～8以外的数字时会输出INVALID
2,长度判断：在length_ok函数中将>=写为了<=，这导致输入长度小于10长度的密码反而会输出true的结果
3,范围边界：digit_ok中判断被设置为了0到9,而不是'0'到'9'('0'到'9'的ascii编码是48到57)，这导致输入0～9都会导致输出INVALID
更改后的代码:
输入Li Ming 12345678Aa, Li Ming 123456Aa, Li Ming 12345678AA, Li Ming 12345678aa, Li Ming 12345678LiAa, Li Ming 12345678MingAa
输出VALID, INVALID, INVALID, INVALID, INVALID,INVALID
*/
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;          
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';                  
    return 0;
}