#pragma once
template <typename T>
class Arrayt{
private:
    int size_ = 0;
    T *data = nullptr;
public:
    Arrayt(){
        data = new T[0];
    };

    Arrayt(int i){
        size_ = i;
        data = new double[size_];
    };

    Arrayt(Arrayt const &a) {
        delete[] data;
        data = new T[a.size()];
        for (ptrdiff_t i = 0; i < a.size(); i++) {
            data[i] = a.data[i];
        }
        size_ = a.size_;
    };

    ~Arrayt(){
        delete[] data;
    };

    void operator=(const ptrdiff_t i){};

    T& operator[](const ptrdiff_t i) {
        if(i < size_ && i >= 0)
            return *(data + i);
    };

    void push_back(T n){
        T *temp = data;
        data = new T[size_ + 1];
        std::copy(temp, temp + size_, data);
        data[size_] = n;
        size_ += 1;
    }

    void pop_back(){
        if(size_ == 0){
            return;
        }
        size_ -= 1;
        T *temp = data;
        data = new T[size_];
        data = temp;
    };

    const int size() const{
        return size_;
    };

    void resize(int _size){
        T* temp = data;
        data = new T[_size];
        std::copy(temp, temp + size_, data);
        size_ = _size;
        delete[] temp;
    };

    void clear(){
        size_ = 0;
        data = new T[0];
    }
};