class Solution {
public:
    bool isValid(string s) {
        stack<char> left;

        for(char n : s){
            if(n == '[' || n == '(' || n == '{'){
                left.push(n);
            } else{
                if(left.empty()){return false;}
                if(n == ']' && left.top() != '['){return false;}
                if(n == '}' && left.top() != '{'){return false;} 
                if(n == ')' && left.top() != '('){return false;}
                left.pop();
            }
        }        
        return left.empty();
    }
};
