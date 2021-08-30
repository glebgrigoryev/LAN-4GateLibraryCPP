#ifndef LAN_4GATELIB_ILAN4GATE_H
#define LAN_4GATELIB_ILAN4GATE_H

#include <cstddef>
#include <memory>
#include <functional>

#include "Lanter/Utils/VisibilityMacroses.h"

#include "Lanter/Communication/ICommunication.h"

#include "Lanter/Message/Request/IRequestData.h"
#include "Lanter/Message/Response/IResponseData.h"
#include "Lanter/Message/Notification/INotificationData.h"

namespace Lanter {
    namespace Manager {
        /// \brief Предоставляет интерфейс взаимодействия с функционалом библиотеки
        class LANTER_VISIBILITY ILan4Gate {
        public:
             virtual ~ILan4Gate() = default;

            /// \brief Устанавливает лоический иденитфикатор кассового ПО. Значение по умолчанию 1
            /// \param[in] ecrNumber Логический идентификатор кассового ПО в диапазоне [1, 999]
            /// \return true, если поле успешно установлено
             virtual bool setEcrNumber(int16_t ecrNumber) = 0;

             /// \brief Возвращает логический идентификатор кассового ПО
             /// \return Логический идентификатор в диапазоне [1,999]. По умолчанию равен 1
             virtual int16_t getEcrNumber() const = 0;

            /// \brief Запускает цикл обработки запросов библиотеки
            /// \return true, если цикл успешно запущен
            virtual bool start() = 0;

            /// \brief Останавливает цикл обработки
            /// \return true, если цикл обработки запросов успешно остановлен
            virtual bool stop() = 0;

            /// \brief Возвращает состояние цикла обработки
            /// \return true, если цикл запущен и выполняется
            virtual bool isStarted() const = 0;

            /// \brief Выполняет одну итерацию цикла обработки запросов.
            /// Используется потоком библиотеки.
            /// Может быть использован в потоке приложения
            virtual void doLan4Gate() = 0;

            /// \brief Запускает цикл обработки запросов в отдельном потоке
            /// Если планируется встраиваение цикла обработки в собственный поток, то данный метод не нужно вызывать
            /// \return true, если поток успешно запущен
            virtual bool runOnThread() = 0;

            /// \brief Устанавливает соединение в качестве основного используемого
            /// \param[in] communication указатель на используемое соединение
            /// \return true, если соединение успешно установлено
            /// \sa Communication::ICommunication
            virtual bool setCommunication(std::shared_ptr<Communication::ICommunication> communication) = 0;

            /// \brief Сбрасывает указатель переданного соединения
            /// \return true, если успешно сброшен указатель
            virtual bool resetCommunication() = 0;

            /// \brief Возвращает указатель установленного соединения
            /// \return nullptr, если соединение не установлено или было сброшено
            virtual std::shared_ptr<Communication::ICommunication> getCommunication() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных запроса
            /// \param[in] callback std::function с сигнатурой `void func(std::shared_ptr<Message::Request::IRequestData>)`
            /// \return id зарегестрированного колбека
            /// \sa Message::Request::IRequestData
            virtual size_t addRequestCallback(std::function<void(std::shared_ptr<Message::Request::IRequestData>)> callback) = 0;

            /// \brief Удаляет колбек запроса из списка
            /// \param[in] id иденитфикатор колбека
            /// \return true, если успешно удалено
            virtual bool removeRequestCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегестрированных колбеков для получения данных запроса
            /// \return количество зарегестрированных колбеков
            virtual size_t requestCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных ответа
            /// \param[in] callback std::function с сигнатурой `void func(std::shared_ptr<Message::Response::IResponseData>)`
            /// \return id зарегестрированного колбека
            /// \sa Message::Response::IResponseData
            virtual size_t addResponseCallback(std::function<void(std::shared_ptr<Message::Response::IResponseData>)> callback) = 0;

            /// \brief Удаляет колбек ответа из списка
            /// \param[in] id иденитфикатор колбека
            /// \return true, если успешно удалено
            virtual bool removeResponseCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегестрированных колбеков для получения данных ответа
            /// \return количество зарегестрированных колбеков
            virtual size_t responseCallbacksCount() const = 0;

            /// \brief Добавляет колбек в список слушателей для получения данных уведомления
            /// \param[in] callback std::function на колбек-функцию
            /// \return id зарегестрированного колбека
            /// \sa Message::Notification::INotificationData
            virtual size_t addNotificationCallback(std::function<void(std::shared_ptr<Message::Notification::INotificationData>)> callback) = 0;

            /// \brief Удаляет колбек уведомления из списка
            /// \param[in] id иденитфикатор колбека
            /// \return true, если успешно удалено
            virtual bool removeNotificationCallback(size_t id) = 0;

            /// \brief Возвращает количество зарегестрированных колбеков для получения данных уведомления
            /// \return количество зарегестрированных колбеков
            virtual size_t notificationCallbacksCount() const = 0;

            /// \brief Возвращает подготовленный объект запроса с заполненными полями EcrNumber и OperationCode
            /// \param[in] operationCode Код операции, для которой необходимо подготовить объект
            /// \return nullptr, если не удалось создать объект запроса
            /// \sa Message::Request::RequestDataFactory
            virtual std::shared_ptr<Message::Request::IRequestData> getPreparedRequest(Message::OperationCode operationCode) = 0;

            /// \brief Возвращает подготовленный объект ответа с заполненными полями EcrNumber и OperationCode
            /// \param[in] operationCode Код операции, для которой необходимо подготовить объект ответа
            /// \return nullptr, если не удалось создать объект
            /// \sa Message::Response::ResponseDataFactory
            virtual std::shared_ptr<Message::Response::IResponseData> getPreparedResponse(Message::OperationCode operationCode) = 0;

            /// \brief Возвращает подготовленный объект ответа с заполненным полем NotificationCode
            /// \param[in] notificationCode Код уведомления, для которого необходимо создать объект. По умолчанию NoNotification
            /// \return nullptr, если не удалось создать объект
            /// \sa Message::Notification::NotificationDataFactory
            virtual std::shared_ptr<Message::Notification::INotificationData> getPreparedNotification(Message::Notification::NotificationCode notificationCode = Message::Notification::NotificationCode::NoNotification) = 0;
        };
    }
}

#endif //LAN_4GATELIB_ILAN4GATE_H
