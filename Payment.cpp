//
// Created by user.v2.0 on 13.12.2020.
//

#include "Payment.h"

Payment::Payment() {
    sum = 0.0;
    payer_org = "corp";
    payer_account = "00000000000000000000";
    payee_org = "corporation";
    payee_account = "11111111111111111111";
}

Payment::Payment(float sum, const std::string &payerAccount, const std::string &payerOrg,
                 const std::string &payeeAccount, const std::string &payeeOrg) : sum(sum), payer_account(payerAccount),
                                                                                 payer_org(payerOrg),
                                                                                 payee_account(payeeAccount),
                                                                                 payee_org(payeeOrg) {}

Payment::Payment(const Payment &another_payment) {
    sum = another_payment.sum;
    payee_org = another_payment.payee_org;
    payee_account = another_payment.payee_account;
    payer_org = another_payment.payer_org;
    payer_account = another_payment.payer_account;
}

float Payment::getSum() const {
    return sum;
}

void Payment::setSum(float sum) {
    Payment::sum = sum;
}

const std::string &Payment::getPayerAccount() const {
    return payer_account;
}

void Payment::setPayerAccount(const std::string &payerAccount) {
    payer_account = payerAccount;
}

const std::string &Payment::getPayerOrg() const {
    return payer_org;
}

void Payment::setPayerOrg(const std::string &payerOrg) {
    payer_org = payerOrg;
}

const std::string &Payment::getPayeeAccount() const {
    return payee_account;
}

void Payment::setPayeeAccount(const std::string &payeeAccount) {
    payee_account = payeeAccount;
}

const std::string &Payment::getPayeeOrg() const {
    return payee_org;
}

void Payment::setPayeeOrg(const std::string &payeeOrg) {
    payee_org = payeeOrg;
}

Payment::~Payment() {

}

bool Payment::operator==(const Payment &rhs) const {
    return sum == rhs.sum &&
           payer_account == rhs.payer_account &&
           payer_org == rhs.payer_org &&
           payee_account == rhs.payee_account &&
           payee_org == rhs.payee_org;
}

bool Payment::operator!=(const Payment &rhs) const {
    return !(rhs == *this);
}

bool Payment::operator<(const Payment &rhs) const {
    return this->sum < rhs.sum;
}

bool Payment::operator>(const Payment &rhs) const {
    return this->sum > rhs.sum;
}

bool Payment::operator<=(const Payment &rhs) const {
    return *this < rhs || *this == rhs;
}

bool Payment::operator>=(const Payment &rhs) const {
    return *this > rhs || *this == rhs;
}

std::ostream &operator<<(std::ostream &os, const Payment &payment) {
    os << "sum: " << payment.sum << " payer_account: " << payment.payer_account << " payer_org: " << payment.payer_org
       << " payee_account: " << payment.payee_account << " payee_org: " << payment.payee_org;
    return os;
}

std::istream &operator>>(std::istream &input, Payment &payment) {
    std::string sum = std::to_string(payment.sum);
    input >> sum >> payment.payee_account >> payment.payee_org >> payment.payer_account >> payment.payee_org;
    payment.sum = std::stof(sum);
}

Payment Payment::operator+(int rhs) {
    Payment new_payment = Payment(*(this));
    new_payment.setSum(new_payment.getSum() + rhs);
    return new_payment;
}

Payment Payment::operator-(int rhs) {
    Payment new_payment = Payment(*(this));
    new_payment.setSum(new_payment.getSum() - rhs);
    return new_payment;
}

Payment operator+(Payment payment, float rhs) {
    Payment new_payment = Payment(payment);
    new_payment.setSum(new_payment.getSum() + rhs);
    return new_payment;
}

Payment operator-(Payment payment, float rhs) {
    Payment new_payment = Payment(payment);
    new_payment.setSum(new_payment.getSum() - rhs);
    return new_payment;
}

Payment Payment::operator=(Payment payment) {
    sum = payment.sum;
    payer_account = payment.payer_account;
    payer_org = payment.payer_org;
    payee_account = payment.payee_account;
    payee_org = payment.payee_org;
}

Payment &Payment::operator++() {
    *this = *this + 1;
    return *this;
}

Payment &Payment::operator--() {
    *this = *this - 1;
    return *this;
}

Payment operator++(Payment payment, int) {
    Payment new_payment = Payment(payment);
    payment = payment + 1;
    return new_payment;
}

Payment operator--(Payment payment, int) {
    Payment new_payment = Payment(payment);
    payment = payment - 1;
    return new_payment;
}


