class Solution {
    private boolean isOverlap(int [] a,int [] b){
        return a[0] <= b[1] && a[1] >= b[0];
    }

    private int[] mergedIntervals(int [] a,int []b)
    {
        
        int [] res = {Math.min(a[0],b[0]),Math.max(a[1],b[1])};
        return res;
    }

    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,Comparator.comparingInt(a->a[0]));

        int n = intervals.length;
        int [][] res  = new int [n][2];
        res[0] = intervals[0];
        int x = 0;
        for(int i =1; i < n; i ++){
            if(isOverlap(intervals[i],res[x])) //if they overlap
                {
                    res[x] = mergedIntervals(intervals[i],res[x]);
                }
            else 
                {
                    x++;
                    res[x] = intervals[i];
                }
        }
        res = Arrays.copyOfRange(res,0,x+1);

        return res;

    }
}