class Solution {
public:
    string simplifyPath(string path) {
        string ans;

        for (int i = 0; i < path.size(); ++i) {

            if (path[i] == '/') continue;
            
            string tmp;
            while (i < path.size() && path[i] != '/') {
                tmp += path[i++];
            }
            
            if (tmp == "..") {
                if (ans != "") {
               		int j = ans.length() - 1;
               		while (ans[j--] != '/') {}

               		ans = ans.substr(0, j + 1);
                }
            } else if (tmp != ".") {
                ans += "/" + tmp;
            }
        }
        
        return (ans == "" ? "/" : ans);
    }
};