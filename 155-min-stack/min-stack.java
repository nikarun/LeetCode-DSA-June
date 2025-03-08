class MinStack {
    public List<Pair<Integer,Integer>>l;
    public MinStack() {
        l=new ArrayList<>();
    }
    
    public void push(int val) {
        if(l.size()==0) l.add(new Pair<>(val,val));
        else{
            int minValue=Math.min(l.get(l.size()-1).getValue(),val);
            l.add(new Pair<>(val,minValue));
        }
    }
    
    public void pop() {
       if(!l.isEmpty()){
        l.remove(l.size()-1);
       }
    }
    
    public int top() {
        return l.get(l.size()-1).getKey();
    }
    
    public int getMin() {
        return l.get(l.size()-1).getValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */