
float max(float a, float b) {
    if (a >= b) return a;
    else return b;
}


float* parse(float lower[], int n1, float upper[], int n2) {
    
    int ans_count = 0;
    int ans_len = 0;
    float* ans = new float[ans_len];
    bool intersected = false;
    for (int i = 0; i < n1 - 1; ++i) {
        if (lower[i] <= lower[i + 1] && lower[i + 1] <= upper[i]) {
            if  (!intersected) { 
                ans_count += 2;
                ans_len += 2;
            }
            ans[ans_count] = lower[i];
            ans[ans_count + 1] = max(upper[i], upper[i + 1]);

            lower[i + 1] = lower[i];
            upper[i + 1] = max(upper[i], upper[i + 1]);
            intersected = true;
            // std::cout << lower[i + 1] << '\t' << upper[i + 1] << std::endl;
        }
        else {

            intersected = false;
        }
    }
    return ans;
}