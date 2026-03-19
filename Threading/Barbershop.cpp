#include<iostream>
#include<vector>
using namespace std;

class barbershop{
    int capacity;
    int customers=0;
    
    atomic<bool> runnning{true};
    counting_semaphore<> customerArrived;
    counting_semaphore<> barberReady;
    counting_semaphore<> barberDone;
    counting_semaphore<> customerDone;
    
    public:
        barbershop(int c):capacity(c),customerArrived(0),barberReady(0),barberDone(0),customerDone(0),mtx(1){}
        void runcustomer(int id){
            mtx.acquire();
            if(customers==capacity){
                mtx.release();
                balk(id);
                return ;
            }

            customers+=1;
            cout<<"customer "<< id <<"has arrived"<<endl;
            mtx.release();

            customerArrived.release();
            barberReady.acquire();
            getHaircut(id);
            customerDone.release();
            barberDone.acquire();

            mtx.acquire();
            customers-=1;
            mtx.release();
        }

        void stopShop(){
            runnning=false;
            customerArrived.release();
        }
    private:
        void cutHair(){
            cout<<" barber is cutting Hair"<<endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        void getHaircut(int id){
            this_thread::sleep_for(chrono::milliseconds(100));
            cout<<"customer "<< id<< "is getting haircut"<<endl;            
        }
        void balk(int id){
            cout<<"customer"<< id << "is leaving the shop"<<endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
};

int main(){  
    int n=4;
    barbershop  shop(n);
    thread barber( & barbershop::runbarber,&shop);
    vector<thread>customers;
    for(int i=0; i< 10;i++){
        customers.emplace_back(&barbershop::runcustomer,&shop,i);
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    for(auto &it:customers){
        it.join();
    }
    shop.stopShop();
    barber.join();
    return 0;
}