class StockSpanner {
    Stack<Pair<Integer,Integer>>st;
    public StockSpanner() {
        st=new Stack<Pair<Integer,Integer>>();
    }
    
    public int next(int price) {
        int count=0;
        while(!st.isEmpty() && st.peek().getKey()<=price){
            count+=st.pop().getValue();
        }
        st.push(new Pair(price,count+1));
        return count+1;
        
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */