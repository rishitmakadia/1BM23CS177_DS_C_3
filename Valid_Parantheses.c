bool isValid(char* s) {
    char stack[50];
    int top=-1;
    for (int i=0; i<strlen(s);i++){
        char ch=s[i];
        if (ch == '(' || ch == '{' || ch == '['){
            stack[++top]=ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            char val = stack[top];
            if ((ch == ')' && val == '(') || (ch == '}' && val == '{') || (ch == ']' && val == '[')){
                top--;
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}