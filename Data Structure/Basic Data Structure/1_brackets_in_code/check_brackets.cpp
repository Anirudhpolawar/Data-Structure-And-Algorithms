#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket temp(next,position+1);
            opening_brackets_stack.push(temp);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty())
            {
                    Bracket temp(next,position+1);
                    opening_brackets_stack.push(temp);
                    break;
            } 
            char top = opening_brackets_stack.top().type;
            if((top=='('&&next==')')||(top=='{'&&next=='}')||(top=='['&&next==']'))
                opening_brackets_stack.pop();
            else
            {
                    Bracket temp(next,position+1);
                    opening_brackets_stack.push(temp);
                    break;
            }
            
        }

       
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.empty())
    {
        std::cout<<"Success\n";
    }
    else
    {
        std::cout<<opening_brackets_stack.top().position<<"\n";
    }
    

    return 0;
}
