class Solution {
public:
    string simplifyPath(string path) {
        stack<string> myPath;
        string current;
        string answer = "/";
        vector<string> reversedShit;
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1) {
                if (path[i] == '.') {
                    if (current == ".") {
                        if (!myPath.empty())
                            myPath.pop();
                        break;
                    } else if (current == "") {
                        break;
                    } else {
                        current += path[i];
                        myPath.push(current);
                        break;
                    }
                }
                if (path[i] != '/') {
                    current += path[i];
                    myPath.push(current);
                    break;
                }
            }
            if (path[i] == '/') { 
                if (current == "..") {
                    if (!myPath.empty())
                        myPath.pop();
                }
                else if (current == ".") {
                    current = "";
                    continue;
                }
                else if (current != "")
                    myPath.push(current);
                current = "";
            } else {
                current += path[i];
            }
        }

        while(!myPath.empty()) {
            reversedShit.push_back(myPath.top());
            myPath.pop();
        }

        for (int i = reversedShit.size()-1; i >= 0; i--) {
            answer += reversedShit[i] + "/";
        }

        if (answer.length() > 1) {
            answer.pop_back();
        }

        return answer;
    }
};