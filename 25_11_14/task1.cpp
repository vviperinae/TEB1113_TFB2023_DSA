#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* insertNode(Node* root, int value) {
    if (root==NULL) { //If tree is empty, create new node
        Node* newNode = new Node(value);
        return newNode;
    }
    
    if (value<root->data) {//If value is smaller than current node's data insert into left subtree
        root->left = insertNode(root->left, value);
    }

    else {//If value is larger or equal than current node's data insert into right subtree
        root->right = insertNode(root->right, value);
    }
    return root;
}


Node* deleteNode(Node* root, int value) {
    if (root==NULL) { //if tree is empty or value not found
        return root;
    }
//search for node to delete
    if (value < root->data) {//in left subtree
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {//in right subtree
        root->right = deleteNode(root->right, value);
    } else {//node has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;//return NULL to parent
        }
        
        else if (root->left == NULL) {//node has only right child
            Node* rightChild = root->right;
            delete root;
            return rightChild;// return right child to parent
        }
        
        //node has only left child
        else if (root->right == NULL) {
            Node* leftChild = root->left; 
            delete root;    
            return leftChild; //return left child to parent
        }
        
        //node has two children
        else {
            //find inorder successor
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data); //(recursive)
        }
    }
    return root;
}

bool updateNode(Node* root, int oldValue, int newValue) {
    //check if tree is empty or reached end of branch
    if (root == NULL) {
        return false;
    }

    //if current node contains the value to update
    if (root->data == oldValue) {
        root->data = newValue;
        return true;
    }
    //search in both subtrees (recursive)
    bool foundInLeft = updateNode(root->left, oldValue, newValue);
    bool foundInRight = updateNode(root->right, oldValue, newValue);
    return foundInLeft || foundInRight;//true if found in either subtree
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data <<" ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root!=NULL) {
        cout << root->data <<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data <<" ";
    }
}

int main() {
    Node* root = NULL;
    int choice, value, oldValue, newValue;

    while (true) {
        cout << "\n===== BINARY TREE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Update a value\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter values to insert (end with -1 to stop): ";
            while (true) {
                cin >> value;
                if (value == -1){
                    break;   
                } 
                root = insertNode(root, value);
            }
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "Enter value to update: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            if (updateNode(root, oldValue, newValue)){
                cout << "Updated successfully.\n";
            }else{
                cout << "Value not found.\n";
            }
            break;

        case 4:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 7:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}