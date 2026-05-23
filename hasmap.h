#include <cstddef>
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

class TestClass{
private:
    int* value = nullptr;

public:
    TestClass() {}

    TestClass(int v): value(new int(v)) {}

    ~TestClass() {
        clear();
    }

    TestClass(const TestClass &other){
        if(other.value){
            value = new int(*other.value);
        } else {
            value = nullptr;
        }
    }

    TestClass(TestClass &&other) noexcept : value(other.value) { 
        other.value = nullptr;
    }

    TestClass& operator=(const TestClass &other){
        if(this != &other){
            clear();
            if(other.value){
                value = new int(*other.value);
            } else {
                value = nullptr;
            }
        }
        return *this;
    }

    TestClass& operator=(TestClass&& other) noexcept{
        if (this != &other){
            clear();
            value = other.value;
            other.value = nullptr;
        }
        return *this;
    }
    
    int get_val() const { 
        return value ? *value : 0;
    }
    bool operator==(const TestClass& other) const {
        if(value == nullptr && other.value == nullptr) return true;
        if(value == nullptr || other.value == nullptr) return false;
        return *value == *other.value;
    }
    bool operator!=(const TestClass& other) const {
        return !(*this == other);
    }

private:
    void clear(){
        if(value){
            delete value;
            value = nullptr;
        }
    }
};

///-------------------------------- DO NOT LOOK ABOVE THIS LINE, IT'S FOR TESTING --------------------------------///
///------------------ IF YOU DO SO MEDUSA WILL COME TO YOU IN YOUR DREAMS AND TURN TO STONE :D ------------------///

template <typename KeyType, typename ValueType>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList &other);
    LinkedList(LinkedList &&other) noexcept;
    LinkedList &operator=(const LinkedList &other);
    LinkedList &operator=(LinkedList &&other) noexcept;

    void insert(const KeyType &key, const ValueType &value);
    void erase(const KeyType &key);
    void clear();

    const ValueType &at(const KeyType &key) const;
    ValueType &at(const KeyType &key);
    ValueType *find(const KeyType &key);

    bool operator==(const LinkedList &other) const;
    bool operator!=(const LinkedList &other) const;

    [[nodiscard]] bool contains(const KeyType &key) const;
    [[nodiscard]] size_t size() const;

private:
    struct Node{
        KeyType key;
        ValueType value;
        Node *next;
    };
    Node *head = nullptr;
    size_t n = 0;
};

template <size_t N, typename KeyType, typename ValueType, typename HashFunc>
class HashMap{
public:
    HashMap();
    ~HashMap();

    HashMap &operator=(const HashMap &other);
    HashMap &operator=(HashMap &&other) noexcept;

    void insert(const KeyType &key, const ValueType &value);
    void erase(const KeyType &key);
    void clear();

    const ValueType &at(const KeyType &key) const;
    ValueType &at(const KeyType &key);
    ValueType &operator[](const KeyType &key);

    bool operator==(const HashMap &other) const;
    bool operator!=(const HashMap &other) const;

    [[nodiscard]] bool contains(const KeyType &key) const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;

private:
    HashFunc hash;
    using Bucket = LinkedList<KeyType, ValueType>;
    Bucket buckets[N];
};

template<typename T>
class HashFunctor{
public:
    size_t operator()(T Key) const;
};

///---------------------- DO NOT TOUCH/MODIFY ABOVE THIS LINE, IT'S FOR YOUR REFERENCE ----------------------///
///------------------ IF YOU DO SO THE CURSE OF KING MIDUS WILL TURN IT INTO BROKEN CODE :P------------------///



// ---------- UnComment the macros as you go on, this allows for partial submissions ----------///
// #define TEST_CASE_1
// #define TEST_CASE_2
// #define TEST_CASE_3
// #define TEST_CASE_4
// #define TEST_CASE_5
// #define TEST_CASE_6
// #define TEST_CASE_7
// #define TEST_CASE_8
// #define TEST_CASE_9
// #define TEST_CASE_10
// #define TEST_CASE_11
// #define TEST_CASE_12
// #define TEST_CASE_13
// #define TEST_CASE_14
// #define TEST_CASE_15
// #define TEST_CASE_16
// #define TEST_CASE_17
// #define TEST_CASE_18
// #define TEST_CASE_19
// #define TEST_CASE_20

