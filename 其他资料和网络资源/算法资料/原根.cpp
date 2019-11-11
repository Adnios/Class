bool Check(int g, int m) {  
    for (int i = 2; i * i < m; i ++)  
        if ((m - 1) % i == 0 && (Pow(g, i, m) == 1 || Pow(g, (m - 1) / i, m) == 1)) return 0;  
    return 1;  
}  
