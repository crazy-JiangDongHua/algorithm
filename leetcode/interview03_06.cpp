class AnimalShelf {
private:
    class Animal{
        private:
            int order;
        public:
            Animal(int order){
                this->order=order;
            }
            bool operator<(const Animal& a) const{
                return order<a.order;
            }
            int getOrder(){return order;}
    };
    class Dog:public Animal{
        public:
            Dog(int order):Animal(order){}
    };
    class Cat:public Animal{
        public:
            Cat(int order):Animal(order){}
    };
    queue<Dog> dogq;
    queue<Cat> catq;
public:
    AnimalShelf() {
    }
    
    void enqueue(vector<int> animal) {
        if(animal[1]==0){
            catq.emplace(animal[0]);
        }else if(animal[1]==1){
            dogq.emplace(animal[0]);
        }else{
            throw exception();
        }
    }
    
    vector<int> dequeueAny() {
        if(catq.empty())
            return dequeueDog();
        if(dogq.empty())
            return dequeueCat();
        Cat cat=catq.front();
        Dog dog=dogq.front();
        return cat<dog?dequeueCat():dequeueDog();
    }
    
    vector<int> dequeueDog() {
        if(dogq.empty())
            return {-1,-1};
        Dog dog=dogq.front();
        dogq.pop();
        return {dog.getOrder(), 1};
    }
    
    vector<int> dequeueCat() {
        if(catq.empty())
            return {-1,-1};
        Cat cat=catq.front();
        catq.pop();
        return {cat.getOrder(), 0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */