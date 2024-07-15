#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

class Malware {
public:
    virtual void mutate() = 0;
};

class IntegerMalware : public Malware {
private:
    vector<int> malwareCode;
    mt19937 gen;

public:
    IntegerMalware(vector<int> code, mt19937 generator)
        : malwareCode(code), gen(generator) {}

    void mutate() override {
        uniform_int_distribution<> mutation_type_dis(0, 4); 
        uniform_int_distribution<> index_dis(0, malwareCode.size() - 1);
        uniform_int_distribution<> increment_dis(10, 50); 
        uniform_int_distribution<> replacement_dis(1, 100);
        uniform_int_distribution<> shift_dis(-5, 5); 

        int mutation_type = mutation_type_dis(gen);

        switch (mutation_type) {
        case 0: {
            int index = index_dis(gen);
            int increment = increment_dis(gen);
            malwareCode[index] += increment;
            break;
        }
        case 1: {
            int index = index_dis(gen);
            int replacement = replacement_dis(gen);
            malwareCode[index] = replacement;
            break;
        }
        case 2: {
            int index1 = index_dis(gen);
            int index2 = index_dis(gen);
            while (index1 == index2) {
                index2 = index_dis(gen);
            }
            swap(malwareCode[index1], malwareCode[index2]);
            break;
        }
        case 3: {
            shuffle(malwareCode.begin(), malwareCode.end(), gen);
            break;
        }
        case 4: {
            for (int& value : malwareCode) {
                value += shift_dis(gen);
                if (value < 0) value = 0; 
            }
            break;
        }
        default:
            break;
        }
    }

    void printMalwareCode() const {
        cout << "example code:";
        for (int value : malwareCode) {
            cout << " " << value;
        }
        cout << endl;
    }
};

int main() {
    vector<int> initialCode = { 1, 2, 3, 4, 5 };

    auto seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    IntegerMalware malware(initialCode, gen);

    cout << "initial ";
    malware.printMalwareCode();

    for (int i = 1; i <= 3; ++i) {
        malware.mutate();

        cout << "iteration " << i << ": mutated ";
        malware.printMalwareCode();
    }

    return 0;
}
