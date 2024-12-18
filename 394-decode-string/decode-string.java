class Solution {
    public String decodeString(String s) {
       int n=s.length();
       if(n==0) return "";
       Stack<Character>st=new Stack<>();
       for(int i=0;i<n;++i){
        if(s.charAt(i)!=']'){
            st.push(s.charAt(i));
        }
        else{
            String currStr=""; 
            while(st.peek()!='['){
                currStr=st.pop()+currStr; //prepare string
            }
            st.pop(); // remove open bracket
            String currNum=""; //number could be greator than 10
            while(!st.empty() && Character.isDigit(st.peek())){
                currNum=st.pop()+currNum;
            }
            int currCount=Integer.parseInt(currNum);
            while(currCount-->0){
                for(int j=0;j<currStr.length();++j){
                    st.push(currStr.charAt(j));
                }
            }
        }
       }
       String resString="";
       while(!st.empty()){
        resString=st.pop()+resString;
       }
       return resString;
    }
}