
/*Function to calculate minimum platform*/
int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int currPlatform = 1;
    int maxPlatform = 1;
    
    int i = 1;
    int j = 0;
    
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            currPlatform += 1;
            i++;
        }
        else {
            currPlatform -= 1;
            j++;
        }
        maxPlatform = max(maxPlatform, currPlatform);
    }
    return maxPlatform;
}