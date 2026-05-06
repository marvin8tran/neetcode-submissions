class Solution {
public:
    bool isValid(string s) {
        stack<int> m;

        for(char i : s){

            if(i == '(' || i == '{' || i == '['){
                m.push(i);
                continue;
            }

            if(i == ')'){
                if(m.empty()){return false;}
                if(m.top() == '('){m.pop();} 
                else{return false;}
            }
            if(i == '}'){
                if(m.empty()){return false;}
                if(m.top() == '{'){m.pop();} 
                else{return false;}
            }
            if(i == ']'){
                if(m.empty()){return false;}
                if(m.top() == '['){m.pop();} 
                else{return false;}
            }
        }
        return m.empty();



    }
};
