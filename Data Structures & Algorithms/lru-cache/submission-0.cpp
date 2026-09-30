class node{
    public :
    pair<int,int>key_value;
    node* next;
    node* prev;

    node(int key,int value){
        this->key_value.first=key;
        this->key_value.second=value;
        next=NULL;
        prev=NULL;
    }  
};

class LRUCache {
public:

    unordered_map<int,node*>mpp;
    int max_capacity;
    node* start;
    node* end;

    LRUCache(int capacity) {

        max_capacity=capacity;

        start = new node(-1,-1); 
        
        end = new node(-1,-1); 

        start->next=end;
        end->prev=start;

    }
    void put_at_head(node* temp){
        
        temp->prev=start;
        temp->next=start->next;

        start->next->prev=temp;
        start->next=temp;

    }

    void delete_and_insert_at_head(node* temp){
        
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;

        put_at_head(temp);
    }

    int get(int key) {

        if(mpp.find(key)==mpp.end())return -1;

        delete_and_insert_at_head(mpp[key]);
        
        return mpp[key]->key_value.second;

    }
    
    void put(int key, int value) {

        if(mpp.find(key)==mpp.end()){

                if(mpp.size()==max_capacity){

                    node* temp=end->prev;

                    temp->next->prev=temp->prev;
                    temp->prev->next=temp->next;
                    
                    mpp.erase(temp->key_value.first);

                    delete temp;

                    node* new_node=new node(key,value);
                    
                    mpp[key]=new_node;

                    put_at_head(new_node);

                }

                else {

                    node* new_node=new node(key,value);

                    mpp[key]=new_node;

                    put_at_head(new_node);
                }

        }
        else {
            
            mpp[key]->key_value.second=value;

            delete_and_insert_at_head(mpp[key]);

        }


    }
};
