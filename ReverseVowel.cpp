bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    return false;
}

string reverseVowels(string s) {

    int start = 0;
    int end = s.length() - 1;

    while(start < end) {
        while(start < s.length() && !isVowel(s[start])) 
            start++;
        while(end >= 0 && !isVowel(s[end]))
            end--;
        if(start < end && start < s.length() && end >= 0) 
           swap(s[start++], s[end--]);
    }

    return s;
}