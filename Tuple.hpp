#ifndef TUPLE_HPP
#define TUPLE_HPP

template<typename T, typename V>

class Tuple  {

private:
    T data1;
    V data2;

public:
    Tuple(const T& t, const V& v);
    void setData1(const T& data1_);
    void setData2(const V& data2_);
    const T& getData1() const;
    const V& getData2() const;
};

template<typename T, typename V>
Tuple<T, V>::Tuple(const T& t, const V& v) {
    data1 = t;
    data2 = v;
}

template<typename T, typename V>
void Tuple<T, V>::setData1(const T& data1_) {
    data1 = data1_;
}

template<typename T, typename V>
void Tuple<T, V>::setData2(const V& data2_) {
    data2 = data2_;
}

template<typename T, typename V>
const T& Tuple<T, V>::getData1() const {
    return data1;
}

template<typename T, typename V>
const V& Tuple<T, V>::getData2() const {
    return data2;
}

#endif