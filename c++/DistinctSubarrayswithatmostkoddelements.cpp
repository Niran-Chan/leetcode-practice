#include <iostream>
#include <vector>

using namespace std;

typedef struct TrieNode {

    int val;
    vector<TrieNode*> children;

} TrieNode;

void populateTrie(TrieNode* root,TrieNode* child)
{
    for(int i =0;i < root->children.size();i++) //If the number already exists in trie, we no longer need to add it
        if(root->children[i] -> val == child -> val)
            {
                return; 
                }
    root -> children.push_back(child);
    

}
void printTrie(TrieNode* root)
{
    cout << root -> val;
    if(root->children.size() ==0)
        return;

    for(int i =0 ; i < root -> children.size();i++)
        {
            cout << "\n" << "->";
            printTrie(root -> children[i]);
        }
    return;
}

TrieNode* checkDuplicateWithTrie(TrieNode* root,int targetVal) //traverse trie 
{
    for(int i =0;i < root -> children.size();i++)
    {if(root ->children[i]->val == targetVal )
    {    
        root = root -> children[i];
        return root;
    }
    }
    
    return NULL;

}


bool checkDuplicate(vector<int>& A,vector<vector<int>> &B)
{
    for(int i =0; i < B.size();i++)
    {
        if(B[i].size() != A.size() || B[i][0] != A[0])
            continue;
        int x = 0;
        while(true)
            {
                if(x == A.size())
                {
                   return true;
                }
                if(A[x] != B[i][x])
                    break;
                x++;    
            }
    }

    return false;

}
int solve (vector<int> nums,int k)
{
    vector<vector<int>> dp; //cache
    vector<vector<int>> allComb; //all possible combinations so far
   
   TrieNode* root = new TrieNode();

   for(int i =0 ;i < nums.size();i++)
    {
        TrieNode* child = new TrieNode();
        child -> val = nums[i];
        populateTrie(root,child);
    }


    for(int i =0 ;i < nums.size();i++)
        {
            vector<int> comb;
            int tmp = k;
            TrieNode* trav = root;
            for(int j = i; j < nums.size();j++)
            {              
                if(nums[j] %2)
                    tmp--; 
                if(tmp == -1)
                    break; 
                comb.push_back(nums[j]);
                TrieNode* tmpNode = checkDuplicateWithTrie(trav,nums[j]); 
                
                if(!comb.empty() && tmpNode == NULL )
                {
                    allComb.push_back(comb);
                    TrieNode* child = new TrieNode();
                    child->val = nums[j];
                    populateTrie(trav,child);
                }
            }
            sort(allComb.begin(),allComb.end());

        }
        
        printTrie(root);
        for(auto a : allComb){
            cout << "[";
            for(auto b : a)
                cout << b << ",";
            cout << "]";    
            
            }

    return allComb.size();

}



int main ()
{
    vector <int> nums = {3, 2, 3, 4};
    int k = 1;

    int ans = solve(nums,k);
    cout << "\n" << ans << endl;
    return 0; 

}