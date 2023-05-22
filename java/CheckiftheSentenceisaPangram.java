class Solution {
    public boolean checkIfPangram(String sentence) {
        ArrayList<Integer> freq = new ArrayList<Integer>();

        for(int i =0;i < 26;i++)
            freq.add(0);
        for(int i =0 ; i < sentence.length();i++)
        {
            char letter = sentence.charAt(i);
            freq.set(letter - 'a', freq.get(letter-'a') + 1);
        }

        for(int i =0 ; i < 26;i++)
            if(freq.get(i) == 0)
                return false;

        return true;
    }
}
