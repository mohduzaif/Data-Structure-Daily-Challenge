string intToRoman(int num) {
    
    int number[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    string str[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

    string ans;
    int i = 12;
    while(num > 0) {
        int quotient = num / number[i];
        num = num % number[i];
        while(quotient--) {
            ans += str[i];
        }
        i--;
    }
    return ans;   
}