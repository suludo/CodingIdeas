//
//  CosineSimilarity.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/19/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef CosineSimilarity_h
#define CosineSimilarity_h


//http://www.lintcode.com/en/problem/cosine-similarity/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        if( A.size() != B.size() ) return 2.0;
        int n = A.size();
        double normA = 0.0, normB = 0.0;
        double crossProd = 0.0;
        for( int i = 0; i < n; i++ ){
            crossProd += A[i]*B[i];
            normA += A[i]*A[i];
            normB += B[i]*B[i];
        }
        normA = sqrt(normA);
        normB = sqrt(normB);
        if( normA==0.0 || normB==0.0 ) return 2.0;
        return crossProd/(normA*normB);
    }
};

void test(){
    vector<int> A = {1,4,3};
    vector<int> B = {2,4,6};
    Solution s;
    cout<<" answer is: "<<s.cosineSimilarity(A, B);
    cout<<endl;
}

#endif /* CosineSimilarity_h */
