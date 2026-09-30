class LRUCache {
public:
    class Node{
        public:

        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int key,int val){
            this->key=key;
            this->val=val;
            prev=NULL;
            next=NULL;
        }

    };

    unordered_map<int,Node*>mpp;
    Node* start;
    Node* end;
    int cap;
    int size=0;
    LRUCache(int capacity) {
        cap=capacity;
        start=new Node(-1,-1);
        end=new Node(-1,-1);
        start->next=end;
        end->prev=start;
    }
    
    int get(int key) {
           if(!mpp.count(key))return -1;

        Node* temp=mpp[key];

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        temp->next=start->next;
        temp->prev=start;
        start->next->prev=temp;
        start->next=temp;

        return temp->val;
    }
    
    void put(int key, int value) {

        if(mpp.count(key)){

        Node* temp=mpp[key];

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        temp->next=start->next;
        temp->prev=start;
        start->next->prev=temp;
        start->next=temp;

        temp->val=value;


        }

        
        else if(size<cap){
            
            Node* new_node=new Node(key,value);

            new_node->next=start->next;
            new_node->prev=start;

            start->next->prev=new_node;
            start->next=new_node;

            mpp[key]=new_node;
            
            size++;
        }
        else if(size==cap){

        Node* del=end->prev;

        del->prev->next=end;
        end->prev=del->prev;
        
        
        
        mpp.erase(del->key);

        delete del;


        Node* temp=new Node(key,value);

        temp->next=start->next;
        temp->prev=start;
        start->next->prev=temp;
        start->next=temp;
        mpp[key]=temp;
       
 
        }

    }
};