///---------------------- DO NOT TOUCH/MODIFY BELOW THIS LINE, IT'S FOR HACKERRANK TESTING ----------------------///
///------------------ IF YOU DO SO THE CURSE OF KING MIDUS WILL TURN IT INTO BROKEN CODE :P------------------///


extern int current_allocations;
inline void reset_alloc_baseline() { current_allocations = 0; }

void run1(), run2(), run3(), run4(), run5(), run6(), run7(), run8(), run9(), run10(), run11(), run12(), run13(), run14(), run15(), run16(), run17(), run18(), run19(), run20();

int current_allocations = 0;

void* operator new(size_t size) {
    current_allocations++;
    return malloc(size);
}
void* operator new[](size_t size) {
    current_allocations++;
    return malloc(size);
}
void operator delete(void* memory) noexcept {
    current_allocations--;
    free(memory);
}
void operator delete(void* memory, size_t size) noexcept {
    current_allocations--;
    free(memory);
}
void operator delete[](void* memory) noexcept {
    current_allocations--;
    free(memory);
}
void operator delete[](void* memory, size_t size) noexcept {
    current_allocations--;
    free(memory);
}

void check_memory_leak(){
    if(current_allocations != 0){
        std::cerr << "Memory Leak: " << current_allocations << " unfreed allocations!" << std::endl;
        exit(1); 
    }
}

int main(){
    int t;
    if (std::cin >> t) {
        {
            switch(t){
                case 1: run1(); break;
                case 2: run2(); break;
                case 3: run3(); break;
                case 4: run4(); break;
                case 5: run5(); break;
                case 6: run6(); break;
                case 7: run7(); break;
                case 8: run8(); break;
                case 9: run9(); break;
                case 10: run10(); break;
                case 11: run11(); break;
                case 12: run12(); break;
                case 13: run13(); break;
                case 14: run14(); break;
                case 15: run15(); break;
                case 16: run16(); break;
                case 17: run17(); break;
                case 18: run18(); break;
                case 19: run19(); break;
                case 20: run20(); break;
                default: break;
            }
        }
    }

    std::cout << std::flush;
    std::cerr << std::flush;
    check_memory_leak();
    return 0;
}

void run1() {
#ifdef TEST_CASE_1
    reset_alloc_baseline();
    LinkedList<std::string,TestClass> sll;
    LinkedList<int,TestClass> ill;
    LinkedList<float,TestClass> fll;
#else
    std::cerr << "testcase1 not being used" << std::endl;
    exit(1);
#endif
}

void run2() {
#ifdef TEST_CASE_2
    reset_alloc_baseline();
    LinkedList<int,TestClass> ill;
    int q;
    std::cin >> q;
    while(q--){
        int key, value;
        std::cin >> key >> value;
        ill.insert(key, TestClass(value));
    }
    std::cout<<ill.size()<<std::endl;
#else
    std::cerr << "testcase2 not being used" << std::endl;
    exit(1);
#endif
}

void run3() {
#ifdef TEST_CASE_3
    reset_alloc_baseline();
    LinkedList<int,TestClass> ill;
    int q;
    std::cin >> q;
    int last_key = -1;
    while(q--){
        int key, value;
        std::cin >> key >> value;
        ill.insert(key, TestClass(value));
        last_key = key;
    }
    std::cout << "Size: " << ill.size() << std::endl;
    if (last_key != -1) {
        try {
            std::cout << "Last Key Value: " << ill.at(last_key).get_val() << std::endl;
        } catch (...) {}
    }
#else
    std::cerr << "testcase3 not being used" << std::endl;
    exit(1);
#endif
}

void run4() {
#ifdef TEST_CASE_4
    reset_alloc_baseline();
    LinkedList<int,TestClass> ill;
    int q;
    std::cin >> q;
    while (q--){
        std::string op; int key;
        std::cin >> op >> key;
        if(op == "insert"){
            int value;
            std::cin >> value;
            ill.insert(key, TestClass(value));
        } else if(op == "erase"){
            ill.erase(key);
        }
    }
#else
    std::cerr << "testcase4 not being used" << std::endl;
    exit(1);
#endif
}

