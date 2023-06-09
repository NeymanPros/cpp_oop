#include <exception>
#pragma once

class ArrayD{
private:
    ptrdiff_t size_ = 0;
    double *data = nullptr;
public:

    ArrayD(){
        data = new double[0];
    };

    ArrayD(ptrdiff_t size){
        try {
            if (size < 0) {
                throw std::invalid_argument("Negative size!");
            }
            size_ = size;
            data = new double[size_];
            std::fill(data, data + size_, 0);
        }
        catch (std::exception& size) {
            std::cerr << size.what() << "\n";
        }
    };

    ArrayD(ptrdiff_t size, double i) {
        try {
            if (size < 0) {
                throw std::invalid_argument("Negative size!");
            }
            delete[] data;
            size_ = size;
            data = new double[size_];
            std::fill(data, data + size_, i);
        }
        catch (std::exception& size) {
            std::cerr << size.what() << "\n";
        }
    }

    ArrayD(const ArrayD &a) {
        delete[] data;
        data = new double[a.size_];
        std::copy(a.data, a.data + a.size_, data);
        size_ = a.size_;
    };

    ~ArrayD(){
        delete[] data;
    };
    
    [[nodiscard]] double &operator[](ptrdiff_t i) {
        return *(data + i);
    }

    void operator=(const ArrayD& a) {
        delete[] data;
        data = new double[a.size_];
        std::copy(a.data, a.data + a.size_, data);
        size_ = a.size_;
    }

    const ptrdiff_t ssize() const noexcept {
        return size_;
    }

    void resize(const ptrdiff_t size) {
        try {
            if (size < 0) {
                throw std::invalid_argument("Negative size!");
            }
            double* temp = new double[size_];
            std::copy(data, data + size_, temp);
            delete[] data;
            data = new double[size];

            if (size <= size_) {
                std::move(temp, temp + size, data);
            }
            else {
                std::move(temp, temp + size_, data);
                std::fill(data + size_, data + size, 0);
            }
            size_ = size;
            delete[] temp;
        }
        catch (std::exception& size) {
            std::cerr << size.what() << "\n";
        }
    }

    void insert(const ptrdiff_t p, const double i) {
        try {
            if (p < 0 || p > this->ssize()) {
                throw std::out_of_range("Out of range!");
            }

            double* temp = new double[size_];
            std::copy(data, data + size_, temp);
            delete[] data;
            data = new double[size_ + 1];

            if (p == 0) {
                *data = i;
                std::copy(temp, temp + size_, data + 1);
            }
            else if (p == size_) {
                std::copy(temp, temp + size_, data);
                *(data + size_) = i;
            }
            else {
                std::copy(temp, temp + p, data);
                *(data + p) = i;
                std::copy(temp + p, temp + size_, data + p + 1);
            }
            size_ += 1;
            delete[] temp;
        }
        catch (std::exception& p) {
            std::cerr << p.what() << "\n";
        }
    }

    void remove(ptrdiff_t p) {
        try {
            if (p < 0 || p >= this->ssize()) {
                throw std::out_of_range("Out of range!");
            }

            double* temp = new double[size_];
            std::copy(data, data + size_, temp);
            delete[] data;
            data = new double[size_ - 1];

            if (p == 0) {
                std::copy(temp + 1, temp + size_, data);
            }
            else if (p == size_ - 1) {
                std::copy(temp, temp + size_ - 1, data);
            }
            else {
                std::copy(temp, temp + p, data);
                std::copy(temp + p + 1, temp + this->ssize(), data + p);
            }
            size_ -= 1;
            delete[] temp;
        }
        catch (std::exception& p) {
            std::cerr << p.what() << "\n";
        }
    }
};