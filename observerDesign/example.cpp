#include<bits/stdc++.h>
using namespace std;

class User {
    private:
        int id;
    public:
        User(int id) {
            this->id = id;
        }

        void notificationReceived(string msg) {
            cout<<"User id = "<<id<<" received notification message = "<<msg<<endl;
        }
};

class Group{
    private:
        unordered_set<User *> users;
    public:
       void subscribe(User *user) {
            users.insert(user);
       }
       void unsubscribe(User *user) {
            users.erase(user);
       }
       void notify(string msg) {
            for(auto user: users) {
                user->notificationReceived(msg);
            }
       }
};


int main() {

    Group *group = new Group();
    User *user1 = new User(1);
    User *user2 = new User(2);
    User *user3 = new User(3);
    

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);
    group->notify("notify everyone connected.");
    group->unsubscribe(user2);
    group->notify("notify everyone connected.");
    

    return 0;
}