void run5() {
#ifdef TEST_CASE_5
    reset_alloc_baseline();
    LinkedList<std::string,TestClass> sll;
    int q;
    std::cin>>q;
    while (q--){
        std::string op, key;
        std::cin >> op >> key;
        if(op == "insert"){
            int value;
            std::cin >> value;
            sll.insert(key, TestClass(value));
        } else if(op == "erase"){
            sll.erase(key);
        }
    }
#else
    std::cerr << "testcase5 not being used" << std::endl;
    exit(1);
#endif
}

void run6() {
#ifdef TEST_CASE_6
    reset_alloc_baseline();
    LinkedList<std::string,int> sll;
    int q;
    std::cin >> q;
    while(q--){
        std::string op, key;
        int value;
        std::cin >> op >> key >> value;   // always read all 3 tokens (dummy 0 for find/at)
        if(op == "insert"){
            sll.insert(key, value);
        } else if(op == "find"){
            int* res = sll.find(key);
            if(res) std::cout << *res << ": Found\n";
            else std::cout << "NULL: Found\n";
        } else if(op == "at"){
            try {
                std::cout << sll.at(key) << ": Found\n";
            } catch (...) {
                std::cout << "ERROR: KEY NOT FOUND\n";
            }
        }
    }
#else
    std::cerr << "testcase6 not being used" << std::endl;
    exit(1);
#endif
}

// *** FIXED: always read 3 tokens (dummy 0 present for find/at in actual test input) ***
void run7() {
#ifdef TEST_CASE_7
    reset_alloc_baseline();
    LinkedList<std::string,int> sll;
    int q;
    std::cin >> q;
    while(q--){
        std::string op, key;
        int value;
        std::cin >> op >> key >> value;   // always read all 3 tokens
        if(op == "insert"){
            sll.insert(key, value);
        } else if(op == "find"){
            int* res = sll.find(key);
            if(res) std::cout << *res << ": Found\n";
            else std::cout << "NULL: Found\n";
        } else if(op == "at"){
            try {
                std::cout << sll.at(key) << ": Found\n";
            } catch (...) {
                std::cout << "ERROR: KEY NOT FOUND\n";
            }
        } else if(op == "replace"){
            try {
                sll.at(key) = value;
                std::cout << "Replaced\n";
            } catch (...) {
                std::cout << "ERROR: KEY NOT FOUND\n";
            }
        }
    }
#else
    std::cerr << "testcase7 not being used" << std::endl;
    exit(1);
#endif
}

void run8() {
#ifdef TEST_CASE_8
    reset_alloc_baseline();
    LinkedList<int,TestClass> a,b;
    int q;
    std::cin>>q;
    while(q--){
        std::string op;
        std::cin>>op;
        if(op == "insert"){
            int key, value;
            std::cin>>key>>value;
            b.insert(key, TestClass(value));
        }else if(op == "copy"){
            a = b;
        } else if(op == "move"){
            a = std::move(b);
        } else if(op == "clear"){
            a.clear();
        } else if(op == "erase"){
            int key;
            std::cin>>key;
            a.erase(key);
        } else if(op == "find"){
            int key;
            std::cin>>key;
            TestClass* res = a.find(key);
            if(res) std::cout << res->get_val() << ": Found\n";
            else std::cout << "NULL: Found\n";
        }
    }
#else
    std::cerr << "testcase8 not being used" << std::endl;
    exit(1);
#endif
}

