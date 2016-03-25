//
//  133_CloneGraph.h
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/20/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef _33_CloneGraph_h
#define _33_CloneGraph_h

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
    UndirectedGraphNode* bfs(UndirectedGraphNode* root,  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>&mp){
        if(!root) return root;
        queue<UndirectedGraphNode*> q;
        q.push(root);
        mp[root] = new UndirectedGraphNode(root->label);
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            for(int i=0; i<n->neighbors.size(); i++){
                //q.push(n->neighbors[i]);
                UndirectedGraphNode * nbr = n->neighbors[i];
                UndirectedGraphNode* newNode = NULL;
                if(mp.find(nbr)!=mp.end()) newNode = mp[nbr];
                else{
                    q.push(nbr);
                    newNode = new UndirectedGraphNode(nbr->label);
                    mp[nbr] = newNode;
                }
                // no matter it's traversed or not, add built node to the new graph node neighbor list
                mp[n]->neighbors.push_back(newNode);
            }
        }
        return mp[root];
    }
    UndirectedGraphNode* dfs(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>&mp){
        if(!root || mp.find(root)!=mp.end()) return mp[root];
        mp[root] = new UndirectedGraphNode(root->label);
        for(int i=0; i<root->neighbors.size(); i++)
            mp[root]->neighbors.push_back(dfs(root->neighbors[i], mp));
        return mp[root];
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        //UndirectedGraphNode* n = dfs(node, mp);
        UndirectedGraphNode* n = bfs(node, mp);
        return n;
    }
};

#endif /* _33_CloneGraph_h */
