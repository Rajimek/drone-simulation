#ifndef INOTIFICATIONOBSERVER_H
#define INOTIFICATIONOBSERVER_H

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include "util/json.h"

/**
 * @brief NotificationObserver interface
 */
class INotificationObserver {
 public:
  /**
  * @brief A destructor for INotificationObserver
  **/
  virtual ~INotificationObserver() {}

  /**
   * @brief Virtual function to update messages passed from subject to observer
   * @param message_from_subject Type JsonObject contains message from subbject
   **/
  virtual void Update(JsonObject &message_from_subject) = 0;
};




#endif
