int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int trustMe[n + 1], trustOthers[n + 1];     //Hash tables
    int ans = -1;
    for(int i = 0; i < n + 1; i++){ //Initialize hash tables to all zeros
        trustMe[i] = 0;
        trustOthers[i] = 0;
    }

    for(int i = 0; i < trustSize; i++){ //ai trusts bi
        trustMe[trust[i][1]]++;     //Count the number that others trust me
        trustOthers[trust[i][0]]++; //Count the number that I trust others
    }
    for(int i = 1; i < n + 1; i++){
        if(trustMe[i] == n - 1 && trustOthers[i] == 0)  //Everybody trusts me but I trust nobody
            ans = i;
    }
    return ans;
}
