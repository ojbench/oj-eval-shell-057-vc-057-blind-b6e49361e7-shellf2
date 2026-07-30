#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
    size_t order;
};

static void print_student(const Student& s) {
    cout << s.id << ' ' << s.name << ' ' << s.score << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;
    unordered_map<string, size_t> by_id;
    unordered_map<string, size_t> by_name;
    students.reserve(10000);
    by_id.reserve(10000);
    by_name.reserve(10000);

    int cmd;
    while (cin >> cmd) {
        if (cmd == 1) {
            string id, name;
            int score;
            cin >> id >> name >> score;
            if (by_id.count(id)) {
                cout << "FAILED\n";
                continue;
            }
            size_t idx = students.size();
            students.push_back(Student{id, name, score, idx});
            by_id[id] = idx;
            by_name[name] = idx;
            cout << "SUCCESS\n";
        } else if (cmd == 2) {
            for (const auto& s : students) {
                print_student(s);
            }
        } else if (cmd == 3) {
            string id;
            cin >> id;
            print_student(students[by_id[id]]);
        } else if (cmd == 4) {
            string name;
            cin >> name;
            print_student(students[by_name[name]]);
        } else if (cmd == 5) {
            vector<const Student*> order;
            order.reserve(students.size());
            for (const auto& s : students) order.push_back(&s);
            sort(order.begin(), order.end(), [](const Student* a, const Student* b) {
                return a->id < b->id;
            });
            for (const auto* s : order) print_student(*s);
        } else if (cmd == 6) {
            vector<const Student*> order;
            order.reserve(students.size());
            for (const auto& s : students) order.push_back(&s);
            stable_sort(order.begin(), order.end(), [](const Student* a, const Student* b) {
                if (a->score != b->score) return a->score > b->score;
                return a->order < b->order;
            });
            for (const auto* s : order) print_student(*s);
        } else if (cmd == 7) {
            cout << "END\n";
            break;
        }
    }

    return 0;
}
