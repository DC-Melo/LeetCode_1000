#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <stdio.h>

using namespace std;
class Solution 
{
public:
    bool isMatch(const char *s, const char *p) 
    {
        //greedy
        bool pre,next;
        const char *start,*end,*mid;
        const char *ss,*se,*sm;
        start = p;
        end = p;
        ss = s;
        while(true)
        {
            if(*start == '*')
                pre = true;//查看前面有没有*
            else 
                pre = false;
            //查看新的没有*的word
            while(*start != '\0' && *start == '*') 
                start++;
            end = start;
            
            while(*end != '\0' && *end != '*') 
                end++;
            if(*end == '*') 
                next = true;
            else 
                next = false;
            end--;
            
            if(*ss == '\0' && pre && *start == '\0')
                return true;//p和s均完全匹配
            if(*ss != '\0' && pre && *start == '\0') 
                return true;
            if(*ss != '\0' && (*start == '\0' && !pre)) 
                return false;//s没能完全匹配
            if(*ss == '\0' && *start != '\0') 
                return false;//p的字母没能匹配完全
            
            //处理greedy匹配问题
            if(next == true)
            {//后面有*可供匹配
                if(pre == true)
                {//前面有供做匹配的
                    sm = ss,mid = start;//判断s中剩余的还够匹配不够
                    while(mid != end && *sm != '\0')
                    {
                        mid++,sm++;
                    }
                    if(*sm == '\0')
                        return false;

                    mid = start;
                    while(*mid != '*' && *ss != '\0')
                    {
                        for(sm = ss,mid = start;*sm != '\0' && *mid != '*';sm++,mid++)
                        {
                            if(*mid == '?')continue;
                            if(*mid != *sm)break;
                        }
                        if(*mid == '*')
                            ss = sm;
                        else 
                            ss++;
                    }//while
                    if(*mid != '*')
                        return false;
                    ss = sm;
                    start = mid;
                }
                else
                {//前面没有供匹配的
                    for(sm = ss,mid = start;*sm != '\0' && mid != end+1;sm++,mid++)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if(mid != end+1)
                        return false;
                    ss = sm;//匹配成功
                    start = end+1;
                }
            }
            else
            {//最后必须匹配的一串，因为后面没有*可供匹配最后的字母
                if(pre)
                {
                    se = ss;
                    while(*se != '\0')
                        se++;
                    se--;
                    for(sm = se,mid = end;mid != start && sm != ss;mid--,sm--)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if((sm == ss && mid != start) || (*mid != *sm && *mid != '?'))
                        return false;//如果s不够匹配或者p开头不能匹配
                    return true;
                }
                else
                {
                    for(sm = ss,mid = start;*sm != '\0' && *mid !='\0';sm++,mid++)
                    {
                        if(*mid == '?')
                            continue;
                        if(*mid != *sm)
                            return false;
                    }
                    if(*sm != '\0' || *mid != '\0')
                        return false;
                    return true;
                }
            }
        }
    }
};
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length(), len2 = p.length();
        vector<vector<bool>> ans(len1 + 1, vector<bool> (len2 + 1, false));
        ans[0][0] = true;
        for (int j=1;j<=len1;j++){
            ans[0][j] = ( p[j]=='*');
        } 
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if(p[j]=='*'){
                    ans[i+1][j+1]= true && (ans[i][j] || ans[i+1][j] );
                }else if(p[j]==s[i] || p[j]=='?'){
                    ans[i+1][j+1]= true && (ans[i][j]);
                }
                /* else{ */
                /*     ans[i+1][j+1]= 0; */
                /* } */
            }
        }
        return ans[len1][len2];
    }
};
class Solution3 {
public:
	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		int i = 0, j = 0, ri = -1, rj = -1;
		while (i < n)
		{
			if (p[j] == '*')
			{
				ri = i;
				rj = j++;
			}
			else if (p[j] == '?' || p[j] == s[i])
			{
				i++; j++;
			}
			else if (rj > -1)
			{
				i = ++ri;
				j = rj+1;
            } else{
                return false;
            } 
		}
		while (j < m && p[j] == '*')j++;
		return j == m;
	}
    bool isMatchB(const char *s, const char *p) {
            const char* ps=nullptr;
            const char* ss=nullptr;
            while (*s){
                if (*p=='*'){ps=p; ss=s; p++;} //save states and then p++,use * as zero
                else if ((*p=='?')||(*p==*s)){s++;p++;} //pattern ok,next
                else if(ps){p=ps+1; s=ss+1;ss++;}//restory states and next step,and old states. 
                else return false;
            }
            while (*p=='*'){++p;}
            return !*p;
    }
};
class Solution4 {
    int drs(const char *s, const char *p){
            const char* ps=nullptr;
            const char* pp=nullptr;
            //边界处理,退出条件
            if (!*s and !*p ){return true;}
            if(!*s and *p=='*'){return true;}
            if(!*s and *p!='*'){return false;}
            //循环判断
            if(*p=='*'){ps=s;pp=p;drs(s,++p);}
            if((*p=='?')||(*p==*s)){drs(++s,++p);}
            if(ps){drs(ps+1,pp+1);++ps;}
    }
     int dfs(string& s, string& p, int si, int pi) {
         if (si == s.size() and pi == p.size()) return 2;
         if (si == s.size() and p[pi] != '*') return 0;
         if (pi == p.size()) return 1;
         if (p[pi] == '*') {
             if (pi + 1 < p.size() and p[pi + 1] == '*')
                 return dfs(s, p, si, pi + 1); // skip duplicate ‘*’
             for (int i = 0; i <= s.size() - si; ++i) {
                 int ret = dfs(s, p, si + i, pi + 1);
                 if (ret == 0 or ret == 2) return ret;
             }
         }else if (p[pi] == '?' or s[si] == p[pi]){
             return dfs(s, p, si + 1, pi + 1);
         }
         return 1;
     }

	 public:
		 bool isMatch(string s, string p) {
			 /* return dfs(s, p, 0, 0) > 1; */
            /* char *sc=s.data(); */
            /* char *pc=p.data(); */
			return drs("abcab", "*a*ab");
			/* return 0; */
		 }
};
int main(){
    Solution sln;
    Solution2 sln2;
    Solution3 sln3;
    Solution4 sln4;
    /* bool ret=sln.isMatch("adcab","*ab"); */
    /* bool ret=sln.isMatch("adcab","**ab"); */
    /* cout << "ret:"<<ret<<endl; */
    bool ret2=sln2.isMatch("adcab","*aab");
    cout << "ret2:"<<ret2<<endl;
    bool ret3=sln3.isMatchB("bcd","**cd");
    cout << "ret3:"<<ret3<<endl;
    bool ret4=sln4.isMatch("adcab","**ab");
    cout << "ret4:"<<ret4<<endl;

}
