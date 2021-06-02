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


void SendSms (const string& number, const string& message) {
  cout << " Send ' " << message << "' to number " << number << endl;
}

void SendEmail (const string& email, const string& message) {
  cout << "Send ' " << message << "' to e-mail " << email << endl;
}

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

int main() {

  SmsNotifier sms{"4-44-444-444"};
  EmailNotifier email{"111@222.ru"};

  Notify(sms, "Nice sms");
  Notify(email, "Nice mail");
return 0;
}
