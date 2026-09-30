class LRUCache {
public:
    class node{
        public :

        int key;
        int val;

        node* next;
        node* prev;

        node(int k,int v){
            key=k;
            val=v;
            next=NULL;
            prev=NULL;

        }
    };

    int cap;
    unordered_map<int,node*>mpp;
    node* start;
    node* end;
    LRUCache(int capacity) {
        cap=capacity;

        start=new node(-1,-1);
        end=new node(-1,-1);

        start->next=end;
        end->prev=start;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        else {

            node* add=mpp[key];

            add->next->prev=add->prev;
            add->prev->next=add->next;

            add->prev=start;
            add->next=start->next;
            
            start->next->prev=add;
            start->next=add;            

            return add->val;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){

            node* add=mpp[key];

            add->next->prev=add->prev;
            add->prev->next=add->next;

            add->prev=start;
            add->next=start->next;
            
            start->next->prev=add;
            start->next=add;            

            add->val=value;

        }
        else if(mpp.find(key)==mpp.end()){
            
            node* new_node=new node(key,value);

            if(mpp.size()==cap){

                node* del=end->prev;
                
                del->prev->next=del->next;
                del->next->prev=del->prev;
                mpp.erase(del->key);

                delete del;

                new_node->prev=start;
                new_node->next=start->next;
            
                start->next->prev=new_node;
                start->next=new_node;
                mpp[key]=new_node; 

            }
            else if(mpp.size()<cap){

                new_node->prev=start;
                new_node->next=start->next;
            
                start->next->prev=new_node;
                start->next=new_node; 

                mpp[key]=new_node;

            }
        }
    }
};
