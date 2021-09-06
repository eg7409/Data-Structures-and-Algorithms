#include <bits/stdc++.h>
using namespace std;

class Car{
    public:
      string id;
      int x, y;

      Car(string id,int x,int y){
          this->id = id;
          this->x = x;
          this->y = y;
      }

      int dist()const{
          return x*x + y*y;
      }
};

class compCar{
    public:
       bool operator()(Car a,Car b){
           return a.dist() < b.dist();
       }
};


void solve(int n,int k,vector<Car> v){

    priority_queue<Car,vector<Car>, compCar > pq(v.begin(),v.begin()+k);

    for(int i=k;i<n;i++){
        auto curr_car = v[i];

        if(curr_car.dist() < pq.top().dist()){
            pq.pop();
            pq.push(curr_car);
        }
    }

    vector<Car> output;

    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }

    reverse(output.begin(),output.end());

    for(auto i : output){
        cout<<i.id<<endl;
    }
}


int main(){

    int n,k;
    cin>>n>>k;

    
    string id;
    int x,y;
    vector<Car> v;

    for(int i=0;i<n;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        v.push_back(car);
    }

    solve(n,k,v);

    return 0;
}
