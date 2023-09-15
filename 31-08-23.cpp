// Reverse stack using recursion

void insert(stack<int>&st, int x){
    if(st.empty()){
        st.push(x);
        return ;
    }
    int y = st.top();
    st.pop();
    insert(st,x);
    st.push(y);
    return;
}
void solve(stack<int>&s){
    if(s.size()==1){
        return;
    }
    int a = s.top();
    s.pop();
    solve(s);
    insert(s,a);
    return ;
}

void reverseStack(stack<int> &stack) {
    if(stack.empty())
    {
        return;
    }
    solve(stack);
    return;
}
