class Rational {
private:
    int ch = 0;
    int zn = 1;
public:
    Rational() {
        ch = 0;
        zn = 1;
    }

    Rational(int a) {
        ch = a;
        zn = 1;
    }

    Rational(int a, int b) {
        ch = a;
        zn = b;
        if (!b) {
            zn = 1;
        }
    }

    ~Rational()  = default;

    void divide(){
        if(!(ch % zn)){
            ch /= zn;
            zn = 1;
        }

        if(!(zn % ch)){
            zn /= ch;
            ch = 1;
        }

        for(int i = 2; i*i <= zn && i*i <= ch; i++){
            if(zn % i == 0 && ch % i == 0){
                zn /= i;
                ch /= i;
                i = 1;
            }
        }
    }

    std::string show(){
        return std::to_string(ch) + "/" + std::to_string(zn);
    }

    Rational operator+(Rational i) {
        if (zn == i.zn) {
            return {(i.ch + ch), zn};
        }
        else {
            return {(ch * i.zn + i.ch * zn), zn * i.zn};
        }
    };

    bool operator==(Rational i) {
        return ch * i.zn == i.ch * zn;
    }
    
    bool operator==(int i) const noexcept {
        return zn * i == ch;
    }

};