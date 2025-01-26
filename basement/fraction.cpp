struct fraction{
    int num, den;
    fraction(int a, int b): num(a), den(b){
        int g = __gcd(num, den);
        num /= g;
        den /= g;
    }
    bool operator==(const fraction& other) const{
        return num == other.num && den == other.den;
    }
};