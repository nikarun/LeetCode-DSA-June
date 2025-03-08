class Solution {
    public boolean isValid(String s) {
     int n=s.length();
     if(n==0) return true;
     Stack<Character>st=new Stack<>();
     for(int i=0;i<n;++i){
        Character c=s.charAt(i);
        if(c=='(' || c=='[' || c=='{') st.push(c);
        else {
            if(st.empty()) return false;
            if(c==')') {
                if(st.peek()!='(') return false;
                st.pop();
            }
            else if(c==']'){
                if(st.peek()!='[') return false;
                st.pop();
            }
            else {
                if(st.peek()!='{') return false;
                st.pop();
            }
        } 
     }   
     return st.empty();
    }
}