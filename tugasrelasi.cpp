#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

    int generateId() {
        return ++globalId;
    }

public:
    User(string nama, string email) {
        this->id = generateId();
        this->nama = nama;
        this->email = email;
    }

    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status; // true = aktif

public:
    Member(string nama, string email)
        : User(nama, email) {
        status = true;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << "------------------------" << endl;
    }

    void setStatus(bool s) {
        status = s;
    }

    bool getStatus() {
        return status;
    }
};

class Admin : public User {
public:
    Admin(string nama, string email)
        : User(nama, email) {}

    void showAllMember(vector<Member> &members) {
        for (auto &m : members) {
            m.showProfile();
        }
    }

    void toggleActivationMember(Member &m) {
        m.setStatus(!m.getStatus());
    }
};


// main
int main() {
    vector<Member> members;

    Member m1("Faatih", "faatih@mail.com");
    Member m2("Budi", "budi@mail.com");

    members.push_back(m1);
    members.push_back(m2);

    Admin admin("Admin1", "admin@mail.com");

    cout << "=== Semua Member ===" << endl;
    admin.showAllMember(members);

    cout << "\n=== Toggle Status Member 1 ===" << endl;
    admin.toggleActivationMember(members[0]);

    cout << "\n=== Setelah Perubahan ===" << endl;
    admin.showAllMember(members);

    return 0;
}