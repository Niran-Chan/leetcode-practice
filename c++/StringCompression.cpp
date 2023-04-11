class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        if(chars.size() == 1)
            return 1;
        int l =0, r= chars.size(),cnt = 0;
        char target = chars[0];
        while(l < r){
            if(chars[l] == target)
                cnt++;
            else
                {
                    if(cnt == 1)
                        s += target;
                    else
                        s += target + to_string(cnt);
                    
                    target = chars[l];
                    cnt=1;}
            
            ++l;
        }
        if(cnt == 1)
            s += target;
        else
             s += target + to_string(cnt);
        //48 - 57 means its a number
        //cout << s << endl;
        for(int i = 0; i < s.size() ;++ i){
            chars[i] = s[i];
        }
        return s.size();


    }

};
