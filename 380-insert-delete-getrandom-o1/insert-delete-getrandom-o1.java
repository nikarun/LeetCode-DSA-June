class RandomizedSet {
    List<Integer>l;
    Map<Integer,Integer>hMap;
    public RandomizedSet() {
        l=new ArrayList<Integer>();
        hMap=new HashMap<>();
    }
    
    public boolean insert(int val) {
        if(hMap.containsKey(val)){
            return false;
        }
        else{
            l.add(val);
            hMap.put(val,l.size()-1);
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(hMap.containsKey(val)){
            int idx = hMap.get(val);
            int lastElement = l.get(l.size() - 1);
            l.set(idx, lastElement);
            hMap.put(lastElement, idx);
            l.remove(l.size() - 1);
            hMap.remove(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    public int getRandom() {
        System.out.println(new Random().nextInt(l.size()));
        System.out.println(l.get(0));
        return l.get(new Random().nextInt(l.size()));
    }
}
// [0,1]
// [1,2]
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */