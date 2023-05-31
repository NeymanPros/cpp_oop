#include <exception>
#include <string>
#include <iostream>
#pragma once

class DivideByZero : public std::exception {
    const char* what() const noexcept override {
        return "Denom can't be 0!";
    }
};

class Rational {
private:
    int32_t num_ = 0;
    int32_t denom_ = 1;
    static const char separator = '/';
public:
    Rational() {
        num_ = 0;
        denom_ = 1;
    }

    explicit Rational(int32_t num) noexcept {
        num_ = num;
        denom_ = 1;
    }

    Rational(int num, int denom) {
        try {
            if (denom == 0) {
                throw DivideByZero();
            }
            num_ = num;
            denom_ = denom;
            if (denom < 0) {
                denom_ *= -1;
                num_ *= -1;
            }
        }
        catch (std::exception& denom) {
            std::cerr << denom.what() << "\n";
        }
    }

    Rational(Rational &i) {
        num_ = i.num_;
        denom_ = i.denom_;
    }

    ~Rational() = default;

    int32_t GetNum() {
        return num_;
    }

    int32_t GetDenom(){
        return denom_;
    }

    void divide(){
        if((num_ % denom_) == 0){
            num_ /= denom_;
            denom_ = 1;
        }

        if(denom_ % num_ == 0){
            denom_ /= num_;
            num_ = 1;
        }

        for(int i = 2; i*i <= denom_ && i*i <= num_; i++){
            if(denom_ % i == 0 && num_ % i == 0){
                denom_ /= i;
                num_ /= i;
                i = 1;
            }
        }
        if (denom_ < 0) {
            denom_ = denom_ * (-1);
            num_ = num_ * (-1);
        }
    }


    bool operator==(Rational i) {
        return (num_ * i.denom_ == i.num_ * denom_);
    }
    bool operator==(int32_t i) {
        return (denom_ * i == num_);
    }
    bool operator!=(Rational i) {
        return (num_ * i.denom_ != i.num_ * denom_);
    }
    bool operator!=(int32_t i) {
        return (denom_ * i != num_);
    }
    bool operator<=(Rational i) {
        return (num_ * i.denom_ <= i.num_ * denom_);
    }
    bool operator<=(int32_t i) {
        return (num_ <= i * denom_);
    }
    bool operator>=(Rational i) {
        return (num_ * i.denom_ >= i.num_ * denom_);
    }
    bool operator>=(int32_t i) {
        return (num_ >= i * denom_);
    }
    bool operator<(Rational i) {
        return (num_ * i.denom_ < i.num_ * denom_);
    }
    bool operator<(int32_t i) {
        return (num_ < i * denom_);
    }
    bool operator>(Rational i) {
        return (num_ * i.denom_ > i.num_ * denom_);
    }
    bool operator>(int32_t i) {
        return (num_ > i * denom_);
    }

    Rational operator-() {
        return { num_ * (-1), denom_ };
    }

    void operator++() {
        num_ += denom_;
    }
    void operator--() {
        num_ -= denom_;
    }

    void operator+=(Rational i) {
        num_ = num_ * i.denom_ + i.num_ * denom_;
        denom_ = denom_ * i.denom_;
        this->divide();
    }
    void operator+=(int32_t i) {
        num_ += i * denom_;
    }
    void operator-=(Rational i) {
        num_ = num_ * i.denom_ - i.num_ * denom_;
        denom_ = denom_ * i.denom_;
        this->divide();
    }
    void operator-=(int32_t i) {
        num_ -= i * denom_;
    }
    void operator*=(Rational i) {
        try {
            if (i.denom_ == 0) {
                throw DivideByZero();
            }
            num_ *= i.num_;
            denom_ *= i.denom_;
            this->divide();
        }
        catch (std::exception& i) {
            std::cerr << i.what() << "\n";
        }
    }
    void operator*=(int32_t i) {
        num_ *= i;
        this->divide();
    }
    void operator/=(Rational i) {
        try {
            if (i.num_ == 0) {
                throw DivideByZero();
            }
            num_ *= i.denom_;
            denom_ *= i.num_;
            this->divide();
        }
        catch (std::exception& i) {
            std::cerr << i.what() << "\n";
        }
    }
    void operator/=(int32_t i) {
        try {
            if (i == 0) {
                throw DivideByZero();
            }
            denom_ *= i;
            this->divide();
        }
        catch (std::exception& i) {
            std::cerr << i.what() << "\n";
        }
    }

    std::ostream& WriteTo(std::ostream& ostrm) noexcept {
        this->divide();
        ostrm << num_ << separator << denom_;
        return ostrm;
    }

    std::istream& ReadFrom(std::istream& istrm) {
        char h;
        int32_t num, denom;
        istrm >> num;
        istrm >> h;
        istrm >> denom;
        if (h != '/' || denom <= 0) {
            istrm.std::ios_base::bad();
            return istrm;
        }
        else {
            num_ = num;
            denom_ = denom;
            istrm.std::ios_base::good();
            return istrm;
        }
    }
};

std::ostream& operator<<(std::ostream& ostrm, Rational &a) {
    return a.WriteTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational &a) {
    return a.ReadFrom(istrm);
}

bool operator==(int32_t i, Rational a) {
    return i * a.GetDenom() == a.GetNum();
}
bool operator!=(int32_t i, Rational a) {
    return i * a.GetDenom() != a.GetNum();
}
bool operator>=(int32_t i, Rational a) {
    return i * a.GetDenom() >= a.GetNum();
}
bool operator>(int32_t i, Rational a) {
    return i * a.GetDenom() > a.GetNum();
}
bool operator<=(int32_t i, Rational a) {
    return i * a.GetDenom() <= a.GetNum();
}
bool operator<(int32_t i, Rational a) {
    return i * a.GetDenom() < a.GetNum();
}

Rational operator+(Rational a, Rational b) {
    if (a.GetDenom() == b.GetDenom()) {
        return { a.GetNum() + b.GetNum(), a.GetDenom() };
    }
    else {
        return { a.GetNum() * b.GetDenom() + b.GetNum() * a.GetDenom(), a.GetDenom() * b.GetDenom() };
    }
};
Rational operator+(Rational a, int32_t i) {
    return { a.GetNum() + i * a.GetDenom(), a.GetDenom() };
}
int32_t operator+(int32_t i, Rational a) {
    return (i * a.GetDenom() + a.GetNum()) / a.GetDenom();
}
Rational operator-(Rational a, Rational b) {
    if (a.GetDenom() == b.GetDenom()) {
        return { a.GetNum() - b.GetNum(), a.GetDenom() };
    }
    else {
        return { a.GetNum() * b.GetDenom() - b.GetNum() * a.GetDenom(), a.GetDenom() * b.GetDenom() };
    }
};
Rational operator-(Rational a, int32_t i) {
    return { a.GetNum() - i * a.GetDenom(), a.GetDenom() };
}
int32_t operator-(int32_t i, Rational a) {
    return (i * a.GetDenom() - a.GetNum()) / a.GetDenom();
}
Rational operator*(Rational a, int32_t i) {
    a.divide();
    return { a.GetNum() * i, a.GetDenom() };
}
Rational operator*(Rational a, Rational b) {
    try {
        if (b.GetDenom() == 0) {
            throw DivideByZero();
        }
        a.divide();
        b.divide();
        return { a.GetNum() * b.GetNum(), a.GetDenom() * b.GetDenom() };
    }
    catch (std::exception& b) {
        std::cerr << b.what() << "\n";
    }
}
int32_t operator*(int32_t i, Rational a) {
    a.divide();
    return i * a.GetNum() / a.GetDenom();
}
Rational operator/(Rational a, int32_t i) {
    try {
        if (i == 0) {
            throw DivideByZero();
        }
        a.divide();
        return { a.GetNum(), a.GetDenom() * i };
    }
    catch (std::exception& i) {
        std::cerr << i.what() << "\n";
    }
}
Rational operator/(Rational a, Rational b) {
    try {
        if (b.GetNum() == 0) {
            throw DivideByZero();
        }
        a.divide();
        b.divide();
        return { a.GetNum() * b.GetDenom(), a.GetDenom() * b.GetNum() };
    }
    catch (std::exception& b) {
        std::cerr << b.what() << "\n";
    }
}
int32_t operator/(int32_t i, Rational a) {
    try {
        if (a.GetNum() == 0) {
            throw DivideByZero();
        }
        a.divide();
        return i * a.GetDenom() / a.GetNum();
    }
    catch (std::exception& a) {
        std::cerr << a.what() << "\n";
    }
}
