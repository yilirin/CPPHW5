//
//  mysort.h
//  Sort
//
//  Created by 范志方 on 16/1/10.
//  Copyright © 2016年 范志方. All rights reserved.
//

#ifndef mysort_h
#define mysort_h
template<typename T>
void swap(T &lhs,T &rhs){
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

//通用模版：使用选择排序
template<typename iterator>
void mysort(iterator begin,iterator end){
    iterator max, it;
    iterator last = end;
    while (begin != --last) {
        it = last;
        max = last;
        while (begin != it--) {
            if (*it > *max) {
                max = it;
            }
        }
        if(*max > *last){
            swap(*max,*last);
        }
    }
}

//特例化模版：使用冒泡排序。
template<>
void mysort(std::vector<int>::iterator begin,std::vector<int>::iterator end){
    auto bubble = begin;
    bool unsorted = 1;
    while (unsorted) {
        unsorted = 0;
        bubble = begin;
        while (bubble != (end-1)) {
            if(*bubble > *(bubble+1)){
                unsorted = 1;
                swap(*bubble, *(bubble+1));
            }
            bubble++;
        }
//        for (auto it = begin; it != end; ++it) {
//            std::cout << *it << ' ';
//        }
//        std::cout << std::endl;
    }
}
#endif /* mysort_h */