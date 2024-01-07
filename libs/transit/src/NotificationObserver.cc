#include "NotificationObserver.h"

void NotificationObserver::Update(JsonObject &message_from_subject) {
  message_from_subject_ = message_from_subject;
  new_message = true;
  PrintInfo();
}

void NotificationObserver::RemoveMeFromTheList() {
  subject_->Detach(this);
  std::cout << "NotificationObserver \"" << number_
            << "\" removed from the list.\n";
}

void NotificationObserver::PrintInfo() {
  std::cout << "NotificationObserver \"" << this->number_
            << "\": a new message is available --> "
            << this->message_from_subject_ << "\n";
}

JsonObject NotificationObserver::GetMessageFromSubject() {
  return message_from_subject_;
}

bool NotificationObserver::HasNewMessage() {
  if (new_message == true) {
    new_message = false;
    return true;
  } else {
    return false;
  }
}
