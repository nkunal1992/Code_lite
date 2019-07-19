#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_set>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *getNode(){
    Node *temp {new Node};
    temp->left = nullptr;
    temp->right = nullptr;
    
    return temp;
}

Node *insert(Node *root, int item){
    Node *temp = getNode();
    temp->data = item;
    
    if(root == nullptr)
        return temp;
        
    Node *cur {root},*parent {nullptr};
    while(cur!=nullptr){
        if(item <= cur->data){
            parent = cur;
            cur = cur->left;
        }
        else{
            parent = cur;
            cur = cur->right;
        }
    }
    
    if(item <= parent->data)
        parent->left = temp;
    else
        parent->right = temp;
    
    return root;
}

Node *sortedArrayToBST(int * const arr, int start, int end){
    if(start > end)
        return nullptr;
    
    int mid = (start + end)/2;
    Node *root = getNode();
    root->data = arr[mid];
    
    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
    
    return root;
}

void mirror(Node * const root){
    if(root==nullptr)
        return;
        
    Node *temp;
    mirror(root->left);
    mirror(root->right);
    
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void preorder(Node * const root){
    if(root!=nullptr){
        std::cout << root->data <<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder_iter(Node * const root){
    /*
        1. create an empty stack s
        2. push root node to s
        3. loop until s is empty
            a. pop from s and print it
            b. push right child of popped item to s
            c. push left child of popped item to s
     */
    if(root==nullptr)
        return;
    std::stack <Node *> s;
    Node *cur {root};
    s.push(cur);
    while(!s.empty()){
        cur = s.top();
        s.pop();
        std::cout<<cur->data<<"\t";
        if(cur->right!=nullptr)
            s.push(cur->right);
        if(cur->left!=nullptr)
            s.push(cur->left);
    }
}

void postorder(Node * const root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data <<"\t";
    }
}

void postorder_iter(Node * const root){
    /*
        1. Push root to first stack
        2. Loop while first stack is not empty
            a. Pop a node from first stack and push it to second stack
            b. Push left and right children of the popped node to first stack.
        3. Print contents of second stack
     */
    if(root==nullptr)
        return;
    std::stack <Node *> first, second;
    first.push(root);
    Node *cur;
    
    while(!first.empty()){
        cur = first.top();
        first.pop();
        second.push(cur);
        if(cur->left!=nullptr)
            first.push(cur->left);
        if(cur->right!=nullptr)
            first.push(cur->right);
    }
    
    while(!second.empty()){
        cur = second.top();
        second.pop();
        std::cout<<cur->data<<"\t";
    }
    std::cout<<std::endl;
}

void inorder(Node * const root){
    if(root!=nullptr){
        inorder(root->left);
        std::cout << root->data <<"\t";
        inorder(root->right);
    }
}

void inorder_iter(Node * const root){
    /*
        1. create an empty stack s
        2. Initialize current node as root
        3. Push the current node to s and set current = current->left until current is nullptr
        4. If current is nullptr and stack is not empty then
            a. Pop the top item from stack
            b. print the popped item. set current = popped_item->right
            c. Goto step 3.
        5. If current is nullptr and stack is empty then we are done.
     */
     if(root==nullptr)
         return;
         
     std::stack <Node *> s;
     Node *cur {root},*temp;
     while(true){
         while(cur!=nullptr){
         s.push(cur);
         cur = cur->left;
         }
         if(cur==nullptr && !s.empty()){
             temp = s.top();
             s.pop();
             std::cout<<temp->data<<"\t";
             cur = temp->right;
         }
         
         if(cur==nullptr && s.empty())
             break;
     }
     
}

void levelorder(Node * const root){
    /*
        1.create an empty queue q
        2.temp_node = root
        3.Enqueue temp_node to q
        3.Loop until q is not empty
            a. Dequeue from q and assign it to temp_node
            b. print temp_node->data
            c. Enqueue temp_node children(first left then right) to q
            d. Dequeue a node from q and assign it's value to temp_node
     */
     if(root==nullptr)
         return;
         
     std::queue<Node *> q;
     Node *temp = root;
     q.push(temp);
     
     while(!q.empty()){
         temp = q.front();
         q.pop();
         std::cout<<temp->data<<"\t";
         if(temp->left!=nullptr)
            q.push(temp->left);
         if(temp->right!=nullptr)
            q.push(temp->right);
     }
     std::cout<<std::endl;
}

void zigzagtraversal(Node * const root){
    if(root==nullptr)
        return;
    
    std::stack <Node *> curLevel,nextLevel;
    
    curLevel.push(root);
    bool leftToright {true};
    
    while(!curLevel.empty()){
        Node *temp = curLevel.top();
        curLevel.pop();
        std::cout<<temp->data<<" ";
        
        if(leftToright){
            if(temp->left!=nullptr)
                nextLevel.push(temp->left);
            if(temp->right!=nullptr)
                nextLevel.push(temp->right);
        }
        else{
            if(temp->right!=nullptr)
                nextLevel.push(temp->right);
            if(temp->left!=nullptr)
                nextLevel.push(temp->left);
        }
        
        if(curLevel.empty()){
            swap(curLevel,nextLevel);
            leftToright = !leftToright;
        }
    }
}

void reverse_levelorder(Node * const root){
    /*
        1. Create an empty queue q and an empty stack s
        2. Enqueue the root node in q
        3. Loop while q is not empty
            a. Dequeue a node from q and make it root
            b. Push the root node to the stack s
            c. Enqueue the root node's children(first right then left) to q
        4. Now pop all items from stack one by one and print it.
     */
    if(root==nullptr)
        return;
         
    std::queue <Node *> q;
    std::stack <Node *> s;
    Node *cur_root {root};
    q.push(cur_root);
    while(!q.empty()){
        cur_root = q.front();
        q.pop();
        s.push(cur_root);
        if(cur_root->right!=nullptr)
            q.push(cur_root->right);
        if(cur_root->left!=nullptr)
            q.push(cur_root->left);
    }
    
    while(!s.empty()){
        Node *temp = s.top();
        std::cout << temp->data <<"\t";
        s.pop();
    }
    std::cout<< std::endl;
}

unsigned int count_halfNodes(Node * const root){
    /*
     Half Nodes: Nodes which have only one child are called half nodes
        1. Create an empty queue q and push root node to q.
        2. Loop until q is not empty
            a. pop an item from q and process it
                i. if it is half node then increment count++
            b. push left and right child of popped item to q, if available.
     */
     
    if(root==nullptr)
        return 0;
    unsigned int count {0};
    std::queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if((temp->left==nullptr && temp->right!=nullptr) || (temp->left!=nullptr && temp->right==nullptr) )
            count++;
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    return count;
}

unsigned int count_leafNodes(Node * const root){
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return 1;
    
    return count_leafNodes(root->left)+count_leafNodes(root->right);
}

unsigned int count_leafNodes_iter(Node * const root){
    /*
     Leaf Nodes: Nodes which have no child are called leaf nodes
        1. Create an empty queue q and push root node to q.
        2. Loop until q is not empty
            a. pop an item from q and process it
                i. if it is leaf node then increment count++
            b. push left and right child of popped item to q, if available.
     */
     
    if(root==nullptr)
        return 0;
    unsigned int count {0};
    std::queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left==nullptr && temp->right==nullptr)
            count++;
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    return count;
}

unsigned int count_fullNodes(Node * const root){
    /*
     Full Nodes: Nodes which have both left and right child are called full nodes
        1. Create an empty queue q and push root node to q.
        2. Loop until q is not empty
            a. pop an item from q and process it
                i. if it is full node then increment count++
            b. push left and right child of popped item to q, if available.
     */
     
    if(root==nullptr)
        return 0;
    unsigned int count {0};
    std::queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left!=nullptr && temp->right!=nullptr)
            count++;
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    return count;
}

