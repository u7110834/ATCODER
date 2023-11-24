using namespace std;

long long factorial(int N){
    return (N == 1 || N == 0)? 1 : factorial(N-1)*N;
}