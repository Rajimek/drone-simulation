#ifndef NOTIFICATIONSUBJECT_H
#define NOTIFICATIONSUBJECT_H

#include "INotificationSubject.h"
#include "util/json.h"

/**
 * @class NotificationSubject
 * @brief Represents the notification subject's notificiation system.
 */
class NotificationSubject : public INotificationSubject {
 public:
  /**
   * @brief Destructor for the Notification Subject
   */
  virtual ~NotificationSubject() {}

  /**
   * @brief Attaches a new subscriber to the list
   * @param observer type INotificationObserver*
   */
  void Attach(INotificationObserver *observer);

  /**
   * @brief Removes subscriber from list
   * @param observer type INotificationObserver*
   */
  void Detach(INotificationObserver *observer);

  /**
   * @brief Notifies all subjects in the list that is subscribed to the
   * notification
   */
  void Notify();

  /**
   * @brief Notifies subscribers of the position of the subject
   * @param message JsonObject message
   */
  void CreateMessage(JsonObject message);

  /**
   * @brief Prints out number of subscribers in the observer list
   */
  void HowManyObserver();

 private:
  std::list<INotificationObserver *> list_observer_;
  JsonObject message_;
};

#endif
