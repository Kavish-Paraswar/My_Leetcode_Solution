using namespace std;
class Foo {
public:
    mutex m;
    condition_variable cv;
    int turn;
    Foo() { turn = 0; }

    void first(function<void()> printFirst) {

        printFirst();
        turn = 1;
        cv.notify_all();

        // printFirst() outputs "first". Do not change or remove this line.
    }

    void second(function<void()> printSecond) {

        unique_lock<std::mutex> lock(m);

        while (turn != 1) {
            cv.wait(lock);
        }

        turn = 2;
        cv.notify_all();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {

        std::unique_lock<std::mutex> lock(m);

        while (turn != 2) {
            cv.wait(lock);
        }

        cv.notify_all();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};