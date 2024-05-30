#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <random>
#include <string>
#include <vector>

static const int N = 5;
static const int numOfMeals = 20;
std::mutex lockprint;

struct Fork 
{
    std::mutex mutex;
};

class Philosopher
{
private:
    int ID;
    Fork& leftFork;
    Fork& rightFork;
    std::thread worker;
    std::mt19937 rng { std::random_device{}() };

    void print(std::string_view text);
    void startDining();
    void think();
    void eat();

public:
    Philosopher(int num, Fork& left, Fork& right)
        : ID(num), leftFork(left), rightFork(right), worker(&Philosopher::startDining, this) {}

    void join();
};

void Philosopher::join()
{
    worker.join();
}

void Philosopher::print(std::string_view text)
{
    std::lock_guard<std::mutex> cout_lock(lockprint);
    std::cout << ID << text << std::endl;
}

void Philosopher::think()
{
    //std::cout << ID << " is thinking\n";
    print(" is thinking");
    static thread_local std::uniform_int_distribution<> wait(1, 6);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait(rng) * 200));
}

void Philosopher::eat()
{
    //std::cout << ID << " is hungry\n";
    print(" is hungry");
    std::unique_lock<std::mutex> llock(leftFork.mutex);
    std::unique_lock<std::mutex> rlock(rightFork.mutex);

    //std::cout << ID << " is eating\n";
    print(" is eating");
    static thread_local std::uniform_int_distribution<> dist(1, 6);
    std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 200));

    //std::cout << ID << " finished eating\n";
    print(" finished eating");
}

void Philosopher::startDining()
{
    for(int i = 0; i < 20; i++)
    {
        think();

        eat();
    }

    //std::cout << ID << " is dying\n";
    print(" is dying");
}

int main()
{
    std::vector<Fork> forks (N);
    std::vector<Philosopher*> philosophers;
    for(int i = 0; i < N; i++)
    {
        Philosopher* p;
        if(i == N - 1)
        {
            p = new Philosopher(i, std::ref(forks[0]), std::ref(forks[i]));
        }
        else
        {
            p = new Philosopher(i, std::ref(forks[i]), std::ref(forks[i+1]));
        }

        philosophers.push_back(p);
    }

    for(auto& p : philosophers)
    {
        p->join();
        delete p;
    }

    philosophers.clear();

    return 0;
}