void run9() {
#ifdef TEST_CASE_9
    reset_alloc_baseline();
    LinkedList<int,TestClass> a,b;
    int q;
    std::cin>>q;
    while(q--){
        std::string op;
        std::cin>>op;
        if(op == "insert"){
            int key, value;
            std::cin>>key>>value;
            b.insert(key, TestClass(value));
        }else if(op == "copy"){
            a = b;
        } else if(op == "move"){
            a = std::move(b);
        } else if(op == "clear"){
            a.clear();
        } else if(op == "erase"){
            int key;
            std::cin>>key;
            a.erase(key);
        } else if(op == "find"){
            int key;
            std::cin>>key;
            TestClass* res = a.find(key);
            if(res) std::cout << res->get_val() << ": Found\n";
            else std::cout << "NULL: Found\n";
        } else if(op == "equal"){
            if(a == b) std::cout << "Equal\n";
            else std::cout << "Not Equal\n";
        }
    }  
#else
    std::cerr << "testcase9 not being used" << std::endl;
    exit(1);
#endif
}

void run10() {
#ifdef TEST_CASE_10
    reset_alloc_baseline();
    HashMap<5, int, TestClass, HashFunctor<int>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            int key, value;
            std::cin >> key >> value;
            hm.insert(key, TestClass(value));
        } else if(op == "size") {
            std::cout << "Size: " << hm.size() << "\n";
        } else if(op == "empty") {
            std::cout << (hm.empty() ? "Empty\n" : "Not Empty\n");
        } else if(op == "contains") {
            int key;
            std::cin >> key;
            std::cout << (hm.contains(key) ? "Contains\n" : "Does Not Contain\n");
        }
    }
#else
    std::cerr << "testcase10 not being used" << std::endl;
    exit(1);
#endif
}

void run11() {
#ifdef TEST_CASE_11
    reset_alloc_baseline();
    HashMap<10, std::string, TestClass, HashFunctor<std::string>> hm;
    int q;
    std::cin >> q;
    std::string last_key = "";
    while(q--) {
        std::string key;
        int value;
        std::cin >> key >> value;
        hm.insert(key, TestClass(value));
        last_key = key;
    }
    std::cout << "Size: " << hm.size() << "\n";
    if (!last_key.empty()) {
        try {
            std::cout << "Last Key Value: " << hm.at(last_key).get_val() << "\n";
        } catch (...) {}
    }
#else
    std::cerr << "testcase11 not being used" << std::endl;
    exit(1);
#endif
}

void run12() {
#ifdef TEST_CASE_12
    reset_alloc_baseline();
    HashMap<10, int, TestClass, HashFunctor<int>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            int key, value;
            std::cin >> key >> value;
            hm.insert(key, TestClass(value));
        } else if(op == "erase") {
            int key;
            std::cin >> key;
            hm.erase(key);
        } else if(op == "clear") {
            hm.clear();
        } else if(op == "size") {
            std::cout << "Size: " << hm.size() << "\n";
        }
    }
#else
    std::cerr << "testcase12 not being used" << std::endl;
    exit(1);
#endif
}

void run13() {
#ifdef TEST_CASE_13
    reset_alloc_baseline();
    HashMap<10, std::string, TestClass, HashFunctor<std::string>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op, key;
        std::cin >> op >> key;
        if(op == "insert") {
            int value;
            std::cin >> value;
            hm.insert(key, TestClass(value));
        } else if(op == "at") {
            try {
                std::cout << hm.at(key).get_val() << ": Found\n";
            } catch (...) {
                std::cout << "ERROR: KEY NOT FOUND\n";
            }
        } else if(op == "replace") {
            try {
                int value;
                std::cin >> value;
                hm.at(key) = TestClass(value);
                std::cout << "Replaced\n";
            } catch (...) {
                std::cout << "ERROR: KEY NOT FOUND\n";
            }
        }
    }
#else
    std::cerr << "testcase13 not being used" << std::endl;
    exit(1);
#endif
}

void run14() {
#ifdef TEST_CASE_14
    reset_alloc_baseline();
    HashMap<5, int, TestClass, HashFunctor<int>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        int key;
        std::cin >> op >> key;
        if(op == "read") {
            std::cout << "Read Value: " << hm[key].get_val() << "\n";
        } else if(op == "write") {
            int val;
            std::cin >> val;
            hm[key] = TestClass(val);
        } else if(op == "size") {
            std::cout << "Size: " << hm.size() << "\n";
        }
    }
#else
    std::cerr << "testcase14 not being used" << std::endl;
    exit(1);
