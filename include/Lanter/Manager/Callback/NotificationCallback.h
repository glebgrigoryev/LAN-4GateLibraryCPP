#ifndef LAN_4GATELIB_NOTIFICATIONCALLBACK_H
#define LAN_4GATELIB_NOTIFICATIONCALLBACK_H

#include <memory>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Message/Notification/INotificationData.h"

namespace Lanter {
    namespace Manager {
        namespace Callback {
            /// \brief Колбэк для приема данных уведомления от терминала
            class LANTER_VISIBILITY NotificationCallback {
            public:
                virtual ~NotificationCallback() = default;
                /// \brief Метод, в который будет переданы данные уведомления
                /// \param data данные уведомления
                /// \sa Message::Notification::INotificationData
                virtual void newData(std::shared_ptr<Message::Notification::INotificationData> data) = 0;
            };
        }
    }
}

#endif //LAN_4GATELIB_NOTIFICATIONCALLBACK_H
