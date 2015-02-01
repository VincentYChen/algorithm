#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        const char * text = s.c_str();
        for (int i = 0 ; i < strlen(text); ++i ){
            char c = text[i];
            if (c == '(' || c == '{' || c == '['){
                char_stack.push(c);
                continue;
            }

            if (char_stack.empty()){
                return false;
            }
            
            if (c == ')'){
                if ( char_stack.top() == '('){
                    char_stack.pop();
                    continue;
                }
                return false;
            }
            if (c == '}'){
                if ( char_stack.top() == '{'){
                    char_stack.pop();
                    continue;
                }
                return false;
            }
            if (c == ']'){
                if ( char_stack.top() == '['){
                    char_stack.pop();
                    continue;
                }
                return false;
            }
        }
        return char_stack.empty();
    }
};

int main()
{
    Solution s;
    std::cout << s.isValid("]");
    return 0;
}