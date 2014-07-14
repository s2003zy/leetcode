# Clone Graph

[Clone Graph](https://oj.leetcode.com/problems/clone-graph/)

###c++

```cpp
class Solution {
public:
    UndirectedGraphNode* getCopy(UndirectedGraphNode* node,unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &copyMap)
    {
        if(copyMap.find(node)!=copyMap.end())return copyMap[node];
        
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        
        copyMap[node] = new_node;
        
        for ( auto neighber : node->neighbors ) {

            new_node->neighbors.push_back(getCopy(neighber, copyMap));

        }

        return new_node;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if( node == nullptr) return nullptr;

        unordered_map<UndirectedGraphNode* , UndirectedGraphNode *> copyMap;

        return getCopy(node,copyMap);

    }
};
```