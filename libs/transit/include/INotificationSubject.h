#ifndef INOTIFICATIONSUBJECT_H
#define INOTIFICATIONSUBJECT_H

#include "INotificationObserver.h"

/**
 * @brief NotificationSubject interface
 */
class INotificationSubject {
 public:
  /**
   * @brief A destructor for INotificationSubject
   **/
  virtual ~INotificationSubject() {}

  /**
   * @brief Virtual function to attach subject to an observer
   * @param observer Type INotificationObserver, the observer the subject will
   *subscribe to
   **/
  virtual void Attach(INotificationObserver *observer) = 0;

  /**
   * @brief Virtual function to detach messages to observers
   * @param observer Type INotificationObserver, the observer the subject will
   *unsubscribe to
   **/
  virtual void Detach(INotificationObserver *observer) = 0;

  /**
   * @brief Virtual function to notify subject
   **/
  virtual void Notify() = 0;
};

#endif
