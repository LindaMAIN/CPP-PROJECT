#include "activity.h"
#include <QDebug>
Activity::Activity(int timeActivity, double cost) : timeActivity(timeActivity), cost(cost) {
}


DiningActivity::DiningActivity() : Activity(DEFAULT_TIME_ACTIVITY, DEFAULT_COST) {
}


void DiningActivity::performActivity(double& budget, int& waitingTime) const {
    // Perform dining activity logic
    int activityTime = getTimeActivity();
    waitingTime += activityTime;

    // qDebug() << "Dining activity for " << activityTime << " minutes.";
    // Update budget based on activity cost
    budget -= getCost();

    // Print waiting time
    // qDebug() << "Waiting time: " << waitingTime << " minutes.";
}




SightseeingActivity::SightseeingActivity() : Activity(DEFAULT_TIME_ACTIVITY, DEFAULT_COST) {
}

void SightseeingActivity::performActivity(double& budget, int& waitingTime) const {
    // Perform sightseeing activity logic
    int activityTime = getTimeActivity();
    waitingTime += activityTime;
    // qDebug() << "Sightseeing activity for " << activityTime << " minutes.";
    // Update budget based on activity cost
    budget -= getCost();

    // Print waiting time
    // qDebug() << "Waiting time: " << waitingTime << " minutes.";
}


void DiningActivity::displayInfo() const {
    qDebug() << "Dining Activity: Time - " << getTimeActivity() << " minutes, Cost - " << getCost();
}

void SightseeingActivity::displayInfo() const {
    qDebug() << "Sightseeing Activity: Time - " << getTimeActivity() << " minutes, Cost - " << getCost();
}
