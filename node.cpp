class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int s = 0;
        int maxdepth = 1;
        int ct = 1;
        int x = 1+g(root);
        std::cout << "x : " << x << std::endl;
        f(root, s, ct, x);
        return s;
    }
    
    int g(TreeNode* node)
    {
       if(node == nullptr)
           return 0;
        if(node->left == nullptr && node->right == nullptr)
            return 0;
        int a = g(node->left);
        int b = g(node->right);
        return 1+max(a,b);
    }
    
    
    void f(TreeNode* node, int& s, int ct, int maxdep)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            if(ct == maxdep)
            {
               s = s + node->val;
            return; 
            }
            
        }
        else
        {
            //ct++;
            if(node->left != nullptr)
            {
                //ct++;
                f(node->left, s, ct+1, maxdep);
                //ct--;
            }
            if(node->right != nullptr)
            {
                //ct++;
                f(node->right, s, ct+1, maxdep);
                //ct--;
            }
            //ct--;
        }
    }
    
};
