class Solution {
    bool checkpartition(int buff, int& i, int sum) {
        if (sum > i) {
            return false;
        }
        if (sum == i && buff==0) {
            return true;
        }
        if (buff == 0) {
            return false;
        }

        int num = 10;
        bool ans = false;
        while ((buff) / num) {
            ans = checkpartition(buff / num, i, sum + (buff % num));
            if(ans){break;}
            num *= 10;
        }

        if(!ans && buff%num){
            ans = checkpartition(buff / num, i, sum + (buff % num));
        }

        return ans;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int buff = i * i;

            if (checkpartition(buff, i, 0)) {
                cout << i << endl;
                ans += i * i;
            }
        }

        return ans;
    }
};