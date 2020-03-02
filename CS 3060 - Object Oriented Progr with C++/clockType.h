#include <string>

using namespace std;

class clockType{
public:
    void setTime(int hours, int minutes, int seconds);
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    
    void getTime(int& hours, int& minutes, int& seconds) const;
    
    int getHours() const {
        return hr;
    }
    int getMinutes() const {
        return min;
    }
    int getSeconds() const {
        return sec;
    }
    
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherClock) const;
    clockType(int hours, int minutes, int seconds);
    clockType();

private:
    int hr;
    int min;
    int sec;
};

