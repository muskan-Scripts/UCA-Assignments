#include <iostream>
#include <vector>
#include <string>  // Add this line to include the string header

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        std::vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int i = 0;
        std::string ans = "";
        while (res[i] == 0)
            i++;
        while (i < res.size())
            ans += std::to_string(res[i++]);

        return ans;
    }
};

int main() {
    Solution solution;

    std::string num1 = "123";
    std::string num2 = "456";
    std::string result = solution.multiply(num1, num2);

    std::cout << "Result: " << result << std::endl;
    // Expected output: "56088"

    // Add more test cases as needed

    return 0;
}
