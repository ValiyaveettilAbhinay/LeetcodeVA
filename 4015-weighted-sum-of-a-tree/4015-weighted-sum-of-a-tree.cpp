class Node{
public:
    vector<Node*>child;
    int data;
    int value;

    Node(int data,int value = 0){
        this->data = data;
        this->value = value;
    }
};
class Solution {
public:

    int findHeight(Node *root,int lvl){
        if(!root) return 0;
        if(root->child.empty()){
            return lvl;
        }

        int maxH = 0;
        for(auto *node : root->child){

            maxH = max(findHeight(node,lvl+1),maxH);
        }
        return maxH;
    }

    long long traversal(Node *root,int depth,int lvl){
        if(!root) return 0;

        long long s = root->value * 1LL * (depth - lvl + 1);
        for(auto *node : root->child){
            s += traversal(node,depth,lvl+1);
        }

        return s;
    }

    Node* getNode(unordered_map<int,Node*>&seen,int val){
        if(!seen.contains(val)){
            Node *x = new Node(val);
            seen[val] = x;
            return x;
        }
        return seen[val];
    }


    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        
        Node *root = new Node(0);
        unordered_map<int,Node*>seen;

        seen[0] = root;
        root->value = nums[0];

        int n = parent.size();

        for(int i = 1;i<n;i++){
            int prnt = parent[i];
            Node *P = getNode(seen,prnt);
            Node *C = getNode(seen,i);
            C->value = nums[i];
            P->child.push_back(C);
        }

        int h = findHeight(root,0);

        long long res = traversal(root,h,0);

        return res;


    }
};