class Solution {
public:
    string simplifyPath(string path) {
        stack<string> buf;
        
        for (int i = 0; i < path.size(); ++i) {

            if (path[i] == '/') continue;
            
            string tmp;
            while (i < path.size() && path[i] != '/') {
                tmp += path[i++];
            }
            
            if (tmp == "..") {
                if (!buf.empty())
                    buf.pop();
            } else if (tmp != ".") {
                buf.push(tmp);
            }
        }
        
        vector<string> vec;
        while (!buf.empty()) {
            vec.push_back(buf.top());
            buf.pop();
        }
        
        string ans;
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            ans += "/" + *it;
        }
        
        return (vec.empty() ? "/" : ans);
    }
};