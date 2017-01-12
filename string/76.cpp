class Solution {
public:
    string minWindow(string s, string t) {
        int t_count[128] = {0};
        int s_count[128] = {0};
        int findAll = 0;
        
        int min_size = 2147483647;
        int min_start = 0, min_end = 0;
        
        int s_len = s.length();
        int t_len = t.length();
        
        int start = 0, end = 0;
        for(int i=0;i<t_len;i++){
            t_count[t[i]]++;
        }
        while(end<s_len){
            if(t_count[s[end]] == 0){
                end++;
                continue;
            }
            
            s_count[s[end]]++;
            if(s_count[s[end]] <= t_count[s[end]]){
                findAll++;
            }
            
            
            
            if(findAll == t_len){
                while(s_count[s[start]] == 0 || s_count[s[start]] > t_count[s[start]]){
                    
                    if(s_count[s[start]] > t_count[s[start]]){
                        s_count[s[start]]--;
                    }
                    start++;
                }
                
                
                if(min_size > end-start+1){
                    min_size = end-start+1;
                    min_start = start;
                    min_end = end;
                }
            }
            end++;
        }
        
        if(findAll < t_len){
            return "";
        }
        
        cout<<start<<" "<<end<<endl;
        return s.substr(min_start,min_size);
        
        
    }
};