unsigned int height_iter(Node * const root){
    /*
        1. Create an empty queue q for level order traversal
        2. Enqueue root and initialize height
        3. Loop until q is not empty
            a. increment height
            b. initialize node count as q.size()
            c. loop until node_count is not zero
                i. Dequeue node from q
                ii. decrement node_count
                iii. Enqueue child of dequeued element
        4. Return height
     */
    if(root==nullptr)
        return 0;
        
    std::queue <Node *> q;
    q.push(root);
    unsigned int height {0};
    
    while(!q.empty()){
        height++;
        int node_count = q.size();
        while(node_count){
            Node *temp = q.front();
            q.pop();
            node_count--;
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
        }
    }
    return height;
}

unsigned int height(Node * const root){
    if(root==nullptr)
        return 0;
    
    unsigned int lheight = height(root->left);
    unsigned int rheight = height(root->right);
    
    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

bool search_iter(Node *const root, int key){
    /*
        1. Create an empty queue q for level order traversal
        2. Enqueue root to q
        3. loop until q is not empty
            a. dequeue a node from q
            b. if node->data == key, return true
            c. Enqueue child of dequeued node
        4. Return false
     */
    if(root==nullptr)
        return false;
        
    std::queue <Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->data == key)
            return true;
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    return false;
}

unsigned int size(Node *const root){
    if(root==nullptr)
        return 0;
    return size(root->left)+size(root->right)+1;
}

