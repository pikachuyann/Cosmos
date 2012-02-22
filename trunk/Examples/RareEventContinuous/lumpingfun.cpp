

void SPN::lumpingFun(vector<int>* vect){
    int reste =0;
    for (int i=vect->size()-1; i>0; i--) {
        if((*vect)[i]>r){
            reste += (*vect)[i]-r ;
            (*vect)[i]=r;
        }
    }
    (*vect)[0] += reste;
    
}
