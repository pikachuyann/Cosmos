
vector< vector<double> > generateMatrix(int n){
    int N =5;
    vector< vector<double> > M(N,vector<double>(N,0) );
    
    M[0][1]=1;
    M[1][1]=0.3;
    M[1][2]=0.4;
    M[1][3]=0.3;
    M[2][0]=0.5;
    M[2][3]=0.5;
    M[3][3]=0.3;
    M[3][4]=0.7;
    M[4][2]=1;
    
    return M;
}