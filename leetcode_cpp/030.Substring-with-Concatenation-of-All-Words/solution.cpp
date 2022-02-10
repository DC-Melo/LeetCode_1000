/* You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. */

/* For example, given: */
/* s: “barfoothefoobarman” */
/* words: [“foo”, “bar”] */

/* You should return the indices: [0,9]. */
/* (order does not matter). */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        map<string, int> words_map;
        int l = s.size(), num = words.size(), len = words[0].size();
        for(int i = 0; i < num; i++){
            words_map[words[i]]++;
        }
        for(int i = 0; i < l - num*len + 1; i++){
            map<string, int> finded;
            int j = 0;
            for( ; j < num; j++){
                string cur = s.substr(i + j*len, len);
                if(words_map.find(cur) != words_map.end()){
                    finded[cur]++;
                    if(finded[cur] > words_map[cur]) break;
                }
                else break;
            }
            if(j == num)
                res.push_back(i);
        }
        return res;
    }
};
class Solution 
{
private:
    int count[1000];
    int countSize;
    map<string, int> index;
    vector<int> ret;
public:
    vector<int> findSubstring(string S, vector<string> &L) 
    {
        ret.clear();
        if (L.size() == 0)
            return ret;

        index.clear();
        countSize = 0;
        for(int i = 0; i < L.size(); i++)
            if (index.count(L[i]) > 0)
                count[index[L[i]]]++;
            else
            {
                index[L[i]] = countSize;
                count[countSize++] = 1;
            }

            int step = L[0].size();

            vector<int> a;

            for(int i = 0; i < step; i++)
            {
                a.clear();
                for(int j = i; j < S.size(); j += step)
                {
                    if (j + step <= S.size())
                    {
                        string s(S, j, step);
                        if (index.count(s) > 0)
                            a.push_back(index[s]);
                        else
                            a.push_back(-1);
                    }
                }

                int beg = -1;
                int end = 0;
                int size = L.size();
                while(end < a.size())
                {
                    if (a[end] != -1)
                    {
                        if (count[a[end]] > 0)
                        {
                            if (beg == -1)
                                beg = end;
                            size--;
                            count[a[end]]--;
                        }
                        else
                        {
                               while(beg < end)
                               {
                                   count[a[beg]]++;
                                   size++;
                                   if (a[beg++] == a[end])
                                       break;
                               }
                               count[a[end]]--;
                               size--;
                           }
                       }
                       else
                       {
                           size = L.size();
                           if (beg != -1)
                           {    
                               for(int i = beg; i < end; i++)
                                   count[a[i]]++;
                           }
                           beg = -1;
                       }
   
                       end++;
   
                       if (size == 0)
                       {
                           ret.push_back(beg * step + i);
                           size++;
                           count[a[beg]]++;
                           beg++;
                       }
                   }
   
                   if (beg != -1)
                   {
                       for(int i = beg; i < end; i++)
                           count[a[i]]++;
                   }
               }
               return ret;
       }
   };
   int main(){
       Solution sln;
       Solution1 sln1;
   
       string s = "barfoothefoobarman";
       vector<string> words= {"foo", "bar"};
       vector<int> ret=sln.findSubstring(s,words);
       vector<int> ret1=sln1.findSubstring(s,words);
       cout << "" <<endl;
   }