unsigned int size_iter(Node *const root){
    /*
        1. Create an empty queue q
        2. Enqueue root to q
        3. Initialize count
        4. Loop until q is empty
            a. Dequeue from q
            b. Increment count
            c. Enqueue child of dequeued element
        5. Return count
     */
    if(root==nullptr)
        return 0;
    std::queue <Node *> q;
    Node *temp {root};
    q.push(temp);
    unsigned int count {0};
    while(!q.empty()){
        temp = q.front();
        q.pop();
        count++;
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
    
    return count;
}

//Function to print the avg value of nodes on each level
void avgOfLevels(Node * const root){
    /*
        1. Create two empty queue q1 and q2
        2. Enqueue root to q1
        3. Loop untill q1 is not empty
            a. initialize node_count as q1.size(), sum and count as 0
            b. loop until node_count is not zero
                i. deque from q1 and assign it to temp
                ii. decrement node_count, increment count and add sum to temp->data
                iii. enqueue child of temp to q2
            c. assign q2 to q1 and clear content of q2
            d. print sum/count
     */
    if(root==nullptr)
        return;
        
    std::queue <Node *> q1,q2;
    q1.push(root);
    
    while(!q1.empty()){
        float sum {0.0};
        int count {0};
        
        unsigned int node_count = q1.size();
        
        while(node_count){
            Node *temp = q1.front();
            q1.pop();
            node_count--;
            sum += temp->data;
            count++; 
            
            if(temp->left != nullptr)
                q2.push(temp->left);
            if(temp->right != nullptr)
                q2.push(temp->right);
        }
        q1 = q2;
        q2 = std::queue <Node *> (); //clear content of q2
        std::cout << (sum/count) <<" ";
    }
    std::cout << std::endl;
}

//print leftmost and rightmost
void printCorner(Node * const root){
    if(root==nullptr)
        return;
    
    std::queue <Node *> q1, q2;
    std::cout<< root->data << " ";
    
    Node *temp {root};
    while(temp->left!=nullptr){
        q1.push(temp->left);
        temp=temp->left;
    }
    temp = root;
    while(temp->right!=nullptr){
        q2.push(temp->right);
        temp=temp->right;
    }
    
    while((!q1.empty()) ||(!q2.empty())){
        if(!q1.empty()){
            temp = q1.front();
            std::cout<<temp->data<<" ";
            q1.pop();
        }
        if(!q2.empty()){
            temp = q2.front();
            std::cout<<temp->data<<" ";
            q2.pop();
        }
    }
    std::cout<<std::endl;
}

void rightView(Node * const root){
    /*
        The Right view contains all nodes that are last nodes in their levels
     */
    if(root==nullptr)
        return;
        
    std::queue <Node *> q1,q2;
    q1.push(root);
    
    while(!q1.empty()){
        Node *temp = q1.back();//extract last node of current level
        std::cout<<temp->data<<" ";
        int node_count = q1.size();
        while(node_count){//insert next level entries
            node_count--;
            temp = q1.front();
            q1.pop();
            
            if(temp->left!=nullptr)
                q2.push(temp->left);
            if(temp->right!=nullptr)
                q2.push(temp->right);
        }
        q1 = q2;
        q2 = std::queue <Node *> ();
    }
    std::cout<<std::endl;
}

void printLevels(Node *root, int low, int high){
    if(root==nullptr)
        return;
        
    std::queue <Node *> q1, q2;
    int level {1};
    q1.push(root);
    
    while(!q1.empty() && level <= high){
        int node_count = q1.size();
        while(node_count){
            Node *temp = q1.front();
            q1.pop();
            if(level >=low){
                std::cout<<temp->data<<" ";
            }
            //insert next level entries
            if(temp->left!=nullptr)
                q2.push(temp->left);
            if(temp->right!=nullptr)
                q2.push(temp->right);
            node_count--;
        }
        if(level >= low)
            std::cout<<std::endl;
        if(!q2.empty()){
            q1 = q2;
            q2 = std::queue <Node *> ();
            level++;
        }
    }
    std::cout<<std::endl;
}

void printKdistanceFromRoot(Node * const root, int k){
    if(root==nullptr)
        return;
    if(k==0){
        std::cout<<root->data<<" ";
        return;
    }
    else{
        printKdistanceFromRoot(root->left,k-1);
        printKdistanceFromRoot(root->right,k-1);
    }
}

void printKdistanceFromRoot_iter(Node * const root, int k){
    if(root==nullptr)
        return;
        
    std::queue <Node *> q1, q2;
    int level {0};
    q1.push(root);
    
    while(!q1.empty()){
        int node_count = q1.size();
        while(node_count){
            Node *temp = q1.front();
            q1.pop();
            if(level == k){
                std::cout<<temp->data<<" ";
            }
            //insert next level entries
            if(temp->left!=nullptr)
                q2.push(temp->left);
            if(temp->right!=nullptr)
                q2.push(temp->right);
            node_count--;
        }
        if(level==k)
            break;
        if(!q2.empty()){
            q1 = q2;
            q2 = std::queue <Node *> ();
            level++;
        }
    }
    std::cout<<std::endl;
}

void distanceOfNodeFromRoot_iter(Node * const root, int key){
    if(root==nullptr){
        std::cout<<"\n"<<key<<" not found"<<std::endl;
        return;
    }
    
    int dist {0};
    std::queue <Node *> q1, q2;
    q1.push(root);
    while(!q1.empty()){
        int node_count = q1.size();
        while(node_count){
            Node *temp = q1.front();
            q1.pop();
            if(temp->data==key){
                std::cout<<"\n"<<key<<" found at distance "<<dist<<" from root"<<std::endl;
                return;
            }
            node_count--;
            if(temp->left!=nullptr)
                q2.push(temp->left);
            if(temp->right!=nullptr)
                q2.push(temp->right);
        }
        if(!q2.empty()){
            q1 = q2;
            q2 = std::queue <Node *> ();
            dist++;
        }
    }
}

bool printAncestors(Node * const root, int key){
    if(root==nullptr)
        return false;
    if(root->data == key)
        return true;
        
    if(printAncestors(root->left,key) || printAncestors(root->right,key)){
        std::cout<<root->data<<" ";
        return true;
    }
    return false;
}

void sumOfLeafAtMinLevel(Node * const root){
    if(root==nullptr)
        return;
        
    std::queue <Node *> q;
    q.push(root);
    int sum {0};
    bool minLevelReached {false};
    while(!minLevelReached){
        int node_count = q.size();
        while(node_count){
            Node *temp = q.front();
            q.pop();
            node_count--;
            if(temp->left==nullptr && temp->right==nullptr){
                sum += temp->data;
                minLevelReached = true;
            }
            else{
                if(temp->left!=nullptr)
                    q.push(temp->left);
                if(temp->right!=nullptr)
                    q.push(temp->right);
            }
        }
    }
    std::cout<<"\nSum of leaf node at minimum level is : "<<sum<<std::endl;
}

void maxLevelSum(Node * const root){
    if(root==nullptr)
        return;
        
    std::queue <Node *> q;
    q.push(root);
    int max = root->data;

    while(!q.empty()){
        int node_count = q.size();
        int sum {0};
        while(node_count){
            Node *temp = q.front();
            sum += temp->data;
            node_count--;
            q.pop();
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
        }
        if(sum>max)
            max = sum;
    }
    std::cout<<"\nMax level sum is : "<<max<<std::endl;
}

int maxOfLeftElement(Node * const root){
    int res = INT_MIN;
    if(root==nullptr)
        return res;
        
    if(root->left!=nullptr)
        res = root->left->data;
        
    return std::max({maxOfLeftElement(root->left),res,maxOfLeftElement(root->right)});
}

/*
 * We store the horizontal distance in a set. While going left, do hdist-1 and
 * for right do hdist+1. We insert all possible distances in a hash table and
 * finally return size of the hashtable.
 */
 
void fillSet(Node * const root, std::unordered_set<int> &s, int hdist){
    if(root==nullptr)
        return;
    fillSet(root->left,s,hdist-1);
    s.insert(hdist);
    fillSet(root->right,s,hdist+1);
}

int verticalWidth(Node * const root){
    std::unordered_set <int> s;
    fillSet(root,s,0);
    return s.size();
}

/*
 * The tilt of a tree node is defined as the absolute difference b/w the sum of
 * all left subtree node values and the sum of all right subtree node values.
 * Null nodes are assigned tilt to be zero. Therefore, tilt of the whole tree is
 * defined as the sum of all node's tilt.
 */

void tiltOfTree(Node * const root){
    if(root==nullptr)
        return;
        
    std::queue <Node *> q;
    q.push(root);
    int tilt {0};
    while(!q.empty()){
        int node_count = q.size();
        while(node_count){
            Node *temp = q.front();
            q.pop();
            node_count--;
            if(temp->left && temp->right){
                tilt += std::abs(temp->left->data - temp->right->data);
                q.push(temp->left);
                q.push(temp->right);
            }
            else if(temp->left && !temp->right){
                tilt += std::abs(temp->left->data);
                q.push(temp->left);
            }
            else if(!temp->left && temp->right){
                tilt += std::abs(0-temp->right->data);
                q.push(temp->right);
            }
        }
    }
    
    std::cout<<"Tilt of tree : "<<tilt<<std::endl;
}

int main(){
	Node *root {nullptr};
    int arr[10] {2,4,6,8,10,12,14,16,18,20};
//    root = insert(root,150);
//    root = insert(root,100);
//    root = insert(root,200);
//    root = insert(root,50);
//    root = insert(root,110);
//    root = insert(root,160);
//    root = insert(root,210);
//    root = insert(root,290);
    root = sortedArrayToBST(arr,0,9);
    preorder(root);
    std::cout<<std::endl;
    preorder_iter(root);
    std::cout<<std::endl;
    
    inorder(root);
    std::cout<<std::endl;
    inorder_iter(root);
    std::cout<<std::endl;
    
    postorder(root);
    std::cout<<std::endl;
    postorder_iter(root);
    std::cout<<std::endl;
    
    std::cout<<"\nZigZag"<<std::endl;
    zigzagtraversal(root);
    std::cout<<"\nLevel order"<<std::endl;
    levelorder(root);
    std::cout<<std::endl;
    
    reverse_levelorder(root);
    printAncestors(root,12);
    std::cout<<std::endl;
    
    std::cout<<"Printlevels(1,4)\n"<<std::endl;
    printLevels(root,1,4);
    tiltOfTree(root);
    printKdistanceFromRoot_iter(root,2);
    printKdistanceFromRoot(root,2);
    distanceOfNodeFromRoot_iter(root,16);
    sumOfLeafAtMinLevel(root);
    maxLevelSum(root);
    std::cout<<"\nMax of left element is : "<<maxOfLeftElement(root)<<std::endl;
    std::cout<<"\nVertical width : "<<verticalWidth(root)<<std::endl;
    std::cout<<"\nNo of half nodes : "<<count_halfNodes(root)<<std::endl;
    std::cout<<"No of leaf nodes : "<<count_leafNodes_iter(root)<<std::endl;
    std::cout<<"No of leaf nodes : "<<count_leafNodes(root)<<std::endl;
    std::cout<<"No of full nodes : "<<count_fullNodes(root)<<std::endl;
    std::cout<<"Height of tree : "<<height_iter(root)<<std::endl;
    std::cout<<"Height of tree : "<<height(root)<<std::endl;
    std::cout<<"Size of tree : "<<size(root)<<std::endl;
    std::cout<<"Size of tree : "<<size_iter(root)<<std::endl;
    std::cout<<"210 found : "<<std::boolalpha<<search_iter(root,210)<<std::endl;
    avgOfLevels(root);
    printCorner(root);
    rightView(root);
    std::cout<<"\n-------------Mirror-------------\n"<<std::endl;
    mirror(root);
    preorder(root);
    std::cout<<std::endl;
    preorder_iter(root);
    std::cout<<std::endl;
    
    inorder(root);
    std::cout<<std::endl;
    inorder_iter(root);
    std::cout<<std::endl;
    
    postorder(root);
    std::cout<<std::endl;
    postorder_iter(root);
    std::cout<<std::endl;
    
    levelorder(root);
    std::cout<<std::endl;
    
    reverse_levelorder(root);
    std::cout<<std::endl;
    
    std::cout<<"No of half nodes : "<<count_halfNodes(root)<<std::endl;
    std::cout<<"No of leaf nodes : "<<count_leafNodes_iter(root)<<std::endl;
    std::cout<<"No of leaf nodes : "<<count_leafNodes(root)<<std::endl;
    std::cout<<"No of full nodes : "<<count_fullNodes(root)<<std::endl;
    std::cout<<"Height of tree : "<<height_iter(root)<<std::endl;
    std::cout<<"Height of tree : "<<height(root)<<std::endl;
    std::cout<<"Size of tree : "<<size(root)<<std::endl;
    std::cout<<"Size of tree : "<<size_iter(root)<<std::endl;
    std::cout<<"210 found : "<<std::boolalpha<<search_iter(root,210)<<std::endl;
    avgOfLevels(root);
    printCorner(root);
    rightView(root);
	return 0;
}
