#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>



using namespace std;








int main() {
    
    /*******PAIRS START*******/
    
    //Pairs
    pair<int,float> p;
    p = {1, 3.2};
    cout << p.first << " " << p.second << endl;
    
    
    //Nested Pairs
    pair < int , pair<int,float> > q = {1,{2, 4.5}};
    cout << q.first << " " << q.second.first << q.second.second << endl;
    //A pair can store a pair as well aka nested pairs and used to store a lot of values
    
    
    //Pairs with array
    // pair <int, int> arr[] = { {1,3,5} , { 2,4,6} };  Wrong
    pair <int, int> arr[] = { {1,3} , {2,4} , {6,8} , {5,7} };  //Right
    //                          0       1       2       3
    cout << arr[1].second << endl;
    


    cout<< endl << endl;
    
    
    /*******PAIRS END*******/
    
    
    
    
    /*******VECTORS START*******/
    
    
    
    vector <int> v;     //Declaring of vector
    v = vector <int> ();       
    
    v.push_back(1);
    v.emplace_back(2);
    cout << v[0] << " "<< v[1] << endl;
    
    vector< pair<int, float>> vec;
    vec.push_back({6,3});   //Curly braces are needed to make it a pair
    vec.emplace_back(4,5);  //Automatically assumes it to be a pair
    cout << vec[0].first << " " << vec[1].second << endl;
    
    v = vector<int> (5,100);
    cout << v[0] << " " <<  v[1] << " " << v[2] << " " << v[3] << " " << v[4] << endl;
    
    /*for (int x : v) 
    cout << x << ' ';cout << endl;*/
    
    v = vector<int> (5);        //A vector of 5 places with garbage values is created
    cout << v[0] << " " <<  v[1] << " " << v[2] << " " << v[3] << " " << v[4] << endl;
    
    vector <int> v1(5,20);
    vector <int> v2(v1);
    v1.push_back(1);        //Even though it is filled you can still push more values. It will just increase its size
    cout << v2[0] << endl;
    
    
    cout<< endl << endl;
    
    
    /*ITERATION Start*/
    
    
    v = {10,20,30,40};
    vector<int> :: iterator it = v.begin();   //It is pointing towards the address of the vector hence deferencing is needed when printing
    //'it' is for storing of the value
        //It is same as int it; so do not redeclare
        
        // it++;
        cout << *(it) << " ";   
        cout << endl;
        
        
        // [10] [20] [30] [40] [END] Explains why -1
        cout << *(v.end() - 1) << " ";   
        cout << endl;
        
        cout << v.back() << " ";   //v.back() is not an iterator. So NO dereferencing
        cout << endl;
        
        
        
        /*WAYS TO PRINT VECTOR ARRAY*/
        
        /*Declaring inside for loop*/
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        
        /*Using already declared*/
        for ( it = v.begin(); it < v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        
        /*Using auto function*/
        /*Auto function in c++ assignes datatype on its own depending upon the type of value*/
        for (auto it = v.begin(); it < v.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        
        
        /*Range Based Loop*/
        for (/*auto*/int x : v) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        cout<< endl << endl;
        
        
        /*ERASE*/
        
        v.erase(v.begin(), v.begin()+2);     //Removes v[0] ie 10 to v[2] ie 20
        // v.begin() = v.begin()+1 (Wrong)
        cout<< "Removing v[0] to v[2] (v[2] is excluded): ";
        for (/*auto*/int x : v) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        cout<< endl << endl;
        
        
        /*INSERT*/
        
        v = {10,20,30,40};
        
        v.insert(v.begin()+2, 25);
        cout<< "Inserting 25 at v[2] ie third place ";
        for (/*auto*/int x : v) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        v = {10,20,30,40};
        
        v.insert(v.begin()+3, 2, 35);
        cout<< "Inserting two 35's from v[3] ";
        for (/*auto*/int x : v) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        v = {10,20,30,40};
        vector <int>v_copy;
        
        v_copy = {33,35,37};
        v.insert(v.begin()+3, v_copy.begin()+1, v_copy.begin()+3);
        cout<< "Inserting v'[1] to v'[3] (v[2] is excluded)s in v from v[3] ";
        for (/*auto*/int x : v) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        
        
        v = {10,20,30,40};
        cout <<"Size of v is "<< v.size()<< endl;    //Size of v ie 4
        v.pop_back(); //Removes Last ie 40
        
        
        v1 = {10,20};
        v2 = {30,40};
        
        cout<<"V1 is: ";
        for (/*auto*/int x : v1) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        cout<<"V2 is: ";
        for (/*auto*/int x : v2) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        v1.swap(v2);
        
        cout<<"Now V1 is: ";
        for (/*auto*/int x : v1) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        cout<<"Now V2 is: ";
        for (/*auto*/int x : v2) 
        {
            cout << x << " ";
        }
        cout << endl;
        
        
        v.clear(); //Entire vector erase
        cout<< v.empty();
        
        cout<< endl << endl;
        /*******VECTORS END*******/
        

        /******LIST START******/

        //List is a lot like linked list

        list<int> ls;

        ls.push_back(2);
        ls.emplace_back(4);

        ls.push_front(5);

        ls.emplace_front(1); //{2,4;}

        ls.pop_back();   // removes last element

        ls.pop_front();  // removes first element


        for (auto it = ls.begin(); it != ls.end(); it++) {
    cout << *it << " ";
        }

        ls.reverse();
        ls.sort();
        ls.clear();
        ls.size();
        ls.empty();         // true if list is empty

        /*When to use list (vs vector)
Operation	                    vector	            list
Random access	             ✅ Fast	             ❌ Slow
Insert/delete in middle	    ❌ Slow	            ✅ Fast
Memory locality	            ✅ Contiguous	    ❌ Scattered
Sorting	                sort(v.begin(), v.end())	ls.sort()

🟢 Use list when you need frequent insertions/deletions anywhere in the sequence.
🟣 Use vector when you need fast random access or work mostly at the end.*/
        cout<< endl << endl;

        /******LIST END******/



        /******STACK START******/
        //First in Last out
stack <int> st;
st.push(1);     // {1}
st.push(2);     // {2,1}
st.push(3);     // {3,2,1}
st.push(4);     // {4,3,2,1}
st.emplace(5);  //{5,4,3,2,1}

cout << st.top();       //prints 5

st.pop();       //Removes 5

cout << st.top(); 

cout << st.size();

cout << st.empty();

stack<int> st1, st2;

st1.swap(st2);

        cout<< endl << endl;


        /******STACK END******/

        /******QUEUE START******/
        //First in first out basis
        queue<int> qu;
        
        qu.push(1);     //{1}
        qu.push(2);     //{1,2}
        qu.emplace(4);      //{1,2,4}
        
        qu.back() += 5;
        
        cout << qu.back();      
        
        cout << qu.front();
        
        qu.pop();
        
        cout << qu.front();
        

                cout<< endl << endl;

        /******QUEUE END******/
        
        
        
        /******PRIORITY QUEUE START******/

        // largest value/char stay at top
        //Data is stored in form of tree and not in linear

        priority_queue<int> pq;

        pq.push(5);     //{5}
        pq.push(2);     //{5,2}
        pq.push(8);     //{8,5,2}
        pq.emplace(10);     //{10,8,5,2}

        cout << pq.top();

        /*Minimum Priority Queue*/
        priority_queue <int , vector <int>, greater <int>> mpq;
        mpq.push(5);     //{5}
        mpq.push(2);     //{2,5}
        mpq.push(8);     //{2,5,8}
        mpq.push(10);        //{2,5,8,10}

        cout << mpq.top();

        cout<< endl << endl;

        //In max heap the parent wil always be greater than its children while in min heap the parent will always be lesser then its children

        /******PRIORITY QUEUE END******/





        /******SETS START******/

        /*Everything is sorted and unique*/

        set<int> sets;

        sets.insert(1);      //{1}
        sets.emplace(2);     //{1,2}
        sets.insert(2);      //{1,2}
        sets.insert(4);      //{1,2,4}
        sets.insert(3);      //{1,2,3,4}
        
        //Functionality of insert in vector can also be used to increase efficiency

        //begin(), end(), rbegin(), rend(), size(), empty(), swap()

        auto its = sets.find(3);
        sets.erase(5);

        int cnt = sets.count(1);

        its = sets.find(3);
        sets.erase(its);

        auto it1 = sets.find(2);
        auto it2 = sets.find(4);
        sets.erase(it1, it2);

        its = sets.lower_bound(2);
        its = sets.upper_bound(3);

        cout<< endl << endl;

        /******SETS END******/


        /******MULTISETS START******/
        //sorted only not unique

        multiset<int> ms;

        ms.insert(1);       //{1}
        ms.insert(1);       //{1,1}
        ms.insert(1);       //{1,1,1}
        ms.insert(1);       //{1,1,1,1}
        ms.insert(1);       //{1,1,1,1,1}

        ms.erase(ms.find(1));       //only one 1 erase  {1,1,1,1}
        //ms.erase(ms.find(1), ms.find(1)+2);       //1 from position 1 to position 3 but not working

        ms.erase(1);        //all 1's erase

        int cont = ms.count(1);

        cout<< endl << endl;
        /******MULTISETS END******/





        /******UNORDERED SETS START******/

        unordered_set <int> ust;
        //Unordered, unique set 
        //Lower and upper bound doesn't work rest all are good
        //Mostly O(1) time complexity of all functions


        /******UNORDERED SETS END******/



        /******MAP START******/
        //Stores same value but makes it unique by assigning different keys and in sorted order of key
        //Keys can be of any datatype
        //It is kind of dict
        
        map<int , int> mpp;
        //unordered_map<int,int> mpp;       It is unsorted and unordered
        // map<int , float> mpp;
        
        // map<pair < float,int > , int> mpp;
        // mpp insert[{2,3}] = 10;      //2,3 is key and value is 10
        
        // map<pair <int , float, double >> mpp; This is wrong pair can take only two
        
        mpp[1] = 2;      //Key 1 value 2
        mpp.emplace(3,1);     //Key 3 value 1
        mpp.insert({2,4});
        
        //Order [{1,2} {2,4} {3,1}]  Sorted!!
        
        for (auto it: mpp) 
        {
            cout << it.first << " " << it.second << endl;
        }
        
        auto ittt = mpp.find(3);
        // cout << *ittt.second;
        cout << ittt->second;
        
        // auto it = mpp.find(5);      Points towards the end 
        
        //Rest all functions work the same
        
        cout<< endl << endl;

        /******MAP END******/

        /******UNORDERED MAP START******/
        string s = "XIV";

 unordered_map <char,int> mp;
 mp = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

for (int i = 0; i < s.size(); i++)
{
    cout<< mp[s[i]] << " ";
}

        cout<< endl << endl;

        /******UNORDERED MAP END******/


        /******MULTIMAP START******/

        //Can save duplicate keys 
        //only mpp[key] cannot be used rest all functions are same

        /******MULTIMAP END******/


        /******SORTING START******/

        int x[4] = {2,8,1,5};
        int n = 4;
        sort(x,x+4);
        // sort(v.begin(),v.end());     For vectors

        sort(x, x+4, greater<int>());

        /* sort (x,x+n,comp);   Comp is self made for custom sorting methods

        bool comp (pair<int,int> p1, pair <int,int> p2){
            Custom made statements depending on type of sorting
            return true/false;
        }
        */

        int numb = 7;
        int ct = __builtin_popcount(numb);      //Binary is 111 So set bit is 3
        
        long long Num = 16584956284;
        int Ct = __builtin_popcountll(Num);

        string ss = "123";

        do
        {
            cout << ss << endl;
        } while (next_permutation(ss.begin(), ss.end()));

        /*If 231 the 231->312->321*/

        int maxi = *max_element(x,x+n);

        cout<< endl << endl;
        /******SORTING END******/



        return 0;
    }