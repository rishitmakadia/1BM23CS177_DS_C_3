bool isValid(char* s) {
    char stack[50000];
    int top=-1;
    for (int i=0; i<strlen(s);i++){
        char ch=s[i];
        if (ch == '(' || ch == '{' || ch == '['){
            stack[++top]=ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if (top == -1){
                return 0;
            }
            char val = stack[top];
            if ((ch == ')' && val == '(') || (ch == '}' && val == '{') || (ch == ']' && val == '[')){
                top--;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    if (top != -1){
        return 0;
    }
    else{
        top = -1;
        return 1;
    }
}