#ifndef NOTIFICATIONOBSERVER_H_
#define NOTIFICATIONOBSERVER_H_

#include "INotificationObserver.h"
#include "NotificationSubject.h"
#include "util/json.h"

/**
 * @class NotificationObserver
 * @brief Classextends the INotificationObserver interface and servers
 *        an observer class
 */
class NotificationObserver : public INotificationObserver {
 public:
  /**
   * @brief Constructor for the NotificationObserver class
   * @param subject type NotificationSubject
   */
  NotificationObserver(NotificationSubject* subject) : subject_(subject) {
    this->subject_->Attach(this);
    std::cout << "New NotificationObserver initialized.\n";
  }

  /**
   * @brief Deonstructor for the NotificationObserver class
   */
  virtual ~NotificationObserver() {
    std::cout << "NotificationObserver Removed\"" << this->number_ << "\".\n";
  }

  /**
   * @brief Update's the observer of the message the subject posts
   * @param message_from_subject type JsonObject that is the message from the
   * subject
   */
  void Update(JsonObject& message_from_subject);

  /**
   * @brief Unsubscribe to notifications from subject
   */
  void RemoveMeFromTheList();

  /**
   * @brief Prints out message notification
   */
  void PrintInfo();

  /**
   * @brief Returns the first message in the queue as JsonObject
   */
  JsonObject GetMessageFromSubject();

  /**
   * @brief Checks to see if there is a new message
   * @return returns true if there is a new message else returs false
   **/
  bool HasNewMessage();

 private:
  JsonObject message_from_subject_;
  bool new_message = false;
  NotificationSubject* subject_;
  int number_;
};

#endif
