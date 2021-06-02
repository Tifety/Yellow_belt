/************************************************************************************//**
 *  @file       notifier.cpp
 *
 *  @brief      Brief descriptinon of notifier.cpp 
 *
 *  @date       2019-03-25 18:52
 *
 ***************************************************************************************/

#include <string>
#include <iostream>


using namespace std;



class INotifier {
  public:
    virtual void Notify (const string& message) const = 0;
};

class SmsNotifier : public INotifier {
  public:
  SmsNotifier(string num) : number(num) {}

void Notify (const string& message) const override {
 SendSms (number, message);
}
  private:
    const string number;

};

class EmailNotifier : public INotifier {
  public:
    EmailNotifier (string mail) : email(mail) {}
    void Notify (const string& message) const override {
      SendEmail (email, message);
    }

  private:
    string email;
};

void Notify (INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

