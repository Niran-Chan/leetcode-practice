class TimeMap {
    Map <String, TreeMap<Integer, String>> timeMap; 
    
    public TimeMap() {
        timeMap = new HashMap<>();   //Hashmap implements Map interface 
    }
    
    public void set(String key, String value, int timestamp) {
        this.timeMap.putIfAbsent(key, new TreeMap<>()); //initialise new 
        this.timeMap.get(key).put(timestamp, value); //Get the initialised TreeMap, and add timestamp as key and value as val
    }
    
    public String get(String key, int timestamp) {
        if (!timeMap.containsKey(key)) return ""; //return nothing if key not found
        Map.Entry<Integer, String> entry = this.timeMap.get(key).floorEntry(timestamp);//Map Extends to Map.Entry, find largest number below the current number
        if (entry == null) return ""; //If no such values, return null
        return entry.getValue();    //Get value method for key to value reference
    }
}
