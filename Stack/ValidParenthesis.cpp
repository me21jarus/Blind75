class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;

        for(char c:s){
            if(c == '(' || c == '[' || c == '{'){
                sta.push(c);
            }
            else{
                if(sta.empty()) return false;

                if((c == '}' && sta.top() == '{') || (c == ']' && sta.top() == '[') || (c == ')' && sta.top() == '(')){
                    sta.pop();
                }else{
                    return false;
                }
            }
        }
        return sta.empty();
    }
};