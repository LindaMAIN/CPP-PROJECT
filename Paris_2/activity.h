#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>

class Activity {
public:
    virtual ~Activity() {}
    virtual void performActivity(double& budget, int& waitingTime) const = 0;

    //Getter
    int getTimeActivity() const { return timeActivity; }
    double getCost() const { return cost; }

    //Diplay info
    virtual void displayInfo() const = 0;
protected:
    Activity(int timeActivity, double cost);

private:
    int timeActivity;
    double cost;
};


// Derived class for Dining activity
class DiningActivity : public Activity {
public:
    DiningActivity();
    void performActivity(double& budget, int& waitingTime) const override;
    void displayInfo() const override;

private:
    static constexpr int DEFAULT_TIME_ACTIVITY = 30;
    static constexpr double DEFAULT_COST = 25.0;
};


// Derived class for Sightseeing activity
class SightseeingActivity : public Activity {
public:
    SightseeingActivity();
    void performActivity(double& budget, int& waitingTime) const override;
    void displayInfo() const override;

private:
    static constexpr int DEFAULT_TIME_ACTIVITY = 60;
    static constexpr double DEFAULT_COST = 10.0;
};

#endif // ACTIVITY_H