#endif
}

void run15() {
#ifdef TEST_CASE_15
    reset_alloc_baseline();
    HashMap<5, int, TestClass, HashFunctor<int>> a, b;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            int key, value;
            std::cin >> key >> value;
            b.insert(key, TestClass(value));
        } else if(op == "copy") {
            a = b;
        } else if(op == "erase_b") {
            int key;
            std::cin >> key;
            b.erase(key);
        } else if(op == "contains_a") {
            int key;
            std::cin >> key;
            std::cout << (a.contains(key) ? "A Contains\n" : "A Missing\n");
        }
    }
#else
    std::cerr << "testcase15 not being used" << std::endl;
    exit(1);
#endif
}

void run16() {
#ifdef TEST_CASE_16
    reset_alloc_baseline();
    HashMap<5, int, TestClass, HashFunctor<int>> a, b;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            int key, value;
            std::cin >> key >> value;
            b.insert(key, TestClass(value));
        } else if(op == "move") {
            a = std::move(b);
        } else if(op == "size_a") {
            std::cout << "A Size: " << a.size() << "\n";
        } else if(op == "size_b") {
            std::cout << "B Size: " << b.size() << "\n";
        }
    }
#else
    std::cerr << "testcase16 not being used" << std::endl;
    exit(1);
#endif
}

void run17() {
#ifdef TEST_CASE_17
    reset_alloc_baseline();
    HashMap<5, int, TestClass, HashFunctor<int>> a, b;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert_a") {
            int key, value;
            std::cin >> key >> value;
            a.insert(key, TestClass(value));
        } else if(op == "insert_b") {
            int key, value;
            std::cin >> key >> value;
            b.insert(key, TestClass(value));
        } else if(op == "equal") {
            if(a == b) std::cout << "Equal\n";
            else std::cout << "Not Equal\n";
        } else if(op == "not_equal") {
            if(a != b) std::cout << "Not Equal\n";
            else std::cout << "Equal\n";
        }
    }
#else
    std::cerr << "testcase17 not being used" << std::endl;
    exit(1);
#endif
}

void run18() {
#ifdef TEST_CASE_18
    reset_alloc_baseline();
    HashMap<2, int, TestClass, HashFunctor<int>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            int key, value;
            std::cin >> key >> value;
            hm.insert(key, TestClass(value));
        } else if(op == "erase") {
            int key;
            std::cin >> key;
            hm.erase(key);
        } else if(op == "contains") {
            int key;
            std::cin >> key;
            std::cout << (hm.contains(key) ? "Contains\n" : "Missing\n");
        } else if(op == "size") {
            std::cout << "Size: " << hm.size() << "\n";
        }
    }
#else
    std::cerr << "testcase18 not being used" << std::endl;
    exit(1);
#endif
}

void run19() {
#ifdef TEST_CASE_19
    reset_alloc_baseline();
    HashMap<7, float, TestClass, HashFunctor<float>> hm;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            float key; int value;
            std::cin >> key >> value;
            hm.insert(key, TestClass(value));
        } else if(op == "contains") {
            float key;
            std::cin >> key;
            std::cout << (hm.contains(key) ? "Contains\n" : "Missing\n");
        }
    }
#else
    std::cerr << "testcase19 not being used" << std::endl;
    exit(1);
#endif
}

void run20() {
#ifdef TEST_CASE_20
    reset_alloc_baseline();
    HashMap<11, std::string, TestClass, HashFunctor<std::string>> a, b;
    int q;
    std::cin >> q;
    while(q--) {
        std::string op;
        std::cin >> op;
        if(op == "insert") {
            std::string key; int val;
            std::cin >> key >> val;
            a.insert(key, TestClass(val));
        } else if(op == "erase") {
            std::string key;
            std::cin >> key;
            a.erase(key);
        } else if(op == "copy") {
            b = a;
        } else if(op == "clear") {
            a.clear();
        } else if(op == "equal") {
            std::cout << (a == b ? "Equal\n" : "Not Equal\n");
        }
    }
#else
    std::cerr << "testcase20 not being used" << std::endl;
    exit(1);
#endif
}