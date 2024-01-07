#include "NotificationSubject.h"

void NotificationSubject::Attach(INotificationObserver *observer) {
  list_observer_.push_back(observer);
}

void NotificationSubject::Detach(INotificationObserver *observer) {
  list_observer_.remove(observer);
}

void NotificationSubject::Notify() {
  std::list<INotificationObserver *>::iterator iterator =
      list_observer_.begin();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(message_);
    ++iterator;
  }
}

void NotificationSubject::CreateMessage(JsonObject message) {
  this->message_ = message;
  Notify();
}

void NotificationSubject::HowManyObserver() {
  std::cout << "There are " << list_observer_.size()
            << " observers in the list.\n";
}
