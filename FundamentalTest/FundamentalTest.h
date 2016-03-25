//
//  FundamentalTest.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/15/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef FundamentalTest_h
#define FundamentalTest_h
#include <iostream>
#include <bitset>
#include <vector>
#include <utility>   //pair
#include <queue>
#include <algorithm> //sort
#include <string>
using namespace std;

//bitset
void test1(){
    for(int i=0; i<100; i++)
        cout<<bitset<8>(i)<<"    "<<i<<endl;
    //Order positions are counted from the rightmost bit, which is order position 0.
    std::bitset<4> foo;
    std::cout << foo.set() << '\n';       // 1111
    std::cout << foo.set(2,0) << '\n';    // 1011
    std::cout << foo.set(2) << '\n';      // 1111

}

//binary search impl
class Comp{
    bool less;
public:
    Comp(bool m):less(m){}
    bool operator()(const int &i, const int &j) const{
        bool ret;
        if(less) ret = i<j;
        else ret = i>j;
        return ret;
    }
};
int lb(vector<int> &v, int x){
    int l = 0, r = v.size()-1;
    while(l<r){
        int m = l+(r-l)/2;
        if(v[m]>=x) r = m;
        else l = m+1;
    }
    return v[l]>=x ? l:-1;
}
int ub(vector<int> &v, int x){
    int l = 0, r = v.size()-1;
    while(l<r){
        int m = l+(r-l)/2;
        if(v[m]<=x) l = m+1;
        else r = m;
    }
    //all elem <x => -1
    return v[r]>x ? r:-1;
}
int bs(vector<int>&v, int x){
    int l=0, r=v.size()-1;
    while(l<r){
        int m = l+(r-l)/2;
        if(v[m]==x) return m;
        if(v[m]<x) l=m+1;
        else r = m-1;
    }
    // all elems <=x => -1
    return v[l]==x ? l:-1;
}
//equal range
pair<int, int> er(vector<int> &v, int x){
    pair<int, int> ret = {-1,-1};
    int l = lb(v,x);
    int r = ub(v,x);
    if(l<0 || v[l]>x) return ret;
    ret.first = l;
    ret.second = r<0 ? (v.size()-1):(r-1);
    return ret;
}
void test2(){
    vector<int> v = {1,1,2,3,5,6,6,7,7,7,8,8,9};
    for(int i=0; i<11; i++){
//        int val = ub(v,i); //lb(v,i) ub(v,i), bs(v,i)
//        cout<<"i="<<i<<" v["<<val<<"]";
//        if(val>=0) cout<<"="<<v[val];
//        cout<<endl;
////        auto p = er(v,i);
////        cout<<"["<<p.first<<", "<<p.second<<"]"<<endl;
        auto q = std::lower_bound(v.begin(), v.end(), i, Comp(true));
        if(q!=v.end()) cout<<*q<<endl;
        else cout<<"not found!"<<endl;
    }
    
}


class WordFreq{
public:
    string str;
    int64_t freq;
    WordFreq(string s=string(""), int64_t f=0):str(s),freq(f){}
    bool operator<(const WordFreq& wf) const{
        return freq<wf.freq;
    }
};

int test3()
{
    cout << "Hello World" << endl;
    priority_queue< WordFreq, vector<WordFreq> > pq;
    vector<WordFreq> v;
    pq.push(WordFreq("d",1));
    pq.push(WordFreq("c",2));
    pq.push(WordFreq("b",3));
    pq.push(WordFreq("a",4));
    
    v.push_back(WordFreq("d",1));
    v.push_back(WordFreq("c",2));
    v.push_back(WordFreq("b",3));
    v.push_back(WordFreq("a",4));
    make_heap(v.begin(), v.end());
    while(pq.empty() == false){
        cout<<"["<<pq.top().str<<","<<pq.top().freq<<"]"<<endl;
        pq.pop();
    }
    cout<<endl;
    while(v.empty()==false){
        cout<<v.front().str<<" "<<v.front().freq<<endl;
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }
    return 0;
}

// count 1 bits
void test4(){
    int x = 31^14;
    int cnt = 0;
    while(x!=0){
        x &= (x-1);
        ++cnt;
    }
    cout<<"result : "<<cnt<<endl;
}

//test enum in a class
//private won't be accessible from outside
//scoped enum
//specify type for enum
#define GAP 2
class eNumClass{
private:
    enum Color{ RED=2, BLUE=RED+GAP, GREEN=BLUE+GAP };
    Color val;
public:
    Color get(){return val;}
    void set(Color v){val = v;}
    eNumClass():val(RED){}
};
void test5(){
    //int val = eNumClass::Color; //NOT WORK
    eNumClass c;
    int val = c.get();
    cout<<val<<endl;
    
    enum charEnum : unsigned char {T=127, F};
    cout<<charEnum::F<<endl;
}

//sort using lambda function
void test6(){
    vector<int> a = {2,1,5,3,6};
    sort(a.begin(),a.end(), [ ](const int &a, const int &b){return a<b;});
    for(auto aa:a) cout<<aa<<endl;
}

//init private static variable
class withPrivateStatic{
    static int i;
    static const int i2= 0; //only can init in declaration if it's const
public:
    static void increment(){i++;}
    static int get(){return i;}
    withPrivateStatic(){i++;}
};

int withPrivateStatic::i = 0;
void test7(){
    withPrivateStatic w1;
    withPrivateStatic w2;
    cout<<withPrivateStatic::get()<<endl;
}

//reference to STL containers
void test8(){
    vector<int> a(10,1);
    for(auto v: a) cout<<v<<" ";
    cout<<endl;
    vector<int> &b = a;
    b[9]=2;
    for(auto v: a) cout<<v<<" ";
    cout<<endl;
}

//http://www.tutorialspoint.com/cplusplus/cpp_templates.htm
template<typename T> T addTemp(T a, T b){
    return a+b;
}
void test(){
    cout<<addTemp(1, 2)<<endl;
    cout<<addTemp(1.05, 2.35)<<endl;
    cout<<addTemp<string>("aa","bb");
}
#endif /* FundamentalTest_h */


