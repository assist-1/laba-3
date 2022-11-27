
float max(float a, float b) {
    if (a >= b) return a;
    else return b;
}


int parse(float lower[], int n1, float upper[], int n2, 
            float ans_low[], int n3, float ans_up[], int n4) {
    
    int ans_count = 0;
    bool intersected = false;
    for (int i = 0; i < n1 - 1; ++i) {
        if (lower[i] <= lower[i + 1] <= upper[i]) {
            ans_low[ans_count] = lower[i];
            ans_up[ans_count] = max(upper[i], upper[i + 1]);
            intersected = true;
        }
    }

    return ans_count;
}
